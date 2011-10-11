// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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

#if defined(HAVE_OCC)

#if defined(HAVE_SALOME)
#include "Partition_Spliter.hxx"
#endif

void addSimpleShapes(TopoDS_Shape theShape, TopTools_ListOfShape &theList);

void OCC_Internals::buildLists()
{
  somap.Clear();
  shmap.Clear();
  fmap.Clear();
  wmap.Clear();
  emap.Clear();
  vmap.Clear();
  addShapeToLists(shape);
}

void OCC_Internals::buildShapeFromLists(TopoDS_Shape _shape)
{
  BRep_Builder B;
  TopoDS_Compound C;
  B.MakeCompound(C);

  TopTools_ListOfShape theList;
  addSimpleShapes(_shape, theList);
  TopTools_ListIteratorOfListOfShape itSub1(theList);
  for (; itSub1.More(); itSub1.Next()) B.Add(C, itSub1.Value());

  for(int i = 1; i <= vmap.Extent(); i++) B.Add(C, vmap(i));
  for(int i = 1; i <= emap.Extent(); i++) B.Add(C, emap(i));
  for(int i = 1; i <= wmap.Extent(); i++) B.Add(C, wmap(i));
  for(int i = 1; i <= fmap.Extent(); i++) B.Add(C, fmap(i));
  for(int i = 1; i <= shmap.Extent(); i++) B.Add(C, shmap(i));
  for(int i = 1; i <= somap.Extent(); i++) B.Add(C, somap(i));
  shape = C;
}

void OCC_Internals::addShapeToLists(TopoDS_Shape _shape)
{
  // Solids
  TopExp_Explorer exp0, exp1, exp2, exp3, exp4, exp5;
  for(exp0.Init(_shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
    TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
    if(somap.FindIndex(solid) < 1){
      somap.Add(solid);

      for(exp1.Init(solid, TopAbs_SHELL); exp1.More(); exp1.Next()){
        TopoDS_Shell shell = TopoDS::Shell(exp1.Current());
        if(shmap.FindIndex(shell) < 1){
          shmap.Add(shell);

          for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()){
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
        }
      }
    }
  }
  
  // Free Shells
  for(exp1.Init(exp0.Current(), TopAbs_SHELL, TopAbs_SOLID); exp1.More(); exp1.Next()){
    TopoDS_Shape shell = exp1.Current();
    if(shmap.FindIndex(shell) < 1){
      shmap.Add(shell);

      for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()){
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
    }
  }
    
  // Free Faces
  for(exp2.Init(_shape, TopAbs_FACE, TopAbs_SHELL); exp2.More(); exp2.Next()){
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
  for(exp3.Init(_shape, TopAbs_WIRE, TopAbs_FACE); exp3.More(); exp3.Next()){
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
  for(exp4.Init(_shape, TopAbs_EDGE, TopAbs_WIRE); exp4.More(); exp4.Next()){
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
  for(exp5.Init(_shape, TopAbs_VERTEX, TopAbs_EDGE); exp5.More(); exp5.Next()){
    TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
    if(vmap.FindIndex(vertex) < 1)
      vmap.Add(vertex);
  }    
  
}

void OCC_Internals::healGeometry(double tolerance, bool fixdegenerated,
                                 bool fixsmalledges, bool fixspotstripfaces, 
                                 bool sewfaces, bool makesolids, bool connect)
{
  if(!fixdegenerated && !fixsmalledges && !fixspotstripfaces &&
     !sewfaces && !makesolids && !connect) return;

  Msg::Info("Starting geometry healing procedure (tolerance: %g)", tolerance);

  buildLists();
  TopExp_Explorer exp0, exp1;
  int nrc = 0, nrcs = 0;
  int nrso = somap.Extent(), nrsh = shmap.Extent(), nrf = fmap.Extent();
  int nrw = wmap.Extent(), nre = emap.Extent(), nrv = vmap.Extent();
  for (exp0.Init(shape, TopAbs_COMPOUND); exp0.More(); exp0.Next()) nrc++;
  for (exp0.Init(shape, TopAbs_COMPSOLID); exp0.More(); exp0.Next()) nrcs++;
 
  double surfacecont = 0;
  for (exp0.Init(shape, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    GProp_GProps system;
    BRepGProp::SurfaceProperties(face, system);
    surfacecont += system.Mass();
  }

  if (fixdegenerated){
    Msg::Info("- fix degenerated edges and faces");

    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(shape);
      for (exp1.Init (shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge))
          rebuild->Remove(edge, false);
      }
      shape = rebuild->Apply(shape);
    }
    buildLists();

    {
      Handle(ShapeFix_Face) sff;
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(shape);
      
      for (exp0.Init (shape, TopAbs_FACE); exp0.More(); exp0.Next()){
        TopoDS_Face face = TopoDS::Face(exp0.Current());

        sff = new ShapeFix_Face (face);
        sff->FixAddNaturalBoundMode() = Standard_True;
        sff->FixSmallAreaWireMode() = Standard_True;
        sff->Perform();
        
        if(sff->Status(ShapeExtend_DONE1) ||
           sff->Status(ShapeExtend_DONE2) ||
           sff->Status(ShapeExtend_DONE3) ||
           sff->Status(ShapeExtend_DONE4) ||
           sff->Status(ShapeExtend_DONE5))
          {
            Msg::Info("  repaired face %d", fmap.FindIndex(face));
            if(sff->Status(ShapeExtend_DONE1))
              Msg::Info("  (some wires are fixed)");
            else if(sff->Status(ShapeExtend_DONE2))
              Msg::Info("  (orientation of wires fixed)");
            else if(sff->Status(ShapeExtend_DONE3))
              Msg::Info("  (missing seam added)");
            else if(sff->Status(ShapeExtend_DONE4))
              Msg::Info("  (small area wire removed)");
            else if(sff->Status(ShapeExtend_DONE5))
              Msg::Info("  (natural bounds added)");
            TopoDS_Face newface = sff->Face();
            
            rebuild->Replace(face, newface, Standard_False);
          }
      }
      shape = rebuild->Apply(shape);
    }
    
    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(shape);
      for (exp1.Init (shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if (BRep_Tool::Degenerated(edge))
          rebuild->Remove(edge, false);
      }
      shape = rebuild->Apply(shape);
    }
  }
  
  if (fixsmalledges){
    Msg::Info("- fixing small edges");
    
    Handle(ShapeFix_Wire) sfw;
    Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
    rebuild->Apply(shape);
    
    for (exp0.Init (shape, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      
      for (exp1.Init (face, TopAbs_WIRE); exp1.More(); exp1.Next()){
        TopoDS_Wire oldwire = TopoDS::Wire(exp1.Current());
        sfw = new ShapeFix_Wire (oldwire, face ,tolerance);
        sfw->ModifyTopologyMode() = Standard_True;
        
        sfw->ClosedWireMode() = Standard_True;
        
        bool replace = false;
        replace = sfw->FixReorder() || replace;
        replace = sfw->FixConnected() || replace;
        
        if (sfw->FixSmall(Standard_False, tolerance) && 
            ! (sfw->StatusSmall(ShapeExtend_FAIL1) ||
               sfw->StatusSmall(ShapeExtend_FAIL2) ||
               sfw->StatusSmall(ShapeExtend_FAIL3))){
          Msg::Info("  fixed small edge in wire %d", wmap.FindIndex(oldwire));
          replace = true;
        }
        else if (sfw->StatusSmall(ShapeExtend_FAIL1))
          Msg::Warning("Failed to fix small edge in wire %d, edge cannot be checked "
                       "(no 3d curve and no pcurve)", wmap.FindIndex(oldwire));
        else if (sfw->StatusSmall(ShapeExtend_FAIL2))
          Msg::Warning("Failed to fix small edge in wire %d, "
                       "edge is null-length and has different vertives at begin and "
                       "end, and lockvtx is True or ModifiyTopologyMode is False",
                       wmap.FindIndex(oldwire));
        else if (sfw->StatusSmall(ShapeExtend_FAIL3))
          Msg::Warning("Failed to fix small edge in wire, CheckConnected has failed",
                       wmap.FindIndex(oldwire));
        
        replace = sfw->FixEdgeCurves() || replace;
        replace = sfw->FixDegenerated() || replace;
        replace = sfw->FixSelfIntersection() || replace;
        replace = sfw->FixLacking(Standard_True) || replace;
        if(replace){
          TopoDS_Wire newwire = sfw->Wire();
          rebuild->Replace(oldwire, newwire, Standard_False);
        }
      }
    }
    
    shape = rebuild->Apply(shape);
    
    {
      buildLists();
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(shape);
      
      for (exp1.Init (shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if (vmap.FindIndex(TopExp::FirstVertex (edge)) ==
            vmap.FindIndex(TopExp::LastVertex (edge))){
          GProp_GProps system;
          BRepGProp::LinearProperties(edge, system);
          if (system.Mass() < tolerance){
            Msg::Info("  removing degenerated edge %d from vertex %d to vertex %d",
                      emap.FindIndex(edge), vmap.FindIndex(TopExp::FirstVertex(edge)),
                      vmap.FindIndex(TopExp::LastVertex(edge)));
            rebuild->Remove(edge, false);
          }
        }
      }
      shape = rebuild->Apply(shape);
    }
    
    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(shape);
      for (exp1.Init (shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge) )
          rebuild->Remove(edge, false);
      }
      shape = rebuild->Apply(shape);
    }
    
    Handle(ShapeFix_Wireframe) sfwf = new ShapeFix_Wireframe;
    sfwf->SetPrecision(tolerance);
    sfwf->Load (shape);
    sfwf->ModeDropSmallEdges() = Standard_True;
    
    if (sfwf->FixWireGaps()){
      Msg::Info("- fixing wire gaps");
      if (sfwf->StatusWireGaps(ShapeExtend_OK)) 
        Msg::Info("  no gaps found");
      if (sfwf->StatusWireGaps(ShapeExtend_DONE1))
        Msg::Info("  some 2D gaps fixed");
      if (sfwf->StatusWireGaps(ShapeExtend_DONE2)) 
        Msg::Info("  some 3D gaps fixed");
      if (sfwf->StatusWireGaps(ShapeExtend_FAIL1)) 
        Msg::Info("  failed to fix some 2D gaps");
      if (sfwf->StatusWireGaps(ShapeExtend_FAIL2))
        Msg::Info("  failed to fix some 3D gaps");
    }
    
    sfwf->SetPrecision(tolerance);
    
    if (sfwf->FixSmallEdges()){
      Msg::Info("- fixing wire frames");
      if (sfwf->StatusSmallEdges(ShapeExtend_OK)) 
        Msg::Info("  no small edges found");
      if (sfwf->StatusSmallEdges(ShapeExtend_DONE1))
        Msg::Info("  some small edges fixed");
      if (sfwf->StatusSmallEdges(ShapeExtend_FAIL1)) 
        Msg::Info("  failed to fix some small edges");
    }
    
    shape = sfwf->Shape();
  }

  if (fixspotstripfaces){
    Msg::Info("- fixing spot and strip faces");
    Handle(ShapeFix_FixSmallFace) sffsm = new ShapeFix_FixSmallFace();
    sffsm -> Init (shape);
    sffsm -> SetPrecision (tolerance);
    sffsm -> Perform();
    
    shape = sffsm -> FixShape();
  }

  if (sewfaces){
    Msg::Info("- sewing faces");
    
    BRepOffsetAPI_Sewing sewedObj(tolerance);
    
    for (exp0.Init (shape, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face (exp0.Current());
      sewedObj.Add (face);
    }
    
    sewedObj.Perform();
    
    if (!sewedObj.SewedShape().IsNull())
      shape = sewedObj.SewedShape();
    else
      Msg::Info("  not possible");
  }
  
  {
    Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
    rebuild->Apply(shape);
    for (exp1.Init (shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
      TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
      if ( BRep_Tool::Degenerated(edge) )
        rebuild->Remove(edge, false);
    }
    shape = rebuild->Apply(shape);
  }
  
  if (makesolids){
    Msg::Info("- making solids");
    
    BRepBuilderAPI_MakeSolid ms;
    int count = 0;
    for (exp0.Init(shape, TopAbs_SHELL); exp0.More(); exp0.Next()){
      count++;
      ms.Add (TopoDS::Shell(exp0.Current()));
    }
    
    if (!count){
      Msg::Info("  not possible (no shells)");
    }
    else{
      BRepCheck_Analyzer ba(ms);
      if (ba.IsValid ()){
        Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
        sfs->Init (ms);
        sfs->SetPrecision(tolerance);
        sfs->SetMaxTolerance(tolerance);
        sfs->Perform();
        shape = sfs->Shape();
        
        for (exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
          TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
          TopoDS_Solid newsolid = solid;
          BRepLib::OrientClosedSolid (newsolid);
          Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
          //		  rebuild->Apply(shape);
          rebuild->Replace(solid, newsolid, Standard_False);
          TopoDS_Shape newshape = rebuild->Apply(shape, TopAbs_COMPSOLID);//, 1);
          //		  TopoDS_Shape newshape = rebuild->Apply(shape);
          shape = newshape;
        }
      }
      else
        Msg::Info("  not possible");
    }
  }

  if (connect){
#if defined(HAVE_SALOME)
    Msg::Info("- cutting and connecting faces with Salome's Partition_Spliter");
    TopExp_Explorer e2;
    Partition_Spliter ps;
    for (e2.Init(shape, TopAbs_SOLID); e2.More(); e2.Next())
      ps.AddShape(e2.Current());
    try{
      ps.Compute();
      shape = ps.Shape();
    }
    catch(Standard_Failure &err){
      Msg::Error("%s", err.GetMessageString());
    }
#else
    Msg::Info("- cutting and connecting faces with OCC_Connect");
    OCC_Connect connect(1);
    for(TopExp_Explorer p(shape, TopAbs_SOLID); p.More(); p.Next())
      connect.Add(p.Current());
    connect.Connect();
    shape = connect;
#endif
  }
  
  double newsurfacecont = 0;
  for (exp0.Init (shape, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    GProp_GProps system;
    BRepGProp::SurfaceProperties(face, system);
    newsurfacecont += system.Mass();
  }

  buildLists();
  int nnrc = 0, nnrcs = 0;
  int nnrso = somap.Extent(), nnrsh = shmap.Extent(), nnrf = fmap.Extent();
  int nnrw = wmap.Extent(), nnre = emap.Extent(), nnrv = vmap.Extent();
  for (exp0.Init(shape, TopAbs_COMPOUND); exp0.More(); exp0.Next()) nnrc++;
  for (exp0.Init(shape, TopAbs_COMPSOLID); exp0.More(); exp0.Next()) nnrcs++;
  
  Msg::Info("-----------------------------------");
  Msg::Info("Compounds          : %d (%d)", nnrc, nrc);
  Msg::Info("Composite solids   : %d (%d)", nnrcs, nrcs);
  Msg::Info("Solids             : %d (%d)", nnrso, nrso);
  Msg::Info("Shells             : %d (%d)", nnrsh, nrsh);
  Msg::Info("Wires              : %d (%d)", nnrw, nrw);
  Msg::Info("Faces              : %d (%d)", nnrf, nrf);
  Msg::Info("Edges              : %d (%d)", nnre, nre);
  Msg::Info("Vertices           : %d (%d)", nnrv, nrv );
  Msg::Info("Totol surface area : %g (%g)", newsurfacecont, surfacecont);
  Msg::Info("-----------------------------------");
}

void OCC_Internals::loadBREP(const char *fn)
{
  BRep_Builder aBuilder;
  BRepTools::Read(shape, (char*)fn, aBuilder);
  BRepTools::Clean(shape);
  healGeometry(CTX::instance()->geom.tolerance, 
               CTX::instance()->geom.occFixDegenerated,
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
  std::ofstream myFile;
  myFile.open (fn);
  try {
    BRepTools::Write(shape, myFile);
  }
  catch(Standard_Failure &err){
    Msg::Error("%s", err.GetMessageString());
  }
  myFile.close ();
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
               CTX::instance()->geom.occFixDegenerated,
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
  IFSelect_ReturnStatus status = writer.Transfer(shape, STEPControl_ManifoldSolidBrep);
  if (status == IFSelect_RetDone) 
    status = writer.Write((char*)fn);
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
               CTX::instance()->geom.occFixDegenerated,
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

GVertex *OCC_Internals::addVertexToModel(GModel *model, TopoDS_Vertex vertex)
{
  GVertex *gv = getOCCVertexByNativePtr(model, vertex);
  if (gv) return gv;
  addShapeToLists(vertex);
  buildShapeFromLists(vertex);
  buildGModel(model);
  return getOCCVertexByNativePtr (model,vertex);
}

GEdge *OCC_Internals::addEdgeToModel(GModel *model, TopoDS_Edge edge)
{
  GEdge *ge = getOCCEdgeByNativePtr(model, edge);
  if (ge) return ge;
  addShapeToLists(edge);
  buildShapeFromLists(edge);
  buildGModel(model);
  return getOCCEdgeByNativePtr(model,edge);
}

GFace* OCC_Internals::addFaceToModel(GModel *model, TopoDS_Face face)
{
  GFace *gf = getOCCFaceByNativePtr(model,face);
  if (gf) return gf;
  addShapeToLists(face);
  buildShapeFromLists(face);
  buildGModel(model);
  return getOCCFaceByNativePtr(model,face);
}

GRegion* OCC_Internals::addRegionToModel(GModel *model, TopoDS_Solid region)
{
  GRegion *gr  = getOCCRegionByNativePtr(model,region);
  if (gr) return gr;
  addShapeToLists(region);
  buildShapeFromLists(region);
  buildGModel(model);
  return getOCCRegionByNativePtr(model,region);
}

void OCC_Internals::buildGModel(GModel *model)
{
  // building geom vertices
  int nvertices = vmap.Extent();
  for(int i = 1; i <= nvertices; i++){
    int num = model->getMaxElementaryNumber(0) + 1;
    if (!getOCCVertexByNativePtr(model, TopoDS::Vertex(vmap(i))))
      model->add(new OCCVertex(model, num, TopoDS::Vertex(vmap(i))));
  }

  // building geom edges
  int nedges = emap.Extent();
  for(int i = 1; i <= nedges; i++){
    int i1 = vmap.FindIndex(TopExp::FirstVertex(TopoDS::Edge(emap(i)))); 
    int i2 = vmap.FindIndex(TopExp::LastVertex(TopoDS::Edge(emap(i))));
    int num = model->getMaxElementaryNumber(1) + 1;
    if (!getOCCEdgeByNativePtr(model, TopoDS::Edge(emap(i)))){
      GVertex *v1 = getOCCVertexByNativePtr(model, TopoDS::Vertex(vmap(i1)));
      GVertex *v2 = getOCCVertexByNativePtr(model, TopoDS::Vertex(vmap(i2)));
      model->add(new OCCEdge(model, TopoDS::Edge(emap(i)), num, v1, v2));
    }
  }

  // building geom faces
  int nfaces = fmap.Extent();
  for(int i = 1; i <= nfaces; i++){
    int num = model->getMaxElementaryNumber(2) + 1;
    if (!getOCCFaceByNativePtr(model, TopoDS::Face(fmap(i))))
      model->add(new OCCFace(model, TopoDS::Face(fmap(i)), num));
  }
  // building geom regions
  int nvolumes = somap.Extent();
  for(int i = 1; i <= nvolumes; i++){
    int num = model->getMaxElementaryNumber(3) + 1;
    if (!getOCCRegionByNativePtr(model, TopoDS::Solid(somap(i))))
      model->add(new OCCRegion(model, TopoDS::Solid(somap(i)), num));
  }
  
  model->updateUpperTopology();
}

void addSimpleShapes(TopoDS_Shape theShape, TopTools_ListOfShape &theList)
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
	  //          if (isOnlySolids)
	  //            theNewShape = GlueFaces(C, Precision::Confusion());
	  //          else
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
	  //          if (isOnlySolids)
	  //            theNewShape = GlueFaces(C, Precision::Confusion());
	  //          else
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
  
void OCC_Internals::fillet(std::vector<TopoDS_Edge> &edgesToFillet,
                           double Radius)
{
  // create a tool for fillet
  BRepFilletAPI_MakeFillet fill(shape);
  for (unsigned int i = 0; i < edgesToFillet.size(); ++i){
    fill.Add(edgesToFillet[i]);
  }
  for (int i = 1; i <= fill.NbContours(); i++){
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
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  else
    _occ_internals->writeBREP(fn.c_str());
  return 1;
}

int GModel::writeOCCSTEP(const std::string &fn)
{
  if (!_occ_internals){
    Msg::Error("No OpenCASCADE model found");
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

#else

void GModel::_deleteOCCInternals()
{
}

int GModel::readOCCBREP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to load '%s'",
             fn.c_str());
  return 0;
}

int GModel::readOCCSTEP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to load '%s'",
             fn.c_str());
  return 0;
}

int GModel::readOCCIGES(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to load '%s'",
             fn.c_str());
  return 0;
}

int GModel::writeOCCBREP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to write '%s'",
             fn.c_str());
  return 0;
}

int GModel::writeOCCSTEP(const std::string &fn)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to write '%s'",
             fn.c_str());
  return 0;
}

int GModel::importOCCShape(const void *shape)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to import "
             "a TopoDS_Shape");
  return 0;
}

#endif
