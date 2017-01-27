// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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

#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <gce_MakeCirc.hxx>
#include <gce_MakePln.hxx>
#include <ElCLib.hxx>
#include <Geom_Circle.hxx>
#include <Geom_TrimmedCurve.hxx>

void OCC_Internals::_addShapeToLists(TopoDS_Shape shape, std::vector<int> indices[4])
{
  // Solids
  TopExp_Explorer exp0, exp1, exp2, exp3, exp4, exp5;
  for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
    TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
    if(_somap.FindIndex(solid) < 1){
      _somap.Add(solid); if(indices) indices[3].push_back(_somap.Extent());
      for(exp1.Init(solid, TopAbs_SHELL); exp1.More(); exp1.Next()){
        TopoDS_Shell shell = TopoDS::Shell(exp1.Current());
        if(_shmap.FindIndex(shell) < 1){
          _shmap.Add(shell);

          for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()){
            TopoDS_Face face = TopoDS::Face(exp2.Current());
            if(_fmap.FindIndex(face) < 1){
              _fmap.Add(face);

              for(exp3.Init(exp2.Current().Oriented(TopAbs_FORWARD), TopAbs_WIRE); exp3.More(); exp3.Next()){
                TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
                if(_wmap.FindIndex(wire) < 1){
                  _wmap.Add(wire);

                  for(exp4.Init(exp3.Current(), TopAbs_EDGE); exp4.More(); exp4.Next()){
                    TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
                    if(_emap.FindIndex(edge) < 1){
                      _emap.Add(edge);

                      for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
                        TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
                        if(_vmap.FindIndex(vertex) < 1)
                          _vmap.Add(vertex);
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
  for(exp1.Init(shape, TopAbs_SHELL, TopAbs_SOLID); exp1.More(); exp1.Next()){
    TopoDS_Shape shell = exp1.Current();
    if(_shmap.FindIndex(shell) < 1){
      _shmap.Add(shell);

      for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()){
        TopoDS_Face face = TopoDS::Face(exp2.Current());
        if(_fmap.FindIndex(face) < 1){
          _fmap.Add(face);

          for(exp3.Init(exp2.Current(), TopAbs_WIRE); exp3.More(); exp3.Next()){
            TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
            if(_wmap.FindIndex(wire) < 1){
              _wmap.Add(wire);

              for(exp4.Init(exp3.Current(), TopAbs_EDGE); exp4.More(); exp4.Next()){
                TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
                if(_emap.FindIndex(edge) < 1){
                  _emap.Add(edge);

                  for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
                    TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
                    if(_vmap.FindIndex(vertex) < 1)
                      _vmap.Add(vertex);
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
    if(_fmap.FindIndex(face) < 1){
      _fmap.Add(face); if(indices) indices[2].push_back(_fmap.Extent());

      for(exp3.Init(exp2.Current(), TopAbs_WIRE); exp3.More(); exp3.Next()){
        TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
        if(_wmap.FindIndex(wire) < 1){
          _wmap.Add(wire);

          for(exp4.Init(exp3.Current(), TopAbs_EDGE); exp4.More(); exp4.Next()){
            TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
            if(_emap.FindIndex(edge) < 1){
              _emap.Add(edge);

              for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
                TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
                if(_vmap.FindIndex(vertex) < 1)
                  _vmap.Add(vertex);
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
    if(_wmap.FindIndex(wire) < 1){
      _wmap.Add(wire);

      for(exp4.Init(exp3.Current(), TopAbs_EDGE); exp4.More(); exp4.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
        if(_emap.FindIndex(edge) < 1){
          _emap.Add(edge);

          for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
            TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
            if(_vmap.FindIndex(vertex) < 1)
              _vmap.Add(vertex);
          }
        }
      }
    }
  }

  // Free Edges
  for(exp4.Init(shape, TopAbs_EDGE, TopAbs_WIRE); exp4.More(); exp4.Next()){
    TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
    if(_emap.FindIndex(edge) < 1){
      _emap.Add(edge); if(indices) indices[1].push_back(_emap.Extent());

      for(exp5.Init(exp4.Current(), TopAbs_VERTEX); exp5.More(); exp5.Next()){
        TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
        if(_vmap.FindIndex(vertex) < 1)
          _vmap.Add(vertex);
      }
    }
  }

  // Free Vertices
  for(exp5.Init(shape, TopAbs_VERTEX, TopAbs_EDGE); exp5.More(); exp5.Next()){
    TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
    if(_vmap.FindIndex(vertex) < 1){
      _vmap.Add(vertex); if(indices) indices[0].push_back(_vmap.Extent());
    }
  }
}

void OCC_Internals::addVertex(int tag, double x, double y, double z)
{
  if(_vTagIndex.count(tag)){
    Msg::Error("OCC vertex with tag %d already exists", tag);
    return;
  }
  TopoDS_Vertex result;
  try{
    gp_Pnt aPnt;
    aPnt = gp_Pnt(x, y, z);
    BRepBuilderAPI_MakeVertex mkVertex(aPnt);
    result = mkVertex.Vertex();
  }
  catch(Standard_Failure &err){
    Msg::Error("OCC %s", err.GetMessageString());
    return;
  }
  std::vector<int> indices[4];
  _addShapeToLists(result, indices);
  if(indices[0].size()){
    int index = indices[0][0];
    _vTagIndex[tag] = index;
    _vIndexTag[index] = tag;
  }
}

void OCC_Internals::addCircleArc(int tag, int tagStart, int tagCenter, int tagEnd)
{
  if(_eTagIndex.count(tag)){
    Msg::Error("OCC edge with tag %d already exists", tag);
    return;
  }

  std::map<int, int>::iterator itStart = _vTagIndex.find(tagStart);
  std::map<int, int>::iterator itCenter = _vTagIndex.find(tagCenter);
  std::map<int, int>::iterator itEnd = _vTagIndex.find(tagEnd);

  if(itStart == _vTagIndex.end()){
    Msg::Error("Unknown OCC vertex with tag %d", tagStart);
    return;
  }
  if(itCenter == _vTagIndex.end()){
    Msg::Error("Unknown OCC vertex with tag %d", tagCenter);
    return;
  }
  if(itEnd == _vTagIndex.end()){
    Msg::Error("Unknown OCC vertex with tag %d", tagEnd);
    return;
  }

  TopoDS_Edge result;
  try{
    TopoDS_Vertex start = TopoDS::Vertex(_vmap(itStart->second));
    TopoDS_Vertex center = TopoDS::Vertex(_vmap(itCenter->second));
    TopoDS_Vertex end = TopoDS::Vertex(_vmap(itEnd->second));
    gp_Pnt aP1 = BRep_Tool::Pnt(start);
    gp_Pnt aP2 = BRep_Tool::Pnt(center);
    gp_Pnt aP3 = BRep_Tool::Pnt(end);
    Standard_Real Radius = aP1.Distance(aP2);
    gce_MakeCirc MC(aP2, gce_MakePln(aP1, aP2, aP3).Value(), Radius);
    const gp_Circ &Circ = MC.Value();
    Standard_Real Alpha1 = ElCLib::Parameter(Circ, aP1);
    Standard_Real Alpha2 = ElCLib::Parameter(Circ, aP3);
    Handle(Geom_Circle) C = new Geom_Circle(Circ);
    Handle(Geom_TrimmedCurve) arc = new Geom_TrimmedCurve(C, Alpha1, Alpha2, false);
    result = BRepBuilderAPI_MakeEdge(arc, start, end).Edge();
  }
  catch(Standard_Failure &err){
    Msg::Error("OCC %s", err.GetMessageString());
    return;
  }
  std::vector<int> indices[4];
  _addShapeToLists(result, indices);
  if(indices[1].size()){
    int index = indices[1][0];
    _eTagIndex[tag] = index;
    _eIndexTag[index] = tag;
  }
}

void OCC_Internals::addSphere(int tag, double xc, double yc, double zc, double radius)
{
  if(_rTagIndex.count(tag)){
    Msg::Error("OCC region with tag %d already exists", tag);
    return;
  }

  TopoDS_Solid result;
  try{
    gp_Pnt aP(xc, yc, zc);
    result = TopoDS::Solid(BRepPrimAPI_MakeSphere(aP, radius).Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OCC %s", err.GetMessageString());
    return;
  }

  std::vector<int> indices[4];
  _addShapeToLists(result, indices);
  if(indices[3].size()){
    int index = indices[3][0];
    _rTagIndex[tag] = index;
    _rIndexTag[index] = tag;
  }
}

void OCC_Internals::addThruSections(int tag, std::vector<std::vector<int> > tagEdges)
{
  if(_rTagIndex.count(tag)){
    Msg::Error("OCC region with tag %d already exists", tag);
    return;
  }

  TopoDS_Solid result;
  try{
    BRepOffsetAPI_ThruSections aGenerator(Standard_True); // create solid
    for (unsigned i = 0; i < tagEdges.size(); i++) {
      BRepBuilderAPI_MakeWire wire_maker;
      for (unsigned j = 0; j < tagEdges[i].size(); j++) {
        std::map<int, int>::iterator it = _eTagIndex.find(tagEdges[i][j]);
        if(it == _eTagIndex.end()){
          Msg::Error("Unknown OCC edge with tag %d", tagEdges[i][j]);
          return;
        }
        TopoDS_Edge edge = TopoDS::Edge(_emap(it->second));
        wire_maker.Add(edge);
      }
      aGenerator.AddWire(wire_maker.Wire());
    }
    aGenerator.CheckCompatibility(Standard_False);
    aGenerator.Build();
    result = TopoDS::Solid(aGenerator.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OCC %s", err.GetMessageString());
    return;
  }

  std::vector<int> indices[4];
  _addShapeToLists(result, indices);
  if(indices[3].size()){
    int index = indices[3][0];
    _rTagIndex[tag] = index;
    _rIndexTag[index] = tag;
  }
}

void OCC_Internals::applyBooleanOperator(int tag,
                                         std::vector<int> shapeTags[4],
                                         std::vector<int> toolTags[4],
                                         BooleanOperator op,
                                         bool removeShape, bool removeTool)
{
  if(tag < 0){
    for(std::map<int, int>::iterator it = _rTagIndex.begin(); it != _rTagIndex.end(); it++)
      tag = std::max(it->first, tag);
    tag++;
  }

  if(_rTagIndex.count(tag)){
    Msg::Error("OCC region with tag %d already exists", tag);
    return;
  }

  if(shapeTags[3].size() == 1 && toolTags[3].size() == 1){
    TopoDS_Shape result;
    std::map<int, int>::iterator it1 = _rTagIndex.find(shapeTags[3][0]);
    if(it1 == _rTagIndex.end()){
      Msg::Error("Unknown OCC region with tag %d", shapeTags[3][0]);
      return;
    }
    std::map<int, int>::iterator it2 = _rTagIndex.find(toolTags[3][0]);
    if(it2 == _rTagIndex.end()){
      Msg::Error("Unknown OCC region with tag %d", toolTags[3][0]);
      return;
    }
    try{
      BRepAlgoAPI_Fuse BO(TopoDS::Solid(_somap(it1->second)),
                          TopoDS::Solid(_somap(it2->second)));
      if(!BO.IsDone()) {
        Msg::Error("Fuse operation can not be performed on the given shapes");
      }
      result = BO.Shape();
      if(removeShape || removeTool){
        TopTools_IndexedMapOfShape tmp;
        std::map<int, int> rIndexTag, rTagIndex;
        for(int i = 1; i <= _somap.Extent(); i++){
          if(removeShape && i == it1->second){
            continue;
          }
          if(removeTool && i == it2->second){
            continue;
          }
          else{
            int tag = _rIndexTag[i];
            tmp.Add(_somap(i));
            int index = tmp.Extent();
            rIndexTag[index] = tag;
            rTagIndex[tag] = index;
          }
        }
        _somap = tmp;
        _rTagIndex = rTagIndex;
        _rIndexTag = rIndexTag;
      }
    }
    catch(Standard_Failure &err){
      Msg::Error("OCC %s", err.GetMessageString());
      return;
    }
    std::vector<int> indices[4];
    _addShapeToLists(result, indices);
    if(indices[3].size()){
      int index = indices[3][0];
      _rTagIndex[tag] = index;
      _rIndexTag[index] = tag;
    }
  }
  else{
    Msg::Error("General boolean operation not implemented yet!");
  }

}


void addSimpleShapes(TopoDS_Shape theShape, TopTools_ListOfShape &theList);

void OCC_Internals::buildLists()
{
  _somap.Clear();
  _shmap.Clear();
  _fmap.Clear();
  _wmap.Clear();
  _emap.Clear();
  _vmap.Clear();
  _addShapeToLists(_shape);
}

void OCC_Internals::buildShapeFromGModel(GModel* gm)
{
  _somap.Clear();
  _shmap.Clear();
  _fmap.Clear();
  _wmap.Clear();
  _emap.Clear();
  _vmap.Clear();
  for (GModel::riter it = gm->firstRegion(); it != gm->lastRegion() ; ++it){
    if ((*it)->getNativeType() == GEntity::OpenCascadeModel){
      OCCRegion *occ = static_cast<OCCRegion*> (*it);
      if(occ) _addShapeToLists(occ->getTopoDS_Shape());
    }
  }
  for (GModel::fiter it = gm->firstFace(); it != gm->lastFace() ; ++it){
    if ((*it)->getNativeType() == GEntity::OpenCascadeModel){
      OCCFace *occ = static_cast<OCCFace*> (*it);
      if(occ) _addShapeToLists(occ->getTopoDS_Face());
    }
  }
  BRep_Builder B;
  TopoDS_Compound C;
  B.MakeCompound(C);
  for(int i = 1; i <= _vmap.Extent(); i++) B.Add(C, _vmap(i));
  for(int i = 1; i <= _emap.Extent(); i++) B.Add(C, _emap(i));
  for(int i = 1; i <= _wmap.Extent(); i++) B.Add(C, _wmap(i));
  for(int i = 1; i <= _fmap.Extent(); i++) B.Add(C, _fmap(i));
  for(int i = 1; i <= _shmap.Extent(); i++) B.Add(C, _shmap(i));
  for(int i = 1; i <= _somap.Extent(); i++) B.Add(C, _somap(i));
  _shape = C;
}

void OCC_Internals::buildShapeFromLists(TopoDS_Shape shape)
{
  BRep_Builder B;
  TopoDS_Compound C;
  B.MakeCompound(C);

  TopTools_ListOfShape theList;
  addSimpleShapes(shape, theList);
  TopTools_ListIteratorOfListOfShape itSub1(theList);
  for (; itSub1.More(); itSub1.Next()) B.Add(C, itSub1.Value());

  for(int i = 1; i <= _vmap.Extent(); i++) B.Add(C, _vmap(i));
  for(int i = 1; i <= _emap.Extent(); i++) B.Add(C, _emap(i));
  for(int i = 1; i <= _wmap.Extent(); i++) B.Add(C, _wmap(i));
  for(int i = 1; i <= _fmap.Extent(); i++) B.Add(C, _fmap(i));
  for(int i = 1; i <= _shmap.Extent(); i++) B.Add(C, _shmap(i));
  for(int i = 1; i <= _somap.Extent(); i++) B.Add(C, _somap(i));
  _shape = C;
}


void OCC_Internals::healGeometry(double tolerance, bool fixdegenerated,
                                 bool fixsmalledges, bool fixspotstripfaces,
                                 bool sewfaces, bool makesolids, int connect,
                                 double scaling)
{
  if(scaling != 1.0){
    Msg::Info("Scaling geometry by factor %g", scaling);
    gp_Trsf t;
    t.SetScaleFactor(scaling);
    BRepBuilderAPI_Transform trsf(_shape, t);
    _shape = trsf.Shape();
  }

  if(!fixdegenerated && !fixsmalledges && !fixspotstripfaces &&
     !sewfaces && !makesolids && !connect) return;

  Msg::Info("Starting geometry healing procedure (tolerance: %g)", tolerance);

  buildLists();
  TopExp_Explorer exp0, exp1;
  int nrc = 0, nrcs = 0;
  int nrso = _somap.Extent(), nrsh = _shmap.Extent(), nrf = _fmap.Extent();
  int nrw = _wmap.Extent(), nre = _emap.Extent(), nrv = _vmap.Extent();
  for(exp0.Init(_shape, TopAbs_COMPOUND); exp0.More(); exp0.Next()) nrc++;
  for(exp0.Init(_shape, TopAbs_COMPSOLID); exp0.More(); exp0.Next()) nrcs++;

  double surfacecont = 0;
  for(exp0.Init(_shape, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    GProp_GProps system;
    BRepGProp::SurfaceProperties(face, system);
    surfacecont += system.Mass();
  }

  if(fixdegenerated){
    Msg::Info("- fix degenerated edges and faces");

    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(_shape);
      for(exp1.Init(_shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge))
          rebuild->Remove(edge, false);
      }
      _shape = rebuild->Apply(_shape);
    }
    buildLists();

    {
      Handle(ShapeFix_Face) sff;
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(_shape);

      for(exp0.Init(_shape, TopAbs_FACE); exp0.More(); exp0.Next()){
        TopoDS_Face face = TopoDS::Face(exp0.Current());

        sff = new ShapeFix_Face(face);
        sff->FixAddNaturalBoundMode() = Standard_True;
        sff->FixSmallAreaWireMode() = Standard_True;
        sff->Perform();

        if(sff->Status(ShapeExtend_DONE1) ||
           sff->Status(ShapeExtend_DONE2) ||
           sff->Status(ShapeExtend_DONE3) ||
           sff->Status(ShapeExtend_DONE4) ||
           sff->Status(ShapeExtend_DONE5))
          {
            Msg::Info("  repaired face %d", _fmap.FindIndex(face));
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
      _shape = rebuild->Apply(_shape);
    }

    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(_shape);
      for(exp1.Init(_shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge))
          rebuild->Remove(edge, false);
      }
      _shape = rebuild->Apply(_shape);
    }
  }

  if(fixsmalledges){
    Msg::Info("- fixing small edges");

    Handle(ShapeFix_Wire) sfw;
    Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
    rebuild->Apply(_shape);

    for(exp0.Init(_shape, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());

      for(exp1.Init(face, TopAbs_WIRE); exp1.More(); exp1.Next()){
        TopoDS_Wire oldwire = TopoDS::Wire(exp1.Current());
        sfw = new ShapeFix_Wire(oldwire, face ,tolerance);
        sfw->ModifyTopologyMode() = Standard_True;

        sfw->ClosedWireMode() = Standard_True;

        bool replace = false;
        replace = sfw->FixReorder() || replace;
        replace = sfw->FixConnected() || replace;

        if(sfw->FixSmall(Standard_False, tolerance) &&
           ! (sfw->StatusSmall(ShapeExtend_FAIL1) ||
              sfw->StatusSmall(ShapeExtend_FAIL2) ||
              sfw->StatusSmall(ShapeExtend_FAIL3))){
          Msg::Info("  fixed small edge in wire %d", _wmap.FindIndex(oldwire));
          replace = true;
        }
        else if(sfw->StatusSmall(ShapeExtend_FAIL1))
          Msg::Warning("Failed to fix small edge in wire %d, edge cannot be checked "
                       "(no 3d curve and no pcurve)", _wmap.FindIndex(oldwire));
        else if(sfw->StatusSmall(ShapeExtend_FAIL2))
          Msg::Warning("Failed to fix small edge in wire %d, "
                       "edge is null-length and has different vertives at begin and "
                       "end, and lockvtx is True or ModifiyTopologyMode is False",
                       _wmap.FindIndex(oldwire));
        else if(sfw->StatusSmall(ShapeExtend_FAIL3))
          Msg::Warning("Failed to fix small edge in wire, CheckConnected has failed",
                       _wmap.FindIndex(oldwire));

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

    _shape = rebuild->Apply(_shape);

    {
      buildLists();
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(_shape);

      for(exp1.Init(_shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(_vmap.FindIndex(TopExp::FirstVertex(edge)) ==
           _vmap.FindIndex(TopExp::LastVertex(edge))){
          GProp_GProps system;
          BRepGProp::LinearProperties(edge, system);
          if(system.Mass() < tolerance){
            Msg::Info("  removing degenerated edge %d from vertex %d to vertex %d",
                      _emap.FindIndex(edge), _vmap.FindIndex(TopExp::FirstVertex(edge)),
                      _vmap.FindIndex(TopExp::LastVertex(edge)));
            rebuild->Remove(edge, false);
          }
        }
      }
      _shape = rebuild->Apply(_shape);
    }

    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(_shape);
      for(exp1.Init(_shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge) )
          rebuild->Remove(edge, false);
      }
      _shape = rebuild->Apply(_shape);
    }

    Handle(ShapeFix_Wireframe) sfwf = new ShapeFix_Wireframe;
    sfwf->SetPrecision(tolerance);
    sfwf->Load(_shape);
    sfwf->ModeDropSmallEdges() = Standard_True;

    if(sfwf->FixWireGaps()){
      Msg::Info("- fixing wire gaps");
      if(sfwf->StatusWireGaps(ShapeExtend_OK))
        Msg::Info("  no gaps found");
      if(sfwf->StatusWireGaps(ShapeExtend_DONE1))
        Msg::Info("  some 2D gaps fixed");
      if(sfwf->StatusWireGaps(ShapeExtend_DONE2))
        Msg::Info("  some 3D gaps fixed");
      if(sfwf->StatusWireGaps(ShapeExtend_FAIL1))
        Msg::Info("  failed to fix some 2D gaps");
      if(sfwf->StatusWireGaps(ShapeExtend_FAIL2))
        Msg::Info("  failed to fix some 3D gaps");
    }

    sfwf->SetPrecision(tolerance);

    if(sfwf->FixSmallEdges()){
      Msg::Info("- fixing wire frames");
      if(sfwf->StatusSmallEdges(ShapeExtend_OK))
        Msg::Info("  no small edges found");
      if(sfwf->StatusSmallEdges(ShapeExtend_DONE1))
        Msg::Info("  some small edges fixed");
      if(sfwf->StatusSmallEdges(ShapeExtend_FAIL1))
        Msg::Info("  failed to fix some small edges");
    }

    _shape = sfwf->Shape();
  }

  if(fixspotstripfaces){
    Msg::Info("- fixing spot and strip faces");
    Handle(ShapeFix_FixSmallFace) sffsm = new ShapeFix_FixSmallFace();
    sffsm->Init(_shape);
    sffsm->SetPrecision(tolerance);
    sffsm->Perform();

    _shape = sffsm->FixShape();
  }

  if(sewfaces){
    Msg::Info("- sewing faces");

    BRepOffsetAPI_Sewing sewedObj(tolerance);

    for(exp0.Init(_shape, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      sewedObj.Add(face);
    }

    sewedObj.Perform();

    if(!sewedObj.SewedShape().IsNull())
      _shape = sewedObj.SewedShape();
    else
      Msg::Info("  not possible");
  }

  {
    Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
    rebuild->Apply(_shape);
    for(exp1.Init(_shape, TopAbs_EDGE); exp1.More(); exp1.Next()){
      TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
      if(BRep_Tool::Degenerated(edge))
        rebuild->Remove(edge, false);
    }
    _shape = rebuild->Apply(_shape);
  }

  if(makesolids){
    Msg::Info("- making solids");

    BRepBuilderAPI_MakeSolid ms;
    int count = 0;
    for(exp0.Init(_shape, TopAbs_SHELL); exp0.More(); exp0.Next()){
      count++;
      ms.Add(TopoDS::Shell(exp0.Current()));
    }

    if(!count){
      Msg::Info("  not possible (no shells)");
    }
    else{
      BRepCheck_Analyzer ba(ms);
      if(ba.IsValid()){
        Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
        sfs->Init(ms);
        sfs->SetPrecision(tolerance);
        sfs->SetMaxTolerance(tolerance);
        sfs->Perform();
        _shape = sfs->Shape();

        for(exp0.Init(_shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
          TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
          TopoDS_Solid newsolid = solid;
          BRepLib::OrientClosedSolid(newsolid);
          Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
          // rebuild->Apply(_shape);
          rebuild->Replace(solid, newsolid, Standard_False);
          TopoDS_Shape newshape = rebuild->Apply(_shape, TopAbs_COMPSOLID);//, 1);
          // TopoDS_Shape newshape = rebuild->Apply(_shape);
          _shape = newshape;
        }
      }
      else
        Msg::Info("  not possible");
    }
  }

#if defined(HAVE_SALOME)
  if(connect == 2){
    Msg::Info("- cutting and connecting faces with Salome's Partition_Spliter");
    TopExp_Explorer e2;
    Partition_Spliter ps;
    for(e2.Init(_shape, TopAbs_SOLID); e2.More(); e2.Next())
      ps.AddShape(e2.Current());
    try{
      ps.Compute();
      _shape = ps.Shape();
    }
    catch(Standard_Failure &err){
      Msg::Error("OCC %s", err.GetMessageString());
    }
  }
  else
#endif
  if(connect){
    Msg::Info("- cutting and connecting faces with OCC_Connect");
    OCC_Connect connect(1);
    for(TopExp_Explorer p(_shape, TopAbs_SOLID); p.More(); p.Next())
      connect.Add(p.Current());
    connect.Connect();
    _shape = connect;
  }

  double newsurfacecont = 0;
  for(exp0.Init(_shape, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    GProp_GProps system;
    BRepGProp::SurfaceProperties(face, system);
    newsurfacecont += system.Mass();
  }

  buildLists();
  int nnrc = 0, nnrcs = 0;
  int nnrso = _somap.Extent(), nnrsh = _shmap.Extent(), nnrf = _fmap.Extent();
  int nnrw = _wmap.Extent(), nnre = _emap.Extent(), nnrv = _vmap.Extent();
  for(exp0.Init(_shape, TopAbs_COMPOUND); exp0.More(); exp0.Next()) nnrc++;
  for(exp0.Init(_shape, TopAbs_COMPSOLID); exp0.More(); exp0.Next()) nnrcs++;

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
  BRepTools::Read(_shape, (char*)fn, aBuilder);
  BRepTools::Clean(_shape);
  healGeometry(CTX::instance()->geom.tolerance,
               CTX::instance()->geom.occFixDegenerated,
               CTX::instance()->geom.occFixSmallEdges,
               CTX::instance()->geom.occFixSmallFaces,
               CTX::instance()->geom.occSewFaces,
               false,
               CTX::instance()->geom.occConnectFaces,
               CTX::instance()->geom.occScaling);
  BRepTools::Clean(_shape);
  buildLists();
}

void OCC_Internals::writeBREP(const char *fn)
{
  std::ofstream myFile;
  myFile.open(fn);
  try {
    BRepTools::Write(_shape, myFile);
  }
  catch(Standard_Failure &err){
    Msg::Error("OCC %s", err.GetMessageString());
  }
  myFile.close();
}

void OCC_Internals::loadSTEP(const char *fn)
{
  STEPControl_Reader reader;
  reader.ReadFile((char*)fn);
  reader.NbRootsForTransfer();
  reader.TransferRoots();
  _shape = reader.OneShape();
  BRepTools::Clean(_shape);
  healGeometry(CTX::instance()->geom.tolerance,
               CTX::instance()->geom.occFixDegenerated,
               CTX::instance()->geom.occFixSmallEdges,
               CTX::instance()->geom.occFixSmallFaces,
               CTX::instance()->geom.occSewFaces,
               false,
               CTX::instance()->geom.occConnectFaces,
               CTX::instance()->geom.occScaling);
  BRepTools::Clean(_shape);
  buildLists();
}

void OCC_Internals::writeSTEP(const char *fn)
{
  STEPControl_Writer writer;
  IFSelect_ReturnStatus status = writer.Transfer(_shape, STEPControl_ManifoldSolidBrep);
  if(status == IFSelect_RetDone)
    status = writer.Write((char*)fn);
}

void OCC_Internals::loadIGES(const char *fn)
{
  IGESControl_Reader reader;
  reader.ReadFile((char*)fn);
  reader.NbRootsForTransfer();
  reader.TransferRoots();
  _shape = reader.OneShape();
  BRepTools::Clean(_shape);
  healGeometry(CTX::instance()->geom.tolerance,
               CTX::instance()->geom.occFixDegenerated,
               CTX::instance()->geom.occFixSmallEdges,
               CTX::instance()->geom.occFixSmallFaces,
               CTX::instance()->geom.occSewFaces,
               false,
               CTX::instance()->geom.occConnectFaces,
               CTX::instance()->geom.occScaling);
  BRepTools::Clean(_shape);
  buildLists();
}

void OCC_Internals::loadShape(const TopoDS_Shape *s)
{
  _shape = *s;
  BRepTools::Clean(_shape);
  buildLists();
}

GVertex *OCC_Internals::getOCCVertexByNativePtr(GModel *model, TopoDS_Vertex toFind)
{
  if(_gvNumCache.IsBound(toFind))
    return model->getVertexByTag(_gvNumCache.Find(toFind));
  return 0;
}

GEdge *OCC_Internals::getOCCEdgeByNativePtr(GModel *model, TopoDS_Edge toFind)
{
  if(_geNumCache.IsBound(toFind))
    return model->getEdgeByTag(_geNumCache.Find(toFind));
  return 0;
}

GFace *OCC_Internals::getOCCFaceByNativePtr(GModel *model, TopoDS_Face toFind)
{
  if(_gfNumCache.IsBound(toFind))
    return model->getFaceByTag(_gfNumCache.Find(toFind));
  return 0;
}

GRegion *OCC_Internals::getOCCRegionByNativePtr(GModel *model, TopoDS_Solid toFind)
{
  if(_grNumCache.IsBound(toFind))
    return model->getRegionByTag(_grNumCache.Find(toFind));
  return 0;
}

GVertex *OCC_Internals::addVertexToModel(GModel *model, TopoDS_Vertex vertex)
{
  GVertex *gv = getOCCVertexByNativePtr(model, vertex);
  if(gv) return gv;
  _addShapeToLists(vertex);
  buildShapeFromLists(vertex);
  buildGModel(model);
  return getOCCVertexByNativePtr(model, vertex);
}

GEdge *OCC_Internals::addEdgeToModel(GModel *model, TopoDS_Edge edge)
{
  GEdge *ge = getOCCEdgeByNativePtr(model, edge);
  if(ge) return ge;
  _addShapeToLists(edge);
  buildShapeFromLists(edge);
  buildGModel(model);
  return getOCCEdgeByNativePtr(model, edge);
}

GFace* OCC_Internals::addFaceToModel(GModel *model, TopoDS_Face face)
{
  GFace *gf = getOCCFaceByNativePtr(model, face);
  if(gf) return gf;
  _addShapeToLists(face);
  buildShapeFromLists(face);
  buildGModel(model);
  return getOCCFaceByNativePtr(model, face);
}

GRegion* OCC_Internals::addRegionToModel(GModel *model, TopoDS_Solid region)
{
  GRegion *gr = getOCCRegionByNativePtr(model, region);
  if(gr) return gr;

  // FIXME THE PREVIOUS IMPLEMENTATION WAS BETTER FOR SOME USERS :-)
  buildShapeFromLists(region);
  model->destroy();
  buildLists();
  buildGModel(model);
  return getOCCRegionByNativePtr(model, region);

  //  _addShapeToLists(region);
  //  buildShapeFromLists(region);
  //  buildGModel(model);
  //  return getOCCRegionByNativePtr(model, region);
}

void OCC_Internals::buildGModel(GModel *model)
{
  // building geom vertices
  int numv = model->getMaxElementaryNumber(0) + 1;
  for(int i = 1; i <= _vmap.Extent(); i++){
    TopoDS_Vertex vertex = TopoDS::Vertex(_vmap(i));
    if(!getOCCVertexByNativePtr(model, vertex)){
      model->add(new OCCVertex(model, numv, vertex));
      numv++;
    }
  }

  // building geom edges
  int nume = model->getMaxElementaryNumber(1) + 1;
  for(int i = 1; i <= _emap.Extent(); i++){
    int i1 = _vmap.FindIndex(TopExp::FirstVertex(TopoDS::Edge(_emap(i))));
    int i2 = _vmap.FindIndex(TopExp::LastVertex(TopoDS::Edge(_emap(i))));
    if(!getOCCEdgeByNativePtr(model, TopoDS::Edge(_emap(i)))){
      GVertex *v1 = getOCCVertexByNativePtr(model, TopoDS::Vertex(_vmap(i1)));
      GVertex *v2 = getOCCVertexByNativePtr(model, TopoDS::Vertex(_vmap(i2)));
      model->add(new OCCEdge(model, TopoDS::Edge(_emap(i)), nume, v1, v2));
      nume++;
    }
  }

  // building geom faces
  int numf = model->getMaxElementaryNumber(2) + 1;
  for(int i = 1; i <= _fmap.Extent(); i++){
    if(!getOCCFaceByNativePtr(model, TopoDS::Face(_fmap(i)))){
      model->add(new OCCFace(model, TopoDS::Face(_fmap(i)), numf));
      numf++;
    }
  }

  // building geom regions
  int numr = model->getMaxElementaryNumber(3) + 1;
  for(int i = 1; i <= _somap.Extent(); i++){
    if(!getOCCRegionByNativePtr(model, TopoDS::Solid(_somap(i)))){
      model->add(new OCCRegion(model, TopoDS::Solid(_somap(i)), numr));
      numr++;
    }
  }
}

int GModel::importOCCInternals()
{
  _occ_internals->importOCCInternals(this);
  return 1;
}

void OCC_Internals::importOCCInternals(GModel *model)
{
  int vTagMax = model->getMaxElementaryNumber(0);
  for(std::map<int, int>::iterator it = _vTagIndex.begin(); it != _vTagIndex.end(); it++)
    vTagMax = std::max(it->first, vTagMax);
  int eTagMax = model->getMaxElementaryNumber(1);
  for(std::map<int, int>::iterator it = _eTagIndex.begin(); it != _eTagIndex.end(); it++)
    eTagMax = std::max(it->first, eTagMax);
  int fTagMax = model->getMaxElementaryNumber(2);
  for(std::map<int, int>::iterator it = _fTagIndex.begin(); it != _fTagIndex.end(); it++)
    fTagMax = std::max(it->first, fTagMax);
  int rTagMax = model->getMaxElementaryNumber(3);
  for(std::map<int, int>::iterator it = _rTagIndex.begin(); it != _rTagIndex.end(); it++)
    rTagMax = std::max(it->first, rTagMax);

  // this imports all OCC entities stored in _vmap, _emap, _fmap and _somap, by
  // preserving any explicit entity tag specified in the TagIndex/IndexTag maps.

  for(int i = 1; i <= _vmap.Extent(); i++){
    TopoDS_Vertex vertex = TopoDS::Vertex(_vmap(i));
    if(!getOCCVertexByNativePtr(model, vertex)){
      int tag;
      std::map<int, int>::iterator it = _vIndexTag.find(i);
      if(it == _vIndexTag.end()){
        tag = vTagMax + 1;
        vTagMax++;
      }
      else
        tag = it->second;
      model->add(new OCCVertex(model, tag, vertex));
    }
  }

  // building geom edges
  for(int i = 1; i <= _emap.Extent(); i++){
    TopoDS_Edge edge = TopoDS::Edge(_emap(i));
    int i1 = _vmap.FindIndex(TopExp::FirstVertex(edge));
    int i2 = _vmap.FindIndex(TopExp::LastVertex(edge));
    if(!getOCCEdgeByNativePtr(model, edge)){
      GVertex *v1 = getOCCVertexByNativePtr(model, TopoDS::Vertex(_vmap(i1)));
      GVertex *v2 = getOCCVertexByNativePtr(model, TopoDS::Vertex(_vmap(i2)));
      int tag;
      std::map<int, int>::iterator it = _eIndexTag.find(i);
      if(it == _eIndexTag.end()){
        tag = eTagMax + 1;
        eTagMax++;
      }
      else
        tag = it->second;
      model->add(new OCCEdge(model, edge, tag, v1, v2));
    }
  }

  // building geom faces
  for(int i = 1; i <= _fmap.Extent(); i++){
    TopoDS_Face face = TopoDS::Face(_fmap(i));
    if(!getOCCFaceByNativePtr(model, face)){
      int tag;
      std::map<int, int>::iterator it = _fIndexTag.find(i);
      if(it == _fIndexTag.end()){
        tag = fTagMax + 1;
        fTagMax++;
      }
      else
        tag = it->second;
      model->add(new OCCFace(model, face, tag));
    }
  }

  // building geom regions
  for(int i = 1; i <= _somap.Extent(); i++){
    TopoDS_Solid region = TopoDS::Solid(_somap(i));
    if(!getOCCRegionByNativePtr(model, region)){
      int tag;
      std::map<int, int>::iterator it = _rIndexTag.find(i);
      if(it == _rIndexTag.end()){
        tag = rTagMax + 1;
        rTagMax++;
      }
      else
        tag = it->second;
      model->add(new OCCRegion(model, region, tag));
    }
  }
}

void addSimpleShapes(TopoDS_Shape theShape, TopTools_ListOfShape &theList)
{
  if(theShape.ShapeType() != TopAbs_COMPOUND &&
     theShape.ShapeType() != TopAbs_COMPSOLID) {
    theList.Append(theShape);
    return;
  }

  TopTools_MapOfShape mapShape;
  TopoDS_Iterator It(theShape, Standard_True, Standard_True);

  for(; It.More(); It.Next()) {
    TopoDS_Shape aShape_i = It.Value();
    if(mapShape.Add(aShape_i)) {
      if(aShape_i.ShapeType() == TopAbs_COMPOUND ||
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
  if(tool.IsNull()) return;
  if(_shape.IsNull()){
    _shape = tool;
    return;
  }

  switch(op){
  case OCC_Internals::Intersection :
    {
      TopoDS_Shape theNewShape;
      BRep_Builder B;
      TopoDS_Compound C;
      B.MakeCompound(C);
      TopTools_ListOfShape listShape1, listShape2;
      addSimpleShapes(_shape, listShape1);
      addSimpleShapes(tool, listShape2);
      Standard_Boolean isCompound =
        (listShape1.Extent() > 1 || listShape2.Extent() > 1);

      TopTools_ListIteratorOfListOfShape itSub1(listShape1);
      for(; itSub1.More(); itSub1.Next()) {
        TopoDS_Shape aValue1 = itSub1.Value();
        TopTools_ListIteratorOfListOfShape itSub2(listShape2);
        for(; itSub2.More(); itSub2.Next()) {
          TopoDS_Shape aValue2 = itSub2.Value();
          BRepAlgoAPI_Common BO(aValue1, aValue2);
          if(!BO.IsDone()) {
            Msg::Error("Boolean Intersection Operator can not be performed");
          }
          if(isCompound) {
            TopoDS_Shape aStepResult = BO.Shape();
            if(aStepResult.ShapeType() == TopAbs_COMPOUND) {
              TopoDS_Iterator aCompIter(aStepResult);
              for(; aCompIter.More(); aCompIter.Next()) {
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
      if(isCompound) {
        TopTools_ListOfShape listShapeC;
        addSimpleShapes(C, listShapeC);
        TopTools_ListIteratorOfListOfShape itSubC(listShapeC);
        //bool isOnlySolids = true;
        for(; itSubC.More(); itSubC.Next()) {
          TopoDS_Shape aValueC = itSubC.Value();
          //if(aValueC.ShapeType() != TopAbs_SOLID) isOnlySolids = false;
        }
        // if(isOnlySolids)
        //   theNewShape = GlueFaces(C, Precision::Confusion());
        // else
        theNewShape = C;
      }
      _shape = theNewShape;
    }
    break;
  case OCC_Internals::Cut :
    {
      TopoDS_Shape theNewShape;
      BRep_Builder B;
      TopoDS_Compound C;
      B.MakeCompound(C);

      TopTools_ListOfShape listShapes, listTools;
      addSimpleShapes(_shape, listShapes);
      addSimpleShapes(tool, listTools);

      Standard_Boolean isCompound = (listShapes.Extent() > 1);

      TopTools_ListIteratorOfListOfShape itSub1(listShapes);
      for(; itSub1.More(); itSub1.Next()) {
        TopoDS_Shape aCut = itSub1.Value();
        // tools
        TopTools_ListIteratorOfListOfShape itSub2(listTools);
        for(; itSub2.More(); itSub2.Next()) {
          TopoDS_Shape aTool = itSub2.Value();
          BRepAlgoAPI_Cut BO(aCut, aTool);
          if(!BO.IsDone()) {
            Msg::Error("Cut operation can not be performed on the given shapes");
            return;
          }
          aCut = BO.Shape();
        }
        if(isCompound) {
          if(aCut.ShapeType() == TopAbs_COMPOUND) {
            TopoDS_Iterator aCompIter(aCut);
            for(; aCompIter.More(); aCompIter.Next()) {
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

      if(isCompound) {
        TopTools_ListOfShape listShapeC;
        addSimpleShapes(C, listShapeC);
        TopTools_ListIteratorOfListOfShape itSubC(listShapeC);
        //bool isOnlySolids = true;
        for(; itSubC.More(); itSubC.Next()) {
          TopoDS_Shape aValueC = itSubC.Value();
          //if(aValueC.ShapeType() != TopAbs_SOLID) isOnlySolids = false;
        }
        // if(isOnlySolids)
        //   theNewShape = GlueFaces(C, Precision::Confusion());
        // else
        theNewShape = C;
      }
      _shape = theNewShape;
    }
    break;
  case OCC_Internals::Fuse :
    {
      TopoDS_Solid solid1, solid2;
      int hack = 0;
      if(_shape.ShapeType() != TopAbs_SOLID && tool.ShapeType() != TopAbs_SOLID){
        TopExp_Explorer exp0;
        for(exp0.Init(_shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
          solid1 = TopoDS::Solid(exp0.Current());
          hack++;
          break;
        }
        for(exp0.Init(tool, TopAbs_SOLID); exp0.More(); exp0.Next()){
          solid2 = TopoDS::Solid(exp0.Current());
          hack++;
          break;
        }
      }
      if(hack == 2){ // FIXME: just a temp hack!
        Msg::Info("Temporary hack in Fuse :-)");
        BRepAlgoAPI_Fuse BO(solid1, solid2);
        if(!BO.IsDone()) {
          Msg::Error("Fuse operation can not be performed on the given shapes");
        }
        _shape = BO.Shape();
      }
      else{
        BRepAlgoAPI_Fuse BO(tool, _shape);
        if(!BO.IsDone()) {
          Msg::Error("Fuse operation can not be performed on the given shapes");
        }
        _shape = BO.Shape();
      }
    }
    break;
  case OCC_Internals::Section :
    {
      TopoDS_Shape theNewShape;
      BRep_Builder B;
      TopoDS_Compound C;
      B.MakeCompound(C);

      TopTools_ListOfShape listShapes, listTools;
      addSimpleShapes(_shape, listShapes);
      addSimpleShapes(tool, listTools);

      Standard_Boolean isCompound = (listShapes.Extent() > 1);
      TopTools_ListIteratorOfListOfShape itSub1(listShapes);
      for(; itSub1.More(); itSub1.Next()) {
        TopoDS_Shape aValue1 = itSub1.Value();
        TopTools_ListIteratorOfListOfShape itSub2(listTools);
        for(; itSub2.More(); itSub2.Next()) {
          TopoDS_Shape aValue2 = itSub2.Value();
          BRepAlgoAPI_Section BO(aValue1, aValue2, Standard_False);
          BO.Approximation(Standard_True);
          BO.Build();
          if(!BO.IsDone()) {
            Msg::Error("Section operation can not be performed on the given shapes");
            return;
          }
          if(isCompound) {
            TopoDS_Shape aStepResult = BO.Shape();
            if(aStepResult.ShapeType() == TopAbs_COMPOUND) {
              TopoDS_Iterator aCompIter(aStepResult);
              for(; aCompIter.More(); aCompIter.Next()) {
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
      if(isCompound)
        theNewShape = C;
      _shape = theNewShape;
    }
    break;
  default :
    Msg::Error("Requested boolean operation not implemented");
    break;
  }
}

void OCC_Internals::fillet(std::vector<TopoDS_Edge> &edgesToFillet,
                           double Radius)
{
  // create a tool for fillet
  BRepFilletAPI_MakeFillet fill(_shape);
  for(unsigned int i = 0; i < edgesToFillet.size(); ++i){
    fill.Add(edgesToFillet[i]);
  }
  for(int i = 1; i <= fill.NbContours(); i++){
    fill.SetRadius(Radius, i, 1);
  }
  fill.Build();
  if(!fill.IsDone()) {
    Msg::Error("Fillet can't be computed on the given shape with the given radius");
    return;
  }
  _shape = fill.Shape();

  if(_shape.IsNull()) return;

  // Check shape validity
  BRepCheck_Analyzer ana(_shape, false);
  if(!ana.IsValid()) {
    Msg::Error("Fillet algorithm have produced an invalid shape result");
  }
}

void GModel::_createOCCInternals()
{
  if(_occ_internals) delete _occ_internals;
  _occ_internals = new OCC_Internals;
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
  //snapVertices();
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
  if(!_occ_internals){
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  else{
    _occ_internals->buildShapeFromGModel(this);
    _occ_internals->writeBREP(fn.c_str());
  }
  return 1;
}

int GModel::writeOCCSTEP(const std::string &fn)
{
  if(!_occ_internals){
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  else{
    _occ_internals->buildShapeFromGModel(this);
    _occ_internals->writeSTEP(fn.c_str());
  }
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

GVertex* GModel::getVertexForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
  return _occ_internals->getOCCVertexByNativePtr(this, *(TopoDS_Vertex*)shape);
}

GEdge* GModel::getEdgeForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
  return _occ_internals->getOCCEdgeByNativePtr(this, *(TopoDS_Edge*)shape);
}

GFace* GModel::getFaceForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
  return _occ_internals->getOCCFaceByNativePtr(this, *(TopoDS_Face*)shape);
}

GRegion* GModel::getRegionForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
  return _occ_internals->getOCCRegionByNativePtr(this, *(TopoDS_Solid*)shape);
}

#else

void GModel::_createOCCInternals()
{
}

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

GVertex* GModel::getVertexForOCCShape(const void *shape)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to query OCC shape");
  return 0;
}

GEdge* GModel::getEdgeForOCCShape(const void *shape)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to query OCC shape");
  return 0;
}

GFace* GModel::getFaceForOCCShape(const void *shape)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to query OCC shape");
  return 0;
}

GRegion* GModel::getRegionForOCCShape(const void *shape)
{
  Msg::Error("Gmsh must be compiled with Open CASCADE support to query OCC shape");
  return 0;
}

int GModel::importOCCInternals(){
	Msg::Error("Gmsh must be compiled with Open CASCADE support to query OCC shape");
  return 0;
}

#endif
