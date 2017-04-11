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
#include "StringUtils.h"
#include "ExtrudeParams.h"

#if defined(HAVE_OCC)

#include <Bnd_Box.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Section.hxx>
#include <BRepBndLib.hxx>
#include <BRepBuilderAPI_Copy.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_GTransform.hxx>
#include <BRepCheck_Analyzer.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepGProp.hxx>
#include <BRepLib.hxx>
#include <BRepMesh_FastDiscret.hxx>
#include <BRepOffsetAPI_MakeFilling.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepOffsetAPI_Sewing.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakeWedge.hxx>
#include <BRepTools.hxx>
#include <BRep_Tool.hxx>
#include <ElCLib.hxx>
#include <GProp_GProps.hxx>
#include <GeomAPI_PointsToBSpline.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_Surface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <IGESControl_Reader.hxx>
#include <IGESControl_Writer.hxx>
#include <Poly_Triangulation.hxx>
#include <Poly_Triangle.hxx>
#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeFix_FixSmallFace.hxx>
#include <ShapeFix_Shape.hxx>
#include <ShapeFix_Wireframe.hxx>
#include <Standard_Version.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools_DataMapIteratorOfDataMapOfIntegerShape.hxx>
#include <TopTools_DataMapIteratorOfDataMapOfShapeInteger.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopoDS.hxx>
#include <gce_MakeCirc.hxx>
#include <gce_MakeElips.hxx>
#include <gce_MakePln.hxx>

#if OCC_VERSION_HEX < 0x060900
#error "Gmsh requires OpenCASCADE >= 6.9"
#endif

OCC_Internals::OCC_Internals()
{
  for(int i = 0; i < 6; i++) _maxTag[i] = 0;
  _changed = true;
}

void OCC_Internals::reset()
{
  for(int i = 0; i < 6; i++) _maxTag[i] = 0;
  _meshAttr.Clear();
  _somap.Clear(); _shmap.Clear(); _fmap.Clear(); _wmap.Clear(); _emap.Clear();
  _vmap.Clear();
  _vertexTag.Clear(); _edgeTag.Clear(); _faceTag.Clear(); _solidTag.Clear();
  _tagVertex.Clear(); _tagEdge.Clear(); _tagFace.Clear(); _tagSolid.Clear();
  _wireTag.Clear(); _shellTag.Clear();
  _tagWire.Clear(); _tagShell.Clear();
  _changed = true;
}

void OCC_Internals::setMaxTag(int dim, int val)
{
  if(dim < -2 || dim > 3) return;
  _maxTag[dim + 2] = val;
}

int OCC_Internals::getMaxTag(int dim) const
{
  if(dim < -2 || dim > 3) return 0;
  return _maxTag[dim + 2];
}

void OCC_Internals::_recomputeMaxTag(int dim)
{
  if(dim < -2 || dim > 3) return;
  _maxTag[dim + 2] = 0;
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp;
  switch(dim){
  case 0: exp.Initialize(_tagVertex); break;
  case 1: exp.Initialize(_tagEdge); break;
  case 2: exp.Initialize(_tagFace); break;
  case 3: exp.Initialize(_tagSolid); break;
  case -1: exp.Initialize(_tagWire); break;
  case -2: exp.Initialize(_tagShell); break;
  }
  for(; exp.More(); exp.Next())
    _maxTag[dim + 2] = std::max(_maxTag[dim + 2], exp.Key());
}

void OCC_Internals::bind(TopoDS_Vertex vertex, int tag, bool recursive)
{
  if(_vertexTag.IsBound(vertex) && _vertexTag.Find(vertex) != tag){
    Msg::Debug("OpenCASCADE vertex %d is already bound to another tag", tag);
  }
  else{
    _vertexTag.Bind(vertex, tag);
    _tagVertex.Bind(tag, vertex);
    setMaxTag(0, tag);
    _changed = true;
  }
}

void OCC_Internals::bind(TopoDS_Edge edge, int tag, bool recursive)
{
  if(_edgeTag.IsBound(edge) && _edgeTag.Find(edge) != tag){
    Msg::Debug("OpenCASCADE edge %d is already bound to another tag", tag);
  }
  else{
    _edgeTag.Bind(edge, tag);
    _tagEdge.Bind(tag, edge);
    setMaxTag(1, tag);
    _changed = true;
  }
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(edge, TopAbs_VERTEX); exp0.More(); exp0.Next()){
      TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
      if(!_vertexTag.IsBound(vertex)){
        int t = getMaxTag(0) + 1;
        bind(vertex, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(TopoDS_Wire wire, int tag, bool recursive)
{
  if(_wireTag.IsBound(wire) && _wireTag.Find(wire) != tag){
    Msg::Debug("OpenCASCADE wire %d is already bound to anthor tag", tag);
  }
  else{
    _wireTag.Bind(wire, tag);
    _tagWire.Bind(tag, wire);
    setMaxTag(-1, tag);
    _changed = true;
  }
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(wire, TopAbs_EDGE); exp0.More(); exp0.Next()){
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(!_edgeTag.IsBound(edge)){
        int t = getMaxTag(1) + 1;
        bind(edge, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(TopoDS_Face face, int tag, bool recursive)
{
  if(_faceTag.IsBound(face) && _faceTag.Find(face) != tag){
    Msg::Debug("OpenCASCADE face %d is already bound to another tag", tag);
  }
  else{
    _faceTag.Bind(face, tag);
    _tagFace.Bind(tag, face);
    setMaxTag(2, tag);
    _changed = true;
  }
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(face, TopAbs_WIRE); exp0.More(); exp0.Next()){
      TopoDS_Wire wire = TopoDS::Wire(exp0.Current());
      if(!_wireTag.IsBound(wire)){
        int t = getMaxTag(-1) + 1;
        bind(wire, t, recursive);
      }
    }
    for(exp0.Init(face, TopAbs_EDGE); exp0.More(); exp0.Next()){
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(!_edgeTag.IsBound(edge)){
        int t = getMaxTag(1) + 1;
        bind(edge, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(TopoDS_Shell shell, int tag, bool recursive)
{
  if(_shellTag.IsBound(shell) && _shellTag.Find(shell) != tag){
    Msg::Debug("OpenCASCADE shell %d is already bound to another tag", tag);
  }
  else{
    _shellTag.Bind(shell, tag);
    _tagShell.Bind(tag, shell);
    setMaxTag(-2, tag);
    _changed = true;
  }
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(shell, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(!_faceTag.IsBound(face)){
        int t = getMaxTag(2) + 1;
        bind(face, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(TopoDS_Solid solid, int tag, bool recursive)
{
  if(_solidTag.IsBound(solid) && _solidTag.Find(solid) != tag){
    Msg::Debug("OpenCASCADE solid %d is already bound to another tag", tag);
  }
  else{
    _solidTag.Bind(solid, tag);
    _tagSolid.Bind(tag, solid);
    setMaxTag(3, tag);
    _changed = true;
  }
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(solid, TopAbs_SHELL); exp0.More(); exp0.Next()){
      TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
      if(!_shellTag.IsBound(shell)){
        int t = getMaxTag(-2) + 1;
        bind(shell, t, recursive);
      }
    }
    for(exp0.Init(solid, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(!_faceTag.IsBound(face)){
        int t = getMaxTag(3) + 1;
        bind(face, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(TopoDS_Shape shape, int dim, int tag, bool recursive)
{
  switch(dim){
  case 0: bind(TopoDS::Vertex(shape), tag, recursive); break;
  case 1: bind(TopoDS::Edge(shape), tag, recursive); break;
  case 2: bind(TopoDS::Face(shape), tag, recursive); break;
  case 3: bind(TopoDS::Solid(shape), tag, recursive); break;
  case -1: bind(TopoDS::Wire(shape), tag, recursive); break;
  case -2: bind(TopoDS::Shell(shape), tag, recursive); break;
  default: break;
  }
}

void OCC_Internals::unbind(TopoDS_Vertex vertex, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagEdge);
  for(; exp0.More(); exp0.Next()){
    TopoDS_Edge edge = TopoDS::Edge(exp0.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(edge, TopAbs_VERTEX); exp1.More(); exp1.Next()){
      if(exp1.Current().IsEqual(vertex)) return;
    }
  }
  _vertexTag.UnBind(vertex);
  _tagVertex.UnBind(tag);
  _toRemove.insert(std::pair<int, int>(0, tag));
  _recomputeMaxTag(0);
  _changed = true;
}

void OCC_Internals::unbind(TopoDS_Edge edge, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp2(_tagFace);
  for(; exp2.More(); exp2.Next()){
    TopoDS_Face face = TopoDS::Face(exp2.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(face, TopAbs_EDGE); exp1.More(); exp1.Next()){
      if(exp1.Current().IsEqual(edge)) return;
    }
  }
  _edgeTag.UnBind(edge);
  _tagEdge.UnBind(tag);
  _toRemove.insert(std::pair<int, int>(1, tag));
  _recomputeMaxTag(1);
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(edge, TopAbs_VERTEX); exp0.More(); exp0.Next()){
      TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
      if(_vertexTag.IsBound(vertex)){
        int t = _vertexTag.Find(vertex);
        unbind(vertex, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(TopoDS_Wire wire, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagFace);
  for(; exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(face, TopAbs_WIRE); exp1.More(); exp1.Next()){
      if(exp1.Current().IsEqual(wire)) return;
    }
  }
  _wireTag.UnBind(wire);
  _tagWire.UnBind(tag);
  _toRemove.insert(std::pair<int, int>(-1, tag));
  _recomputeMaxTag(-1);
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(wire, TopAbs_EDGE); exp0.More(); exp0.Next()){
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(_edgeTag.IsBound(edge)){
        int t = _edgeTag.Find(edge);
        unbind(edge, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(TopoDS_Face face, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp2(_tagSolid);
  for(; exp2.More(); exp2.Next()){
    TopoDS_Solid solid = TopoDS::Solid(exp2.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(solid, TopAbs_FACE); exp1.More(); exp1.Next()){
      if(exp1.Current().IsEqual(face)) return;
    }
  }
  _faceTag.UnBind(face);
  _tagFace.UnBind(tag);
  _toRemove.insert(std::pair<int, int>(2, tag));
  _recomputeMaxTag(2);
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(face, TopAbs_WIRE); exp0.More(); exp0.Next()){
      TopoDS_Wire wire = TopoDS::Wire(exp0.Current());
      if(_wireTag.IsBound(wire)){
        int t = _wireTag.Find(wire);
        unbind(wire, t, recursive);
      }
    }
    for(exp0.Init(face, TopAbs_EDGE); exp0.More(); exp0.Next()){
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(_edgeTag.IsBound(edge)){
        int t = _edgeTag.Find(edge);
        unbind(edge, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(TopoDS_Shell shell, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagSolid);
  for(; exp0.More(); exp0.Next()){
    TopoDS_Solid solid = TopoDS::Solid(exp0.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(solid, TopAbs_SHELL); exp1.More(); exp1.Next()){
      if(exp1.Current().IsEqual(shell)) return;
    }
  }
  _shellTag.UnBind(shell);
  _tagShell.UnBind(tag);
  _toRemove.insert(std::pair<int, int>(-2, tag));
  _recomputeMaxTag(-2);
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(shell, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(_faceTag.IsBound(face)){
        int t = _faceTag.Find(face);
        unbind(face, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(TopoDS_Solid solid, int tag, bool recursive)
{
  _solidTag.UnBind(solid);
  _tagSolid.UnBind(tag);
  _toRemove.insert(std::pair<int, int>(3, tag));
  _recomputeMaxTag(3);
  if(recursive){
    TopExp_Explorer exp0;
    for(exp0.Init(solid, TopAbs_SHELL); exp0.More(); exp0.Next()){
      TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
      if(_shellTag.IsBound(shell)){
        int t = _shellTag.Find(shell);
        unbind(shell, t, recursive);
      }
    }
    for(exp0.Init(solid, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(_faceTag.IsBound(face)){
        int t = _faceTag.Find(face);
        unbind(face, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(TopoDS_Shape shape, int dim, int tag, bool recursive)
{
  switch(dim){
  case 0: unbind(TopoDS::Vertex(shape), tag, recursive); break;
  case 1: unbind(TopoDS::Edge(shape), tag, recursive); break;
  case 2: unbind(TopoDS::Face(shape), tag, recursive); break;
  case 3: unbind(TopoDS::Solid(shape), tag, recursive); break;
  case -1: unbind(TopoDS::Wire(shape), tag, recursive); break;
  case -2: unbind(TopoDS::Shell(shape), tag, recursive); break;
  default: break;
  }
}

void OCC_Internals::bind(TopoDS_Shape shape, int tag,
                         std::vector<std::pair<int, int> > &outDimTags,
                         bool returnHighestDimOnly, bool recursive,
                         bool returnNewOnly)
{
  TopExp_Explorer exp0;
  int count = 0;
  for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
    TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
    bool exists = false;
    int t = tag;
    if(t <= 0){
      if(_solidTag.IsBound(solid)){
        t = _solidTag.Find(solid);
        exists = true;
      }
      else
        t = getMaxTag(3) + 1;
    }
    else if(count){
      Msg::Error("Cannot bind multiple regions to single tag %d", t);
      return;
    }
    if(!exists)
      bind(solid, t, recursive);
    if(!exists || !returnNewOnly)
      outDimTags.push_back(std::pair<int, int>(3, t));
    count++;
  }
  if(returnHighestDimOnly && count) return;
  for(exp0.Init(shape, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    bool exists = false;
    int t = tag;
    if(t <= 0){
      if(_faceTag.IsBound(face)){
        t = _faceTag.Find(face);
        exists = true;
      }
      else
        t = getMaxTag(2) + 1;
    }
    else if(count){
      Msg::Error("Cannot bind multiple faces to single tag %d", t);
      return;
    }
    if(!exists)
      bind(face, t, recursive);
    if(!exists || !returnNewOnly)
      outDimTags.push_back(std::pair<int, int>(2, t));
    count++;
  }
  if(returnHighestDimOnly && count) return;
  for(exp0.Init(shape, TopAbs_EDGE); exp0.More(); exp0.Next()){
    TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
    bool exists = false;
    int t = tag;
    if(t <= 0){
      if(_edgeTag.IsBound(edge)){
        t = _edgeTag.Find(edge);
        exists = true;
      }
      else
        t = getMaxTag(1) + 1;
    }
    else if(count){
      Msg::Error("Cannot bind multiple edges to single tag %d", t);
      return;
    }
    if(!exists)
      bind(edge, t, recursive);
    if(!exists || !returnNewOnly)
      outDimTags.push_back(std::pair<int, int>(1, t));
    count++;
  }
  if(returnHighestDimOnly && count) return;
  for(exp0.Init(shape, TopAbs_VERTEX); exp0.More(); exp0.Next()){
    TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
    bool exists = false;
    int t = tag;
    if(t <= 0){
      if(_vertexTag.IsBound(vertex)){
        t = _vertexTag.Find(vertex);
        exists = false;
      }
      t = getMaxTag(0) + 1;
    }
    else if(count){
      Msg::Error("Cannot bind multiple vertices to single tag %d", t);
      return;
    }
    if(!exists)
      bind(vertex, t, recursive);
    if(!exists || !returnNewOnly)
      outDimTags.push_back(std::pair<int, int>(0, t));
    count++;
  }
}

bool OCC_Internals::isBound(int dim, int tag)
{
  switch(dim){
  case 0 : return _tagVertex.IsBound(tag);
  case 1 : return _tagEdge.IsBound(tag);
  case 2 : return _tagFace.IsBound(tag);
  case 3 : return _tagSolid.IsBound(tag);
  case -1 : return _tagWire.IsBound(tag);
  case -2 : return _tagShell.IsBound(tag);
  default: return false;
  }
}

TopoDS_Shape OCC_Internals::find(int dim, int tag)
{
  switch(dim){
  case 0: return _tagVertex.Find(tag);
  case 1: return _tagEdge.Find(tag);
  case 2: return _tagFace.Find(tag);
  case 3: return _tagSolid.Find(tag);
  case -1: return _tagWire.Find(tag);
  case -2: return _tagShell.Find(tag);
  default: return TopoDS_Shape();
  }
}

bool OCC_Internals::addVertex(int &tag, double x, double y, double z,
                              double meshSize)
{
  if(tag >= 0 && _tagVertex.IsBound(tag)){
    Msg::Error("OpenCASCADE vertex with tag %d already exists", tag);
    return false;
  }
  TopoDS_Vertex result;
  try{
    gp_Pnt aPnt(x, y, z);
    BRepBuilderAPI_MakeVertex v(aPnt);
    v.Build();
    if(!v.IsDone()){
      Msg::Error("Could not create vertex");
      return false;
    }
    result = v.Vertex();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(meshSize > 0 && meshSize < MAX_LC)
    _meshAttr.Bind(result, meshAttr(meshSize));
  if(tag < 0) tag = getMaxTag(0) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addLine(int &tag, int startTag, int endTag)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return false;
  }
  if(!_tagVertex.IsBound(startTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", startTag);
    return false;
  }
  if(!_tagVertex.IsBound(endTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", endTag);
    return false;
  }

  TopoDS_Edge result;
  try{
    TopoDS_Vertex start = TopoDS::Vertex(_tagVertex.Find(startTag));
    TopoDS_Vertex end = TopoDS::Vertex(_tagVertex.Find(endTag));
    BRepBuilderAPI_MakeEdge e(start, end);
    e.Build();
    if(!e.IsDone()){
      Msg::Error("Could not create edge");
      return false;
    }
    result = e.Edge();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addLine(int &tag, const std::vector<int> &vertexTags)
{
  if(vertexTags.size() == 2)
    return addLine(tag, vertexTags[0], vertexTags[1]);

  // FIXME: if tag < 0 we could create multiple lines
  Msg::Error("OpenCASCADE polyline currently not supported");
  return false;
}

bool OCC_Internals::_addArc(int &tag, int startTag, int centerTag, int endTag,
                            int mode)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return false;
  }
  if(!_tagVertex.IsBound(startTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", startTag);
    return false;
  }
  if(!_tagVertex.IsBound(centerTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", centerTag);
    return false;
  }
  if(!_tagVertex.IsBound(endTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", endTag);
    return false;
  }

  TopoDS_Edge result;
  try{
    TopoDS_Vertex start = TopoDS::Vertex(_tagVertex.Find(startTag));
    TopoDS_Vertex center = TopoDS::Vertex(_tagVertex.Find(centerTag));
    TopoDS_Vertex end = TopoDS::Vertex(_tagVertex.Find(endTag));
    gp_Pnt aP1 = BRep_Tool::Pnt(start);
    gp_Pnt aP2 = BRep_Tool::Pnt(center);
    gp_Pnt aP3 = BRep_Tool::Pnt(end);
    Handle(Geom_TrimmedCurve) arc;
    if(mode == 0){ // circle
      Standard_Real Radius = aP1.Distance(aP2);
      gce_MakeCirc MC(aP2, gce_MakePln(aP1, aP2, aP3).Value(), Radius);
      if(!MC.IsDone()){
        Msg::Error("Could not build circle");
        return false;
      }
      const gp_Circ &Circ = MC.Value();
      Standard_Real Alpha1 = ElCLib::Parameter(Circ, aP1);
      Standard_Real Alpha2 = ElCLib::Parameter(Circ, aP3);
      Handle(Geom_Circle) C = new Geom_Circle(Circ);
      arc = new Geom_TrimmedCurve(C, Alpha1, Alpha2, false);
    }
    else{
      gce_MakeElips ME(aP1, aP3, aP2);
      if(!ME.IsDone()){
        Msg::Error("Could not build ellipse");
        return false;
      }
      const gp_Elips &Elips = ME.Value();
      Standard_Real Alpha1 = ElCLib::Parameter(Elips, aP1);
      Standard_Real Alpha2 = ElCLib::Parameter(Elips, aP3);
      Handle(Geom_Ellipse) E = new Geom_Ellipse(Elips);
      arc = new Geom_TrimmedCurve(E, Alpha1, Alpha2, true);
    }
    BRepBuilderAPI_MakeEdge e(arc, start, end);
    e.Build();
    if(!e.IsDone()){
      Msg::Error("Could not create %s arc", mode ? "ellipse" : "circle");
      return false;
    }
    result = e.Edge();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addCircleArc(int &tag, int startTag, int centerTag, int endTag)
{
  return _addArc(tag, startTag, centerTag, endTag, 0);
}

bool OCC_Internals::addEllipseArc(int &tag, int startTag, int centerTag, int endTag)
{
  return _addArc(tag, startTag, centerTag, endTag, 1);
}

bool OCC_Internals::addCircle(int &tag, double x, double y, double z, double r,
                              double angle1, double angle2)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return false;
  }

  TopoDS_Edge result;
  try{
    gp_Dir N_dir(0., 0., 1.);
    gp_Dir x_dir(1., 0., 0.);
    gp_Pnt center(x, y, z);
    gp_Ax2 axis(center, N_dir, x_dir);
    gp_Circ circ(axis, r);
    if(angle1 == 0. && angle2 == 2 * M_PI){
      result = BRepBuilderAPI_MakeEdge(circ);
    }
    else{
      Handle(Geom_Circle) C = new Geom_Circle(circ);
      Handle(Geom_TrimmedCurve) arc = new Geom_TrimmedCurve(C, angle1, angle2, false);
      BRepBuilderAPI_MakeEdge e(arc);
      if(!e.IsDone()){
        Msg::Error("Could not create circle arc");
        return false;
      }
      result = e.Edge();
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addEllipse(int &tag, double x, double y, double z, double rx,
                               double ry, double angle1, double angle2)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return false;
  }
  if(ry > rx){
    Msg::Error("Major radius rx should be larger than minor radius ry");
    return false;
  }

  TopoDS_Edge result;
  try{
    gp_Dir N_dir(0., 0., 1.);
    gp_Dir x_dir(1., 0., 0.);
    gp_Pnt center(x, y, z);
    gp_Ax2 axis(center, N_dir, x_dir);
    gp_Elips elips(axis, rx, ry);
    if(angle1 == 0 && angle2 == 2 * M_PI){
      result = BRepBuilderAPI_MakeEdge(elips);
    }
    else{
      Handle(Geom_Ellipse) E = new Geom_Ellipse(elips);
      Handle(Geom_TrimmedCurve) arc = new Geom_TrimmedCurve(E, angle1, angle2, true);
      BRepBuilderAPI_MakeEdge e(arc);
      if(!e.IsDone()){
        Msg::Error("Could not create ellipse arc");
        return false;
      }
      result = e.Edge();
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::_addSpline(int &tag, const std::vector<int> &vertexTags, int mode)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return false;
  }
  if(vertexTags.size() < 2 || vertexTags.size() > 20){
    Msg::Error("Number of control points should be in [2,20]");
    return false;
  }

  TopoDS_Edge result;
  try{
    TColgp_Array1OfPnt ctrlPoints(1, vertexTags.size());
    TopoDS_Vertex start, end;
    for(unsigned int i = 0; i < vertexTags.size(); i++){
      if(!_tagVertex.IsBound(vertexTags[i])){
        Msg::Error("Unknown OpenCASCADE vertex with tag %d", vertexTags[i]);
        return false;
      }
      TopoDS_Vertex vertex = TopoDS::Vertex(_tagVertex.Find(vertexTags[i]));
      ctrlPoints.SetValue(i + 1, BRep_Tool::Pnt(vertex));
      if(i == 0) start = vertex;
      if(i == vertexTags.size() - 1) end = vertex;
    }
    if(mode == 0){ // BSpline through points (called "Spline" in Gmsh)
      Handle(Geom_BSplineCurve) curve = GeomAPI_PointsToBSpline(ctrlPoints).Curve();
      BRepBuilderAPI_MakeEdge e(curve, start, end);
      if(!e.IsDone()){
        Msg::Error("Could not create spline");
        return false;
      }
      result = e.Edge();
    }
    else if(mode == 1){
      Handle(Geom_BezierCurve) curve = new Geom_BezierCurve(ctrlPoints);
      BRepBuilderAPI_MakeEdge e(curve, start, end);
      if(!e.IsDone()){
        Msg::Error("Could not create Bezier curve");
        return false;
      }
      result = e.Edge();
    }
    else if(mode == 2){
      // TODO: BSpline treat periodic case, allow to set order, etc.
      // Handle(Geom_BSplineCurve) curve = new Geom_BSplineCurve(ctrlPoints, ...);
      // ...
      Msg::Error("OpenCASCADE BSpline not implemented yet");
      return false;
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addSpline(int &tag, const std::vector<int> &vertexTags)
{
  return _addSpline(tag, vertexTags, 0);
}

bool OCC_Internals::addBezier(int &tag, const std::vector<int> &vertexTags)
{
  return _addSpline(tag, vertexTags, 1);
}

bool OCC_Internals::addBSpline(int &tag, const std::vector<int> &vertexTags)
{
  return _addSpline(tag, vertexTags, 2);
}

bool OCC_Internals::addWire(int &tag, const std::vector<int> &edgeTags,
                            bool checkClosed)
{
  if(tag >= 0 && _tagWire.IsBound(tag)){
    Msg::Error("OpenCASCADE wire or line loop with tag %d already exists", tag);
    return false;
  }

  TopoDS_Wire result;
  try{
    BRepBuilderAPI_MakeWire w;
    for (unsigned int i = 0; i < edgeTags.size(); i++) {
      if(!_tagEdge.IsBound(edgeTags[i])){
        Msg::Error("Unknown OpenCASCADE edge with tag %d", edgeTags[i]);
        return false;
      }
      TopoDS_Edge edge = TopoDS::Edge(_tagEdge.Find(edgeTags[i]));
      w.Add(edge);
    }
    result = w.Wire();
    if(checkClosed && !result.Closed()){
      Msg::Error("Line Loop is not closed");
      return false;
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(-1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addLineLoop(int &tag, const std::vector<int> &edgeTags)
{
  return addWire(tag, edgeTags, true);
}

bool OCC_Internals::_makeRectangle(TopoDS_Face &result, double x, double y, double z,
                                   double dx, double dy, double roundedRadius)
{
  try{
    TopoDS_Wire wire;
    double x1 = x, y1 = y, z1 = z, x2 = x1 + dx, y2 = y1 + dy;
    if(roundedRadius <= 0.){
      TopoDS_Vertex v1 = BRepBuilderAPI_MakeVertex(gp_Pnt(x1, y1, z1));
      TopoDS_Vertex v2 = BRepBuilderAPI_MakeVertex(gp_Pnt(x2, y1, z1));
      TopoDS_Vertex v3 = BRepBuilderAPI_MakeVertex(gp_Pnt(x2, y2, z1));
      TopoDS_Vertex v4 = BRepBuilderAPI_MakeVertex(gp_Pnt(x1, y2, z1));
      TopoDS_Edge e1 = BRepBuilderAPI_MakeEdge(v1, v2);
      TopoDS_Edge e2 = BRepBuilderAPI_MakeEdge(v2, v3);
      TopoDS_Edge e3 = BRepBuilderAPI_MakeEdge(v3, v4);
      TopoDS_Edge e4 = BRepBuilderAPI_MakeEdge(v4, v1);
      wire = BRepBuilderAPI_MakeWire(e1, e2, e3, e4);
    }
    else{
      double r = roundedRadius;
      TopoDS_Vertex v1 = BRepBuilderAPI_MakeVertex(gp_Pnt(x1 + r, y1, z1));
      TopoDS_Vertex v2 = BRepBuilderAPI_MakeVertex(gp_Pnt(x2 - r, y1, z1));
      TopoDS_Vertex v3 = BRepBuilderAPI_MakeVertex(gp_Pnt(x2, y1 + r, z1));
      TopoDS_Vertex v4 = BRepBuilderAPI_MakeVertex(gp_Pnt(x2, y2 - r, z1));
      TopoDS_Vertex v5 = BRepBuilderAPI_MakeVertex(gp_Pnt(x2 - r, y2, z1));
      TopoDS_Vertex v6 = BRepBuilderAPI_MakeVertex(gp_Pnt(x1 + r, y2, z1));
      TopoDS_Vertex v7 = BRepBuilderAPI_MakeVertex(gp_Pnt(x1, y2 - r, z1));
      TopoDS_Vertex v8 = BRepBuilderAPI_MakeVertex(gp_Pnt(x1, y1 + r, z1));
      TopoDS_Edge e1 = BRepBuilderAPI_MakeEdge(v1, v2);
      TopoDS_Edge e2 = BRepBuilderAPI_MakeEdge(v3, v4);
      TopoDS_Edge e3 = BRepBuilderAPI_MakeEdge(v5, v6);
      TopoDS_Edge e4 = BRepBuilderAPI_MakeEdge(v7, v8);
      gp_Pnt c1(x1 + r, y1 + r, z1);
      gp_Pnt c2(x2 - r, y1 + r, z1);
      gp_Pnt c3(x2 - r, y2 - r, z1);
      gp_Pnt c4(x1 + r, y2 - r, z1);
      gp_Pln plane = gce_MakePln(c1, c2, c3).Value();
      gp_Circ circ1 = gce_MakeCirc(c1, plane, r).Value();
      gp_Circ circ2 = gce_MakeCirc(c2, plane, r).Value();
      gp_Circ circ3 = gce_MakeCirc(c3, plane, r).Value();
      gp_Circ circ4 = gce_MakeCirc(c4, plane, r).Value();
      Handle(Geom_Circle) circle1 = new Geom_Circle(circ1);
      Handle(Geom_Circle) circle2 = new Geom_Circle(circ2);
      Handle(Geom_Circle) circle3 = new Geom_Circle(circ3);
      Handle(Geom_Circle) circle4 = new Geom_Circle(circ4);
      Handle(Geom_TrimmedCurve) arc1 = new Geom_TrimmedCurve(circle1, -M_PI, -M_PI/2., true);
      Handle(Geom_TrimmedCurve) arc2 = new Geom_TrimmedCurve(circle2, -M_PI/2, 0, true);
      Handle(Geom_TrimmedCurve) arc3 = new Geom_TrimmedCurve(circle3, 0, M_PI/2, true);
      Handle(Geom_TrimmedCurve) arc4 = new Geom_TrimmedCurve(circle4, M_PI/2, M_PI, true);
      TopoDS_Edge ce1 = BRepBuilderAPI_MakeEdge(arc1, v8, v1);
      TopoDS_Edge ce2 = BRepBuilderAPI_MakeEdge(arc2, v2, v3);
      TopoDS_Edge ce3 = BRepBuilderAPI_MakeEdge(arc3, v4, v5);
      TopoDS_Edge ce4 = BRepBuilderAPI_MakeEdge(arc4, v6, v7);
      BRepBuilderAPI_MakeWire w;
      w.Add(e1); w.Add(ce2); w.Add(e2); w.Add(ce3);
      w.Add(e3); w.Add(ce4); w.Add(e4); w.Add(ce1);
      wire = w.Wire();
    }
    result = BRepBuilderAPI_MakeFace(wire);
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addRectangle(int &tag, double x, double y, double z,
                                 double dx, double dy, double roundedRadius)
{
  if(tag >= 0 && _tagFace.IsBound(tag)){
    Msg::Error("OpenCASCADE face with tag %d already exists", tag);
    return false;
  }
  TopoDS_Face result;
  if(!_makeRectangle(result, x, y, z, dx, dy, roundedRadius))
    return false;
  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::_makeDisk(TopoDS_Face &result, double xc, double yc, double zc,
                              double rx, double ry)
{
  if(ry > rx){
    Msg::Error("Major radius rx should be larger than minor radius ry");
    return false;
  }
  try{
    gp_Dir N_dir(0., 0., 1.);
    gp_Dir x_dir(1., 0., 0.);
    gp_Pnt center(xc, yc, zc);
    gp_Ax2 axis(center, N_dir, x_dir);
    gp_Elips ellipse = gp_Elips(axis, rx, ry);
    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(ellipse);
    TopoDS_Wire wire = BRepBuilderAPI_MakeWire(edge);
    result = BRepBuilderAPI_MakeFace(wire);
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addDisk(int &tag, double xc, double yc, double zc,
                            double rx, double ry)
{
  if(tag >= 0 && _tagFace.IsBound(tag)){
    Msg::Error("OpenCASCADE face with tag %d already exists", tag);
    return false;
  }
  TopoDS_Face result;
  if(!_makeDisk(result, xc, yc, zc, rx, ry))
    return false;
  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addPlaneSurface(int &tag, const std::vector<int> &wireTags)
{
  const bool autoFix = true;

  if(tag >= 0 && _tagFace.IsBound(tag)){
    Msg::Error("OpenCASCADE face with tag %d already exists", tag);
    return false;
  }

  std::vector<TopoDS_Wire> wires;
  for (unsigned int i = 0; i < wireTags.size(); i++) {
    if(!_tagWire.IsBound(wireTags[i])){
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTags[i]);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTags[i]));
    wires.push_back(wire);
  }

  TopoDS_Face result;
  if(wires.size() == 0){
    Msg::Error("Plane surface requires at least one line loop");
    return false;
  }
  else if(wires.size() == 1){
    result = BRepBuilderAPI_MakeFace(wires[0]);
  }
  else{
    // compute mean plane
    TopTools_IndexedMapOfShape vmap;
    for(unsigned int i = 0; i < wires.size(); i++){
      TopExp_Explorer exp0;
      for(exp0.Init(wires[i], TopAbs_VERTEX); exp0.More(); exp0.Next()){
        TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
        if(vmap.FindIndex(vertex) < 1)
          vmap.Add(vertex);
      }
    }
    std::vector<SPoint3> points;
    for(int i = 1; i <= vmap.Extent(); i++){
      gp_Pnt pnt = BRep_Tool::Pnt(TopoDS::Vertex(vmap(i)));
      points.push_back(SPoint3(pnt.X(), pnt.Y(), pnt.Z()));
    }
    // FIXME: should check that points are not colinear; if so, add more
    mean_plane meanPlane;
    computeMeanPlaneSimple(points, meanPlane);
    try{
      gp_Pln aPlane(meanPlane.a, meanPlane.b, meanPlane.c, -meanPlane.d);
      BRepBuilderAPI_MakeFace f(aPlane, wires[0]);
      for(unsigned int i = 1; i < wires.size(); i++){
        f.Add(wires[i]);
      }
      f.Build();
      if(!f.IsDone()){
        Msg::Error("Could not create face");
        return false;
      }
      result = f.Face();
      if(autoFix){
        // make sure wires are oriented correctly
        ShapeFix_Face fix(result);
        fix.Perform();
        result = fix.Face();
      }
    }
    catch(Standard_Failure &err){
      Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
      return false;
    }
  }
  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addSurfaceFilling(int &tag, int wireTag)
{
  if(tag >= 0 && _tagFace.IsBound(tag)){
    Msg::Error("OpenCASCADE face with tag %d already exists", tag);
    return false;
  }

  TopoDS_Face result;
  try{
    BRepOffsetAPI_MakeFilling f;
    // add edge constraints
    if(!_tagWire.IsBound(wireTag)){
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    TopExp_Explorer exp0;
    for(exp0.Init(wire, TopAbs_EDGE); exp0.More(); exp0.Next()){
      f.Add(TopoDS::Edge(exp0.Current()), GeomAbs_C0);
    }
    // TODO: add optional point constraints using
    // f.Add(gp_Pnt(x, y, z);

    f.Build();
    if(!f.IsDone()){
      Msg::Error("Could not build surface filling");
      return false;
    }
    result = TopoDS::Face(f.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addSurfaceLoop(int &tag, const std::vector<int> &faceTags)
{
  const bool autoFix = true;

  if(tag >= 0 && _tagShell.IsBound(tag)){
    Msg::Error("OpenCASCADE surface loop with tag %d already exists", tag);
    return false;
  }

  TopoDS_Shape result;
  try{
    BRepBuilderAPI_Sewing s;
    for (unsigned int i = 0; i < faceTags.size(); i++) {
      if(!_tagFace.IsBound(faceTags[i])){
        Msg::Error("Unknown OpenCASCADE face with tag %d", faceTags[i]);
        return false;
      }
      TopoDS_Face face = TopoDS::Face(_tagFace.Find(faceTags[i]));
      s.Add(face);
    }
    s.Perform();
    result = s.SewedShape();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  bool first = true;
  TopExp_Explorer exp0;
  for(exp0.Init(result, TopAbs_SHELL); exp0.More(); exp0.Next()){
    TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
    if(autoFix){
      // make sure faces in shell are oriented correctly
      ShapeFix_Shell fix(shell);
      fix.Perform();
      shell = fix.Shell();
    }
    int t = tag;
    if(first){
      first = false;
    }
    else{
      t = getMaxTag(-2) + 1;
      Msg::Warning("Creating additional surface loop %d", t);
    }
    bind(shell, t, true);
  }
  return true;
}

bool OCC_Internals::addVolume(int &tag, const std::vector<int> &shellTags)
{
  const bool autoFix = true;

  if(tag >= 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return false;
  }

  TopoDS_Solid result;
  try{
    BRepBuilderAPI_MakeSolid s;
    for (unsigned int i = 0; i < shellTags.size(); i++) {
      if(!_tagShell.IsBound(shellTags[i])){
        Msg::Error("Unknown OpenCASCADE surface loop with tag %d", shellTags[i]);
        return false;
      }
      TopoDS_Shell shell = TopoDS::Shell(_tagShell.Find(shellTags[i]));
      s.Add(shell);
    }
    result = s.Solid();
    if(autoFix){
      // make sure the volume is finite
      ShapeFix_Solid fix(result);
      fix.Perform();
      result = TopoDS::Solid(fix.Solid());
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::_makeSphere(TopoDS_Solid &result, double xc, double yc, double zc,
                                double radius, double angle1, double angle2,
                                double angle3)
{
  try{
    gp_Pnt p(xc, yc, zc);
    BRepPrimAPI_MakeSphere s(p, radius, angle1, angle2, angle3);
    s.Build();
    if(!s.IsDone()){
      Msg::Error("Could not create sphere");
      return false;
    }
    result = TopoDS::Solid(s.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addSphere(int &tag, double xc, double yc, double zc,
                              double radius, double angle1, double angle2,
                              double angle3)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!_makeSphere(result, xc, yc, zc, radius, angle1, angle2, angle3))
    return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::_makeBlock(TopoDS_Solid &result, double x, double y, double z,
                               double dx, double dy, double dz)
{
  try{
    gp_Pnt P1(x, y, z);
    gp_Pnt P2(x + dx, y + dy, z + dz);
    BRepPrimAPI_MakeBox b(P1, P2);
    b.Build();
    if(!b.IsDone()){
      Msg::Error("Could not create block");
      return false;
    }
    result = TopoDS::Solid(b.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addBlock(int &tag, double x, double y, double z,
                             double dx, double dy, double dz)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!_makeBlock(result, x, y, z, dx, dy, dz))
    return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::_makeCylinder(TopoDS_Solid &result, double x, double y, double z,
                                  double dx, double dy, double dz, double r, double angle)
{
  const double H = sqrt(dx * dx + dy * dy + dz * dz);
  if(!H){
    Msg::Error("Cannot build cylinder of zero height");
    return false;
  }
  try{
    gp_Pnt aP(x, y, z);
    gp_Vec aV(dx / H, dy / H, dz / H);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeCylinder c(anAxes, r, H, angle);
    c.Build();
    if(!c.IsDone()){
      Msg::Error("Could not create cylinder");
      return false;
    }
    result = TopoDS::Solid(c.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addCylinder(int &tag, double x, double y, double z,
                                double dx, double dy, double dz, double r,
                                double angle)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!_makeCylinder(result, x, y, z, dx, dy, dz, r, angle))
    return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::_makeTorus(TopoDS_Solid &result, double x, double y, double z,
                               double r1, double r2, double angle)
{
  try{
    gp_Pnt aP(x, y, z);
    gp_Vec aV(0, 0, 1);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeTorus t(anAxes, r1, r2, angle);
    t.Build();
    if (!t.IsDone()) {
      Msg::Error("Could not create torus");
      return false;
    }
    result = TopoDS::Solid(t.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addTorus(int &tag, double x, double y, double z,
                             double r1, double r2, double angle)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!_makeTorus(result, x, y, z, r1, r2, angle))
    return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::_makeCone(TopoDS_Solid &result, double x, double y, double z,
                              double dx, double dy, double dz, double r1, double r2,
                              double angle)
{
  const double H = sqrt(dx * dx + dy * dy + dz * dz);
  if(!H){
    Msg::Error("Cannot build cone of zero height");
    return false;
  }
  try{
    gp_Pnt aP(x, y, z);
    gp_Vec aV(dx / H, dy / H, dz / H);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeCone c(anAxes, r1, r2, H, angle);
    c.Build();
    if(!c.IsDone()){
      Msg::Error("Could not create cone");
      return false;
    }
    result = TopoDS::Solid(c.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addCone(int &tag, double x, double y, double z,
                            double dx, double dy, double dz, double r1,
                            double r2, double angle)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!_makeCone(result, x, y, z, dx, dy, dz, r1, r2, angle))
    return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::_makeWedge(TopoDS_Solid &result, double x, double y, double z,
                               double dx, double dy, double dz, double ltx)
{
  try{
    gp_Pnt aP(x, y, z);
    gp_Vec aV(0, 0, 1);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeWedge w(anAxes, dx, dy, dz, ltx);
    w.Build();
    if(!w.IsDone()){
      Msg::Error("Could not create wedge");
      return false;
    }
    result = TopoDS::Solid(w.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addWedge(int &tag, double x, double y, double z,
                             double dx, double dy, double dz, double ltx)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!_makeWedge(result, x, y, z, dx, dy, dz, ltx))
    return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addThruSections(int tag, const std::vector<int> &wireTags,
                                    bool makeSolid, bool makeRuled,
                                    std::vector<std::pair<int, int> > &outDimTags)
{
  int dim = makeSolid ? 3 : 2;
  if(tag >= 0 && isBound(dim, tag)){
    Msg::Error("OpenCASCADE entity of dimension %d with tag %d already exists",
               dim, tag);
    return false;
  }
  if(wireTags.size() < 2){
    Msg::Error("ThruSections require at least 2 wires");
    return false;
  }
  TopoDS_Shape result;
  try{
    BRepOffsetAPI_ThruSections ts(makeSolid, makeRuled);
    for (unsigned int i = 0; i < wireTags.size(); i++) {
      if(!_tagWire.IsBound(wireTags[i])){
        Msg::Error("Unknown OpenCASCADE wire or line loop with tag %d", wireTags[i]);
        return false;
      }
      TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTags[i]));
      if(makeSolid && !wire.Closed()){
        Msg::Error("Making solid requires closed wires");
        return false;
      }
      ts.AddWire(wire);
    }
    ts.CheckCompatibility(Standard_False);
    ts.Build();
    if(!ts.IsDone()){
      Msg::Error("Could not create ThruSection");
      return false;
    }
    result = ts.Shape();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  bind(result, tag, outDimTags, true, true);
  return true;
}

bool OCC_Internals::addThickSolid(int tag, int solidTag,
                                  const std::vector<int> &excludeFaceTags,
                                  double offset,
                                  std::vector<std::pair<int, int> > &outDimTags)
{
  if(tag >= 0 && isBound(3, tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return false;
  }
  if(!isBound(3, solidTag)){
    Msg::Error("Unknown OpenCASCADE region with tag %d", solidTag);
    return false;
  }
  TopoDS_Shape result;
  try{
    TopoDS_Shape shape = find(3, solidTag);
    TopTools_ListOfShape exclude;
    for(unsigned int i = 0; i < excludeFaceTags.size(); i++){
      if(!_tagFace.IsBound(excludeFaceTags[i])){
        Msg::Error("Unknown OpenCASCADE face with tag %d", excludeFaceTags[i]);
        return false;
      }
      exclude.Append(_tagFace.Find(excludeFaceTags[i]));
    }
    BRepOffsetAPI_MakeThickSolid ts(shape, exclude, offset,
                                    CTX::instance()->geom.tolerance);
    ts.Build();
    if(!ts.IsDone()){
      Msg::Error("Could not build thick solid");
      return false;
    }
    result = ts.Shape();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  bind(result, tag, outDimTags, true, true);
  return true;
}

void OCC_Internals::_setExtrudedMeshAttr(const TopoDS_Compound &c,
                                         BRepSweep_Prism *p,
                                         BRepSweep_Revol *r,
                                         ExtrudeParams *e,
                                         double x, double y, double z,
                                         double dx, double dy, double dz,
                                         double ax, double ay, double az,
                                         double angle)
{
  if(!p && !r) return;

  if(r && angle >= 2 * M_PI){
    // OCC removes the origin edge from e.g. disks, which makes it impossible to
    // generate the 2D surface mesh by extrusion of the 1D edge mesh
    Msg::Warning("Extruded meshes by revolution only for angle < 2*Pi");
    return;
  }

  TopExp_Explorer exp0;

  for(exp0.Init(c, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    TopoDS_Shape bot = p ? p->FirstShape(face) : r->FirstShape(face);
    TopoDS_Shape top = p ? p->LastShape(face) : r->LastShape(face);
    {
      ExtrudeParams *ee = new ExtrudeParams(COPIED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      meshAttr m(ee);
      m.source = bot;
      _meshAttr.Bind(top, m);
    }
    TopoDS_Shape vol = p ? p->Shape(face) : r->Shape(face);
    {
      ExtrudeParams *ee = new ExtrudeParams(EXTRUDED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      meshAttr m(ee);
      m.source = bot;
      _meshAttr.Bind(vol, m);
    }
  }

  for(exp0.Init(c, TopAbs_EDGE); exp0.More(); exp0.Next()){
    TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
    TopoDS_Shape bot = p ? p->FirstShape(edge) : r->FirstShape(edge);
    TopoDS_Shape top = p ? p->LastShape(edge) : r->LastShape(edge);
    {
      ExtrudeParams *ee = new ExtrudeParams(COPIED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      meshAttr m(ee);
      m.source = bot;
      _meshAttr.Bind(top, m);
    }
    TopoDS_Shape sur = p ? p->Shape(edge) : r->Shape(edge);
    {
      ExtrudeParams *ee = new ExtrudeParams(EXTRUDED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      meshAttr m(ee);
      m.source = bot;
      _meshAttr.Bind(sur, m);
    }
  }

  for(exp0.Init(c, TopAbs_VERTEX); exp0.More(); exp0.Next()){
    TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
    TopoDS_Shape bot = p ? p->FirstShape(vertex) : r->FirstShape(vertex);
    TopoDS_Shape top = p ? p->LastShape(vertex) : r->LastShape(vertex);
    TopoDS_Shape lin = p ? p->Shape(vertex) : r->Shape(vertex);
    {
      ExtrudeParams *ee = new ExtrudeParams(EXTRUDED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      meshAttr m(ee);
      m.source = bot;
      _meshAttr.Bind(lin, m);
    }
  }
}

void OCC_Internals::_copyExtrudedMeshAttr(TopoDS_Edge edge, GEdge *ge)
{
  if(!_meshAttr.IsBound(edge)) return;
  meshAttr m = _meshAttr.Find(edge);
  if(!m.extrude) return;
  ge->meshAttributes.extrude = m.extrude;
  if(ge->meshAttributes.extrude->geo.Mode == EXTRUDED_ENTITY){
    if(_vertexTag.IsBound(m.source))
      ge->meshAttributes.extrude->geo.Source = _vertexTag.Find(m.source);
  }
  else if(ge->meshAttributes.extrude->geo.Mode == COPIED_ENTITY){
    if(_edgeTag.IsBound(m.source)){
      int t = _edgeTag.Find(m.source);
      if(t == ge->tag()) // degenerate extrusion
        ge->meshAttributes.extrude = 0;
      else
        ge->meshAttributes.extrude->geo.Source = t;
    }
  }
}

void OCC_Internals::_copyExtrudedMeshAttr(TopoDS_Face face, GFace *gf)
{
  if(!_meshAttr.IsBound(face)) return;
  meshAttr m = _meshAttr.Find(face);
  if(!m.extrude) return;
  gf->meshAttributes.extrude = m.extrude;
  if(gf->meshAttributes.extrude->geo.Mode == EXTRUDED_ENTITY){
    if(_edgeTag.IsBound(m.source))
      gf->meshAttributes.extrude->geo.Source = _edgeTag.Find(m.source);
  }
  else if(gf->meshAttributes.extrude->geo.Mode == COPIED_ENTITY){
    if(_faceTag.IsBound(m.source)){
      int t = _faceTag.Find(m.source);
      if(t == gf->tag()) // degenerate extrusion
        gf->meshAttributes.extrude = 0;
      else
        gf->meshAttributes.extrude->geo.Source = t;
    }
  }
}

void OCC_Internals::_copyExtrudedMeshAttr(TopoDS_Solid solid, GRegion *gr)
{
  if(!_meshAttr.IsBound(solid)) return;
  meshAttr m = _meshAttr.Find(solid);
  if(!m.extrude) return;
  gr->meshAttributes.extrude = m.extrude;
  if(gr->meshAttributes.extrude->geo.Mode == EXTRUDED_ENTITY){
    if(_faceTag.IsBound(m.source))
      gr->meshAttributes.extrude->geo.Source = _faceTag.Find(m.source);
  }
}

bool OCC_Internals::_extrude(int mode,
                             const std::vector<std::pair<int, int> > &inDimTags,
                             double x, double y, double z,
                             double dx, double dy, double dz,
                             double ax, double ay, double az, double angle,
                             int wireTag,
                             std::vector<std::pair<int, int> > &outDimTags,
                             ExtrudeParams *e)
{
  // build a single compound shape, so that we won't duplicate internal
  // boundaries
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(unsigned int i = 0; i < inDimTags.size(); i++){
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(!isBound(dim, tag)){
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim, tag);
      return false;
    }
    TopoDS_Shape shape = find(dim, tag);
    b.Add(c, shape);
  }
  TopoDS_Shape result;
  try{
    if(mode == 0){ // extrude
      BRepPrimAPI_MakePrism p(c, gp_Vec(dx, dy, dz), Standard_False);
      p.Build();
      if(!p.IsDone()){
        Msg::Error("Could not extrude");
        return false;
      }
      result = p.Shape();
      if(e){
        const BRepSweep_Prism &prism(p.Prism());
        _setExtrudedMeshAttr(c, (BRepSweep_Prism*)&prism, 0, e,
                             0., 0., 0., dx, dy, dz, 0., 0., 0., 0.);
      }
    }
    else if(mode == 1){ // revolve
      gp_Ax1 axisOfRevolution(gp_Pnt(x, y, z), gp_Dir(ax, ay, az));
      BRepPrimAPI_MakeRevol r(c, axisOfRevolution, angle, Standard_False);
      r.Build();
      if(!r.IsDone()){
        Msg::Error("Could not revolve");
        return false;
      }
      result = r.Shape();
      if(e){
        const BRepSweep_Revol &revol(r.Revol());
        _setExtrudedMeshAttr(c, 0, (BRepSweep_Revol*)&revol, e,
                             x, y, z, 0., 0., 0., ax, ay, az, angle);
      }
    }
    else if(mode == 2){ // pipe
      if(!_tagWire.IsBound(wireTag)){
        Msg::Error("Unknown OpenCASCADE wire with tag %d", wireTag);
        return false;
      }
      TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
      BRepOffsetAPI_MakePipe p(wire, c, GeomFill_IsCorrectedFrenet);
      /* GeomFill_IsCorrectedFrenet, GeomFill_IsFixed, GeomFill_IsFrenet,
         GeomFill_IsConstantNormal, GeomFill_IsDarboux, GeomFill_IsGuideAC,
         GeomFill_IsGuidePlan, GeomFill_IsGuideACWithContact,
         GeomFill_IsGuidePlanWithContact, GeomFill_IsDiscreteTrihedron */
      p.Build();
      if(!p.IsDone()){
        Msg::Error("Could not create pipe");
        return false;
      }
      result = p.Shape();
      if(e)
        Msg::Warning("Structured meshes not yet available with OpenCASCADE pipe");
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  bind(result, -1, outDimTags, true, true);
  return true;
}

bool OCC_Internals::extrude(const std::vector<std::pair<int, int> > &inDimTags,
                            double dx, double dy, double dz,
                            std::vector<std::pair<int, int> > &outDimTags,
                            ExtrudeParams *e)
{
  return _extrude(0, inDimTags, 0., 0., 0., dx, dy, dz, 0., 0., 0., 0., 0,
                  outDimTags, e);
}

bool OCC_Internals::revolve(const std::vector<std::pair<int, int> > &inDimTags,
                            double x, double y, double z,
                            double ax, double ay, double az, double angle,
                            std::vector<std::pair<int, int> > &outDimTags,
                            ExtrudeParams *e)
{
  return _extrude(1, inDimTags, x, y, z, 0., 0., 0., ax, ay, az, angle, 0,
                  outDimTags, e);
}

bool OCC_Internals::addPipe(const std::vector<std::pair<int, int> > &inDimTags,
                            int wireTag, std::vector<std::pair<int, int> > &outDimTags)
{
  return _extrude(2, inDimTags, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., wireTag,
                  outDimTags);
}

bool OCC_Internals::fillet(const std::vector<int> &regionTags,
                           const std::vector<int> &edgeTags, double radius,
                           std::vector<std::pair<int, int> > &outDimTags,
                           bool removeRegion)
{
  std::vector<TopoDS_Edge> edges;
  for(unsigned int i = 0; i < edgeTags.size(); i++){
    if(!_tagEdge.IsBound(edgeTags[i])){
      Msg::Error("Unknown OpenCASCADE edge with tag %d", edgeTags[i]);
      return false;
    }
    edges.push_back(TopoDS::Edge(_tagEdge.Find(edgeTags[i])));
  }

  // build a single compound shape
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(unsigned int i = 0; i < regionTags.size(); i++){
    if(!isBound(3, regionTags[i])){
      Msg::Error("Unknown OpenCASCADE region with tag %d", regionTags[i]);
      return false;
    }
    TopoDS_Shape shape = find(3, regionTags[i]);
    b.Add(c, shape);
    if(removeRegion) unbind(shape, 3, regionTags[i], true); // recursive
  }
  TopoDS_Shape result;
  try{
    BRepFilletAPI_MakeFillet f(c);
    for(unsigned int i = 0; i < edges.size(); i++)
      f.Add(edges[i]);
    for(int i = 1; i <= f.NbContours(); i++)
      f.SetRadius(radius, i, 1);
    f.Build();
    if(!f.IsDone()) {
      Msg::Error("Could not compute fillet");
      return false;
    }
    result = f.Shape();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(result.IsNull()){
    Msg::Error("Fillet produces empty shape");
    return false;
  }
  bind(result, -1, outDimTags, true, true);
  return true;
}

bool OCC_Internals::booleanOperator(int tag, BooleanOperator op,
                                    const std::vector<std::pair<int, int> > &objectDimTags,
                                    const std::vector<std::pair<int, int> > &toolDimTags,
                                    std::vector<std::pair<int, int> > &outDimTags,
                                    bool removeObject, bool removeTool)
{
  double tolerance = CTX::instance()->geom.toleranceBoolean;
  bool parallel = CTX::instance()->geom.occParallel;

  if(objectDimTags.empty()) return true;

  if(tag >= 0 && isBound(objectDimTags[0].first, tag)){
    Msg::Error("OpenCASCADE entity with tag %d already exists", tag);
    return false;
  }

  TopTools_ListOfShape objectShapes, toolShapes;
  for(unsigned int i = 0; i < objectDimTags.size(); i++){
    int dim = objectDimTags[i].first;
    int t = objectDimTags[i].second;
    if(!isBound(dim, t)){
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim, t);
      return false;
    }
    else{
      TopoDS_Shape object = find(dim, t);
      objectShapes.Append(object);
    }
  }
  for(unsigned int i = 0; i < toolDimTags.size(); i++){
    int dim = toolDimTags[i].first;
    int t = toolDimTags[i].second;
    if(!isBound(dim, t)){
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim, t);
      return false;
    }
    else{
      TopoDS_Shape tool = find(dim, t);
      toolShapes.Append(tool);
    }
  }

  TopoDS_Shape result;
  std::vector<TopTools_ListOfShape> mapModified, mapGenerated;
  std::vector<bool> mapDeleted;
  try{
    switch(op){
    case OCC_Internals::Union :
      {
        BRepAlgoAPI_Fuse fuse;
        fuse.SetRunParallel(parallel);
        fuse.SetArguments(objectShapes);
        fuse.SetTools(toolShapes);
        if(tolerance > 0.0)
          fuse.SetFuzzyValue(tolerance);
        fuse.Build();
        if(!fuse.IsDone()){
          Msg::Error("Fuse operation cannot be performed");
          return false;
        }
        result = fuse.Shape();
        TopTools_ListIteratorOfListOfShape it(objectShapes);
        for(; it.More(); it.Next()){
          mapModified.push_back(fuse.Modified(it.Value()));
          mapDeleted.push_back(fuse.IsDeleted(it.Value()));
          mapGenerated.push_back(fuse.Generated(it.Value()));
        }
        TopTools_ListIteratorOfListOfShape it2(toolShapes);
        for(; it2.More(); it2.Next()){
          mapModified.push_back(fuse.Modified(it2.Value()));
          mapDeleted.push_back(fuse.IsDeleted(it2.Value()));
          mapGenerated.push_back(fuse.Generated(it2.Value()));
        }
      }
      break;
    case OCC_Internals::Intersection :
      {
        BRepAlgoAPI_Common common;
        common.SetRunParallel(parallel);
        common.SetArguments(objectShapes);
        common.SetTools(toolShapes);
        if(tolerance > 0.0)
          common.SetFuzzyValue(tolerance);
        common.Build();
        if(!common.IsDone()){
          Msg::Error("Intersection operation cannot be performed");
          return false;
        }
        result = common.Shape();
        TopTools_ListIteratorOfListOfShape it(objectShapes);
        for(; it.More(); it.Next()){
          mapModified.push_back(common.Modified(it.Value()));
          mapDeleted.push_back(common.IsDeleted(it.Value()));
          mapGenerated.push_back(common.Generated(it.Value()));
        }
        TopTools_ListIteratorOfListOfShape it2(toolShapes);
        for(; it2.More(); it2.Next()){
          mapModified.push_back(common.Modified(it2.Value()));
          mapDeleted.push_back(common.IsDeleted(it2.Value()));
          mapGenerated.push_back(common.Generated(it2.Value()));
        }
      }
      break;

    case OCC_Internals::Difference :
      {
        BRepAlgoAPI_Cut cut;
        cut.SetRunParallel(parallel);
        cut.SetArguments(objectShapes);
        cut.SetTools(toolShapes);
        if(tolerance > 0.0)
          cut.SetFuzzyValue(tolerance);
        cut.Build();
        if(!cut.IsDone()){
          Msg::Error("Intersection operation cannot be performed");
          return false;
        }
        result = cut.Shape();
        TopTools_ListIteratorOfListOfShape it(objectShapes);
        for(; it.More(); it.Next()){
          mapModified.push_back(cut.Modified(it.Value()));
          mapDeleted.push_back(cut.IsDeleted(it.Value()));
          mapGenerated.push_back(cut.Generated(it.Value()));
        }
        TopTools_ListIteratorOfListOfShape it2(toolShapes);
        for(; it2.More(); it2.Next()){
          mapModified.push_back(cut.Modified(it2.Value()));
          mapDeleted.push_back(cut.IsDeleted(it2.Value()));
          mapGenerated.push_back(cut.Generated(it2.Value()));
        }
      }
      break;

    case OCC_Internals::Fragments :
    default:
      {
        BRepAlgoAPI_BuilderAlgo fragments;
        fragments.SetRunParallel(parallel);
        objectShapes.Append(toolShapes);
        toolShapes.Clear();
        fragments.SetArguments(objectShapes);
        if(tolerance > 0.0)
          fragments.SetFuzzyValue(tolerance);
        fragments.Build();
        if(!fragments.IsDone()){
          Msg::Error("Boolean fragments failed");
          return false;
        }
        result = fragments.Shape();
        TopTools_ListIteratorOfListOfShape it(objectShapes);
        for(; it.More(); it.Next()){
          mapModified.push_back(fragments.Modified(it.Value()));
          mapDeleted.push_back(fragments.IsDeleted(it.Value()));
          mapGenerated.push_back(fragments.Generated(it.Value()));
        }
      }
      break;
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  // don't try to preserve numbering if we specify the tag explicitly, or if
  // there is a problem
  bool bug1 = (objectDimTags.size() + toolDimTags.size() != mapModified.size());
  bool bug2 = (op == OCC_Internals::Union); // steange fuse behavior in OCC 7.1
  if(tag >= 0 || bug1 || bug2){
    if(bug1) Msg::Error("Wrong shape count in boolean operation");
    if(removeObject){
      for(unsigned int i = 0; i < objectDimTags.size(); i++){
        int d = objectDimTags[i].first;
        int t = objectDimTags[i].second;
        if(isBound(d, t)) unbind(find(d, t), d, t, true); // recursive
      }
    }
    if(removeTool){
      for(unsigned int i = 0; i < toolDimTags.size(); i++){
        int d = toolDimTags[i].first;
        int t = toolDimTags[i].second;
        if(isBound(d, t)) unbind(find(d, t), d, t, true); // recursive
      }
    }
    bind(result, tag, outDimTags, true, true);
    return true;
  }

  // otherwise, try to preserve the numbering
  std::vector<TopoDS_Shape> toBind;
  for(unsigned int i = 0; i < objectDimTags.size(); i++){
    int dim = objectDimTags[i].first;
    int tag = objectDimTags[i].second;
    if(mapDeleted[i] && !mapGenerated[i].Extent()){
      // the shape has been deleted
      if(removeObject && isBound(dim, tag)){
        unbind(find(dim, tag), dim, tag, true);
      }
    }
    else if(mapModified[i].Extent() == 0){
      // the shape has not been modified
      outDimTags.push_back(std::pair<int, int>(dim, tag));
      // FIXME: since we currently don't guarantee that the tags of the entities
      // on the boundary will be preserved, we must force a re-sync of the
      // shape, by unbinding (which will add it in _toRemove) and re-binding it
      if(removeObject && isBound(dim, tag)){
        TopoDS_Shape shape = find(dim, tag);
        unbind(shape, dim, tag, true);
        bind(shape, dim, tag, true);
      }
    }
    else if(mapModified[i].Extent() == 1){
      if(removeObject){
        // the shape has been replaced by a single shape, keep the same tag
        if(isBound(dim, tag)){
          unbind(find(dim, tag), dim, tag, true);
        }
        bind(mapModified[i].First(), dim, tag, true);
        outDimTags.push_back(std::pair<int, int>(dim, tag));
      }
      else{
        toBind.push_back(mapModified[i].First());
      }
    }
    else{
      if(removeObject && isBound(dim, tag)){
        unbind(find(dim, tag), dim, tag, true);
      }
      TopTools_ListIteratorOfListOfShape it(mapModified[i]);
      for(; it.More(); it.Next())
        toBind.push_back(it.Value());
    }
    {
      TopTools_ListIteratorOfListOfShape it(mapGenerated[i]);
      for(; it.More(); it.Next())
        toBind.push_back(it.Value());
    }
  }

  for(unsigned int i = 0; i < toolDimTags.size(); i++){
    int k = objectDimTags.size() + i;
    int dim = toolDimTags[i].first;
    int tag = toolDimTags[i].second;
    if(mapDeleted[k] && !mapGenerated[k].Extent()){
      // the shape has been deleted
      if(removeTool && isBound(dim, tag)){
        unbind(find(dim, tag), dim, tag, true); // recursive
      }
    }
    else if(mapModified[k].Extent() == 0){
      // the shape has not been modified
      outDimTags.push_back(std::pair<int, int>(dim, tag));
      // FIXME: since we currently don't guarantee that the tags of the entities
      // on the boundary will be preserved, we must force a re-sync of the
      // shape, by unbinding (which will add it in _toRemove) and re-binding it
      if(removeTool && isBound(dim, tag)){
        TopoDS_Shape shape = find(dim, tag);
        unbind(shape, dim, tag, true);
        bind(shape, dim, tag, true);
      }
    }
    else if(mapModified[k].Extent() == 1){
      if(removeTool){
        // the shape has been replaced by a single shape, keep the same tag
        if(isBound(dim, tag)){
          unbind(find(dim, tag), dim, tag, true); // recursive
        }
        bind(mapModified[k].First(), dim, tag, true); // recursive
        outDimTags.push_back(std::pair<int, int>(dim, tag));
      }
      else{
        toBind.push_back(mapModified[k].First());
      }
    }
    else{
      if(removeTool && isBound(dim, tag)){
        unbind(find(dim, tag), dim, tag, true); // recursive
      }
      TopTools_ListIteratorOfListOfShape it(mapModified[k]);
      for(; it.More(); it.Next())
        toBind.push_back(it.Value());
    }
    {
      TopTools_ListIteratorOfListOfShape it(mapGenerated[k]);
      for(; it.More(); it.Next())
        toBind.push_back(it.Value());
    }
  }

  for(unsigned int i = 0; i < toBind.size(); i++){
    // bind all remaining entities (and only return the new ones, as modified
    // entities can appear as "Modified()" subshapes of both object and tool)
    bind(toBind[i], -1, outDimTags, true, true, true);
  }

  return true;
}

bool OCC_Internals::booleanUnion(int tag,
                                 const std::vector<std::pair<int, int> > &objectDimTags,
                                 const std::vector<std::pair<int, int> > &toolDimTags,
                                 std::vector<std::pair<int, int> > &outDimTags,
                                 bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Union, objectDimTags, toolDimTags,
                         outDimTags, removeObject, removeTool);
}

bool OCC_Internals::booleanIntersection(int tag,
                                        const std::vector<std::pair<int, int> > &objectDimTags,
                                        const std::vector<std::pair<int, int> > &toolDimTags,
                                        std::vector<std::pair<int, int> > &outDimTags,
                                        bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Intersection, objectDimTags, toolDimTags,
                         outDimTags, removeObject, removeTool);
}

bool OCC_Internals::booleanDifference(int tag,
                                      const std::vector<std::pair<int, int> > &objectDimTags,
                                      const std::vector<std::pair<int, int> > &toolDimTags,
                                      std::vector<std::pair<int, int> > &outDimTags,
                                      bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Difference, objectDimTags, toolDimTags,
                         outDimTags, removeObject, removeTool);
}

bool OCC_Internals::booleanFragments(int tag,
                                     const std::vector<std::pair<int, int> > &objectDimTags,
                                     const std::vector<std::pair<int, int> > &toolDimTags,
                                     std::vector<std::pair<int, int> > &outDimTags,
                                     bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Fragments, objectDimTags, toolDimTags,
                         outDimTags, removeObject, removeTool);
}

bool OCC_Internals::_transform(const std::vector<std::pair<int, int> > &inDimTags,
                               BRepBuilderAPI_Transform *tfo,
                               BRepBuilderAPI_GTransform *gtfo)
{
  for(unsigned int i = 0; i < inDimTags.size(); i++){
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(!isBound(dim, tag)){
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                 dim, tag);
      return false;
    }
    TopoDS_Shape object = find(dim, tag), result;
    if(tfo){
      tfo->Perform(object, Standard_False);
      if(!tfo->IsDone()){
        Msg::Error("Could not apply transformation");
        return false;
      }
      result = tfo->Shape();
    }
    else if(gtfo){
      gtfo->Perform(object, Standard_False);
      if(!gtfo->IsDone()){
        Msg::Error("Could not apply transformation");
        return false;
      }
      result = gtfo->Shape();
    }
    unbind(object, dim, tag, true);
    bind(result, dim, tag, true);
  }
  return true;
}

bool OCC_Internals::translate(const std::vector<std::pair<int, int> > &inDimTags,
                              double dx, double dy, double dz)
{
  gp_Trsf t;
  t.SetTranslation(gp_Pnt(0, 0, 0), gp_Pnt(dx, dy, dz));
  BRepBuilderAPI_Transform tfo(t);
  return _transform(inDimTags, &tfo, 0);
}

bool OCC_Internals::rotate(const std::vector<std::pair<int, int> > &inDimTags,
                           double x, double y, double z,
                           double ax, double ay, double az, double angle)
{
  gp_Trsf t;
  gp_Ax1 axisOfRevolution(gp_Pnt(x, y, z), gp_Dir(ax, ay, az));
  t.SetRotation(axisOfRevolution, angle);
  BRepBuilderAPI_Transform tfo(t);
  return _transform(inDimTags, &tfo, 0);
}

bool OCC_Internals::dilate(const std::vector<std::pair<int, int> > &inDimTags,
                           double x, double y, double z,
                           double a, double b, double c)
{
  gp_GTrsf gt;
  gt.SetVectorialPart(gp_Mat(a, 0, 0, 0, b, 0, 0, 0, c));
  gt.SetTranslationPart(gp_XYZ(x * (1 - a), y * (1 - b), z * (1 - c)));
  BRepBuilderAPI_GTransform gtfo(gt);
  return _transform(inDimTags, 0, &gtfo);
}

bool OCC_Internals::symmetry(const std::vector<std::pair<int, int> > &inDimTags,
                             double a, double b, double c, double d)
{
  gp_GTrsf gt;
  double p = (a * a + b * b + c * c);
  if(!p) p = 1e-12;
  double f = -2.0 / p;
  gt.SetVectorialPart(gp_Mat(1 + a * a * f, a * b * f,      a * c * f,
                             a * b * f,     1. + b * b * f, b * c * f,
                             a * c * f,     b * c * f,      1. + c * c * f));
  gt.SetTranslationPart(gp_XYZ(a * d * f, b * d * f, c * d * f));
  BRepBuilderAPI_GTransform gtfo(gt);
  return _transform(inDimTags, 0, &gtfo);
}

bool OCC_Internals::copy(const std::vector<std::pair<int, int> > &inDimTags,
                         std::vector<std::pair<int, int> > &outDimTags)
{
  bool ret = true;
  for(unsigned int i = 0; i < inDimTags.size(); i++){
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(!isBound(dim, tag)){
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                 dim, tag);
      ret = false;
      continue;
    }
    TopoDS_Shape result = BRepBuilderAPI_Copy(find(dim, tag)).Shape();
    int newtag = getMaxTag(dim) + 1;
    bind(result, dim, newtag, true);
    outDimTags.push_back(std::pair<int, int>(dim, newtag));
  }
  return ret;
}

bool OCC_Internals::remove(int dim, int tag, bool recursive)
{
  if(!isBound(dim, tag)){
    Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
               dim, tag);
    return false;
  }
  unbind(find(dim, tag), dim, tag, recursive);
  return true;
}

bool OCC_Internals::remove(const std::vector<std::pair<int, int> > &dimTags,
                           bool recursive)
{
  bool ret = true;
  for(unsigned int i = 0; i < dimTags.size(); i++){
    if(!remove(dimTags[i].first, dimTags[i].second, recursive))
      ret = false;
  }
  return ret;
}

bool OCC_Internals::importShapes(const std::string &fileName, bool highestDimOnly,
                                 std::vector<std::pair<int, int> > &outDimTags,
                                 const std::string &format)
{
  std::vector<std::string> split = SplitFileName(fileName);
  TopoDS_Shape result;
  try{
    if(format == "brep" ||
       split[2] == ".brep" || split[2] == ".BREP"){
      BRep_Builder aBuilder;
      BRepTools::Read(result, fileName.c_str(), aBuilder);
    }
    else if(format == "step" ||
            split[2] == ".step" || split[2] == ".stp" ||
            split[2] == ".STEP" || split[2] == ".STP"){
      STEPControl_Reader reader;
      if(reader.ReadFile(fileName.c_str()) != IFSelect_RetDone){
        Msg::Error("Could not read file '%s'", fileName.c_str());
        return false;
      }
      reader.NbRootsForTransfer();
      reader.TransferRoots();
      result = reader.OneShape();
    }
    else if(format == "iges" ||
            split[2] == ".iges" || split[2] == ".igs" ||
            split[2] == ".IGES" || split[2] == ".IGS"){
      IGESControl_Reader reader;
      if(reader.ReadFile(fileName.c_str()) != IFSelect_RetDone){
        Msg::Error("Could not read file '%s'", fileName.c_str());
        return false;
      }
      reader.NbRootsForTransfer();
      reader.TransferRoots();
      result = reader.OneShape();
    }
    else{
      Msg::Error("Unknown file type '%s'", fileName.c_str());
      return false;
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  BRepTools::Clean(result);
  _healShape(result, CTX::instance()->geom.tolerance,
             CTX::instance()->geom.occFixDegenerated,
             CTX::instance()->geom.occFixSmallEdges,
             CTX::instance()->geom.occFixSmallFaces,
             CTX::instance()->geom.occSewFaces,
             false, CTX::instance()->geom.occScaling);
  bind(result, -1, outDimTags, highestDimOnly, true);
  return true;
}

bool OCC_Internals::importShapes(const TopoDS_Shape *shape, bool highestDimOnly,
                                 std::vector<std::pair<int, int> > &outDimTags)
{
  bind(*shape, -1, outDimTags, highestDimOnly, true);
  return true;
}

bool OCC_Internals::exportShapes(const std::string &fileName,
                                 const std::string &format)
{
  // iterate over all shapes with tags, and import them into the (sub)shape _maps
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagVertex);
  for(; exp0.More(); exp0.Next()) _addShapeToMaps(exp0.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp1(_tagEdge);
  for(; exp1.More(); exp1.Next()) _addShapeToMaps(exp1.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp2(_tagFace);
  for(; exp2.More(); exp2.Next()) _addShapeToMaps(exp2.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp3(_tagSolid);
  for(; exp3.More(); exp3.Next()) _addShapeToMaps(exp3.Value());

  // build a single compound shape
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(int i = 1; i <= _vmap.Extent(); i++) b.Add(c, _vmap(i));
  for(int i = 1; i <= _emap.Extent(); i++) b.Add(c, _emap(i));
  for(int i = 1; i <= _wmap.Extent(); i++) b.Add(c, _wmap(i));
  for(int i = 1; i <= _fmap.Extent(); i++) b.Add(c, _fmap(i));
  for(int i = 1; i <= _shmap.Extent(); i++) b.Add(c, _shmap(i));
  for(int i = 1; i <= _somap.Extent(); i++) b.Add(c, _somap(i));

  std::vector<std::string> split = SplitFileName(fileName);

  try {
    if(format == "brep" ||
       split[2] == ".brep" || split[2] == ".BREP"){
      BRepTools::Write(c, fileName.c_str());
    }
    else if(format == "step" ||
            split[2] == ".step" || split[2] == ".stp" ||
            split[2] == ".STEP" || split[2] == ".STP"){
      STEPControl_Writer writer;
      if(writer.Transfer(c, STEPControl_ManifoldSolidBrep) == IFSelect_RetDone){
        if(writer.Write(fileName.c_str()) != IFSelect_RetDone){
          Msg::Error("Could not create file '%s'", fileName.c_str());
          return false;
        }
      }
      else{
        Msg::Error("Could not create STEP data");
        return false;
      }
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

void OCC_Internals::setMeshSize(int dim, int tag, double size)
{
  if(dim != 0) return;
  if(_tagVertex.IsBound(tag)){
    _meshAttr.Bind(_tagVertex.Find(tag), meshAttr(size));
  }
}

bool OCC_Internals::getVertex(int tag, double &x, double &y, double &z)
{
  if(_tagVertex.IsBound(tag)){
    gp_Pnt pnt = BRep_Tool::Pnt(TopoDS::Vertex(_tagVertex.Find(tag)));
    x = pnt.X();
    y = pnt.Y();
    z = pnt.Z();
    return true;
  }
  return false;
}

void OCC_Internals::synchronize(GModel *model)
{
  Msg::Debug("Syncing OCC_Internals with GModel");

  // make sure to remove from GModel all entities that have been deleted in
  // OCC_Internals since the last synchronization
  std::vector<std::pair<int, int> > toRemove;
  toRemove.insert(toRemove.end(), _toRemove.begin(), _toRemove.end());
  Msg::Debug("Sync is removing %d model entities", toRemove.size());
  model->remove(toRemove);
  _toRemove.clear();

  // iterate over all shapes with tags, and import them into the (sub)shape _maps
  _somap.Clear();
  _shmap.Clear();
  _fmap.Clear();
  _wmap.Clear();
  _emap.Clear();
  _vmap.Clear();
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagVertex);
  for(; exp0.More(); exp0.Next()) _addShapeToMaps(exp0.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp1(_tagEdge);
  for(; exp1.More(); exp1.Next()) _addShapeToMaps(exp1.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp2(_tagFace);
  for(; exp2.More(); exp2.Next()) _addShapeToMaps(exp2.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp3(_tagSolid);
  for(; exp3.More(); exp3.Next()) _addShapeToMaps(exp3.Value());

  // import all shapes in _maps into the GModel, preserving all explicit tags
  int vTagMax = std::max(model->getMaxElementaryNumber(0), getMaxTag(0));
  int eTagMax = std::max(model->getMaxElementaryNumber(1), getMaxTag(1));
  int fTagMax = std::max(model->getMaxElementaryNumber(2), getMaxTag(2));
  int rTagMax = std::max(model->getMaxElementaryNumber(3), getMaxTag(3));
  for(int i = 1; i <= _vmap.Extent(); i++){
    TopoDS_Vertex vertex = TopoDS::Vertex(_vmap(i));
    if(!getVertexForOCCShape(model, vertex)){
      int tag;
      if(_vertexTag.IsBound(vertex))
        tag = _vertexTag.Find(vertex);
      else{
        tag = ++vTagMax;
        Msg::Info("Binding unbound OpenCASCADE vertex to tag %d", tag);
      }
      double lc = MAX_LC;
      if(_meshAttr.IsBound(vertex)){
        meshAttr m = _meshAttr.Find(vertex);
        lc = m.size;
      }
      OCCVertex *occv = new OCCVertex(model, tag, vertex, lc);
      model->add(occv);
    }
  }
  for(int i = 1; i <= _emap.Extent(); i++){
    TopoDS_Edge edge = TopoDS::Edge(_emap(i));
    if(!getEdgeForOCCShape(model, edge)){
      GVertex *v1 = getVertexForOCCShape(model, TopExp::FirstVertex(edge));
      GVertex *v2 = getVertexForOCCShape(model, TopExp::LastVertex(edge));
      int tag;
      if(_edgeTag.IsBound(edge))
        tag = _edgeTag.Find(edge);
      else{
        tag = ++eTagMax;
        Msg::Info("Binding unbound OpenCASCADE edge to tag %d", tag);
      }
      OCCEdge *occe = new OCCEdge(model, edge, tag, v1, v2);
      model->add(occe);
      _copyExtrudedMeshAttr(edge, occe);
    }
  }
  for(int i = 1; i <= _fmap.Extent(); i++){
    TopoDS_Face face = TopoDS::Face(_fmap(i));
    if(!getFaceForOCCShape(model, face)){
      int tag;
      if(_faceTag.IsBound(face))
        tag = _faceTag.Find(face);
      else{
        tag = ++fTagMax;
        Msg::Info("Binding unbound OpenCASCADE face to tag %d", tag);
      }
      OCCFace *occf = new OCCFace(model, face, tag);
      model->add(occf);
      _copyExtrudedMeshAttr(face, occf);
    }
  }
  for(int i = 1; i <= _somap.Extent(); i++){
    TopoDS_Solid region = TopoDS::Solid(_somap(i));
    if(!getRegionForOCCShape(model, region)){
      int tag;
      if(_solidTag.IsBound(region))
        tag = _solidTag(region);
      else{
        tag = ++rTagMax;
        Msg::Info("Binding unbound OpenCASCADE solid to tag %d", tag);
      }
      OCCRegion *occr = new OCCRegion(model, region, tag);
      model->add(occr);
      _copyExtrudedMeshAttr(region, occr);
    }
  }

  Msg::Debug("GModel imported:");
  Msg::Debug("%d vertices", model->getNumVertices());
  Msg::Debug("%d edges", model->getNumEdges());
  Msg::Debug("%d faces", model->getNumFaces());
  Msg::Debug("%d regions", model->getNumRegions());
  _changed = false;
}

GVertex *OCC_Internals::getVertexForOCCShape(GModel *model, TopoDS_Vertex toFind)
{
  if(_vertexTag.IsBound(toFind))
    return model->getVertexByTag(_vertexTag.Find(toFind));
  return 0;
}

GEdge *OCC_Internals::getEdgeForOCCShape(GModel *model, TopoDS_Edge toFind)
{
  if(_edgeTag.IsBound(toFind))
    return model->getEdgeByTag(_edgeTag.Find(toFind));
  return 0;
}

GFace *OCC_Internals::getFaceForOCCShape(GModel *model, TopoDS_Face toFind)
{
  if(_faceTag.IsBound(toFind))
    return model->getFaceByTag(_faceTag.Find(toFind));
  return 0;
}

GRegion *OCC_Internals::getRegionForOCCShape(GModel *model, TopoDS_Solid toFind)
{
  if(_solidTag.IsBound(toFind))
    return model->getRegionByTag(_solidTag.Find(toFind));
  return 0;
}

void OCC_Internals::_addShapeToMaps(TopoDS_Shape shape)
{
  // Solids
  TopExp_Explorer exp0, exp1, exp2, exp3, exp4, exp5;
  for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
    TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
    if(_somap.FindIndex(solid) < 1){
      _somap.Add(solid);
      for(exp1.Init(solid, TopAbs_SHELL); exp1.More(); exp1.Next()){
        TopoDS_Shell shell = TopoDS::Shell(exp1.Current());
        if(_shmap.FindIndex(shell) < 1){
          _shmap.Add(shell);

          for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()){
            TopoDS_Face face = TopoDS::Face(exp2.Current());
            if(_fmap.FindIndex(face) < 1){
              _fmap.Add(face);

              for(exp3.Init(face.Oriented(TopAbs_FORWARD), TopAbs_WIRE);
                  exp3.More(); exp3.Next()){
              //for(exp3.Init(face, TopAbs_WIRE); exp3.More(); exp3.Next()){
                TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
                if(_wmap.FindIndex(wire) < 1){
                  _wmap.Add(wire);

                  for(exp4.Init(wire, TopAbs_EDGE); exp4.More();
                      exp4.Next()){
                    TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
                    if(_emap.FindIndex(edge) < 1){
                      _emap.Add(edge);

                      for(exp5.Init(edge, TopAbs_VERTEX); exp5.More();
                          exp5.Next()){
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

          for(exp3.Init(face, TopAbs_WIRE); exp3.More(); exp3.Next()){
            TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
            if(_wmap.FindIndex(wire) < 1){
              _wmap.Add(wire);

              for(exp4.Init(wire, TopAbs_EDGE); exp4.More(); exp4.Next()){
                TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
                if(_emap.FindIndex(edge) < 1){
                  _emap.Add(edge);

                  for(exp5.Init(edge, TopAbs_VERTEX); exp5.More(); exp5.Next()){
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
      _fmap.Add(face);

      for(exp3.Init(face, TopAbs_WIRE); exp3.More(); exp3.Next()){
        TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
        if(_wmap.FindIndex(wire) < 1){
          _wmap.Add(wire);

          for(exp4.Init(wire, TopAbs_EDGE); exp4.More(); exp4.Next()){
            TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
            if(_emap.FindIndex(edge) < 1){
              _emap.Add(edge);

              for(exp5.Init(edge, TopAbs_VERTEX); exp5.More(); exp5.Next()){
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

      for(exp4.Init(wire, TopAbs_EDGE); exp4.More(); exp4.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
        if(_emap.FindIndex(edge) < 1){
          _emap.Add(edge);

          for(exp5.Init(edge, TopAbs_VERTEX); exp5.More(); exp5.Next()){
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
      _emap.Add(edge);

      for(exp5.Init(edge, TopAbs_VERTEX); exp5.More(); exp5.Next()){
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
      _vmap.Add(vertex);
    }
  }
}

void OCC_Internals::_healShape(TopoDS_Shape &myshape, double tolerance,
                               bool fixdegenerated, bool fixsmalledges,
                               bool fixspotstripfaces, bool sewfaces,
                               bool makesolids, double scaling)
{
  if(scaling != 1.0){
    Msg::Info("Scaling geometry by factor %g", scaling);
    gp_Trsf t;
    t.SetScaleFactor(scaling);
    BRepBuilderAPI_Transform trsf(myshape, t);
    myshape = trsf.Shape();
  }

  if(!fixdegenerated && !fixsmalledges && !fixspotstripfaces &&
     !sewfaces && !makesolids) return;

  Msg::Info("Starting shape healing (tolerance: %g)", tolerance);

  _somap.Clear();
  _shmap.Clear();
  _fmap.Clear();
  _wmap.Clear();
  _emap.Clear();
  _vmap.Clear();
  _addShapeToMaps(myshape);

  TopExp_Explorer exp0, exp1;
  int nrc = 0, nrcs = 0;
  int nrso = _somap.Extent(), nrsh = _shmap.Extent(), nrf = _fmap.Extent();
  int nrw = _wmap.Extent(), nre = _emap.Extent(), nrv = _vmap.Extent();
  for(exp0.Init(myshape, TopAbs_COMPOUND); exp0.More(); exp0.Next()) nrc++;
  for(exp0.Init(myshape, TopAbs_COMPSOLID); exp0.More(); exp0.Next()) nrcs++;

  double surfacecont = 0;
  for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    GProp_GProps system;
    BRepGProp::SurfaceProperties(face, system);
    surfacecont += system.Mass();
  }

  if(fixdegenerated){
    Msg::Info("- fix degenerated edges and faces");

    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(myshape);
      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge))
          rebuild->Remove(edge, false);
      }
      myshape = rebuild->Apply(myshape);
    }
    _somap.Clear();
    _shmap.Clear();
    _fmap.Clear();
    _wmap.Clear();
    _emap.Clear();
    _vmap.Clear();
    _addShapeToMaps(myshape);

    {
      Handle(ShapeFix_Face) sff;
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(myshape);

      for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()){
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
      myshape = rebuild->Apply(myshape);
    }

    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(myshape);
      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge))
          rebuild->Remove(edge, false);
      }
      myshape = rebuild->Apply(myshape);
    }
  }

  if(fixsmalledges){
    Msg::Info("- fixing small edges");

    Handle(ShapeFix_Wire) sfw;
    Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
    rebuild->Apply(myshape);

    for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()){
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

    myshape = rebuild->Apply(myshape);
    _somap.Clear();
    _shmap.Clear();
    _fmap.Clear();
    _wmap.Clear();
    _emap.Clear();
    _vmap.Clear();
    _addShapeToMaps(myshape);

    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(myshape);

      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()){
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
      myshape = rebuild->Apply(myshape);
    }

    {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(myshape);
      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()){
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge) )
          rebuild->Remove(edge, false);
      }
      myshape = rebuild->Apply(myshape);
    }

    Handle(ShapeFix_Wireframe) sfwf = new ShapeFix_Wireframe;
    sfwf->SetPrecision(tolerance);
    sfwf->Load(myshape);
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

    myshape = sfwf->Shape();
  }

  if(fixspotstripfaces){
    Msg::Info("- fixing spot and strip faces");
    Handle(ShapeFix_FixSmallFace) sffsm = new ShapeFix_FixSmallFace();
    sffsm->Init(myshape);
    sffsm->SetPrecision(tolerance);
    sffsm->Perform();

    myshape = sffsm->FixShape();
  }

  if(sewfaces){
    Msg::Info("- sewing faces");

    BRepOffsetAPI_Sewing sewedObj(tolerance);

    for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()){
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      sewedObj.Add(face);
    }

    sewedObj.Perform();

    if(!sewedObj.SewedShape().IsNull())
      myshape = sewedObj.SewedShape();
    else
      Msg::Info("  not possible");
  }

  {
    Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
    rebuild->Apply(myshape);
    for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()){
      TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
      if(BRep_Tool::Degenerated(edge))
        rebuild->Remove(edge, false);
    }
    myshape = rebuild->Apply(myshape);
  }

  if(makesolids){
    Msg::Info("- making solids");

    BRepBuilderAPI_MakeSolid ms;
    int count = 0;
    for(exp0.Init(myshape, TopAbs_SHELL); exp0.More(); exp0.Next()){
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
        myshape = sfs->Shape();

        for(exp0.Init(myshape, TopAbs_SOLID); exp0.More(); exp0.Next()){
          TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
          TopoDS_Solid newsolid = solid;
          BRepLib::OrientClosedSolid(newsolid);
          Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
          // rebuild->Apply(myshape);
          rebuild->Replace(solid, newsolid, Standard_False);
          TopoDS_Shape newshape = rebuild->Apply(myshape, TopAbs_COMPSOLID);//, 1);
          // TopoDS_Shape newshape = rebuild->Apply(myshape);
          myshape = newshape;
        }
      }
      else
        Msg::Info("  not possible");
    }
  }

  double newsurfacecont = 0;
  for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    GProp_GProps system;
    BRepGProp::SurfaceProperties(face, system);
    newsurfacecont += system.Mass();
  }

  _somap.Clear();
  _shmap.Clear();
  _fmap.Clear();
  _wmap.Clear();
  _emap.Clear();
  _vmap.Clear();
  _addShapeToMaps(myshape);
  int nnrc = 0, nnrcs = 0;
  int nnrso = _somap.Extent(), nnrsh = _shmap.Extent(), nnrf = _fmap.Extent();
  int nnrw = _wmap.Extent(), nnre = _emap.Extent(), nnrv = _vmap.Extent();
  for(exp0.Init(myshape, TopAbs_COMPOUND); exp0.More(); exp0.Next()) nnrc++;
  for(exp0.Init(myshape, TopAbs_COMPSOLID); exp0.More(); exp0.Next()) nnrcs++;

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

bool OCC_Internals::_makeFaceSTL(TopoDS_Face s,
                                 std::vector<SPoint2> *verticesUV,
                                 std::vector<SPoint3> *verticesXYZ,
                                 std::vector<SVector3> *normals,
                                 std::vector<int> &triangles)
{
  Bnd_Box aBox;
  BRepBndLib::Add(s, aBox);

#if (OCC_VERSION_MAJOR >= 7)
  BRepMesh_FastDiscret::Parameters parameters;
  parameters.Deflection = 0.1;
  parameters.Angle = 0.35;
  parameters.Relative = Standard_True;
  BRepMesh_FastDiscret aMesher(aBox, parameters);
#else
  BRepMesh_FastDiscret aMesher(0.1, 0.35, aBox, Standard_False, Standard_False,
                               Standard_True, Standard_False);
#endif
  aMesher.Perform(s);

  TopLoc_Location loc;
  Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(s, loc);

  if(triangulation.IsNull())
    return false;

  if(verticesUV && !triangulation->HasUVNodes())
    return false;

  int start = 0;
  if(verticesUV) start = verticesUV->size();
  if(verticesXYZ) start = verticesXYZ->size();
  for(int i = 1; i <= triangulation->NbNodes(); i++){
    gp_Pnt2d p = (triangulation->UVNodes())(i);
    if(verticesUV){
      verticesUV->push_back(SPoint2(p.X(), p.Y()));
    }
    if(verticesXYZ){
      gp_Pnt pp = (triangulation->Nodes())(i);
      verticesXYZ->push_back(SPoint3(pp.X(), pp.Y(), pp.Z()));
    }
    if(normals){
      Handle(Geom_Surface) sur = BRep_Tool::Surface(s);
      gp_Pnt pnt;
      gp_Vec du, dv;
      sur->D1(p.X(), p.Y(), pnt, du, dv);
      SVector3 t1(du.X(), du.Y(), du.Z());
      SVector3 t2(dv.X(), dv.Y(), dv.Z());
      SVector3 n(crossprod(t1, t2));
      n.normalize();
      if(s.Orientation() == TopAbs_REVERSED) return n * (-1.);
      normals->push_back(n);
    }
  }
  for(int i = 1; i <= triangulation->NbTriangles(); i++){
    Poly_Triangle triangle = (triangulation->Triangles())(i);
    int p1, p2, p3;
    triangle.Get(p1, p2, p3);
    triangles.push_back(start + p1 - 1);
    triangles.push_back(start + p2 - 1);
    triangles.push_back(start + p3 - 1);
  }
  return true;
}

bool OCC_Internals::makeFaceSTL(TopoDS_Face s, std::vector<SPoint2> &vertices,
                                std::vector<int> &triangles)
{
  return _makeFaceSTL(s, &vertices, 0, 0, triangles);
}

bool OCC_Internals::makeFaceSTL(TopoDS_Face s, std::vector<SPoint3> &vertices,
                                std::vector<SVector3> &normals, std::vector<int> &triangles)
{
  return _makeFaceSTL(s, 0, &vertices, &normals, triangles);
}

bool OCC_Internals::makeSolidSTL(TopoDS_Solid s, std::vector<SPoint3> &vertices,
                                 std::vector<SVector3> &normals, std::vector<int> &triangles)
{
  bool ret = true;
  TopExp_Explorer exp0;
  for(exp0.Init(s, TopAbs_FACE); exp0.More(); exp0.Next()){
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    bool tmp = _makeFaceSTL(TopoDS::Face(face.Oriented(TopAbs_FORWARD)),
                            0, &vertices, &normals, triangles);
    if(!tmp) ret = false;
  }
  return ret;
}

bool OCC_Internals::makeRectangleSTL(double x, double y, double z, double dx, double dy,
                                     double roundedRadius, std::vector<SPoint3> &vertices,
                                     std::vector<SVector3> &normals, std::vector<int> &triangles)
{
  TopoDS_Face result;
  if(!_makeRectangle(result, x, y, z, dx, dy, roundedRadius))
    return false;
  if(!makeFaceSTL(result, vertices, normals, triangles))
    return false;
  return true;
}

bool OCC_Internals::makeDiskSTL(double xc, double yc, double zc, double rx, double ry,
                                std::vector<SPoint3> &vertices, std::vector<SVector3> &normals,
                                std::vector<int> &triangles)
{
  TopoDS_Face result;
  if(!_makeDisk(result, xc, yc, zc, rx, ry))
    return false;
  if(!makeFaceSTL(result, vertices, normals, triangles))
    return false;
  return true;
}

bool OCC_Internals::makeSphereSTL(double xc, double yc, double zc, double radius, double angle1,
                                  double angle2, double angle3, std::vector<SPoint3> &vertices,
                                  std::vector<SVector3> &normals, std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!_makeSphere(result, xc, yc, zc, radius, angle1, angle2, angle3))
    return false;
  if(!makeSolidSTL(result, vertices, normals, triangles))
    return false;
  return true;
}

bool OCC_Internals::makeBlockSTL(double x, double y, double z, double dx, double dy, double dz,
                                 std::vector<SPoint3> &vertices, std::vector<SVector3> &normals,
                                 std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!_makeBlock(result, x, y, z, dx, dy, dz))
    return false;
  if(!makeSolidSTL(result, vertices, normals, triangles))
    return false;
  return true;
}

bool OCC_Internals::makeCylinderSTL(double x, double y, double z, double dx, double dy, double dz,
                                    double r, double angle, std::vector<SPoint3> &vertices,
                                    std::vector<SVector3> &normals, std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!_makeCylinder(result, x, y, z, dx, dy, dz, r, angle))
    return false;
  if(!makeSolidSTL(result, vertices, normals, triangles))
    return false;
  return true;
}

bool OCC_Internals::makeConeSTL(double x, double y, double z, double dx, double dy, double dz,
                                double r1, double r2, double angle, std::vector<SPoint3> &vertices,
                                std::vector<SVector3> &normals, std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!_makeCone(result, x, y, z, dx, dy, dz, r1, r2, angle))
    return false;
  if(!makeSolidSTL(result, vertices, normals, triangles))
    return false;
  return true;
}

bool OCC_Internals::makeWedgeSTL(double x, double y, double z, double dx, double dy, double dz,
                                 double ltx, std::vector<SPoint3> &vertices,
                                 std::vector<SVector3> &normals, std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!_makeWedge(result, x, y, z, dx, dy, dz, ltx))
    return false;
  if(!makeSolidSTL(result, vertices, normals, triangles))
    return false;
  return true;
}

bool OCC_Internals::makeTorusSTL(double x, double y, double z, double r1, double r2, double angle,
                                 std::vector<SPoint3> &vertices, std::vector<SVector3> &normals,
                                 std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!_makeTorus(result, x, y, z, r1, r2, angle))
    return false;
  if(!makeSolidSTL(result, vertices, normals, triangles))
    return false;
  return true;
}

// FIXME ***************** BEGIN WILL BE REMOVED ************************

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

void OCC_Internals::buildLists()
{
  _somap.Clear();
  _shmap.Clear();
  _fmap.Clear();
  _wmap.Clear();
  _emap.Clear();
  _vmap.Clear();
  _addShapeToMaps(_shape);
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
      if(occ) _addShapeToMaps(occ->getTopoDS_Shape());
    }
  }
  for (GModel::fiter it = gm->firstFace(); it != gm->lastFace() ; ++it){
    if ((*it)->getNativeType() == GEntity::OpenCascadeModel){
      OCCFace *occ = static_cast<OCCFace*> (*it);
      if(occ) _addShapeToMaps(occ->getTopoDS_Face());
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

GVertex *OCC_Internals::addVertexToModel(GModel *model, TopoDS_Vertex vertex)
{
  GVertex *gv = getVertexForOCCShape(model, vertex);
  if(gv) return gv;
  _addShapeToMaps(vertex);
  buildShapeFromLists(vertex);
  buildGModel(model);
  return getVertexForOCCShape(model, vertex);
}

GEdge *OCC_Internals::addEdgeToModel(GModel *model, TopoDS_Edge edge)
{
  GEdge *ge = getEdgeForOCCShape(model, edge);
  if(ge) return ge;
  _addShapeToMaps(edge);
  buildShapeFromLists(edge);
  buildGModel(model);
  return getEdgeForOCCShape(model, edge);
}

GFace* OCC_Internals::addFaceToModel(GModel *model, TopoDS_Face face)
{
  GFace *gf = getFaceForOCCShape(model, face);
  if(gf) return gf;
  _addShapeToMaps(face);
  buildShapeFromLists(face);
  buildGModel(model);
  return getFaceForOCCShape(model, face);
}

GRegion* OCC_Internals::addRegionToModel(GModel *model, TopoDS_Solid region)
{
  GRegion *gr = getRegionForOCCShape(model, region);
  if(gr) return gr;

  //   FIXME THE PREVIOUS IMPLEMENTATION WAS BETTER FOR SOME USERS :-)
  buildShapeFromLists(region);
  model->destroy();
  buildLists();
  buildGModel(model);
  return getRegionForOCCShape(model, region);
  //  _addShapeToMaps(region);
  //  buildShapeFromLists(region);
  //  buildGModel(model);
  //  return getRegionForOCCShape(model, region);
}

void OCC_Internals::buildGModel(GModel *model)
{
  // building geom vertices
  int numv = model->getMaxElementaryNumber(0) + 1;
  for(int i = 1; i <= _vmap.Extent(); i++){
    TopoDS_Vertex vertex = TopoDS::Vertex(_vmap(i));
    if(!getVertexForOCCShape(model, vertex)){
      model->add(new OCCVertex(model, numv, vertex));
      numv++;
    }
  }

  // building geom edges
  int nume = model->getMaxElementaryNumber(1) + 1;
  for(int i = 1; i <= _emap.Extent(); i++){
    int i1 = _vmap.FindIndex(TopExp::FirstVertex(TopoDS::Edge(_emap(i))));
    int i2 = _vmap.FindIndex(TopExp::LastVertex(TopoDS::Edge(_emap(i))));
    if(!getEdgeForOCCShape(model, TopoDS::Edge(_emap(i)))){
      GVertex *v1 = getVertexForOCCShape(model, TopoDS::Vertex(_vmap(i1)));
      GVertex *v2 = getVertexForOCCShape(model, TopoDS::Vertex(_vmap(i2)));
      model->add(new OCCEdge(model, TopoDS::Edge(_emap(i)), nume, v1, v2));
      nume++;
    }
  }

  // building geom faces
  int numf = model->getMaxElementaryNumber(2) + 1;
  for(int i = 1; i <= _fmap.Extent(); i++){
    if(!getFaceForOCCShape(model, TopoDS::Face(_fmap(i)))){
      model->add(new OCCFace(model, TopoDS::Face(_fmap(i)), numf));
      numf++;
    }
  }

  // building geom regions
  int numr = model->getMaxElementaryNumber(3) + 1;
  for(int i = 1; i <= _somap.Extent(); i++){
    if(!getRegionForOCCShape(model, TopoDS::Solid(_somap(i)))){
      model->add(new OCCRegion(model, TopoDS::Solid(_somap(i)), numr));
      numr++;
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
  case OCC_Internals::Difference :
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
  case OCC_Internals::Union :
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

// FIXME ***************** END OF WILL BE REMOVED ************************

#endif

void GModel::createOCCInternals()
{
  if(_occ_internals) delete _occ_internals;
  _occ_internals = new OCC_Internals;
}

void GModel::_deleteOCCInternals()
{
  if(_occ_internals) delete _occ_internals;
  _occ_internals = 0;
}

void GModel::_resetOCCInternals()
{
  if(!_occ_internals) return;
  _occ_internals->reset();
}

int GModel::readOCCBREP(const std::string &fn)
{
  if(!_occ_internals)
    _occ_internals = new OCC_Internals;
  std::vector<std::pair<int, int> > outDimTags;
  _occ_internals->importShapes(fn, false, outDimTags, "brep");
  _occ_internals->synchronize(this);
  snapVertices();
  return 1;
}

int GModel::readOCCSTEP(const std::string &fn)
{
  if(!_occ_internals)
    _occ_internals = new OCC_Internals;
  std::vector<std::pair<int, int> > outDimTags;
  _occ_internals->importShapes(fn, false, outDimTags, "step");
  _occ_internals->synchronize(this);
  return 1;
}

int GModel::readOCCIGES(const std::string &fn)
{
  if(!_occ_internals)
    _occ_internals = new OCC_Internals;
  std::vector<std::pair<int, int> > outDimTags;
  _occ_internals->importShapes(fn, false, outDimTags, "iges");
  _occ_internals->synchronize(this);
  return 1;
}

int GModel::writeOCCBREP(const std::string &fn)
{
  if(!_occ_internals){
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  _occ_internals->exportShapes(fn, "brep");
  return 1;
}

int GModel::writeOCCSTEP(const std::string &fn)
{
  if(!_occ_internals){
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  _occ_internals->exportShapes(fn, "step");
  return 1;
}

int GModel::importOCCShape(const void *shape)
{
  if(!_occ_internals)
    _occ_internals = new OCC_Internals;
#if defined(HAVE_OCC)
  std::vector<std::pair<int, int> > outDimTags;
  _occ_internals->importShapes((TopoDS_Shape*)shape, false, outDimTags);
#else
  Msg::Error("Gmsh requires OpenCASCADE to import TopoDS_Shape");
#endif
  _occ_internals->synchronize(this);
  snapVertices();
  SetBoundingBox();
  return 1;
}

GVertex* GModel::getVertexForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
#if defined(HAVE_OCC)
  return _occ_internals->getVertexForOCCShape(this, *(TopoDS_Vertex*)shape);
#else
  return 0;
#endif
}

GEdge* GModel::getEdgeForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
#if defined(HAVE_OCC)
  return _occ_internals->getEdgeForOCCShape(this, *(TopoDS_Edge*)shape);
#else
  return 0;
#endif
}

GFace* GModel::getFaceForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
#if defined(HAVE_OCC)
  return _occ_internals->getFaceForOCCShape(this, *(TopoDS_Face*)shape);
#else
  return 0;
#endif
}

GRegion* GModel::getRegionForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
#if defined(HAVE_OCC)
  return _occ_internals->getRegionForOCCShape(this, *(TopoDS_Solid*)shape);
#else
  return 0;
#endif
}
