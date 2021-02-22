// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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

#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Section.hxx>
#include <BRepBndLib.hxx>
#include <BRepBuilderAPI_Copy.hxx>
#include <BRepBuilderAPI_GTransform.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeShell.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepCheck_Analyzer.hxx>
#include <BRepFill_CurveConstraint.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepGProp.hxx>
#include <BRepLib.hxx>
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
#include <Bnd_Box.hxx>
#include <ElCLib.hxx>
#include <GProp_GProps.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <GeomFill_BSplineCurves.hxx>
#include <GeomFill_BezierCurves.hxx>
#include <GeomProjLib.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_Plane.hxx>
#include <Geom_Surface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <IGESControl_Reader.hxx>
#include <IGESControl_Writer.hxx>
#include <Interface_Static.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Triangle.hxx>
#include <Poly_Triangulation.hxx>
#include <ProjLib_ProjectedCurve.hxx>
#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeFix_FixSmallFace.hxx>
#include <ShapeFix_Shape.hxx>
#include <ShapeFix_Wireframe.hxx>
#include <ShapeUpgrade_UnifySameDomain.hxx>
#include <Standard_Version.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools_DataMapIteratorOfDataMapOfIntegerShape.hxx>
#include <TopTools_DataMapIteratorOfDataMapOfShapeInteger.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopoDS.hxx>
#include <gce_MakeCirc.hxx>
#include <gce_MakeElips.hxx>
#include <gce_MakePln.hxx>
#include <numeric>
#include <utility>

#include "OCCAttributes.h"

#if OCC_VERSION_HEX < 0x060900
#error "Gmsh requires OpenCASCADE >= 6.9"
#endif

#if OCC_VERSION_HEX > 0x070300
#include <BRepMesh_IncrementalMesh.hxx>
#else
#include <BRepMesh_FastDiscret.hxx>
#endif

#if defined(HAVE_OCC_CAF)
#include <IGESCAFControl_Reader.hxx>
#include <Quantity_Color.hxx>
#include <STEPCAFControl_Reader.hxx>
#include <TDF_ChildIterator.hxx>
#include <TDF_Tool.hxx>
#include <TDataStd_Name.hxx>
#include <TDocStd_Document.hxx>
#include <XCAFApp_Application.hxx>
#include <XCAFDoc_Color.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <XCAFDoc_Location.hxx>
#include <XCAFDoc_MaterialTool.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#endif

OCC_Internals::OCC_Internals()
{
  for(int i = 0; i < 6; i++) _maxTag[i] = 0;
  _changed = true;
  _attributes = new OCCAttributesRTree(CTX::instance()->geom.tolerance);
}

OCC_Internals::~OCC_Internals() { delete _attributes; }

void OCC_Internals::reset()
{
  _attributes->clear();
  _somap.Clear();
  _shmap.Clear();
  _fmap.Clear();
  _wmap.Clear();
  _emap.Clear();
  _vmap.Clear();
  unbind();
}

void OCC_Internals::setMaxTag(int dim, int val)
{
  if(dim < -2 || dim > 3) return;
  _maxTag[dim + 2] = std::max(_maxTag[dim + 2], val);
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
  switch(dim) {
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

void OCC_Internals::bind(const TopoDS_Vertex &vertex, int tag, bool recursive)
{
  if(vertex.IsNull()) return;
  if(_vertexTag.IsBound(vertex)) {
    if(_vertexTag.Find(vertex) != tag) {
      Msg::Info("Cannot bind existing OpenCASCADE point %d to second tag %d",
                _vertexTag.Find(vertex), tag);
    }
  }
  else {
    if(_tagVertex.IsBound(tag)) {
      // this leaves the old vertex bound in _vertexTag, but we cannot remove it
      Msg::Info("Rebinding OpenCASCADE point %d", tag);
    }
    _vertexTag.Bind(vertex, tag);
    _tagVertex.Bind(tag, vertex);
    setMaxTag(0, tag);
    _changed = true;
    _attributes->insert(new OCCAttributes(0, vertex));
  }
}

void OCC_Internals::bind(const TopoDS_Edge &edge, int tag, bool recursive)
{
  if(edge.IsNull()) return;
  if(_edgeTag.IsBound(edge)) {
    if(_edgeTag.Find(edge) != tag) {
      Msg::Info("Cannot bind existing OpenCASCADE curve %d to second tag %d",
                _edgeTag.Find(edge), tag);
    }
  }
  else {
    if(_tagEdge.IsBound(tag)) {
      // this leaves the old edge bound in _edgeTag, but we cannot remove it
      Msg::Info("Rebinding OpenCASCADE curve %d", tag);
    }
    _edgeTag.Bind(edge, tag);
    _tagEdge.Bind(tag, edge);
    setMaxTag(1, tag);
    _changed = true;
    _attributes->insert(new OCCAttributes(1, edge));
  }
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(edge, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
      TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
      if(!_vertexTag.IsBound(vertex)) {
        int t = getMaxTag(0) + 1;
        bind(vertex, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(const TopoDS_Wire &wire, int tag, bool recursive)
{
  if(wire.IsNull()) return;
  if(_wireTag.IsBound(wire)) {
    if(_wireTag.Find(wire) != tag) {
      Msg::Info("Cannot bind existing OpenCASCADE wire %d to second tag %d",
                _wireTag.Find(wire), tag);
    }
  }
  else {
    if(_tagWire.IsBound(tag)) {
      // this leaves the old wire bound in _wireTag, but we cannot remove it
      Msg::Info("Rebinding OpenCASCADE wire %d", tag);
    }
    _wireTag.Bind(wire, tag);
    _tagWire.Bind(tag, wire);
    setMaxTag(-1, tag);
    _changed = true;
  }
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(wire, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(!_edgeTag.IsBound(edge)) {
        int t = getMaxTag(1) + 1;
        bind(edge, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(const TopoDS_Face &face, int tag, bool recursive)
{
  if(face.IsNull()) return;
  if(_faceTag.IsBound(face)) {
    if(_faceTag.Find(face) != tag) {
      Msg::Info("Cannot bind existing OpenCASCADE surface %d to second tag %d",
                _faceTag.Find(face), tag);
    }
  }
  else {
    if(_tagFace.IsBound(tag)) {
      // this leaves the old face bound in _faceTag, but we cannot remove it
      Msg::Info("Rebinding OpenCASCADE surface %d", tag);
    }
    _faceTag.Bind(face, tag);
    _tagFace.Bind(tag, face);
    setMaxTag(2, tag);
    _changed = true;
    _attributes->insert(new OCCAttributes(2, face));
  }
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(face, TopAbs_WIRE); exp0.More(); exp0.Next()) {
      TopoDS_Wire wire = TopoDS::Wire(exp0.Current());
      if(!_wireTag.IsBound(wire)) {
        int t = getMaxTag(-1) + 1;
        bind(wire, t, recursive);
      }
    }
    for(exp0.Init(face, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(!_edgeTag.IsBound(edge)) {
        int t = getMaxTag(1) + 1;
        bind(edge, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(const TopoDS_Shell &shell, int tag, bool recursive)
{
  if(shell.IsNull()) return;
  if(_shellTag.IsBound(shell)) {
    if(_shellTag.Find(shell) != tag) {
      Msg::Info("Cannot bind existing OpenCASCADE shell %d to second tag %d",
                _shellTag.Find(shell), tag);
    }
  }
  else {
    if(_tagShell.IsBound(tag)) {
      // this leaves the old shell bound in _faceTag, but we cannot remove it
      Msg::Info("Rebinding OpenCASCADE shell %d", tag);
    }
    _shellTag.Bind(shell, tag);
    _tagShell.Bind(tag, shell);
    setMaxTag(-2, tag);
    _changed = true;
  }
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(shell, TopAbs_FACE); exp0.More(); exp0.Next()) {
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(!_faceTag.IsBound(face)) {
        int t = getMaxTag(2) + 1;
        bind(face, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(const TopoDS_Solid &solid, int tag, bool recursive)
{
  if(solid.IsNull()) return;
  if(_solidTag.IsBound(solid)) {
    if(_solidTag.Find(solid) != tag) {
      Msg::Info("Cannot bind existing OpenCASCADE volume %d to second tag %d",
                _solidTag.Find(solid), tag);
    }
  }
  else {
    if(_tagSolid.IsBound(tag)) {
      // this leaves the old solid bound in _faceTag, but we cannot remove it
      Msg::Info("Rebinding OpenCASCADE volume %d", tag);
    }
    _solidTag.Bind(solid, tag);
    _tagSolid.Bind(tag, solid);
    setMaxTag(3, tag);
    _changed = true;
    _attributes->insert(new OCCAttributes(3, solid));
  }
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(solid, TopAbs_SHELL); exp0.More(); exp0.Next()) {
      TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
      if(!_shellTag.IsBound(shell)) {
        int t = getMaxTag(-2) + 1;
        bind(shell, t, recursive);
      }
    }
    for(exp0.Init(solid, TopAbs_FACE); exp0.More(); exp0.Next()) {
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(!_faceTag.IsBound(face)) {
        int t = getMaxTag(3) + 1;
        bind(face, t, recursive);
      }
    }
  }
}

void OCC_Internals::bind(TopoDS_Shape shape, int dim, int tag, bool recursive)
{
  switch(dim) {
  case 0: bind(TopoDS::Vertex(shape), tag, recursive); break;
  case 1: bind(TopoDS::Edge(shape), tag, recursive); break;
  case 2: bind(TopoDS::Face(shape), tag, recursive); break;
  case 3: bind(TopoDS::Solid(shape), tag, recursive); break;
  case -1: bind(TopoDS::Wire(shape), tag, recursive); break;
  case -2: bind(TopoDS::Shell(shape), tag, recursive); break;
  default: break;
  }
}

void OCC_Internals::unbind(const TopoDS_Vertex &vertex, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagEdge);
  for(; exp0.More(); exp0.Next()) {
    TopoDS_Edge edge = TopoDS::Edge(exp0.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(edge, TopAbs_VERTEX); exp1.More(); exp1.Next()) {
      if(exp1.Current().IsSame(vertex)) return;
    }
  }
  std::pair<int, int> dimTag(0, tag);
  if(_toPreserve.find(dimTag) != _toPreserve.end()) return;
  _vertexTag.UnBind(vertex);
  _tagVertex.UnBind(tag);
  _toRemove.insert(dimTag);
  _recomputeMaxTag(0);
  _changed = true;
}

void OCC_Internals::unbind(const TopoDS_Edge &edge, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp2(_tagFace);
  for(; exp2.More(); exp2.Next()) {
    TopoDS_Face face = TopoDS::Face(exp2.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(face, TopAbs_EDGE); exp1.More(); exp1.Next()) {
      if(exp1.Current().IsSame(edge)) return;
    }
  }
  std::pair<int, int> dimTag(1, tag);
  if(_toPreserve.find(dimTag) != _toPreserve.end()) return;
  _edgeTag.UnBind(edge);
  _tagEdge.UnBind(tag);
  _toRemove.insert(dimTag);
  _recomputeMaxTag(1);
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(edge, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
      TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
      if(_vertexTag.IsBound(vertex)) {
        int t = _vertexTag.Find(vertex);
        unbind(vertex, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(const TopoDS_Wire &wire, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagFace);
  for(; exp0.More(); exp0.Next()) {
    TopoDS_Face face = TopoDS::Face(exp0.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(face, TopAbs_WIRE); exp1.More(); exp1.Next()) {
      if(exp1.Current().IsSame(wire)) return;
    }
  }
  std::pair<int, int> dimTag(-1, tag);
  if(_toPreserve.find(dimTag) != _toPreserve.end()) return;
  _wireTag.UnBind(wire);
  _tagWire.UnBind(tag);
  _toRemove.insert(dimTag);
  _recomputeMaxTag(-1);
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(wire, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(_edgeTag.IsBound(edge)) {
        int t = _edgeTag.Find(edge);
        unbind(edge, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(const TopoDS_Face &face, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp2(_tagSolid);
  for(; exp2.More(); exp2.Next()) {
    TopoDS_Solid solid = TopoDS::Solid(exp2.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(solid, TopAbs_FACE); exp1.More(); exp1.Next()) {
      if(exp1.Current().IsSame(face)) return;
    }
  }
  std::pair<int, int> dimTag(2, tag);
  if(_toPreserve.find(dimTag) != _toPreserve.end()) return;
  _faceTag.UnBind(face);
  _tagFace.UnBind(tag);
  _toRemove.insert(dimTag);
  _recomputeMaxTag(2);
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(face, TopAbs_WIRE); exp0.More(); exp0.Next()) {
      TopoDS_Wire wire = TopoDS::Wire(exp0.Current());
      if(_wireTag.IsBound(wire)) {
        int t = _wireTag.Find(wire);
        unbind(wire, t, recursive);
      }
    }
    for(exp0.Init(face, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(_edgeTag.IsBound(edge)) {
        int t = _edgeTag.Find(edge);
        unbind(edge, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(const TopoDS_Shell &shell, int tag, bool recursive)
{
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagSolid);
  for(; exp0.More(); exp0.Next()) {
    TopoDS_Solid solid = TopoDS::Solid(exp0.Value());
    TopExp_Explorer exp1;
    for(exp1.Init(solid, TopAbs_SHELL); exp1.More(); exp1.Next()) {
      if(exp1.Current().IsSame(shell)) return;
    }
  }
  std::pair<int, int> dimTag(-2, tag);
  if(_toPreserve.find(dimTag) != _toPreserve.end()) return;
  _shellTag.UnBind(shell);
  _tagShell.UnBind(tag);
  _toRemove.insert(dimTag);
  _recomputeMaxTag(-2);
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(shell, TopAbs_FACE); exp0.More(); exp0.Next()) {
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(_faceTag.IsBound(face)) {
        int t = _faceTag.Find(face);
        unbind(face, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(const TopoDS_Solid &solid, int tag, bool recursive)
{
  std::pair<int, int> dimTag(3, tag);
  if(_toPreserve.find(dimTag) != _toPreserve.end()) return;
  _solidTag.UnBind(solid);
  _tagSolid.UnBind(tag);
  _toRemove.insert(dimTag);
  _recomputeMaxTag(3);
  if(recursive) {
    TopExp_Explorer exp0;
    for(exp0.Init(solid, TopAbs_SHELL); exp0.More(); exp0.Next()) {
      TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
      if(_shellTag.IsBound(shell)) {
        int t = _shellTag.Find(shell);
        unbind(shell, t, recursive);
      }
    }
    for(exp0.Init(solid, TopAbs_FACE); exp0.More(); exp0.Next()) {
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(_faceTag.IsBound(face)) {
        int t = _faceTag.Find(face);
        unbind(face, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::unbind(TopoDS_Shape shape, int dim, int tag, bool recursive)
{
  switch(dim) {
  case 0: unbind(TopoDS::Vertex(shape), tag, recursive); break;
  case 1: unbind(TopoDS::Edge(shape), tag, recursive); break;
  case 2: unbind(TopoDS::Face(shape), tag, recursive); break;
  case 3: unbind(TopoDS::Solid(shape), tag, recursive); break;
  case -1: unbind(TopoDS::Wire(shape), tag, recursive); break;
  case -2: unbind(TopoDS::Shell(shape), tag, recursive); break;
  default: break;
  }
}

void OCC_Internals::unbind()
{
  for(int i = 0; i < 6; i++) _maxTag[i] = 0;

  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp;
  exp.Initialize(_tagVertex);
  for(; exp.More(); exp.Next())
    _toRemove.insert(std::pair<int, int>(0, exp.Key()));
  exp.Initialize(_tagEdge);
  for(; exp.More(); exp.Next())
    _toRemove.insert(std::pair<int, int>(1, exp.Key()));
  exp.Initialize(_tagFace);
  for(; exp.More(); exp.Next())
    _toRemove.insert(std::pair<int, int>(2, exp.Key()));
  exp.Initialize(_tagSolid);
  for(; exp.More(); exp.Next())
    _toRemove.insert(std::pair<int, int>(3, exp.Key()));
  exp.Initialize(_tagWire);
  for(; exp.More(); exp.Next())
    _toRemove.insert(std::pair<int, int>(-1, exp.Key()));
  exp.Initialize(_tagShell);
  for(; exp.More(); exp.Next())
    _toRemove.insert(std::pair<int, int>(-2, exp.Key()));

  _tagVertex.Clear();
  _tagEdge.Clear();
  _tagFace.Clear();
  _tagSolid.Clear();
  _tagWire.Clear();
  _tagShell.Clear();

  _vertexTag.Clear();
  _edgeTag.Clear();
  _faceTag.Clear();
  _solidTag.Clear();
  _wireTag.Clear();
  _shellTag.Clear();

  _changed = true;
}

void OCC_Internals::_multiBind(const TopoDS_Shape &shape, int tag,
                               std::vector<std::pair<int, int> > &outDimTags,
                               bool highestDimOnly, bool recursive,
                               bool returnNewOnly)
{
  TopExp_Explorer exp0;
  int count = 0;
  for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()) {
    TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
    bool exists = false;
    int t = tag;
    if(t <= 0) {
      if(_solidTag.IsBound(solid)) {
        t = _solidTag.Find(solid);
        exists = true;
      }
      else
        t = getMaxTag(3) + 1;
    }
    else if(count) {
      Msg::Error("Cannot bind multiple volumes to single tag %d", t);
      return;
    }
    if(!exists) bind(solid, t, recursive);
    if(!exists || !returnNewOnly)
      outDimTags.push_back(std::pair<int, int>(3, t));
    count++;
  }
  if(highestDimOnly && count) return;
  for(exp0.Init(shape, TopAbs_FACE); exp0.More(); exp0.Next()) {
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    bool exists = false;
    int t = tag;
    if(t <= 0) {
      if(_faceTag.IsBound(face)) {
        t = _faceTag.Find(face);
        exists = true;
      }
      else
        t = getMaxTag(2) + 1;
    }
    else if(count) {
      Msg::Error("Cannot bind multiple surfaces to single tag %d", t);
      return;
    }
    if(!exists) bind(face, t, recursive);
    if(!exists || !returnNewOnly)
      outDimTags.push_back(std::pair<int, int>(2, t));
    count++;
  }
  if(highestDimOnly && count) return;
  for(exp0.Init(shape, TopAbs_EDGE); exp0.More(); exp0.Next()) {
    TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
    bool exists = false;
    int t = tag;
    if(t <= 0) {
      if(_edgeTag.IsBound(edge)) {
        t = _edgeTag.Find(edge);
        exists = true;
      }
      else
        t = getMaxTag(1) + 1;
    }
    else if(count) {
      Msg::Error("Cannot bind multiple curves to single tag %d", t);
      return;
    }
    if(!exists) bind(edge, t, recursive);
    if(!exists || !returnNewOnly)
      outDimTags.push_back(std::pair<int, int>(1, t));
    count++;
  }
  if(highestDimOnly && count) return;
  for(exp0.Init(shape, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
    TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
    bool exists = false;
    int t = tag;
    if(t <= 0) {
      if(_vertexTag.IsBound(vertex)) {
        t = _vertexTag.Find(vertex);
        exists = true;
      }
      else
        t = getMaxTag(0) + 1;
    }
    else if(count) {
      Msg::Error("Cannot bind multiple points to single tag %d", t);
      return;
    }
    if(!exists) bind(vertex, t, recursive);
    if(!exists || !returnNewOnly)
      outDimTags.push_back(std::pair<int, int>(0, t));
    count++;
  }
}

bool OCC_Internals::_isBound(int dim, int tag)
{
  switch(dim) {
  case 0: return _tagVertex.IsBound(tag);
  case 1: return _tagEdge.IsBound(tag);
  case 2: return _tagFace.IsBound(tag);
  case 3: return _tagSolid.IsBound(tag);
  case -1: return _tagWire.IsBound(tag);
  case -2: return _tagShell.IsBound(tag);
  default: return false;
  }
}

bool OCC_Internals::_isBound(int dim, const TopoDS_Shape &shape)
{
  switch(dim) {
  case 0: return _vertexTag.IsBound(shape);
  case 1: return _edgeTag.IsBound(shape);
  case 2: return _faceTag.IsBound(shape);
  case 3: return _solidTag.IsBound(shape);
  case -1: return _wireTag.IsBound(shape);
  case -2: return _shellTag.IsBound(shape);
  default: return false;
  }
}

TopoDS_Shape OCC_Internals::_find(int dim, int tag)
{
  switch(dim) {
  case 0: return _tagVertex.Find(tag);
  case 1: return _tagEdge.Find(tag);
  case 2: return _tagFace.Find(tag);
  case 3: return _tagSolid.Find(tag);
  case -1: return _tagWire.Find(tag);
  case -2: return _tagShell.Find(tag);
  default: return TopoDS_Shape();
  }
}

int OCC_Internals::_find(int dim, const TopoDS_Shape &shape)
{
  switch(dim) {
  case 0: return _vertexTag.Find(shape);
  case 1: return _edgeTag.Find(shape);
  case 2: return _faceTag.Find(shape);
  case 3: return _solidTag.Find(shape);
  case -1: return _wireTag.Find(shape);
  case -2: return _shellTag.Find(shape);
  default: return -1;
  }
}

bool OCC_Internals::addVertex(int &tag, double x, double y, double z,
                              double meshSize)
{
  if(tag >= 0 && _tagVertex.IsBound(tag)) {
    Msg::Error("OpenCASCADE point with tag %d already exists", tag);
    return false;
  }
  TopoDS_Vertex result;
  try {
    gp_Pnt aPnt(x, y, z);
    BRepBuilderAPI_MakeVertex v(aPnt);
    v.Build();
    if(!v.IsDone()) {
      Msg::Error("Could not create point");
      return false;
    }
    result = v.Vertex();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(meshSize > 0 && meshSize < MAX_LC)
    _attributes->insert(new OCCAttributes(0, result, meshSize));
  if(tag < 0) tag = getMaxTag(0) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addLine(int &tag, int startTag, int endTag)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }
  if(!_tagVertex.IsBound(startTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", startTag);
    return false;
  }
  if(!_tagVertex.IsBound(endTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", endTag);
    return false;
  }
  if(startTag == endTag) {
    Msg::Error("Start and end points of line should be different");
    return false;
  }
  TopoDS_Edge result;
  try {
    TopoDS_Vertex start = TopoDS::Vertex(_tagVertex.Find(startTag));
    TopoDS_Vertex end = TopoDS::Vertex(_tagVertex.Find(endTag));
    BRepBuilderAPI_MakeEdge e(start, end);
    e.Build();
    if(!e.IsDone()) {
      Msg::Error("Could not create line");
      return false;
    }
    result = e.Edge();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addLine(int &tag, const std::vector<int> &pointTags)
{
  if(pointTags.size() == 2) return addLine(tag, pointTags[0], pointTags[1]);

  // FIXME: if tag < 0 we could create multiple lines
  Msg::Error("OpenCASCADE polyline currently not supported");
  return false;
}

bool OCC_Internals::addCircleArc(int &tag, int startTag, int centerTag,
                                 int endTag)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }
  if(!_tagVertex.IsBound(startTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", startTag);
    return false;
  }
  if(!_tagVertex.IsBound(centerTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", centerTag);
    return false;
  }
  if(!_tagVertex.IsBound(endTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", endTag);
    return false;
  }

  TopoDS_Edge result;
  try {
    TopoDS_Vertex start = TopoDS::Vertex(_tagVertex.Find(startTag));
    TopoDS_Vertex center = TopoDS::Vertex(_tagVertex.Find(centerTag));
    TopoDS_Vertex end = TopoDS::Vertex(_tagVertex.Find(endTag));
    gp_Pnt aP1 = BRep_Tool::Pnt(start);
    gp_Pnt aP2 = BRep_Tool::Pnt(center);
    gp_Pnt aP3 = BRep_Tool::Pnt(end);
    Standard_Real Radius = aP1.Distance(aP2);
    gce_MakeCirc MC(aP2, gce_MakePln(aP1, aP2, aP3).Value(), Radius);
    if(!MC.IsDone()) {
      Msg::Error("Could not build circle");
      return false;
    }
    const gp_Circ &Circ = MC.Value();
    Standard_Real Alpha1 = ElCLib::Parameter(Circ, aP1);
    Standard_Real Alpha2 = ElCLib::Parameter(Circ, aP3);
    Handle(Geom_Circle) C = new Geom_Circle(Circ);
    Handle(Geom_TrimmedCurve) arc =
      new Geom_TrimmedCurve(C, Alpha1, Alpha2, false);
    BRepBuilderAPI_MakeEdge e(arc, start, end);
    e.Build();
    if(!e.IsDone()) {
      Msg::Error("Could not create circle arc");
      return false;
    }
    result = e.Edge();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addEllipseArc(int &tag, int startTag, int centerTag,
                                  int majorTag, int endTag)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }
  if(!_tagVertex.IsBound(startTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", startTag);
    return false;
  }
  if(!_tagVertex.IsBound(centerTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", centerTag);
    return false;
  }
  if(!_tagVertex.IsBound(majorTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", majorTag);
    return false;
  }
  if(!_tagVertex.IsBound(endTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", endTag);
    return false;
  }

  TopoDS_Edge result;
  try {
    TopoDS_Vertex start = TopoDS::Vertex(_tagVertex.Find(startTag));
    TopoDS_Vertex center = TopoDS::Vertex(_tagVertex.Find(centerTag));
    TopoDS_Vertex major = TopoDS::Vertex(_tagVertex.Find(majorTag));
    TopoDS_Vertex end = TopoDS::Vertex(_tagVertex.Find(endTag));
    gp_Pnt startPnt = BRep_Tool::Pnt(start);
    gp_Pnt centerPnt = BRep_Tool::Pnt(center);
    gp_Pnt majorPnt = BRep_Tool::Pnt(major);
    gp_Pnt endPnt = BRep_Tool::Pnt(end);
    gp_XYZ x1 = startPnt.XYZ() - centerPnt.XYZ();
    gp_XYZ x2 = endPnt.XYZ() - centerPnt.XYZ();
    gp_Dir u = majorPnt.XYZ() - centerPnt.XYZ();
    gp_Dir v;
    if(!u.IsParallel(x1, 1e-6))
      v = x1 - x1.Dot(u.XYZ()) * u.XYZ();
    else if(!u.IsParallel(x2, 1e-6))
      v = x2 - x2.Dot(u.XYZ()) * u.XYZ();
    else {
      Msg::Error("The points do not define an ellipse");
      return false;
    }
    Standard_Real x1u = Square(x1.Dot(u.XYZ()));
    Standard_Real x1v = Square(x1.Dot(v.XYZ()));
    Standard_Real x2u = Square(x2.Dot(u.XYZ()));
    Standard_Real x2v = Square(x2.Dot(v.XYZ()));
    if(IsEqual(x1u, x2u) || IsEqual(x1v, x2v)) {
      Msg::Error("The points do not define an ellipse");
      return false;
    }
    Standard_Real a2 = (x1v * x2u - x1u * x2v) / (x1v - x2v);
    Standard_Real b2 = (x1u * x2v - x1v * x2u) / (x1u - x2u);
    if(a2 <= 0.0 || b2 <= 0.0) {
      Msg::Error("The points do not define an ellipse");
      return false;
    }
    Standard_Real a; // Major radius
    Standard_Real b; // Minor radius
    gp_Ax2 Axes; // Ellipse local coordinate system
    if(a2 >= b2) {
      a = Sqrt(a2);
      b = Sqrt(b2);
      Axes = gp_Ax2(centerPnt, u ^ v, u);
    }
    else {
      Msg::Warning("Major radius smaller than minor radius");
      a = Sqrt(b2);
      b = Sqrt(a2);
      Axes = gp_Ax2(centerPnt, v ^ u, v);
    }
    gce_MakeElips ME(Axes, a, b);
    if(!ME.IsDone()) {
      Msg::Error("Could not build ellipse");
      return false;
    }
    const gp_Elips &Elips = ME.Value();
    Standard_Real Alpha1 = ElCLib::Parameter(Elips, startPnt);
    Standard_Real Alpha2 = ElCLib::Parameter(Elips, endPnt);
    Handle(Geom_Ellipse) E = new Geom_Ellipse(Elips);
    Handle(Geom_TrimmedCurve) arc;
    if((Alpha2 > Alpha1 && Alpha2 - Alpha1 < M_PI) || Alpha1 - Alpha2 > M_PI)
      arc = new Geom_TrimmedCurve(E, Alpha1, Alpha2, true);
    else
      arc = new Geom_TrimmedCurve(E, Alpha2, Alpha1, false);
    BRepBuilderAPI_MakeEdge e(arc, start, end);
    e.Build();
    if(!e.IsDone()) {
      Msg::Error("Could not create ellipse arc");
      return false;
    }
    result = e.Edge();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addCircle(int &tag, double x, double y, double z, double r,
                              double angle1, double angle2)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }
  if(r <= 0) {
    Msg::Error("Circle radius should be positive");
    return false;
  }

  TopoDS_Edge result;
  try {
    gp_Dir N_dir(0., 0., 1.);
    gp_Dir x_dir(1., 0., 0.);
    gp_Pnt center(x, y, z);
    gp_Ax2 axis(center, N_dir, x_dir);
    gp_Circ circ(axis, r);
    if(angle1 == 0. && angle2 == 2 * M_PI) {
      result = BRepBuilderAPI_MakeEdge(circ);
    }
    else {
      Handle(Geom_Circle) C = new Geom_Circle(circ);
      Handle(Geom_TrimmedCurve) arc =
        new Geom_TrimmedCurve(C, angle1, angle2, false);
      BRepBuilderAPI_MakeEdge e(arc);
      if(!e.IsDone()) {
        Msg::Error("Could not create circle arc");
        return false;
      }
      result = e.Edge();
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addEllipse(int &tag, double x, double y, double z,
                               double rx, double ry, double angle1,
                               double angle2)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }
  if(ry > rx) {
    Msg::Error("Major radius rx should be larger than minor radius ry");
    return false;
  }
  if(ry <= 0 || rx <= 0) {
    Msg::Error("Ellipse radii should be positive");
    return false;
  }

  TopoDS_Edge result;
  try {
    gp_Dir N_dir(0., 0., 1.);
    gp_Dir x_dir(1., 0., 0.);
    gp_Pnt center(x, y, z);
    gp_Ax2 axis(center, N_dir, x_dir);
    gp_Elips elips(axis, rx, ry);
    if(angle1 == 0 && angle2 == 2 * M_PI) {
      result = BRepBuilderAPI_MakeEdge(elips);
    }
    else {
      Handle(Geom_Ellipse) E = new Geom_Ellipse(elips);
      Handle(Geom_TrimmedCurve) arc =
        new Geom_TrimmedCurve(E, angle1, angle2, true);
      BRepBuilderAPI_MakeEdge e(arc);
      if(!e.IsDone()) {
        Msg::Error("Could not create ellipse arc");
        return false;
      }
      result = e.Edge();
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

void debugBSpline(const Handle(Geom_BSplineCurve) & curve)
{
  int degree = curve->Degree();
  bool periodic = curve->IsPeriodic();
  bool rational = curve->IsRational();

  int npoles = curve->NbPoles();
  TColgp_Array1OfPnt poles(1, npoles);
  curve->Poles(poles);

  TColStd_Array1OfReal weights(1, npoles);
  curve->Weights(weights);

  int nknots = curve->NbKnots();
  TColStd_Array1OfReal knots(1, nknots);
  curve->Knots(knots);

  TColStd_Array1OfInteger mults(1, nknots);
  curve->Multiplicities(mults);

  printf("BSpline: degree %d, periodic %d, rational %d\n", degree, periodic,
         rational);
  printf("Poles:\n");
  for(int i = 1; i <= npoles; i++)
    printf("  %d (%g, %g, %g) weight %g\n", i, poles(i).X(), poles(i).Y(),
           poles(i).Z(), weights(i));
  printf("Knots:\n");
  for(int i = 1; i <= nknots; i++)
    printf("  %d (%g) mult %d\n", i, knots(i), mults(i));
}

bool OCC_Internals::_addBSpline(int &tag, const std::vector<int> &pointTags,
                                int mode, const int degree,
                                const std::vector<double> &weights,
                                const std::vector<double> &knots,
                                const std::vector<int> &multiplicities)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }
  if(pointTags.size() < 2) {
    Msg::Error("Number of control points should be at least 2");
    return false;
  }

  TopoDS_Edge result;
  try {
    TColgp_Array1OfPnt ctrlPoints(1, pointTags.size());
    TopoDS_Vertex start, end;
    for(std::size_t i = 0; i < pointTags.size(); i++) {
      if(!_tagVertex.IsBound(pointTags[i])) {
        Msg::Error("Unknown OpenCASCADE point with tag %d", pointTags[i]);
        return false;
      }
      TopoDS_Vertex vertex = TopoDS::Vertex(_tagVertex.Find(pointTags[i]));
      ctrlPoints.SetValue(i + 1, BRep_Tool::Pnt(vertex));
      if(i == 0) start = vertex;
      if(i == pointTags.size() - 1) end = vertex;
    }
    bool periodic = (pointTags.front() == pointTags.back());
    if(mode == 0) {
      // BSpline through points (called "Spline" in Gmsh; will be C2, whereas it
      // is only C1 in the GEO kernel)
      int np = periodic ? ctrlPoints.Length() - 1 : ctrlPoints.Length();
      Handle(TColgp_HArray1OfPnt) p = new TColgp_HArray1OfPnt(1, np);
      for(int i = 1; i <= np; i++) p->SetValue(i, ctrlPoints(i));
      GeomAPI_Interpolate intp(p, periodic, CTX::instance()->geom.tolerance);
      intp.Perform();
      if(!intp.IsDone()) {
        Msg::Error("Could not interpolate spline");
        return false;
      }
      Handle(Geom_BSplineCurve) curve = intp.Curve();
      BRepBuilderAPI_MakeEdge e(curve, start, end);
      if(!e.IsDone()) {
        Msg::Error("Could not create spline");
        return false;
      }
      result = e.Edge();
    }
    else if(mode == 1) {
      // Bezier curve
      Handle(Geom_BezierCurve) curve = new Geom_BezierCurve(ctrlPoints);
      BRepBuilderAPI_MakeEdge e(curve, start, end);
      if(!e.IsDone()) {
        Msg::Error("Could not create Bezier curve");
        return false;
      }
      result = e.Edge();
    }
    else if(mode == 2) {
      // General BSpline curve, polynomial or rational, with explicit degree,
      // weights, knots and multiplicities
      if(degree < 0) {
        Msg::Error("BSpline degree (%d) should be >= 0", degree);
        return false;
      }
      if(weights.size() != pointTags.size()) {
        Msg::Error("Number of BSpline weights (%d) and control points (%d) "
                   "should be equal",
                   weights.size(), pointTags.size());
        return false;
      }
      if(knots.size() != multiplicities.size()) {
        Msg::Error(
          "Number of BSpline knots (%d) and multiplicities (%d) should be "
          "equal",
          knots.size(), multiplicities.size());
        return false;
      }
      if(knots.size() < 2) {
        Msg::Error("Number of BSpline knots (%d) should be >= 2", knots.size());
        return false;
      }
      for(std::size_t i = 0; i < knots.size() - 1; i++) {
        if(knots[i] >= knots[i + 1]) {
          Msg::Error("BSpline knots should be increasing: knot %d (%g) > "
                     "knot %d (%g)",
                     i, knots[i], i + 1, knots[i + 1]);
          return false;
        }
      }
      for(std::size_t i = 0; i < multiplicities.size(); i++) {
        if(multiplicities[i] < 1) {
          Msg::Error("BSpline multiplicities should be >= 1");
          return false;
        }
        if(i != 0 && i != multiplicities.size() - 1 &&
           multiplicities[i] > degree) {
          Msg::Error(
            "BSpline interior knot multiplicities should be <= degree");
          return false;
        }
        if((i == 0 || i == multiplicities.size() - 1) &&
           multiplicities[i] > degree + 1) {
          Msg::Error("BSpline end knot multiplicities should be <= degree + 1");
          return false;
        }
      }
      if(periodic) {
        if(multiplicities.front() != multiplicities.back()) {
          Msg::Error(
            "Periodic BSpline end knot multiplicies (%d and %d) should "
            "be equal",
            multiplicities.front(), multiplicities.back());
          return false;
        }
        const auto sum = std::accumulate(
          begin(multiplicities), std::prev(std::end(multiplicities)),
          std::size_t(0),
          [](std::size_t const partial_sum, int const multiplicity) {
            return partial_sum + multiplicity;
          });
        if(pointTags.size() - 1 != sum) {
          Msg::Error("Number of control points - 1 for periodic BSpline should "
                     "be equal to the sum of multiplicities for all knots "
                     "except the first (or last)");
          return false;
        }
      }
      else {
        const auto sum = std::accumulate(
          begin(multiplicities), std::end(multiplicities), std::size_t(0),
          [](std::size_t const partial_sum, int const multiplicity) {
            return partial_sum + multiplicity;
          });
        if(pointTags.size() != sum - degree - 1) {
          Msg::Error("Number of control points for non-periodic BSpline should "
                     "be equal to the sum of multiplicities - degree - 1");
          return false;
        }
      }
      int np = (periodic ? ctrlPoints.Length() - 1 : ctrlPoints.Length());
      TColgp_Array1OfPnt p(1, np);
      TColStd_Array1OfReal w(1, np);
      for(int i = 1; i <= np; i++) {
        p.SetValue(i, ctrlPoints(i));
        w.SetValue(i, weights[i - 1]);
      }
      TColStd_Array1OfReal k(1, knots.size());
      for(std::size_t i = 0; i < knots.size(); i++) k.SetValue(i + 1, knots[i]);
      TColStd_Array1OfInteger m(1, multiplicities.size());
      for(std::size_t i = 0; i < multiplicities.size(); i++)
        m.SetValue(i + 1, multiplicities[i]);
      Handle(Geom_BSplineCurve) curve =
        new Geom_BSplineCurve(p, w, k, m, degree, periodic);
      if(curve->StartPoint().IsEqual(BRep_Tool::Pnt(start),
                                     CTX::instance()->geom.tolerance) &&
         curve->EndPoint().IsEqual(BRep_Tool::Pnt(end),
                                   CTX::instance()->geom.tolerance)) {
        BRepBuilderAPI_MakeEdge e(curve, start, end);
        if(!e.IsDone()) {
          Msg::Error("Could not create BSpline curve (with end points)");
          return false;
        }
        result = e.Edge();
      }
      else { // will create new topo vertices as necessary
        BRepBuilderAPI_MakeEdge e(curve);
        if(!e.IsDone()) {
          Msg::Error("Could not create BSpline curve (without end points)");
          return false;
        }
        result = e.Edge();
        // copy mesh size from start control point to new topo vertex; this way
        // we'll behave more like the built-in kernel (although the built-in
        // kernel keeps track of all the control points)
        double lc = _attributes->getMeshSize(0, start);
        if(lc > 0 && lc < MAX_LC) {
          TopExp_Explorer exp0;
          for(exp0.Init(result, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
            TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
            _attributes->insert(new OCCAttributes(0, vertex, lc));
          }
        }
      }
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(1) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addSpline(int &tag, const std::vector<int> &pointTags)
{
  return _addBSpline(tag, pointTags, 0);
}

bool OCC_Internals::addBezier(int &tag, const std::vector<int> &pointTags)
{
  return _addBSpline(tag, pointTags, 1);
}

bool OCC_Internals::addBSpline(int &tag, const std::vector<int> &pointTags,
                               const int degree,
                               const std::vector<double> &weights,
                               const std::vector<double> &knots,
                               const std::vector<int> &multiplicities)
{
  int np = pointTags.size();
  if(np < 2) {
    Msg::Error("BSpline curve requires at least 2 control points");
    return false;
  }
  int d = degree;
  std::vector<double> w(weights), k(knots);
  std::vector<int> m(multiplicities);
  // degree 3 if not specified...
  if(d <= 0) d = 3;
  // ... or number of control points - 1 if not enough points
  if(d > np - 1) d = np - 1;
  // automatic default weights if not provided:
  if(w.empty()) w.resize(np, 1);
  // automatic default knots and multiplicities if not provided:
  if(k.empty()) {
    bool periodic = (pointTags.front() == pointTags.back());
    if(!periodic) {
      int sumOfAllMult = np + d + 1;
      int numKnots = sumOfAllMult - 2 * d;
      if(numKnots < 2) {
        Msg::Error("Not enough control points for building BSpline of "
                   "degree %d",
                   d);
        return false;
      }
      k.resize(numKnots);
      for(std::size_t i = 0; i < k.size(); i++) k[i] = i;
      m.resize(numKnots, 1);
      m.front() = d + 1;
      m.back() = d + 1;
    }
    else {
      k.resize(np - d + 2);
      for(std::size_t i = 0; i < k.size(); i++) k[i] = i;
      m.resize(k.size(), 1);
      m.front() = d - 1;
      m.back() = d - 1;
    }
  }
  return _addBSpline(tag, pointTags, 2, d, w, k, m);
}

bool OCC_Internals::addWire(int &tag, const std::vector<int> &curveTags,
                            bool checkClosed)
{
  if(tag >= 0 && _tagWire.IsBound(tag)) {
    Msg::Error("OpenCASCADE wire or line loop with tag %d already exists", tag);
    return false;
  }

  // Note: contrary to shells wires are always "sewed", i.e., a valid wire is
  // constructed if points are geometrically at the same location (even if they
  // are not topologically identical); there is thus no need to add a "sewing"
  // option.
  try {
    BRepBuilderAPI_MakeWire w;
    TopoDS_Wire wire;
    for(std::size_t i = 0; i < curveTags.size(); i++) {
      // all curve tags are > 0 for OCC : but to improve compatibility between
      // GEO and OCC factories, we allow negative tags - and simply ignore the
      // sign here
      int t = std::abs(curveTags[i]);
      if(!_tagEdge.IsBound(t)) {
        Msg::Error("Unknown OpenCASCADE curve with tag %d", t);
        return false;
      }
      TopoDS_Edge edge = TopoDS::Edge(_tagEdge.Find(t));
      w.Add(edge);
    }
    wire = w.Wire();
    if(checkClosed && !wire.Closed()) {
      Msg::Error("Line Loop is not closed");
      return false;
    }
    if(tag < 0) tag = getMaxTag(-1) + 1;
    bind(wire, tag, true);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addCurveLoop(int &tag, const std::vector<int> &curveTags)
{
  return addWire(tag, curveTags, true);
}

static bool makeRectangle(TopoDS_Face &result, double x, double y, double z,
                          double dx, double dy, double roundedRadius)
{
  if(!dx || !dy) {
    Msg::Error("Rectangle with zero width or height");
    return false;
  }
  try {
    TopoDS_Wire wire;
    if(roundedRadius <= 0.) {
      double x1 = x, y1 = y, z1 = z, x2 = x1 + dx, y2 = y1 + dy;
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
    else {
      double x1, y1, z1 = z, x2, y2;
      double r = roundedRadius;
      if(dx > 0.) {
        x1 = x;
        x2 = x1 + dx;
      }
      else {
        x2 = x;
        x1 = x2 + dx;
      }
      if(dy > 0.) {
        y1 = y;
        y2 = y1 + dy;
      }
      else {
        y2 = y;
        y1 = y2 + dy;
      }
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
      Handle(Geom_TrimmedCurve) arc1 =
        new Geom_TrimmedCurve(circle1, -M_PI, -M_PI / 2., true);
      Handle(Geom_TrimmedCurve) arc2 =
        new Geom_TrimmedCurve(circle2, -M_PI / 2, 0, true);
      Handle(Geom_TrimmedCurve) arc3 =
        new Geom_TrimmedCurve(circle3, 0, M_PI / 2, true);
      Handle(Geom_TrimmedCurve) arc4 =
        new Geom_TrimmedCurve(circle4, M_PI / 2, M_PI, true);
      TopoDS_Edge ce1 = BRepBuilderAPI_MakeEdge(arc1, v8, v1);
      TopoDS_Edge ce2 = BRepBuilderAPI_MakeEdge(arc2, v2, v3);
      TopoDS_Edge ce3 = BRepBuilderAPI_MakeEdge(arc3, v4, v5);
      TopoDS_Edge ce4 = BRepBuilderAPI_MakeEdge(arc4, v6, v7);
      BRepBuilderAPI_MakeWire w;
      w.Add(e1);
      w.Add(ce2);
      w.Add(e2);
      w.Add(ce3);
      w.Add(e3);
      w.Add(ce4);
      w.Add(e4);
      w.Add(ce1);
      wire = w.Wire();
    }
    result = BRepBuilderAPI_MakeFace(wire);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addRectangle(int &tag, double x, double y, double z,
                                 double dx, double dy, double roundedRadius)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }
  TopoDS_Face result;
  if(!makeRectangle(result, x, y, z, dx, dy, roundedRadius)) return false;
  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

static bool makeDisk(TopoDS_Face &result, double xc, double yc, double zc,
                     double rx, double ry)
{
  if(ry > rx) {
    Msg::Error("Major radius rx should be larger than minor radius ry");
    return false;
  }
  if(ry <= 0 || rx <= 0) {
    Msg::Error("Disk radius should be positive");
    return false;
  }
  try {
    gp_Dir N_dir(0., 0., 1.);
    gp_Dir x_dir(1., 0., 0.);
    gp_Pnt center(xc, yc, zc);
    gp_Ax2 axis(center, N_dir, x_dir);
    gp_Elips ellipse = gp_Elips(axis, rx, ry);
    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(ellipse);
    TopoDS_Wire wire = BRepBuilderAPI_MakeWire(edge);
    result = BRepBuilderAPI_MakeFace(wire);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addDisk(int &tag, double xc, double yc, double zc,
                            double rx, double ry)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }
  TopoDS_Face result;
  if(!makeDisk(result, xc, yc, zc, rx, ry)) return false;
  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addPlaneSurface(int &tag, const std::vector<int> &wireTags)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  std::vector<TopoDS_Wire> wires;
  for(std::size_t i = 0; i < wireTags.size(); i++) {
    // all wire tags are > 0 for OCC : to improve compatibility between GEO and
    // OCC factories, allow negative tags - and simply ignore the sign here
    int wireTag = std::abs(wireTags[i]);
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    wires.push_back(wire);
  }

  TopoDS_Face result;
  if(wires.size() == 0) {
    Msg::Error("Plane surface requires at least one line loop");
    return false;
  }

  try {
    BRepBuilderAPI_MakeFace f(wires[0]);
    for(std::size_t i = 1; i < wires.size(); i++) {
      // holes
      TopoDS_Wire w = wires[i];
      w.Orientation(TopAbs_REVERSED);
      f.Add(w);
    }
    f.Build();
    if(!f.IsDone()) {
      Msg::Error("Could not create face");
      return false;
    }
    result = f.Face();
    if(CTX::instance()->geom.occAutoFix) {
      // make sure wires are oriented correctly
      ShapeFix_Face fix(result);
      fix.Perform();
      result = fix.Face();
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addSurfaceFilling(int &tag, int wireTag,
                                      const std::vector<int> &pointTags,
                                      const std::vector<int> &surfaceTags,
                                      const std::vector<int> &surfaceContinuity)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  TopoDS_Face result;
  try {
    BRepOffsetAPI_MakeFilling f;
    // bounding edge constraints
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    TopExp_Explorer exp0;
    std::size_t i = 0;
    for(exp0.Init(wire, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(i < surfaceTags.size()) {
        // associated face constraint (does not seem to work...)
        if(!_tagFace.IsBound(surfaceTags[i])) {
          Msg::Error("Unknown OpenCASCADE surface with tag %d", surfaceTags[i]);
          return false;
        }
        TopoDS_Face face = TopoDS::Face(_tagFace.Find(surfaceTags[i]));
        if(i < surfaceContinuity.size() && surfaceContinuity[i] == 2)
          f.Add(edge, face, GeomAbs_G2);
        else
          f.Add(edge, face, GeomAbs_G1);
      }
      else {
        f.Add(edge, GeomAbs_C0);
      }
      i++;
    }
    // point constraints
    for(std::size_t i = 0; i < pointTags.size(); i++) {
      if(!_tagVertex.IsBound(pointTags[i])) {
        Msg::Error("Unknown OpenCASCADE point with tag %d", pointTags[i]);
        return false;
      }
      TopoDS_Vertex vertex = TopoDS::Vertex(_tagVertex.Find(pointTags[i]));
      f.Add(BRep_Tool::Pnt(vertex));
    }
    f.Build();
    if(!f.IsDone()) {
      Msg::Error("Could not build surface filling");
      return false;
    }
    // face filling duplicates the edges, so we need to go back to the
    // underlying surface, and remake a new face explicitly with the wire;
    // applying ShapeFix is mandatory (not sure why...)
    TopoDS_Face tmp = TopoDS::Face(f.Shape());
    Handle(Geom_Surface) s = BRep_Tool::Surface(tmp);
    result = BRepBuilderAPI_MakeFace(s, wire);
    ShapeFix_Face fix(result);
    fix.SetPrecision(CTX::instance()->geom.tolerance);
    fix.Perform();
    fix.FixOrientation(); // and I don't understand why this is necessary
    result = fix.Face();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addBSplineFilling(int &tag, int wireTag,
                                      const std::string &type)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  TopoDS_Face result;
  try {
    GeomFill_BSplineCurves f;
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    TopExp_Explorer exp0;
    std::vector<Handle(Geom_BSplineCurve)> bsplines;
    for(exp0.Init(wire, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      double s0, s1;
      Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, s0, s1);
      if(curve->DynamicType() == STANDARD_TYPE(Geom_BSplineCurve)) {
        bsplines.push_back(Handle(Geom_BSplineCurve)::DownCast(curve));
      }
      else {
        Msg::Error("Bounding curve for BSpline filling should be a BSpline");
      }
    }

    GeomFill_FillingStyle t;
    if(type == "Stretch")
      t = GeomFill_StretchStyle; // flattest patch
    else if(type == "Coons")
      t = GeomFill_CoonsStyle; // rounded with less depth than Curved
    else
      t = GeomFill_CurvedStyle; // most rounded patch

    if(bsplines.size() == 4) {
      f.Init(bsplines[0], bsplines[1], bsplines[2], bsplines[3], t);
    }
    else if(bsplines.size() == 3) {
      f.Init(bsplines[0], bsplines[1], bsplines[2], t);
    }
    else if(bsplines.size() == 2) {
      f.Init(bsplines[0], bsplines[1], t);
    }
    else {
      Msg::Error(
        "BSpline filling requires between 2 and 4 boundary BSpline curves");
      return false;
    }
    const Handle(Geom_BSplineSurface) &surf = f.Surface();
    result = BRepBuilderAPI_MakeFace(surf, wire);
    ShapeFix_Face fix(result); // not sure why, but this is necessary
    fix.SetPrecision(CTX::instance()->geom.tolerance);
    fix.Perform();
    fix.FixOrientation();
    result = fix.Face();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addBezierFilling(int &tag, int wireTag,
                                     const std::string &type)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  TopoDS_Face result;
  try {
    GeomFill_BezierCurves f;
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    TopExp_Explorer exp0;
    std::vector<Handle(Geom_BezierCurve)> beziers;
    for(exp0.Init(wire, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      double s0, s1;
      Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, s0, s1);
      if(curve->DynamicType() == STANDARD_TYPE(Geom_BezierCurve)) {
        beziers.push_back(Handle(Geom_BezierCurve)::DownCast(curve));
      }
      else {
        Msg::Error(
          "Bounding curve for Bezier filling should be a Bezier curve");
      }
    }

    GeomFill_FillingStyle t;
    if(type == "Stretch")
      t = GeomFill_StretchStyle; // flattest patch
    else if(type == "Coons")
      t = GeomFill_CoonsStyle; // rounded with less depth than Curved
    else
      t = GeomFill_CurvedStyle; // most rounded patch

    if(beziers.size() == 4) {
      f.Init(beziers[0], beziers[1], beziers[2], beziers[3], t);
    }
    else if(beziers.size() == 3) {
      f.Init(beziers[0], beziers[1], beziers[2], t);
    }
    else if(beziers.size() == 2) {
      f.Init(beziers[0], beziers[1], t);
    }
    else {
      Msg::Error(
        "Bezier filling requires between 2 and 4 boundary Bezier curves");
      return false;
    }
    const Handle(Geom_BezierSurface) &surf = f.Surface();
    result = BRepBuilderAPI_MakeFace(surf, wire);
    ShapeFix_Face fix(result); // not sure why, but this is necessary
    fix.SetPrecision(CTX::instance()->geom.tolerance);
    fix.Perform();
    fix.FixOrientation();
    result = fix.Face();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

static bool makeTrimmedSurface(Handle(Geom_Surface) & surf,
                               std::vector<TopoDS_Wire> &wires, bool wire3D,
                               TopoDS_Face &result)
{
  if(wires.empty()) { // natural bounds
    result = BRepBuilderAPI_MakeFace(surf, CTX::instance()->geom.tolerance);
#if 0
    // Activate this to use input points as corners if they are on the corners
    // of the patch. (Since the natural "Replace(old_vertex, new_vertex)" on the
    // face does not work, we do it on each edge. Sigh...)  Since when buiding
    // multi-patch models a fragment or sewing will eventually be necessary to
    // glue the patches, it's not that useful  let's leave this commented out.
    ShapeBuild_ReShape rebuild;
    TopExp_Explorer exp0;
    for(exp0.Init(result, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge e = TopoDS::Edge(exp0.Current());
      TopoDS_Vertex v1 = TopExp::FirstVertex(e);
      TopoDS_Vertex v2 = TopExp::LastVertex(e);
      double s0, s1;
      Handle(Geom_Curve) curve = BRep_Tool::Curve(e, s0, s1);
      if(curve->DynamicType() == STANDARD_TYPE(Geom_BSplineCurve)){
        Handle(Geom_BSplineCurve) bs = Handle(Geom_BSplineCurve)::DownCast(curve);
        for(std::size_t i = 0; i < corners.size(); i++) {
          if(bs->StartPoint().IsEqual(BRep_Tool::Pnt(corners[i]),
                                      CTX::instance()->geom.tolerance)) {
            v1 = corners[i];
          }
          if(bs->EndPoint().IsEqual(BRep_Tool::Pnt(corners[i]),
                                    CTX::instance()->geom.tolerance)) {
            v2 = corners[i];
          }
        }
      }
      BRepBuilderAPI_MakeEdge newe(curve, v1, v2);
      rebuild.Replace(e, newe);
    }
    result = TopoDS::Face(rebuild.Apply(result));
    ShapeFix_Face fix(result); // not sure why, but this is necessary
    fix.SetPrecision(CTX::instance()->geom.tolerance);
    fix.Perform();
    fix.FixOrientation();
    result = fix.Face();
#endif
  }
  else { // trimmed patch, using provided wires
    std::vector<TopoDS_Wire> wiresProj;
    for(std::size_t i = 0; i < wires.size(); i++) {
      BRepBuilderAPI_MakeWire w;
      TopExp_Explorer exp0;
      for(exp0.Init(wires[i], TopAbs_EDGE); exp0.More(); exp0.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
        Standard_Real first, last;
        Handle(Geom_Curve) c = BRep_Tool::Curve(edge, first, last);
        if(wire3D) {
          // use the 3D curves in the wire and project them onto the patch
          Handle(Geom_Curve) cProj = GeomProjLib::Project(
            new Geom_TrimmedCurve(c, first, last, Standard_True,
                                  Standard_False),
            surf);
          TopoDS_Edge edgeProj = BRepBuilderAPI_MakeEdge(
            cProj, cProj->FirstParameter(), cProj->LastParameter());
          w.Add(edgeProj);
        }
        else {
          // assume the 3D curves are actually 2D curves in the parametric space
          // of the patch: to retrieve the 2D curves, project the 3D curves on
          // the z=0 plane
          Handle(Geom_Plane) p = new Geom_Plane(0, 0, 1, 0);
          TopLoc_Location loc;
          Handle(Geom2d_Curve) c2d =
            BRep_Tool::CurveOnSurface(edge, p, loc, first, last);
          // BRep_Tool::CurveOnPlane(edge, p, loc, first, last); // OCCT >= 7.2
          TopoDS_Edge edgeSurf =
            BRepBuilderAPI_MakeEdge(c2d, surf, first, last);
          w.Add(edgeSurf);
        }
      }
      TopoDS_Wire wire = w.Wire();
      wiresProj.push_back(wire);
    }
    BRepBuilderAPI_MakeFace f(surf, wiresProj[0]);
    for(std::size_t i = 1; i < wiresProj.size(); i++) f.Add(wiresProj[i]);
    result = f.Face();
    // recover 3D curves for pcurves
    ShapeFix_Face fix(result);
    fix.Perform();
    result = fix.Face();
  }
  return true;
}

bool OCC_Internals::addBSplineSurface(
  int &tag, const std::vector<int> &pointTags, const int numPointsU,
  const int degreeU, const int degreeV, const std::vector<double> &weights,
  const std::vector<double> &knotsU, const std::vector<double> &knotsV,
  const std::vector<int> &multiplicitiesU,
  const std::vector<int> &multiplicitiesV, const std::vector<int> &wireTags,
  bool wire3D)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  // deal with default values
  if(numPointsU < 1) {
    Msg::Error("Wrong number of control points along U for BSpline surface");
    return false;
  }
  int numPointsV = pointTags.size() / numPointsU;
  if(numPointsU * numPointsV != (int)pointTags.size()) {
    Msg::Error("Wrong number of control points for BSpline surface");
    return false;
  }
  int dU = degreeU, dV = degreeV;
  std::vector<double> w(weights), kU(knotsU), kV(knotsV);
  std::vector<int> mU(multiplicitiesU), mV(multiplicitiesV);
  // degree 3 if not specified...
  if(dU <= 0) dU = 3;
  if(dV <= 0) dV = 3;
  // ... or number of control points - 1 if not enough points
  if(dU > numPointsU - 1) dU = numPointsU - 1;
  if(dV > numPointsV - 1) dV = numPointsV - 1;
  // automatic default weights if not provided:
  if(w.empty()) w.resize(pointTags.size(), 1);
  if(w.size() != pointTags.size()) {
    Msg::Error("Wrong number of weights for BSpline surface");
    return false;
  }
  bool periodicU = true;
  for(int i = 0; i < numPointsV; i++) {
    if(pointTags[i * numPointsU] != pointTags[(i + 1) * numPointsU - 1]) {
      periodicU = false;
      break;
    }
  }
  bool periodicV = true;
  for(int i = 0; i < numPointsU; i++) {
    if(pointTags[i * numPointsV] != pointTags[(i + 1) * numPointsV - 1]) {
      periodicV = false;
      break;
    }
  }
  // automatic default knots and multiplicities along U if not provided:
  if(kU.empty()) {
    if(!periodicU) {
      int sumOfAllMultU = numPointsU + dU + 1;
      int numKnotsU = sumOfAllMultU - 2 * dU;
      if(numKnotsU < 2) {
        Msg::Error("Not enough control points along U for building BSpline of "
                   "degree %d x %d",
                   dU, dV);
        return false;
      }
      kU.resize(numKnotsU);
      for(std::size_t i = 0; i < kU.size(); i++) kU[i] = i;
      mU.resize(numKnotsU, 1);
      mU.front() = dU + 1;
      mU.back() = dU + 1;
    }
    else {
      kU.resize(numPointsU - dU + 2);
      for(std::size_t i = 0; i < kU.size(); i++) kU[i] = i;
      mU.resize(kU.size(), 1);
      mU.front() = dU - 1;
      mU.back() = dU - 1;
    }
  }
  if(kU.size() != mU.size()) {
    Msg::Error("Number of BSpline knots and multiplicities should be equal");
    return false;
  }
  // automatic default knots and multiplicities along V if not provided:
  if(kV.empty()) {
    if(!periodicV) {
      int sumOfAllMultV = numPointsV + dV + 1;
      int numKnotsV = sumOfAllMultV - 2 * dV;
      if(numKnotsV < 2) {
        Msg::Error("Not enough control points along V for building BSpline of "
                   "degree %d x %d",
                   dU, dV);
        return false;
      }
      kV.resize(numKnotsV);
      for(std::size_t i = 0; i < kV.size(); i++) kV[i] = i;
      mV.resize(numKnotsV, 1);
      mV.front() = dV + 1;
      mV.back() = dV + 1;
    }
    else {
      kV.resize(numPointsV - dV + 2);
      for(std::size_t i = 0; i < kV.size(); i++) kV[i] = i;
      mV.resize(kV.size(), 1);
      mV.front() = dV - 1;
      mV.back() = dV - 1;
    }
  }
  if(kV.size() != mV.size()) {
    Msg::Error("Number of BSpline knots and multiplicities should be equal");
    return false;
  }

  std::vector<TopoDS_Wire> wires;
  for(std::size_t i = 0; i < wireTags.size(); i++) {
    int wireTag = std::abs(wireTags[i]);
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    wires.push_back(wire);
  }

  TopoDS_Face result;
  try {
    std::vector<TopoDS_Vertex> corners;
    int npU = (periodicU ? numPointsU - 1 : numPointsU);
    int npV = (periodicV ? numPointsV - 1 : numPointsV);
    TColgp_Array2OfPnt pp(1, npU, 1, npV);
    for(int i = 1; i <= npU; i++) {
      for(int j = 1; j <= npV; j++) {
        int k = (j - 1) * numPointsU + (i - 1);
        if(!_tagVertex.IsBound(pointTags[k])) {
          Msg::Error("Unknown OpenCASCADE point with tag %d", pointTags[k]);
          return false;
        }
        TopoDS_Vertex vertex = TopoDS::Vertex(_tagVertex.Find(pointTags[k]));
        if((i == 1 && j == 1) || (i == 1 && j == npV) || (i == npU && j == 1) ||
           (i == npU && j == npV))
          corners.push_back(vertex);
        pp.SetValue(i, j, BRep_Tool::Pnt(vertex));
      }
    }
    TColStd_Array2OfReal ww(1, npU, 1, npV);
    for(int i = 1; i <= npU; i++) {
      for(int j = 1; j <= npV; j++) {
        int k = (j - 1) * numPointsU + (i - 1);
        ww.SetValue(i, j, w[k]);
      }
    }
    TColStd_Array1OfReal kkU(1, kU.size());
    for(std::size_t i = 1; i <= kU.size(); i++) kkU.SetValue(i, kU[i - 1]);
    TColStd_Array1OfReal kkV(1, kV.size());
    for(std::size_t i = 1; i <= kV.size(); i++) kkV.SetValue(i, kV[i - 1]);
    TColStd_Array1OfInteger mmU(1, mU.size());
    for(std::size_t i = 1; i <= mU.size(); i++) mmU.SetValue(i, mU[i - 1]);
    TColStd_Array1OfInteger mmV(1, mV.size());
    for(std::size_t i = 1; i <= mV.size(); i++) mmV.SetValue(i, mV[i - 1]);
    Handle(Geom_BSplineSurface) surf = new Geom_BSplineSurface(
      pp, ww, kkU, kkV, mmU, mmV, dU, dV, periodicU, periodicV);
    makeTrimmedSurface(surf, wires, wire3D, result);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addBezierSurface(int &tag,
                                     const std::vector<int> &pointTags,
                                     const int numPointsU,
                                     const std::vector<int> &wireTags,
                                     bool wire3D)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  // deal with default values
  if(numPointsU < 1) {
    Msg::Error("Wrong number of control points along U for Bezier surface");
    return false;
  }
  int numPointsV = pointTags.size() / numPointsU;
  if(numPointsU * numPointsV != (int)pointTags.size()) {
    Msg::Error("Wrong number of control points for Bezier surface");
    return false;
  }

  std::vector<TopoDS_Wire> wires;
  for(std::size_t i = 0; i < wireTags.size(); i++) {
    int wireTag = std::abs(wireTags[i]);
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    wires.push_back(wire);
  }

  TopoDS_Face result;
  try {
    TColgp_Array2OfPnt pp(1, numPointsU, 1, numPointsV);
    for(int i = 1; i <= numPointsU; i++) {
      for(int j = 1; j <= numPointsV; j++) {
        int k = (j - 1) * numPointsU + (i - 1);
        if(!_tagVertex.IsBound(pointTags[k])) {
          Msg::Error("Unknown OpenCASCADE point with tag %d", pointTags[k]);
          return false;
        }
        TopoDS_Vertex vertex = TopoDS::Vertex(_tagVertex.Find(pointTags[k]));
        pp.SetValue(i, j, BRep_Tool::Pnt(vertex));
      }
    }
    Handle(Geom_BezierSurface) surf = new Geom_BezierSurface(pp);
    makeTrimmedSurface(surf, wires, wire3D, result);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addTrimmedSurface(int &tag, int surfaceTag,
                                      const std::vector<int> &wireTags,
                                      bool wire3D)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  if(!_tagFace.IsBound(surfaceTag)) {
    Msg::Error("Unknown OpenCASCADE surface with tag %d", surfaceTag);
    return false;
  }
  TopoDS_Face face = TopoDS::Face(_tagFace.Find(surfaceTag));

  std::vector<TopoDS_Wire> wires;
  for(std::size_t i = 0; i < wireTags.size(); i++) {
    int wireTag = std::abs(wireTags[i]);
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    wires.push_back(wire);
  }

  TopoDS_Face result;
  try {
    Handle(Geom_Surface) surf = BRep_Tool::Surface(face);
    makeTrimmedSurface(surf, wires, wire3D, result);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addSurfaceLoop(int &tag,
                                   const std::vector<int> &surfaceTags,
                                   bool sewing)
{
  if(tag >= 0 && _tagShell.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface loop with tag %d already exists", tag);
    return false;
  }

  if(sewing) {
    // this allows to build a shell made of surfaces that share geometrically
    // identical (but topologically different) curves.
    TopoDS_Shape result;
    try {
      BRepBuilderAPI_Sewing s;
      for(std::size_t i = 0; i < surfaceTags.size(); i++) {
        if(!_tagFace.IsBound(surfaceTags[i])) {
          Msg::Error("Unknown OpenCASCADE surface with tag %d", surfaceTags[i]);
          return false;
        }
        TopoDS_Face face = TopoDS::Face(_tagFace.Find(surfaceTags[i]));
        s.Add(face);
      }
      s.Perform();
      result = s.SewedShape();
    } catch(Standard_Failure &err) {
      Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
      return false;
    }
    bool first = true;
    TopExp_Explorer exp0;
    for(exp0.Init(result, TopAbs_SHELL); exp0.More(); exp0.Next()) {
      TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
      if(CTX::instance()->geom.occAutoFix) {
        // make sure faces in shell are oriented correctly
        ShapeFix_Shell fix(shell);
        fix.Perform();
        shell = fix.Shell();
      }
      int t = tag;
      if(first) { first = false; }
      else {
        t = getMaxTag(-2) + 1;
        Msg::Warning("Creating additional surface loop %d", t);
      }
      bind(shell, t, true);
      return true;
    }
  }

  try {
    BRep_Builder builder;
    BRepPrim_Builder b(builder);
    TopoDS_Shell shell;
    b.MakeShell(shell);
    for(std::size_t i = 0; i < surfaceTags.size(); i++) {
      if(!_tagFace.IsBound(surfaceTags[i])) {
        Msg::Error("Unknown OpenCASCADE surface with tag %d", surfaceTags[i]);
        return false;
      }
      TopoDS_Face face = TopoDS::Face(_tagFace.Find(surfaceTags[i]));
      b.AddShellFace(shell, face);
    }
    if(CTX::instance()->geom.occAutoFix) {
      // make sure faces in shell are oriented correctly
      ShapeFix_Shell fix(shell);
      fix.Perform();
      shell = fix.Shell();
    }
    bind(shell, tag, true);
    return true;
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
}

bool OCC_Internals::addVolume(int &tag, const std::vector<int> &shellTags)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }

  TopoDS_Solid result;
  try {
    BRepBuilderAPI_MakeSolid s;
    for(std::size_t i = 0; i < shellTags.size(); i++) {
      if(!_tagShell.IsBound(shellTags[i])) {
        Msg::Error("Unknown OpenCASCADE surface loop with tag %d",
                   shellTags[i]);
        return false;
      }
      TopoDS_Shell shell = TopoDS::Shell(_tagShell.Find(shellTags[i]));
      s.Add(shell);
    }
    result = s.Solid();
    if(CTX::instance()->geom.occAutoFix) {
      // make sure the volume is finite
      ShapeFix_Solid fix(result);
      fix.Perform();
      result = TopoDS::Solid(fix.Solid());
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

static bool makeSphere(TopoDS_Solid &result, double xc, double yc, double zc,
                       double radius, double angle1, double angle2,
                       double angle3)
{
  if(radius <= 0) {
    Msg::Error("Sphere radius should be positive");
    return false;
  }
  if(angle3 <= 0 || angle3 > 2 * M_PI) {
    Msg::Error("Cannot build sphere with angle <= 0 or angle > 2*Pi");
    return false;
  }
  try {
    gp_Pnt p(xc, yc, zc);
    BRepPrimAPI_MakeSphere s(p, radius, angle1, angle2, angle3);
    s.Build();
    if(!s.IsDone()) {
      Msg::Error("Could not create sphere");
      return false;
    }
    result = TopoDS::Solid(s.Shape());
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addSphere(int &tag, double xc, double yc, double zc,
                              double radius, double angle1, double angle2,
                              double angle3)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!makeSphere(result, xc, yc, zc, radius, angle1, angle2, angle3))
    return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

static bool makeBox(TopoDS_Solid &result, double x, double y, double z,
                    double dx, double dy, double dz)
{
  if(!dx || !dy || !dz) {
    Msg::Error("Degenerate box");
    return false;
  }
  try {
    gp_Pnt P1(x, y, z);
    gp_Pnt P2(x + dx, y + dy, z + dz);
    BRepPrimAPI_MakeBox b(P1, P2);
    b.Build();
    if(!b.IsDone()) {
      Msg::Error("Could not create box");
      return false;
    }
    result = TopoDS::Solid(b.Shape());
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addBox(int &tag, double x, double y, double z, double dx,
                           double dy, double dz)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!makeBox(result, x, y, z, dx, dy, dz)) return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

static bool makeCylinder(TopoDS_Solid &result, double x, double y, double z,
                         double dx, double dy, double dz, double r,
                         double angle)
{
  const double H = sqrt(dx * dx + dy * dy + dz * dz);
  if(!H) {
    Msg::Error("Cannot build cylinder of zero height");
    return false;
  }
  if(angle <= 0 || angle > 2 * M_PI) {
    Msg::Error("Cannot build cylinder with angle <= 0 or angle > 2*Pi");
    return false;
  }
  try {
    gp_Pnt aP(x, y, z);
    gp_Vec aV(dx / H, dy / H, dz / H);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeCylinder c(anAxes, r, H, angle);
    c.Build();
    if(!c.IsDone()) {
      Msg::Error("Could not create cylinder");
      return false;
    }
    result = TopoDS::Solid(c.Shape());
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addCylinder(int &tag, double x, double y, double z,
                                double dx, double dy, double dz, double r,
                                double angle)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!makeCylinder(result, x, y, z, dx, dy, dz, r, angle)) return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

static bool makeTorus(TopoDS_Solid &result, double x, double y, double z,
                      double r1, double r2, double angle)
{
  if(r1 <= 0 || r2 <= 0) {
    Msg::Error("Torus radii should be positive");
    return false;
  }
  try {
    gp_Pnt aP(x, y, z);
    gp_Vec aV(0, 0, 1);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeTorus t(anAxes, r1, r2, angle);
    t.Build();
    if(!t.IsDone()) {
      Msg::Error("Could not create torus");
      return false;
    }
    result = TopoDS::Solid(t.Shape());
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addTorus(int &tag, double x, double y, double z, double r1,
                             double r2, double angle)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!makeTorus(result, x, y, z, r1, r2, angle)) return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

static bool makeCone(TopoDS_Solid &result, double x, double y, double z,
                     double dx, double dy, double dz, double r1, double r2,
                     double angle)
{
  const double H = sqrt(dx * dx + dy * dy + dz * dz);
  if(!H) {
    Msg::Error("Cannot build cone of zero height");
    return false;
  }
  if(angle <= 0) {
    Msg::Error("Cone angle should be positive");
    return false;
  }
  try {
    gp_Pnt aP(x, y, z);
    gp_Vec aV(dx / H, dy / H, dz / H);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeCone c(anAxes, r1, r2, H, angle);
    c.Build();
    if(!c.IsDone()) {
      Msg::Error("Could not create cone");
      return false;
    }
    result = TopoDS::Solid(c.Shape());
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addCone(int &tag, double x, double y, double z, double dx,
                            double dy, double dz, double r1, double r2,
                            double angle)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!makeCone(result, x, y, z, dx, dy, dz, r1, r2, angle)) return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

static bool makeWedge(TopoDS_Solid &result, double x, double y, double z,
                      double dx, double dy, double dz, double ltx)
{
  try {
    gp_Pnt aP(x, y, z);
    gp_Vec aV(0, 0, 1);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeWedge w(anAxes, dx, dy, dz, ltx);
    w.Build();
    if(!w.IsDone()) {
      Msg::Error("Could not create wedge");
      return false;
    }
    result = TopoDS::Solid(w.Shape());
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addWedge(int &tag, double x, double y, double z, double dx,
                             double dy, double dz, double ltx)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!makeWedge(result, x, y, z, dx, dy, dz, ltx)) return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  bind(result, tag, true);
  return true;
}

bool OCC_Internals::addThruSections(
  int tag, const std::vector<int> &wireTags, bool makeSolid, bool makeRuled,
  std::vector<std::pair<int, int> > &outDimTags, int maxDegree)
{
  int dim = makeSolid ? 3 : 2;
  if(tag >= 0 && _isBound(dim, tag)) {
    Msg::Error("OpenCASCADE entity of dimension %d with tag %d already exists",
               dim, tag);
    return false;
  }
  if(wireTags.size() < 2) {
    Msg::Error("ThruSections require at least 2 wires");
    return false;
  }
  TopoDS_Shape result;
  try {
    BRepOffsetAPI_ThruSections ts(makeSolid, makeRuled);
    // ts.SetContinuity(GeomAbs_C1);
    // Available choices:
    //    GeomAbs_C0, GeomAbs_G1, GeomAbs_C1, GeomAbs_G2, GeomAbs_C2,
    //    GeomAbs_C3, GeomAbs_CN

    // ts.SetCriteriumWeight(1, 1, 1);

    if(maxDegree > 0)
      ts.SetMaxDegree(maxDegree);
    else if(CTX::instance()->geom.occThruSectionsDegree > 0)
      ts.SetMaxDegree(CTX::instance()->geom.occThruSectionsDegree);

    // ts.SetParType(Approx_ChordLength);
    // Available choices:
    //    Approx_ChordLength, Approx_Centripetal, Approx_IsoParametric

    // ts.SetSmoothing(Standard_True);
    for(std::size_t i = 0; i < wireTags.size(); i++) {
      if(!_tagWire.IsBound(wireTags[i])) {
        Msg::Error("Unknown OpenCASCADE wire or line loop with tag %d",
                   wireTags[i]);
        return false;
      }
      TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTags[i]));
      if(makeSolid && !wire.Closed()) {
        Msg::Error("Making solid requires closed wires");
        return false;
      }
      ts.AddWire(wire);
    }
    ts.CheckCompatibility(Standard_False);
    ts.Build();
    if(!ts.IsDone()) {
      Msg::Error("Could not create ThruSection");
      return false;
    }
    result = ts.Shape();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  _multiBind(result, tag, outDimTags, true, true);
  return true;
}

bool OCC_Internals::addThickSolid(int tag, int solidTag,
                                  const std::vector<int> &excludeFaceTags,
                                  double offset,
                                  std::vector<std::pair<int, int> > &outDimTags)
{
  if(tag >= 0 && _isBound(3, tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  if(!_isBound(3, solidTag)) {
    Msg::Error("Unknown OpenCASCADE volume with tag %d", solidTag);
    return false;
  }
  TopoDS_Shape result;
  try {
    TopoDS_Shape shape = _find(3, solidTag);
    TopTools_ListOfShape exclude;
    for(std::size_t i = 0; i < excludeFaceTags.size(); i++) {
      if(!_tagFace.IsBound(excludeFaceTags[i])) {
        Msg::Error("Unknown OpenCASCADE surface with tag %d",
                   excludeFaceTags[i]);
        return false;
      }
      exclude.Append(_tagFace.Find(excludeFaceTags[i]));
    }
#if OCC_VERSION_HEX > 0x070400
    BRepOffsetAPI_MakeThickSolid ts;
    ts.MakeThickSolidByJoin(shape, exclude, offset,
                            CTX::instance()->geom.tolerance);
#else
    BRepOffsetAPI_MakeThickSolid ts(shape, exclude, offset,
                                    CTX::instance()->geom.tolerance);
    ts.Build();
#endif
    if(!ts.IsDone()) {
      Msg::Error("Could not build thick solid");
      return false;
    }
    result = ts.Shape();
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  _multiBind(result, tag, outDimTags, true, true);
  return true;
}

void OCC_Internals::_setExtrudedAttributes(
  const TopoDS_Compound &c, BRepSweep_Prism *p, BRepSweep_Revol *r,
  ExtrudeParams *e, double x, double y, double z, double dx, double dy,
  double dz, double ax, double ay, double az, double angle)
{
  if(!p && !r) return;

  bool extrude_attributes = (e ? true : false);

  if(extrude_attributes && r && angle >= 2 * M_PI) {
    // OCC removes the origin edge from e.g. disks, which makes it impossible to
    // generate the 2D surface mesh by extrusion of the 1D edge mesh
    Msg::Warning("Extruded meshes by revolution only for angle < 2*Pi");
    extrude_attributes = false;
  }

  TopExp_Explorer exp0;

  for(exp0.Init(c, TopAbs_FACE); exp0.More(); exp0.Next()) {
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    TopoDS_Shape bot = p ? p->FirstShape(face) : r->FirstShape(face);
    TopoDS_Shape top = p ? p->LastShape(face) : r->LastShape(face);
    if(extrude_attributes) {
      ExtrudeParams *ee = new ExtrudeParams(COPIED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      _attributes->insert(new OCCAttributes(2, top, ee, 2, bot));
    }
    TopoDS_Shape vol = p ? p->Shape(face) : r->Shape(face);
    if(extrude_attributes) {
      ExtrudeParams *ee = new ExtrudeParams(EXTRUDED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      _attributes->insert(new OCCAttributes(3, vol, ee, 2, bot));
    }
  }

  for(exp0.Init(c, TopAbs_EDGE); exp0.More(); exp0.Next()) {
    TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
    TopoDS_Shape bot = p ? p->FirstShape(edge) : r->FirstShape(edge);
    TopoDS_Shape top = p ? p->LastShape(edge) : r->LastShape(edge);
    if(extrude_attributes) {
      ExtrudeParams *ee = new ExtrudeParams(COPIED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      _attributes->insert(new OCCAttributes(1, top, ee, 1, bot));
    }
    TopoDS_Shape sur = p ? p->Shape(edge) : r->Shape(edge);
    if(extrude_attributes) {
      ExtrudeParams *ee = new ExtrudeParams(EXTRUDED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      _attributes->insert(new OCCAttributes(2, sur, ee, 1, bot));
    }
  }

  for(exp0.Init(c, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
    TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
    TopoDS_Shape bot = p ? p->FirstShape(vertex) : r->FirstShape(vertex);
    TopoDS_Shape top = p ? p->LastShape(vertex) : r->LastShape(vertex);
    TopoDS_Shape lin = p ? p->Shape(vertex) : r->Shape(vertex);
    if(extrude_attributes) {
      ExtrudeParams *ee = new ExtrudeParams(EXTRUDED_ENTITY);
      ee->fill(p ? TRANSLATE : ROTATE, dx, dy, dz, ax, ay, az, x, y, z, angle);
      ee->mesh = e->mesh;
      _attributes->insert(new OCCAttributes(1, lin, ee, 0, bot));
    }
    {
      double lc = _attributes->getMeshSize(0, bot);
      if(lc > 0 && lc < MAX_LC)
        _attributes->insert(new OCCAttributes(0, top, lc));
    }
  }
}

int OCC_Internals::_getFuzzyTag(int dim, const TopoDS_Shape &s)
{
  if(_isBound(dim, s)) return _find(dim, s);

  std::vector<TopoDS_Shape> candidates;
  _attributes->getSimilarShapes(dim, s, candidates);

  int num = 0;
  for(std::size_t i = 0; i < candidates.size(); i++) {
    if(_isBound(dim, candidates[i])) { num++; }
  }
  Msg::Debug("Extruded mesh constraint fuzzy search: found %d candidates "
             "(dim=%d, %d bound)",
             (int)candidates.size(), dim, num);
  for(std::size_t i = 0; i < candidates.size(); i++) {
    if(_isBound(dim, candidates[i])) { return _find(dim, candidates[i]); }
  }
  return -1;
}

void OCC_Internals::_copyExtrudedAttributes(TopoDS_Edge edge, GEdge *ge)
{
  int sourceDim = -1;
  TopoDS_Shape sourceShape;
  ExtrudeParams *e =
    _attributes->getExtrudeParams(1, edge, sourceDim, sourceShape);
  if(!e) return;
  if(e->geo.Mode == EXTRUDED_ENTITY) {
    e->geo.Source = _getFuzzyTag(0, sourceShape);
  }
  else if(e->geo.Mode == COPIED_ENTITY) {
    e->geo.Source = _getFuzzyTag(1, sourceShape);
    // detect degenerate extrusions or cycles
    ExtrudeParams *p = e;
    int recur = 0;
    while(++recur < CTX::instance()->mesh.maxRetries) {
      if(ge->tag() == p->geo.Source) {
        Msg::Info("Extrusion layer cycle detected for curve %d", ge->tag());
        e = nullptr;
        break;
      }
      GEdge *src = ge->model()->getEdgeByTag(p->geo.Source);
      if(src && src->meshAttributes.extrude &&
         src->meshAttributes.extrude->geo.Mode == COPIED_ENTITY) {
        p = src->meshAttributes.extrude;
      }
      else {
        break;
      }
    }
  }
  ge->meshAttributes.extrude = e;
}

void OCC_Internals::_copyExtrudedAttributes(TopoDS_Face face, GFace *gf)
{
  int sourceDim = -1;
  TopoDS_Shape sourceShape;
  ExtrudeParams *e =
    _attributes->getExtrudeParams(2, face, sourceDim, sourceShape);
  if(!e) return;
  if(e->geo.Mode == EXTRUDED_ENTITY) {
    e->geo.Source = _getFuzzyTag(1, sourceShape);
  }
  else if(e->geo.Mode == COPIED_ENTITY) {
    e->geo.Source = _getFuzzyTag(2, sourceShape);
    // detect degenerate extrusions or cycles
    ExtrudeParams *p = e;
    int recur = 0;
    while(++recur < CTX::instance()->mesh.maxRetries) {
      if(gf->tag() == p->geo.Source) {
        Msg::Info("Extrusion layer cycle detected for surface %d", gf->tag());
        e = nullptr;
        break;
      }
      GFace *src = gf->model()->getFaceByTag(p->geo.Source);
      if(src && src->meshAttributes.extrude &&
         src->meshAttributes.extrude->geo.Mode == COPIED_ENTITY) {
        p = src->meshAttributes.extrude;
      }
      else {
        break;
      }
    }
  }
  gf->meshAttributes.extrude = e;
}

void OCC_Internals::_copyExtrudedAttributes(TopoDS_Solid solid, GRegion *gr)
{
  int sourceDim = -1;
  TopoDS_Shape sourceShape;
  ExtrudeParams *e =
    _attributes->getExtrudeParams(3, solid, sourceDim, sourceShape);
  if(!e) return;
  if(e->geo.Mode == EXTRUDED_ENTITY) {
    e->geo.Source = _getFuzzyTag(2, sourceShape);
  }
  gr->meshAttributes.extrude = e;
}

template <class T>
static int getReturnedShapes(const TopoDS_Compound &c, T *sweep,
                             std::vector<TopoDS_Shape> &top,
                             std::vector<TopoDS_Shape> &body,
                             std::vector<std::vector<TopoDS_Shape> > &lateral)
{
  TopExp_Explorer exp0, exp1;
  for(exp0.Init(c, TopAbs_FACE); exp0.More(); exp0.Next()) {
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    top.push_back(sweep->LastShape(face));
    body.push_back(sweep->Shape(face));
    lateral.push_back(std::vector<TopoDS_Shape>());
    for(exp1.Init(face, TopAbs_EDGE); exp1.More(); exp1.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
      lateral.back().push_back(sweep->Shape(edge));
    }
  }
  if(top.size()) return 3;
  for(exp0.Init(c, TopAbs_EDGE); exp0.More(); exp0.Next()) {
    TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
    top.push_back(sweep->LastShape(edge));
    body.push_back(sweep->Shape(edge));
    lateral.push_back(std::vector<TopoDS_Shape>());
    for(exp1.Init(edge, TopAbs_VERTEX); exp1.More(); exp1.Next()) {
      TopoDS_Vertex vertex = TopoDS::Vertex(exp1.Current());
      lateral.back().push_back(sweep->Shape(vertex));
    }
  }
  if(top.size()) return 2;
  for(exp0.Init(c, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
    TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
    top.push_back(sweep->LastShape(vertex));
    body.push_back(sweep->Shape(vertex));
  }
  if(top.size()) return 1;
  return 0;
}

bool OCC_Internals::_extrudePerDim(
  int mode, int inDim, const std::vector<int> &inTags, double x, double y,
  double z, double dx, double dy, double dz, double ax, double ay, double az,
  double angle, int wireTag, std::vector<std::pair<int, int> > &outDimTags,
  ExtrudeParams *e, const std::string &trihedron)
{
  // build a single compound shape, so that we won't duplicate internal
  // boundaries
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(std::size_t i = 0; i < inTags.size(); i++) {
    if(!_isBound(inDim, inTags[i])) {
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                 inDim, inTags[i]);
      return false;
    }
    TopoDS_Shape shape = _find(inDim, inTags[i]);
    b.Add(c, shape);
  }
  TopoDS_Shape result;
  std::vector<TopoDS_Shape> top, body;
  std::vector<std::vector<TopoDS_Shape> > lateral;
  int dim = -1;
  try {
    if(mode == 0) { // extrude
      BRepPrimAPI_MakePrism p(c, gp_Vec(dx, dy, dz), Standard_False);
      p.Build();
      if(!p.IsDone()) {
        Msg::Error("Could not extrude");
        return false;
      }
      result = p.Shape();
      const BRepSweep_Prism &prism(p.Prism());
      _setExtrudedAttributes(c, (BRepSweep_Prism *)&prism, nullptr, e, 0., 0.,
                             0., dx, dy, dz, 0., 0., 0., 0.);
      dim = getReturnedShapes(c, (BRepSweep_Prism *)&prism, top, body, lateral);
    }
    else if(mode == 1) { // revolve
      gp_Ax1 axisOfRevolution(gp_Pnt(x, y, z), gp_Dir(ax, ay, az));
      BRepPrimAPI_MakeRevol r(c, axisOfRevolution, angle, Standard_False);
      r.Build();
      if(!r.IsDone()) {
        Msg::Error("Could not revolve");
        return false;
      }
      result = r.Shape();
      const BRepSweep_Revol &revol(r.Revol());
      _setExtrudedAttributes(c, nullptr, (BRepSweep_Revol *)&revol, e, x, y, z,
                             0., 0., 0., ax, ay, az, angle);
      dim = getReturnedShapes(c, (BRepSweep_Revol *)&revol, top, body, lateral);
    }
    else if(mode == 2) { // pipe
      if(!_tagWire.IsBound(wireTag)) {
        Msg::Error("Unknown OpenCASCADE wire with tag %d", wireTag);
        return false;
      }
      TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
      // DiscreteTrihedron seems the most robust; CorrectedFrenet e.g. fails on
      // very simple cases with straight extrusions.
      GeomFill_Trihedron mode = GeomFill_IsDiscreteTrihedron;
      if(trihedron == "" || trihedron == "DiscreteTrihedron")
        mode = GeomFill_IsDiscreteTrihedron;
      else if(trihedron == "CorrectedFrenet")
        mode = GeomFill_IsCorrectedFrenet;
      else if(trihedron == "Fixed")
        mode = GeomFill_IsFixed;
      else if(trihedron == "Frenet")
        mode = GeomFill_IsFrenet;
      else if(trihedron == "ConstantNormal")
        mode = GeomFill_IsConstantNormal;
      else if(trihedron == "Darboux")
        mode = GeomFill_IsDarboux;
      else if(trihedron == "GuideAC")
        mode = GeomFill_IsGuideAC;
      else if(trihedron == "GuidePlan")
        mode = GeomFill_IsGuidePlan;
      else if(trihedron == "GuideACWithContact")
        mode = GeomFill_IsGuideACWithContact;
      else if(trihedron == "GuidePlanWithContact")
        mode = GeomFill_IsGuidePlanWithContact;
      else
        Msg::Warning(
          "Unknown trihedron mode for pipe: using 'DiscreteTrihedron'");
      BRepOffsetAPI_MakePipe p(wire, c, mode);
      p.Build();
      if(!p.IsDone()) {
        Msg::Error("Could not create pipe");
        return false;
      }
      result = p.Shape();
      // const BRepFill_Pipe &pipe(p.Pipe());
      if(e)
        Msg::Warning(
          "Structured meshes not yet available with OpenCASCADE pipe");
      // Check if
      //   pipe.FirstShape() gives us "bottom"
      //   pipe.LastShape() gives us "top"
      //   pipe.Shape() gives us "body"
      //   using pipe.Spine(), pipe.{Face,Edge}(spine, c) gives us the lateral
      //     entities
      // dim = getReturnedShapesForPipe(c, pipe, top, body, lateral);
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  _multiBind(result, -1, outDimTags, true, true);

  // return entities in the same order as the built-in kernel extrusion
  if(dim >= 1 && dim <= 3 && top.size() == inTags.size() &&
     top.size() == body.size()) {
    outDimTags.clear();
    for(std::size_t i = 0; i < top.size(); i++) {
      if(_isBound(dim - 1, top[i]))
        outDimTags.push_back(
          std::pair<int, int>(dim - 1, _find(dim - 1, top[i])));
      if(_isBound(dim, body[i]))
        outDimTags.push_back(std::pair<int, int>(dim, _find(dim, body[i])));
      if(CTX::instance()->geom.extrudeReturnLateral &&
         top.size() == lateral.size()) {
        for(std::size_t j = 0; j < lateral[i].size(); j++) {
          if(_isBound(dim - 1, lateral[i][j]))
            outDimTags.push_back(
              std::pair<int, int>(dim - 1, _find(dim - 1, lateral[i][j])));
        }
      }
    }
  }
  return true;
}

bool OCC_Internals::_extrude(int mode,
                             const std::vector<std::pair<int, int> > &inDimTags,
                             double x, double y, double z, double dx, double dy,
                             double dz, double ax, double ay, double az,
                             double angle, int wireTag,
                             std::vector<std::pair<int, int> > &outDimTags,
                             ExtrudeParams *e, const std::string &trihedron)
{
  std::vector<int> inTags[4];
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    if(dim < 0 || dim > 3) {
      Msg::Error("Wrong input dimension in extrusion");
      return false;
    }
    inTags[dim].push_back(inDimTags[i].second);
  }
  for(int dim = 0; dim < 4; dim++) {
    if(!inTags[dim].empty()) {
      std::vector<std::pair<int, int> > out;
      if(_extrudePerDim(mode, dim, inTags[dim], x, y, z, dx, dy, dz, ax, ay, az,
                        angle, wireTag, out, e, trihedron)) {
        outDimTags.insert(outDimTags.end(), out.begin(), out.end());
      }
    }
  }
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
                            double x, double y, double z, double ax, double ay,
                            double az, double angle,
                            std::vector<std::pair<int, int> > &outDimTags,
                            ExtrudeParams *e)
{
  return _extrude(1, inDimTags, x, y, z, 0., 0., 0., ax, ay, az, angle, 0,
                  outDimTags, e);
}

bool OCC_Internals::addPipe(const std::vector<std::pair<int, int> > &inDimTags,
                            int wireTag,
                            std::vector<std::pair<int, int> > &outDimTags,
                            const std::string &trihedron)
{
  return _extrude(2, inDimTags, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., wireTag,
                  outDimTags, nullptr, trihedron);
}

bool OCC_Internals::_fillet(int mode, const std::vector<int> &volumeTags,
                            const std::vector<int> &curveTags,
                            const std::vector<int> &surfaceTags,
                            const std::vector<double> &param,
                            std::vector<std::pair<int, int> > &outDimTags,
                            bool removeVolume)
{
  std::vector<TopoDS_Edge> edges;
  for(std::size_t i = 0; i < curveTags.size(); i++) {
    if(!_tagEdge.IsBound(curveTags[i])) {
      Msg::Error("Unknown OpenCASCADE curve with tag %d", curveTags[i]);
      return false;
    }
    edges.push_back(TopoDS::Edge(_tagEdge.Find(curveTags[i])));
  }

  std::vector<TopoDS_Face> faces;
  for(std::size_t i = 0; i < surfaceTags.size(); i++) {
    if(!_tagFace.IsBound(surfaceTags[i])) {
      Msg::Error("Unknown OpenCASCADE surface with tag %d", surfaceTags[i]);
      return false;
    }
    faces.push_back(TopoDS::Face(_tagFace.Find(surfaceTags[i])));
  }
  if(mode && edges.size() != faces.size()) {
    Msg::Error("Different number of curves and surfaces for chamfer");
    return false;
  }

  // build a single compound shape
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(std::size_t i = 0; i < volumeTags.size(); i++) {
    if(!_isBound(3, volumeTags[i])) {
      Msg::Error("Unknown OpenCASCADE volume with tag %d", volumeTags[i]);
      return false;
    }
    TopoDS_Shape shape = _find(3, volumeTags[i]);
    if(removeVolume) unbind(shape, 3, volumeTags[i], true);
    if(CTX::instance()->geom.occAutoFix) {
      // make sure the volume is finite
      ShapeFix_Solid fix(TopoDS::Solid(shape));
      fix.Perform();
      shape = fix.Solid();
    }
    b.Add(c, shape);
  }
  TopoDS_Shape result;
  try {
    if(mode == 0) { // fillet
      BRepFilletAPI_MakeFillet f(c);
      for(std::size_t i = 0; i < edges.size(); i++) {
        if(param.size() == 1)
          f.Add(param[0], edges[i]);
        else if(param.size() == edges.size())
          f.Add(param[i], edges[i]);
        else if(param.size() == 2 * edges.size())
          f.Add(param[2 * i], param[2 * i + 1], edges[i]);
      }
      f.Build();
      if(!f.IsDone()) {
        Msg::Error("Could not compute fillet");
        return false;
      }
      result = f.Shape();
    }
    else { // chamfer
      BRepFilletAPI_MakeChamfer f(c);
      for(std::size_t i = 0; i < edges.size(); i++) {
        if(param.size() == 1)
          f.Add(param[0], param[0], edges[i], faces[i]);
        else if(param.size() == edges.size())
          f.Add(param[i], param[i], edges[i], faces[i]);
        else if(param.size() == 2 * edges.size())
          f.Add(param[2 * i], param[2 * i + 1], edges[i], faces[i]);
      }
      f.Build();
      if(!f.IsDone()) {
        Msg::Error("Could not compute chamfer");
        return false;
      }
      result = f.Shape();
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(result.IsNull()) {
    Msg::Error("%s produces empty shape", mode ? "Chamfer" : "Fillet");
    return false;
  }

  // TODO: if removeVolume and CTX::instance()->geom.occBooleanPreserveNumbering
  // are set we could use Generated(), Modified() and IsDeleted() in a similar
  // way as what we do for boolean operation, in order to try to preserve tags

  _multiBind(result, -1, outDimTags, true, true);
  return true;
}

bool OCC_Internals::fillet(const std::vector<int> &volumeTags,
                           const std::vector<int> &curveTags,
                           const std::vector<double> &radii,
                           std::vector<std::pair<int, int> > &outDimTags,
                           bool removeVolume)
{
  std::vector<int> dummy;
  return _fillet(0, volumeTags, curveTags, dummy, radii, outDimTags,
                 removeVolume);
}

bool OCC_Internals::chamfer(const std::vector<int> &volumeTags,
                            const std::vector<int> &curveTags,
                            const std::vector<int> &surfaceTags,
                            const std::vector<double> &distances,
                            std::vector<std::pair<int, int> > &outDimTags,
                            bool removeVolume)
{
  return _fillet(1, volumeTags, curveTags, surfaceTags, distances, outDimTags,
                 removeVolume);
}

static void _filterTags(std::vector<std::pair<int, int> > &outDimTags,
                        int minDim)
{
  std::vector<std::pair<int, int> > tmp(outDimTags);
  outDimTags.clear();
  for(std::size_t i = 0; i < tmp.size(); i++) {
    if(tmp[i].first >= minDim) outDimTags.push_back(tmp[i]);
  }
}

bool OCC_Internals::booleanOperator(
  int tag, BooleanOperator op,
  const std::vector<std::pair<int, int> > &objectDimTags,
  const std::vector<std::pair<int, int> > &toolDimTags,
  std::vector<std::pair<int, int> > &outDimTags,
  std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
  bool removeObject, bool removeTool)
{
  double tolerance = CTX::instance()->geom.toleranceBoolean;
  bool parallel = CTX::instance()->geom.occParallel;
  bool preserveNumbering = CTX::instance()->geom.occBooleanPreserveNumbering;

  if(objectDimTags.empty()) return true;

  if(tag >= 0 && _isBound(objectDimTags[0].first, tag)) {
    Msg::Error("OpenCASCADE entity with tag %d already exists", tag);
    return false;
  }

  int minDim = 3;
  TopTools_ListOfShape objectShapes, toolShapes;
  for(std::size_t i = 0; i < objectDimTags.size(); i++) {
    int dim = objectDimTags[i].first;
    int t = objectDimTags[i].second;
    if(!_isBound(dim, t)) {
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
                 t);
      return false;
    }
    else {
      TopoDS_Shape object = _find(dim, t);
      objectShapes.Append(object);
    }
    minDim = std::min(minDim, dim);
  }
  for(std::size_t i = 0; i < toolDimTags.size(); i++) {
    int dim = toolDimTags[i].first;
    int t = toolDimTags[i].second;
    if(!_isBound(dim, t)) {
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
                 t);
      return false;
    }
    else {
      TopoDS_Shape tool = _find(dim, t);
      toolShapes.Append(tool);
    }
    minDim = std::min(minDim, dim);
  }

  TopoDS_Shape result;
  std::vector<TopoDS_Shape> mapOriginal;
  std::vector<TopTools_ListOfShape> mapModified, mapGenerated;
  std::vector<bool> mapDeleted;
  try {
    switch(op) {
    case OCC_Internals::Union: {
      BRepAlgoAPI_Fuse fuse;
      fuse.SetRunParallel(parallel);
      fuse.SetArguments(objectShapes);
      fuse.SetTools(toolShapes);
      if(tolerance > 0.0) fuse.SetFuzzyValue(tolerance);
      fuse.Build();
      if(!fuse.IsDone()) {
        Msg::Error("Fuse operation cannot be performed");
        return false;
      }
      result = fuse.Shape();
      // try to unify faces and edges of the shape (remove internal seams) which
      // lie on the same geometry
      if(CTX::instance()->geom.occUnionUnify) {
        ShapeUpgrade_UnifySameDomain unify(result);
        unify.Build();
        result = unify.Shape();
      }
      TopTools_ListIteratorOfListOfShape it(objectShapes);
      for(; it.More(); it.Next()) {
        mapOriginal.push_back(it.Value());
        mapModified.push_back(fuse.Modified(it.Value()));
        mapDeleted.push_back(fuse.IsDeleted(it.Value()));
        mapGenerated.push_back(fuse.Generated(it.Value()));
      }
      TopTools_ListIteratorOfListOfShape it2(toolShapes);
      for(; it2.More(); it2.Next()) {
        mapOriginal.push_back(it2.Value());
        mapModified.push_back(fuse.Modified(it2.Value()));
        mapDeleted.push_back(fuse.IsDeleted(it2.Value()));
        mapGenerated.push_back(fuse.Generated(it2.Value()));
      }
    } break;
    case OCC_Internals::Intersection: {
      BRepAlgoAPI_Common common;
      common.SetRunParallel(parallel);
      common.SetArguments(objectShapes);
      common.SetTools(toolShapes);
      if(tolerance > 0.0) common.SetFuzzyValue(tolerance);
      common.Build();
      if(!common.IsDone()) {
        Msg::Error("Intersection operation cannot be performed");
        return false;
      }
      result = common.Shape();
      TopTools_ListIteratorOfListOfShape it(objectShapes);
      for(; it.More(); it.Next()) {
        mapOriginal.push_back(it.Value());
        mapModified.push_back(common.Modified(it.Value()));
        mapDeleted.push_back(common.IsDeleted(it.Value()));
        mapGenerated.push_back(common.Generated(it.Value()));
      }
      TopTools_ListIteratorOfListOfShape it2(toolShapes);
      for(; it2.More(); it2.Next()) {
        mapOriginal.push_back(it2.Value());
        mapModified.push_back(common.Modified(it2.Value()));
        mapDeleted.push_back(common.IsDeleted(it2.Value()));
        mapGenerated.push_back(common.Generated(it2.Value()));
      }
    } break;

    case OCC_Internals::Difference: {
      BRepAlgoAPI_Cut cut;
      cut.SetRunParallel(parallel);
      cut.SetArguments(objectShapes);
      cut.SetTools(toolShapes);
      if(tolerance > 0.0) cut.SetFuzzyValue(tolerance);
      cut.Build();
      if(!cut.IsDone()) {
        Msg::Error("Intersection operation cannot be performed");
        return false;
      }
      result = cut.Shape();
      TopTools_ListIteratorOfListOfShape it(objectShapes);
      for(; it.More(); it.Next()) {
        mapOriginal.push_back(it.Value());
        mapModified.push_back(cut.Modified(it.Value()));
        mapDeleted.push_back(cut.IsDeleted(it.Value()));
        mapGenerated.push_back(cut.Generated(it.Value()));
      }
      TopTools_ListIteratorOfListOfShape it2(toolShapes);
      for(; it2.More(); it2.Next()) {
        mapOriginal.push_back(it2.Value());
        mapModified.push_back(cut.Modified(it2.Value()));
        mapDeleted.push_back(cut.IsDeleted(it2.Value()));
        mapGenerated.push_back(cut.Generated(it2.Value()));
      }
    } break;

    case OCC_Internals::Fragments:
    default: {
      BRepAlgoAPI_BuilderAlgo fragments;
      fragments.SetRunParallel(parallel);
      objectShapes.Append(toolShapes);
      toolShapes.Clear();
      fragments.SetArguments(objectShapes);
      if(tolerance > 0.0) fragments.SetFuzzyValue(tolerance);
      fragments.Build();
      if(!fragments.IsDone()) {
        Msg::Error("Boolean fragments failed");
        return false;
      }
      result = fragments.Shape();
      TopTools_ListIteratorOfListOfShape it(objectShapes);
      for(; it.More(); it.Next()) {
        mapOriginal.push_back(it.Value());
        mapModified.push_back(fragments.Modified(it.Value()));
        mapDeleted.push_back(fragments.IsDeleted(it.Value()));
        mapGenerated.push_back(fragments.Generated(it.Value()));
      }
    } break;
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  std::vector<std::pair<int, int> > inDimTags;
  inDimTags.insert(inDimTags.end(), objectDimTags.begin(), objectDimTags.end());
  inDimTags.insert(inDimTags.end(), toolDimTags.begin(), toolDimTags.end());
  std::size_t numObjects = objectDimTags.size();

  if(tag >= 0 || !preserveNumbering) {
    // if we specify the tag explicitly, or if we don't care about preserving
    // the numering, just go ahead and bind the resulting shape (and sub-shapes)
    for(std::size_t i = 0; i < inDimTags.size(); i++) {
      bool remove = (i < numObjects) ? removeObject : removeTool;
      if(remove) {
        int d = inDimTags[i].first;
        int t = inDimTags[i].second;
        if(_isBound(d, t)) unbind(_find(d, t), d, t, true);
      }
    }
    _multiBind(result, tag, outDimTags, (tag >= 0) ? true : false, true,
               (tag >= 0) ? false : true);
    _filterTags(outDimTags, minDim);
  }
  else {
    // otherwise, try to preserve the numbering of the input shapes that did not
    // change, or that were replaced by a single shape. Note that to preserve
    // the numbering of smaller dimension entities (on boundaries) they should
    // appear *before* higher dimensional entities in the object/tool lists.
    _toPreserve.clear();
    for(std::size_t i = 0; i < inDimTags.size(); i++) {
      int dim = inDimTags[i].first;
      int tag = inDimTags[i].second;
      bool remove = (i < numObjects) ? removeObject : removeTool;
      if(mapDeleted[i]) { // deleted
        if(remove) unbind(mapOriginal[i], dim, tag, true);
        Msg::Debug("BOOL (%d,%d) deleted", dim, tag);
      }
      else if(mapModified[i].Extent() == 0) { // not modified
        auto ins = _toPreserve.insert(std::pair<int, int>(dim, tag));
        if(ins.second) // it's not yet in outDimTags
          outDimTags.push_back(std::pair<int, int>(dim, tag));
        Msg::Debug("BOOL (%d,%d) not modified", dim, tag);
      }
      else if(mapModified[i].Extent() == 1) { // replaced by single one
        if(remove) {
          unbind(mapOriginal[i], dim, tag, true);
          bind(mapModified[i].First(), dim, tag, false); // not recursive!
          int t = _find(dim, mapModified[i].First());
          if(tag != t)
            Msg::Info("Could not preserve tag of %dD object %d (->%d)", dim,
                      tag, t);
          auto ins = _toPreserve.insert(std::pair<int, int>(dim, t));
          if(ins.second) // it's not yet in outDimTags
            outDimTags.push_back(std::pair<int, int>(dim, t));
        }
        Msg::Debug("BOOL (%d,%d) replaced by 1", dim, tag);
      }
      else {
        if(remove) unbind(mapOriginal[i], dim, tag, true);
        Msg::Debug("BOOL (%d,%d) other", dim, tag);
      }
    }
    for(int dim = -2; dim <= 3; dim++) _recomputeMaxTag(dim);
    // bind all remaining entities and add the new ones to the returned list
    _multiBind(result, -1, outDimTags, false, true, true);
    _filterTags(outDimTags, minDim);
    _toPreserve.clear();
  }

  // return input/output correspondance maps
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    std::pair<int, int> dimTag(dim, tag);
    std::vector<std::pair<int, int> > dimTags;
    if(mapDeleted[i]) { // deleted
    }
    else if(mapModified[i].Extent() == 0) { // not modified
      if(_isBound(dim, tag)) dimTags.push_back(dimTag);
    }
    else {
      TopTools_ListIteratorOfListOfShape it(mapModified[i]);
      for(; it.More(); it.Next()) {
        if(_isBound(dim, it.Value())) {
          int t = _find(dim, it.Value());
          dimTags.push_back(std::pair<int, int>(dim, t));
        }
      }
      TopTools_ListIteratorOfListOfShape it2(mapGenerated[i]);
      for(; it2.More(); it2.Next()) {
        if(_isBound(dim, it2.Value())) {
          int t = _find(dim, it2.Value());
          dimTags.push_back(std::pair<int, int>(dim, t));
        }
      }
    }
    std::ostringstream sstream;
    sstream << "BOOL in (" << dim << "," << tag << ") -> out";
    for(std::size_t j = 0; j < dimTags.size(); j++)
      sstream << " (" << dimTags[j].first << "," << dimTags[j].second << ")";
    Msg::Debug("%s", sstream.str().c_str());
    outDimTagsMap.push_back(dimTags);
  }

  return true;
}

bool OCC_Internals::booleanUnion(
  int tag, const std::vector<std::pair<int, int> > &objectDimTags,
  const std::vector<std::pair<int, int> > &toolDimTags,
  std::vector<std::pair<int, int> > &outDimTags,
  std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
  bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Union, objectDimTags, toolDimTags,
                         outDimTags, outDimTagsMap, removeObject, removeTool);
}

bool OCC_Internals::booleanIntersection(
  int tag, const std::vector<std::pair<int, int> > &objectDimTags,
  const std::vector<std::pair<int, int> > &toolDimTags,
  std::vector<std::pair<int, int> > &outDimTags,
  std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
  bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Intersection, objectDimTags,
                         toolDimTags, outDimTags, outDimTagsMap, removeObject,
                         removeTool);
}

bool OCC_Internals::booleanDifference(
  int tag, const std::vector<std::pair<int, int> > &objectDimTags,
  const std::vector<std::pair<int, int> > &toolDimTags,
  std::vector<std::pair<int, int> > &outDimTags,
  std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
  bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Difference, objectDimTags,
                         toolDimTags, outDimTags, outDimTagsMap, removeObject,
                         removeTool);
}

bool OCC_Internals::booleanFragments(
  int tag, const std::vector<std::pair<int, int> > &objectDimTags,
  const std::vector<std::pair<int, int> > &toolDimTags,
  std::vector<std::pair<int, int> > &outDimTags,
  std::vector<std::vector<std::pair<int, int> > > &outDimTagsMap,
  bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Fragments, objectDimTags,
                         toolDimTags, outDimTags, outDimTagsMap, removeObject,
                         removeTool);
}

int OCC_Internals::_getMaxDim()
{
  if(_tagSolid.Extent()) return 3;
  if(_tagFace.Extent()) return 2;
  if(_tagEdge.Extent()) return 1;
  return 0;
}

void OCC_Internals::_getAllDimTags(std::vector<std::pair<int, int> > &dimTags,
                                   int dim)
{
  for(int d = -2; d < 4; d++) {
    if(dim != 99 && dim != d) continue;
    TopTools_DataMapIteratorOfDataMapOfIntegerShape exp;
    switch(d) {
    case 0: exp.Initialize(_tagVertex); break;
    case 1: exp.Initialize(_tagEdge); break;
    case 2: exp.Initialize(_tagFace); break;
    case 3: exp.Initialize(_tagSolid); break;
    case -1: exp.Initialize(_tagWire); break;
    case -2: exp.Initialize(_tagShell); break;
    }
    for(; exp.More(); exp.Next())
      dimTags.push_back(std::pair<int, int>(d, exp.Key()));
  }
}

void OCC_Internals::removeAllDuplicates()
{
  std::vector<std::pair<int, int> > objectDimTags, toolDimTags, outDimTags;
  std::vector<std::vector<std::pair<int, int> > > outDimTagsMap;
  _getAllDimTags(objectDimTags, _getMaxDim());
  booleanFragments(-1, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
                   true, true);
}

bool OCC_Internals::mergeVertices(const std::vector<int> &tags)
{
  std::vector<std::pair<int, int> > objectDimTags, toolDimTags, outDimTags;
  std::vector<std::vector<std::pair<int, int> > > outDimTagsMap;
  for(std::size_t i = 0; i < tags.size(); i++)
    objectDimTags.push_back(std::pair<int, int>(0, tags[i]));
  return booleanFragments(-1, objectDimTags, toolDimTags, outDimTags,
                          outDimTagsMap, true, true);
}

void _addSimpleShapes(const TopoDS_Shape &shape,
                      std::vector<TopoDS_Shape> &simple)
{
  if(shape.ShapeType() != TopAbs_COMPOUND &&
     shape.ShapeType() != TopAbs_COMPSOLID) {
    simple.push_back(shape);
    return;
  }

  TopTools_MapOfShape mapShape;
  TopoDS_Iterator It(shape, Standard_True, Standard_True);

  for(; It.More(); It.Next()) {
    const TopoDS_Shape &s = It.Value();
    if(mapShape.Add(s)) {
      if(s.ShapeType() == TopAbs_COMPOUND ||
         s.ShapeType() == TopAbs_COMPSOLID) {
        _addSimpleShapes(s, simple);
      }
      else {
        simple.push_back(s);
      }
    }
  }
}

bool OCC_Internals::_transform(
  const std::vector<std::pair<int, int> > &inDimTags,
  BRepBuilderAPI_Transform *tfo, BRepBuilderAPI_GTransform *gtfo)
{
  // build a single compound shape, so that we won't duplicate internal
  // boundaries
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(!_isBound(dim, tag)) {
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
                 tag);
      return false;
    }
    TopoDS_Shape shape = _find(dim, tag);
    b.Add(c, shape);
  }

  std::vector<TopoDS_Shape> inShapes;
  _addSimpleShapes(c, inShapes);

  TopoDS_Shape result;
  if(tfo) {
    tfo->Perform(c, Standard_False);
    if(!tfo->IsDone()) {
      Msg::Error("Could not apply transformation");
      return false;
    }
    result = tfo->Shape();
  }
  else if(gtfo) {
    gtfo->Perform(c, Standard_False);
    if(!gtfo->IsDone()) {
      Msg::Error("Could not apply transformation");
      return false;
    }
    result = gtfo->Shape();
  }

  // copy vertex-based meshing attributes
  TopExp_Explorer exp0;
  for(exp0.Init(c, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
    TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
    TopoDS_Shape transformed;
    if(tfo)
      transformed = tfo->ModifiedShape(vertex);
    else if(gtfo)
      transformed = gtfo->ModifiedShape(vertex);
    if(!transformed.IsNull()) {
      double lc = _attributes->getMeshSize(0, vertex);
      if(lc > 0 && lc < MAX_LC)
        _attributes->insert(new OCCAttributes(0, transformed, lc));
    }
  }

  // try to re-bind trasnformed shapes to same tags as original shapes
  std::vector<TopoDS_Shape> outShapes;
  _addSimpleShapes(result, outShapes);

  if(inShapes.size() != inDimTags.size() ||
     inShapes.size() != outShapes.size()) {
    Msg::Error("OpenCASCADE transform changed the number of shapes");
    return false;
  }
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    // FIXME we should implement rebind(object, result, dim) which would
    // unbind/bind all subshapes to the same tags
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    unbind(inShapes[i], dim, tag, true);
    bind(outShapes[i], dim, tag, true);
  }

  return true;
}

bool OCC_Internals::translate(
  const std::vector<std::pair<int, int> > &inDimTags, double dx, double dy,
  double dz)
{
  try {
    gp_Trsf t;
    t.SetTranslation(gp_Pnt(0, 0, 0), gp_Pnt(dx, dy, dz));
    BRepBuilderAPI_Transform tfo(t);
    return _transform(inDimTags, &tfo, nullptr);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
}

bool OCC_Internals::rotate(const std::vector<std::pair<int, int> > &inDimTags,
                           double x, double y, double z, double ax, double ay,
                           double az, double angle)
{
  try {
    gp_Trsf t;
    gp_Ax1 axisOfRevolution(gp_Pnt(x, y, z), gp_Dir(ax, ay, az));
    t.SetRotation(axisOfRevolution, angle);
    BRepBuilderAPI_Transform tfo(t);
    return _transform(inDimTags, &tfo, nullptr);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
}

bool OCC_Internals::dilate(const std::vector<std::pair<int, int> > &inDimTags,
                           double x, double y, double z, double a, double b,
                           double c)
{
  try {
    gp_GTrsf gt;
    gt.SetVectorialPart(gp_Mat(a, 0, 0, 0, b, 0, 0, 0, c));
    gt.SetTranslationPart(gp_XYZ(x * (1 - a), y * (1 - b), z * (1 - c)));
    BRepBuilderAPI_GTransform gtfo(gt);
    return _transform(inDimTags, nullptr, &gtfo);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
}

bool OCC_Internals::symmetry(const std::vector<std::pair<int, int> > &inDimTags,
                             double a, double b, double c, double d)
{
  try {
    gp_GTrsf gt;
    double p = (a * a + b * b + c * c);
    if(!p) p = 1e-12;
    double f = -2.0 / p;
    gt.SetVectorialPart(gp_Mat(1 + a * a * f, a * b * f, a * c * f, a * b * f,
                               1. + b * b * f, b * c * f, a * c * f, b * c * f,
                               1. + c * c * f));
    gt.SetTranslationPart(gp_XYZ(a * d * f, b * d * f, c * d * f));
    BRepBuilderAPI_GTransform gtfo(gt);
    return _transform(inDimTags, nullptr, &gtfo);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
}

bool OCC_Internals::affine(const std::vector<std::pair<int, int> > &inDimTags,
                           const std::vector<double> &mat)
{
  try {
    std::vector<double> a(mat);
    if(a.size() < 12) {
      Msg::Warning("%d < 12 entries in affine transform matrix", (int)a.size());
      a.resize(12, 0.);
    }
    gp_GTrsf gt;
    gt.SetVectorialPart(
      gp_Mat(a[0], a[1], a[2], a[4], a[5], a[6], a[8], a[9], a[10]));
    gt.SetTranslationPart(gp_XYZ(a[3], a[7], a[11]));
    BRepBuilderAPI_GTransform gtfo(gt);
    return _transform(inDimTags, nullptr, &gtfo);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
}

bool OCC_Internals::copy(const std::vector<std::pair<int, int> > &inDimTags,
                         std::vector<std::pair<int, int> > &outDimTags)
{
  bool ret = true;
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(!_isBound(dim, tag)) {
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
                 tag);
      ret = false;
      continue;
    }
    TopoDS_Shape result = BRepBuilderAPI_Copy(_find(dim, tag)).Shape();
    int newtag = getMaxTag(dim) + 1;
    bind(result, dim, newtag, true);
    outDimTags.push_back(std::pair<int, int>(dim, newtag));
  }
  return ret;
}

bool OCC_Internals::remove(int dim, int tag, bool recursive)
{
  if(!_isBound(dim, tag)) {
    Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
               tag);
    return false;
  }
  unbind(_find(dim, tag), dim, tag, recursive);
  return true;
}

bool OCC_Internals::remove(const std::vector<std::pair<int, int> > &dimTags,
                           bool recursive)
{
  bool ret = true;
  for(std::size_t i = 0; i < dimTags.size(); i++) {
    if(!remove(dimTags[i].first, dimTags[i].second, recursive)) ret = false;
  }
  return ret;
}

static void setTargetUnit(const std::string &unit)
{
  if(unit.empty()) return; // use unit specified in the file
  if(!Interface_Static::SetCVal("xstep.cascade.unit", unit.c_str()))
    Msg::Error("Could not set OpenCASCADE target unit '%s'", unit.c_str());
}

#if defined(HAVE_OCC_CAF)

static void setShapeAttributes(OCCAttributesRTree *attributes,
                               const Handle_XCAFDoc_ShapeTool &shapeTool,
                               const Handle_XCAFDoc_ColorTool &colorTool,
                               const Handle_XCAFDoc_MaterialTool &materialTool,
                               const TDF_Label &label,
                               const TopLoc_Location &loc,
                               const std::string &pathName, bool isRef)
{
  std::string phys = pathName;
  Handle(TDataStd_Name) n;
  if(label.FindAttribute(TDataStd_Name::GetID(), n)) {
    TCollection_ExtendedString name = n->Get();
    if(!phys.empty()) phys += "/";
    phys += TCollection_AsciiString(name).ToCString();
  }

  TopLoc_Location partLoc = loc;
  Handle(XCAFDoc_Location) l;
  if(label.FindAttribute(XCAFDoc_Location::GetID(), l)) {
    if(isRef)
      partLoc = partLoc * l->Get();
    else
      partLoc = l->Get();
  }

  TDF_Label ref;
  if(shapeTool->IsReference(label) && shapeTool->GetReferredShape(label, ref)) {
    setShapeAttributes(attributes, shapeTool, colorTool, materialTool, ref,
                       partLoc, phys, true);
  }

  if(shapeTool->IsSimpleShape(label) && (isRef || shapeTool->IsFree(label))) {
    TopoDS_Shape shape = shapeTool->GetShape(label);
    shape.Location(isRef ? loc : partLoc);
    int dim =
      (shape.ShapeType() == TopAbs_VERTEX) ? 0 :
      (shape.ShapeType() == TopAbs_EDGE || shape.ShapeType() == TopAbs_WIRE) ?
                                             1 :
      (shape.ShapeType() == TopAbs_FACE || shape.ShapeType() == TopAbs_SHELL) ?
                                             2 :
                                             3;

    Handle(TCollection_HAsciiString) matName;
    Handle(TCollection_HAsciiString) matDescription;
    Standard_Real matDensity;
    Handle(TCollection_HAsciiString) matDensName;
    Handle(TCollection_HAsciiString) matDensValType;
    if(materialTool->GetMaterial(label, matName, matDescription, matDensity,
                                 matDensName, matDensValType)) {
      if(!phys.empty()) phys += " & ";
      phys += matName->ToCString();
      Msg::Info(" - Label & material '%s' (%dD)", phys.c_str());
    }
    else if(phys.size()) {
      Msg::Info(" - Label '%s' (%dD)", phys.c_str(), dim);
    }
    if(phys.size()) { attributes->insert(new OCCAttributes(dim, shape, phys)); }

    Quantity_Color col;
    if(colorTool->GetColor(label, XCAFDoc_ColorGen, col)) {
      double r = col.Red(), g = col.Green(), b = col.Blue();
      Msg::Info(" - Color (%g, %g, %g) (%dD)", r, g, b, dim);
      attributes->insert(new OCCAttributes(dim, shape, r, g, b, 1.));
    }
    else if(colorTool->GetColor(label, XCAFDoc_ColorSurf, col)) {
      double r = col.Red(), g = col.Green(), b = col.Blue();
      Msg::Info(" - Color (%g, %g, %g) (%dD & Surfaces)", r, g, b, dim);
      attributes->insert(new OCCAttributes(dim, shape, r, g, b, 1., 1));
    }
    else if(colorTool->GetColor(label, XCAFDoc_ColorCurv, col)) {
      double r = col.Red(), g = col.Green(), b = col.Blue();
      Msg::Info(" - Color (%g, %g, %g) (%dD & Curves)", r, g, b, dim);
      attributes->insert(new OCCAttributes(dim, shape, r, g, b, 1., 2));
    }
    // check explicit coloring of boundary entities
    if(dim == 3) {
      TopExp_Explorer xp2(shape, TopAbs_FACE);
      while(xp2.More()) {
        if(colorTool->GetColor(xp2.Current(), XCAFDoc_ColorGen, col) ||
           colorTool->GetColor(xp2.Current(), XCAFDoc_ColorSurf, col) ||
           colorTool->GetColor(xp2.Current(), XCAFDoc_ColorCurv, col)) {
          double r = col.Red(), g = col.Green(), b = col.Blue();
          Msg::Info(" - Color (%g, %g, %g) (Surface)", r, g, b);
          TopoDS_Face face = TopoDS::Face(xp2.Current());
          attributes->insert(new OCCAttributes(2, face, r, g, b, 1.));
        }
        xp2.Next();
      }
    }
    if(dim == 2) {
      TopExp_Explorer xp1(shape, TopAbs_EDGE);
      while(xp1.More()) {
        if(colorTool->GetColor(xp1.Current(), XCAFDoc_ColorGen, col) ||
           colorTool->GetColor(xp1.Current(), XCAFDoc_ColorSurf, col) ||
           colorTool->GetColor(xp1.Current(), XCAFDoc_ColorCurv, col)) {
          double r = col.Red(), g = col.Green(), b = col.Blue();
          Msg::Info(" - Color (%g, %g, %g) (Curve)", r, g, b);
          attributes->insert(
            new OCCAttributes(1, TopoDS::Face(xp1.Current()), r, g, b, 1.));
        }
        xp1.Next();
      }
    }
  }
  else {
    for(TDF_ChildIterator it(label); it.More(); it.Next()) {
      setShapeAttributes(attributes, shapeTool, colorTool, materialTool,
                         it.Value(), partLoc, phys, isRef);
    }
  }
}

template <class T>
void readAttributes(OCCAttributesRTree *attributes, T &reader,
                    const std::string &format)
{
  // dummy XCAF Application to handle the STEP XCAF Document
  static Handle_XCAFApp_Application dummy_app =
    XCAFApp_Application::GetApplication();
  // XCAF Document to contain the STEP/IGES file itself
  Handle_TDocStd_Document doc;
  // check if a file is already open under this handle, if so, close it to
  // prevent segfaults when trying to create a new document
  if(dummy_app->NbDocuments() > 0) {
    dummy_app->GetDocument(1, doc);
    dummy_app->Close(doc);
  }
  dummy_app->NewDocument(format.c_str(), doc);
  // transfer STEP/IGES into the document, and get the main label
  reader.Transfer(doc);
  TDF_Label mainLabel = doc->Main();
  Handle_XCAFDoc_ShapeTool shapeTool =
    XCAFDoc_DocumentTool::ShapeTool(mainLabel);
  Handle_XCAFDoc_ColorTool colorTool =
    XCAFDoc_DocumentTool::ColorTool(mainLabel);
  Handle_XCAFDoc_MaterialTool materialTool =
    XCAFDoc_DocumentTool::MaterialTool(mainLabel);
  // traverse the labels recursively to set attributes on shapes
  setShapeAttributes(attributes, shapeTool, colorTool, materialTool, mainLabel,
                     TopLoc_Location(), "", false);
}

#endif

bool OCC_Internals::importShapes(const std::string &fileName,
                                 bool highestDimOnly,
                                 std::vector<std::pair<int, int> > &outDimTags,
                                 const std::string &format)
{
  std::vector<std::string> split = SplitFileName(fileName);

  TCollection_AsciiString occfile(fileName.c_str());

  TopoDS_Shape result;
  try {
    if(format == "brep" || split[2] == ".brep" || split[2] == ".BREP") {
      BRep_Builder aBuilder;
      BRepTools::Read(result, occfile.ToCString(), aBuilder);
    }
    else if(format == "step" || split[2] == ".step" || split[2] == ".stp" ||
            split[2] == ".STEP" || split[2] == ".STP") {
      STEPControl_Reader reader;
      setTargetUnit(CTX::instance()->geom.occTargetUnit);
#if defined(HAVE_OCC_CAF)
      STEPCAFControl_Reader cafreader;
      if(cafreader.ReadFile(occfile.ToCString()) != IFSelect_RetDone) {
        Msg::Error("Could not read file '%s'", fileName.c_str());
        return false;
      }
      if(CTX::instance()->geom.occImportLabels)
        readAttributes(_attributes, cafreader, "STEP-XCAF");
      reader = cafreader.ChangeReader();
#else
      if(reader.ReadFile(occfile.ToCString()) != IFSelect_RetDone) {
        Msg::Error("Could not read file '%s'", fileName.c_str());
        return false;
      }
#endif
      reader.NbRootsForTransfer();
      reader.TransferRoots();
      result = reader.OneShape();
    }
    else if(format == "iges" || split[2] == ".iges" || split[2] == ".igs" ||
            split[2] == ".IGES" || split[2] == ".IGS") {
      setTargetUnit(CTX::instance()->geom.occTargetUnit);
#if defined(HAVE_OCC_CAF)
      IGESCAFControl_Reader reader;
      if(reader.ReadFile(occfile.ToCString()) != IFSelect_RetDone) {
        Msg::Error("Could not read file '%s'", fileName.c_str());
        return false;
      }
      if(CTX::instance()->geom.occImportLabels)
        readAttributes(_attributes, reader, "IGES-XCAF");
#else
      IGESControl_Reader reader;
      if(reader.ReadFile(occfile.ToCString()) != IFSelect_RetDone) {
        Msg::Error("Could not read file '%s'", fileName.c_str());
        return false;
      }
#endif
      reader.NbRootsForTransfer();
      reader.TransferRoots();
      result = reader.OneShape();
    }
    else {
      Msg::Error("Unknown file type '%s'", fileName.c_str());
      return false;
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  BRepTools::Clean(result);

  _healShape(
    result, CTX::instance()->geom.tolerance,
    CTX::instance()->geom.occFixDegenerated,
    CTX::instance()->geom.occFixSmallEdges,
    CTX::instance()->geom.occFixSmallFaces, CTX::instance()->geom.occSewFaces,
    CTX::instance()->geom.occMakeSolids, CTX::instance()->geom.occScaling);

  _multiBind(result, -1, outDimTags, highestDimOnly, true);
  return true;
}

bool OCC_Internals::importShapes(const TopoDS_Shape *shape, bool highestDimOnly,
                                 std::vector<std::pair<int, int> > &outDimTags)
{
  if(!shape) return false;
  _multiBind(*shape, -1, outDimTags, highestDimOnly, true);
  return true;
}

bool OCC_Internals::exportShapes(GModel *model, const std::string &fileName,
                                 const std::string &format)
{
  // put all top-level OCC shapes from a GModel in a single compound (we use the
  // topology to only consider top-level shapes; otherwise we get duplicates in
  // the STEP export)
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(auto it = model->firstRegion(); it != model->lastRegion(); it++) {
    GRegion *gr = *it;
    if(gr->getNativeType() == GEntity::OpenCascadeModel)
      b.Add(c, *(TopoDS_Solid *)gr->getNativePtr());
  }
  for(auto it = model->firstFace(); it != model->lastFace(); it++) {
    GFace *gf = *it;
    if(!gf->numRegions() && gf->getNativeType() == GEntity::OpenCascadeModel)
      b.Add(c, *(TopoDS_Face *)gf->getNativePtr());
  }
  for(auto it = model->firstEdge(); it != model->lastEdge(); it++) {
    GEdge *ge = *it;
    if(!ge->numFaces() && ge->getNativeType() == GEntity::OpenCascadeModel)
      b.Add(c, *(TopoDS_Edge *)ge->getNativePtr());
  }
  for(auto it = model->firstVertex(); it != model->lastVertex(); it++) {
    GVertex *gv = *it;
    if(!gv->numEdges() && gv->getNativeType() == GEntity::OpenCascadeModel)
      b.Add(c, *(TopoDS_Vertex *)gv->getNativePtr());
  }

  std::vector<std::string> split = SplitFileName(fileName);

  TCollection_AsciiString occfile(fileName.c_str());

  try {
    if(format == "brep" || split[2] == ".brep" || split[2] == ".BREP") {
      BRepTools::Write(c, occfile.ToCString());
    }
    else if(format == "step" || split[2] == ".step" || split[2] == ".stp" ||
            split[2] == ".STEP" || split[2] == ".STP") {
      STEPControl_Writer writer;
      setTargetUnit(CTX::instance()->geom.occTargetUnit);
      if(writer.Transfer(c, STEPControl_AsIs) == IFSelect_RetDone) {
        if(writer.Write(occfile.ToCString()) != IFSelect_RetDone) {
          Msg::Error("Could not create file '%s'", fileName.c_str());
          return false;
        }
      }
      else {
        Msg::Error("Could not create STEP data");
        return false;
      }
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

void OCC_Internals::setMeshSize(int dim, int tag, double size)
{
  if(dim != 0) return;
  if(_tagVertex.IsBound(tag)) {
    OCCAttributes *a = new OCCAttributes(0, _tagVertex.Find(tag), size);
    // first remove any other constraint
    _attributes->remove(a);
    _attributes->insert(a);
  }
}

bool OCC_Internals::getEntities(std::vector<std::pair<int, int> > &dimTags,
                                int dim)
{
  for(int d = 0; d < 4; d++) {
    if(dim != -1 && dim != d) continue;
    TopTools_DataMapIteratorOfDataMapOfIntegerShape exp;
    switch(d) {
    case 0: exp.Initialize(_tagVertex); break;
    case 1: exp.Initialize(_tagEdge); break;
    case 2: exp.Initialize(_tagFace); break;
    case 3: exp.Initialize(_tagSolid); break;
    }
    for(; exp.More(); exp.Next())
      dimTags.push_back(std::pair<int, int>(d, exp.Key()));
  }
  return true;
}

bool OCC_Internals::getVertex(int tag, double &x, double &y, double &z)
{
  if(_tagVertex.IsBound(tag)) {
    gp_Pnt pnt = BRep_Tool::Pnt(TopoDS::Vertex(_tagVertex.Find(tag)));
    x = pnt.X();
    y = pnt.Y();
    z = pnt.Z();
    return true;
  }
  return false;
}

bool OCC_Internals::_getBoundingBox(const TopoDS_Shape &shape, double &xmin,
                                    double &ymin, double &zmin, double &xmax,
                                    double &ymax, double &zmax)
{
  if(CTX::instance()->geom.occBoundsUseSTL) {
    std::vector<SPoint3> vertices;
    std::vector<SVector3> normals;
    std::vector<int> triangles;
    _makeSTL(shape, vertices, normals, triangles);
  }
  Bnd_Box b;
  try {
    BRepBndLib::Add(shape, b);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  b.Get(xmin, ymin, zmin, xmax, ymax, zmax);
  if(CTX::instance()->geom.occBoundsUseSTL)
    fixSTLBounds(xmin, ymin, zmin, xmax, ymax, zmax);
  return true;
}

bool OCC_Internals::getBoundingBox(int dim, int tag, double &xmin, double &ymin,
                                   double &zmin, double &xmax, double &ymax,
                                   double &zmax)
{
  if(!_isBound(dim, tag)) {
    Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
               tag);
    return false;
  }
  TopoDS_Shape shape = _find(dim, tag);
  return _getBoundingBox(shape, xmin, ymin, zmin, xmax, ymax, zmax);
}

bool OCC_Internals::getEntitiesInBoundingBox(
  double xmin, double ymin, double zmin, double xmax, double ymax, double zmax,
  std::vector<std::pair<int, int> > &dimTags, int dim)
{
  // if we use this often, create an rtree to avoid the linear search
  for(int d = 0; d < 4; d++) {
    if(dim != -1 && dim != d) continue;
    TopTools_DataMapIteratorOfDataMapOfIntegerShape exp;
    switch(d) {
    case 0: exp.Initialize(_tagVertex); break;
    case 1: exp.Initialize(_tagEdge); break;
    case 2: exp.Initialize(_tagFace); break;
    case 3: exp.Initialize(_tagSolid); break;
    }
    for(; exp.More(); exp.Next()) {
      double xmin2 = 0, ymin2 = 0, zmin2 = 0, xmax2 = 0, ymax2 = 0, zmax2 = 0;
      _getBoundingBox(exp.Value(), xmin2, ymin2, zmin2, xmax2, ymax2, zmax2);
      if(xmin2 >= xmin && xmax2 <= xmax && ymin2 >= ymin && ymax2 <= ymax &&
         zmin2 >= zmin && zmax2 <= zmax)
        dimTags.push_back(std::pair<int, int>(d, exp.Key()));
    }
  }
  return true;
}

bool OCC_Internals::getMass(int dim, int tag, double &mass)
{
  if(!_isBound(dim, tag)) {
    Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
               tag);
    return false;
  }
  TopoDS_Shape shape = _find(dim, tag);
  GProp_GProps System;
  switch(dim) {
  case 1: BRepGProp::LinearProperties(shape, System); break;
  case 2: BRepGProp::SurfaceProperties(shape, System); break;
  case 3: BRepGProp::VolumeProperties(shape, System); break;
  }
  mass = System.Mass();
  return true;
}

bool OCC_Internals::getCenterOfMass(int dim, int tag, double &x, double &y,
                                    double &z)
{
  if(!_isBound(dim, tag)) {
    Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
               tag);
    return false;
  }
  TopoDS_Shape shape = _find(dim, tag);
  GProp_GProps System;
  switch(dim) {
  case 1: BRepGProp::LinearProperties(shape, System); break;
  case 2: BRepGProp::SurfaceProperties(shape, System); break;
  case 3: BRepGProp::VolumeProperties(shape, System); break;
  }
  gp_Pnt c = System.CentreOfMass();
  x = c.X();
  y = c.Y();
  z = c.Z();
  return true;
}

bool OCC_Internals::getMatrixOfInertia(int dim, int tag,
                                       std::vector<double> &mat)
{
  if(!_isBound(dim, tag)) {
    Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
               tag);
    return false;
  }
  TopoDS_Shape shape = _find(dim, tag);
  GProp_GProps System;
  switch(dim) {
  case 1: BRepGProp::LinearProperties(shape, System); break;
  case 2: BRepGProp::SurfaceProperties(shape, System); break;
  case 3: BRepGProp::VolumeProperties(shape, System); break;
  }
  gp_Mat m = System.MatrixOfInertia();
  mat.clear();
  for(int i = 1; i <= 3; i++)
    for(int j = 1; j <= 3; j++) mat.push_back(m.Value(i, j));
  return true;
}

bool const sortByInvDim(std::pair<int, int> const &lhs,
                        std::pair<int, int> const &rhs)
{
  return lhs.first > rhs.first;
}

void OCC_Internals::synchronize(GModel *model)
{
  Msg::Debug("Syncing OCC_Internals with GModel");

  // make sure to remove from GModel all entities that have been deleted in
  // OCC_Internals since the last synchronization
  std::vector<std::pair<int, int> > toRemove;
  toRemove.insert(toRemove.end(), _toRemove.begin(), _toRemove.end());
  Msg::Debug("Sync is removing %d model entities", toRemove.size());
  // make sure to delete highest dimensional entities first (model->remove()
  // will not remove entities that are the boundary of others!)
  std::sort(toRemove.begin(), toRemove.end(), sortByInvDim);
  model->remove(toRemove);
  _toRemove.clear();

  // iterate over all shapes with tags, and import them into the (sub)shape
  // _maps
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
  for(int i = 1; i <= _vmap.Extent(); i++) {
    TopoDS_Vertex vertex = TopoDS::Vertex(_vmap(i));
    GVertex *occv = getVertexForOCCShape(model, vertex);
    if(!occv) {
      int tag;
      if(_vertexTag.IsBound(vertex))
        tag = _vertexTag.Find(vertex);
      else {
        tag = ++vTagMax;
        Msg::Debug("Binding unbound OpenCASCADE point to tag %d", tag);
        bind(vertex, tag);
      }
      occv = new OCCVertex(model, vertex, tag);
      model->add(occv);
    }
    double lc = _attributes->getMeshSize(0, vertex);
    if(lc != MAX_LC) occv->setPrescribedMeshSizeAtVertex(lc);
    std::vector<std::string> labels;
    _attributes->getLabels(0, vertex, labels);
    if(labels.size()) model->setElementaryName(0, occv->tag(), labels[0]);
    unsigned int col = 0, boundary = 0;
    if(_attributes->getColor(0, vertex, col, boundary)) { occv->setColor(col); }
  }
  for(int i = 1; i <= _emap.Extent(); i++) {
    TopoDS_Edge edge = TopoDS::Edge(_emap(i));
    GEdge *occe = getEdgeForOCCShape(model, edge);
    if(!occe) {
      GVertex *v1 = getVertexForOCCShape(model, TopExp::FirstVertex(edge));
      GVertex *v2 = getVertexForOCCShape(model, TopExp::LastVertex(edge));
      int tag;
      if(_edgeTag.IsBound(edge))
        tag = _edgeTag.Find(edge);
      else {
        tag = ++eTagMax;
        Msg::Debug("Binding unbound OpenCASCADE curve to tag %d", tag);
        bind(edge, tag);
      }
      occe = new OCCEdge(model, edge, tag, v1, v2);
      model->add(occe);
    }
    _copyExtrudedAttributes(edge, occe);
    std::vector<std::string> labels;
    _attributes->getLabels(1, edge, labels);
    if(labels.size()) model->setElementaryName(1, occe->tag(), labels[0]);
    unsigned int col = 0, boundary = 0;
    if(_attributes->getColor(1, edge, col, boundary)) { occe->setColor(col); }
  }
  for(int i = 1; i <= _fmap.Extent(); i++) {
    TopoDS_Face face = TopoDS::Face(_fmap(i));
    GFace *occf = getFaceForOCCShape(model, face);
    if(!occf) {
      int tag;
      if(_faceTag.IsBound(face))
        tag = _faceTag.Find(face);
      else {
        tag = ++fTagMax;
        Msg::Debug("Binding unbound OpenCASCADE surface to tag %d", tag);
        bind(face, tag);
      }
      occf = new OCCFace(model, face, tag);
      model->add(occf);
    }
    _copyExtrudedAttributes(face, occf);
    std::vector<std::string> labels;
    _attributes->getLabels(2, face, labels);
    if(labels.size()) model->setElementaryName(2, occf->tag(), labels[0]);
    unsigned int col = 0, boundary = 0;
    if(_attributes->getColor(2, face, col, boundary)) {
      occf->setColor(col);
      if(boundary == 2) {
        std::vector<GEdge *> edges = occf->edges();
        for(std::size_t j = 0; j < edges.size(); j++) {
          // only if not specified explicitly before
          if(!edges[j]->useColor()) edges[j]->setColor(col);
        }
      }
    }
  }
  for(int i = 1; i <= _somap.Extent(); i++) {
    TopoDS_Solid region = TopoDS::Solid(_somap(i));
    GRegion *occr = getRegionForOCCShape(model, region);
    if(!occr) {
      int tag;
      if(_solidTag.IsBound(region))
        tag = _solidTag(region);
      else {
        tag = ++rTagMax;
        Msg::Debug("Binding unbound OpenCASCADE volume to tag %d", tag);
        bind(region, tag);
      }
      occr = new OCCRegion(model, region, tag);
      model->add(occr);
    }
    _copyExtrudedAttributes(region, occr);
    std::vector<std::string> labels;
    _attributes->getLabels(3, region, labels);
    if(labels.size()) model->setElementaryName(3, occr->tag(), labels[0]);
    unsigned int col = 0, boundary = 0;
    if(_attributes->getColor(3, region, col, boundary)) {
      occr->setColor(col);
      if(boundary == 1) {
        std::vector<GFace *> faces = occr->faces();
        for(std::size_t j = 0; j < faces.size(); j++) {
          // only if not specified explicitly before
          if(!faces[j]->useColor()) faces[j]->setColor(col);
        }
      }
      else if(boundary == 2) {
        std::vector<GEdge *> edges = occr->edges();
        for(std::size_t j = 0; j < edges.size(); j++) {
          // only if not specified explicitly before
          if(!edges[j]->useColor()) edges[j]->setColor(col);
        }
      }
    }
  }

  // if fuzzy boolean tolerance was used, some vertex positions should be
  // recomputed (e.g. end point of curves
  if(CTX::instance()->geom.toleranceBoolean) model->snapVertices();

  // recompute global boundind box in CTX
  SetBoundingBox();

  Msg::Debug("GModel imported:");
  Msg::Debug("%d points", model->getNumVertices());
  Msg::Debug("%d curves", model->getNumEdges());
  Msg::Debug("%d surfaces", model->getNumFaces());
  Msg::Debug("%d volumes", model->getNumRegions());
  _changed = false;
}

GVertex *OCC_Internals::getVertexForOCCShape(GModel *model,
                                             const TopoDS_Vertex &toFind)
{
  if(_vertexTag.IsBound(toFind))
    return model->getVertexByTag(_vertexTag.Find(toFind));
  return nullptr;
}

GEdge *OCC_Internals::getEdgeForOCCShape(GModel *model,
                                         const TopoDS_Edge &toFind)
{
  if(_edgeTag.IsBound(toFind))
    return model->getEdgeByTag(_edgeTag.Find(toFind));
  return nullptr;
}

GFace *OCC_Internals::getFaceForOCCShape(GModel *model,
                                         const TopoDS_Face &toFind)
{
  if(_faceTag.IsBound(toFind))
    return model->getFaceByTag(_faceTag.Find(toFind));
  return nullptr;
}

GRegion *OCC_Internals::getRegionForOCCShape(GModel *model,
                                             const TopoDS_Solid &toFind)
{
  if(_solidTag.IsBound(toFind))
    return model->getRegionByTag(_solidTag.Find(toFind));
  return nullptr;
}

void OCC_Internals::_addShapeToMaps(const TopoDS_Shape &shape)
{
  // Solids
  TopExp_Explorer exp0, exp1, exp2, exp3, exp4, exp5;
  for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()) {
    TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
    if(_somap.FindIndex(solid) < 1) {
      _somap.Add(solid);
      for(exp1.Init(solid, TopAbs_SHELL); exp1.More(); exp1.Next()) {
        TopoDS_Shell shell = TopoDS::Shell(exp1.Current());
        if(_shmap.FindIndex(shell) < 1) {
          _shmap.Add(shell);

          for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()) {
            TopoDS_Face face = TopoDS::Face(exp2.Current());
            if(_fmap.FindIndex(face) < 1) {
              _fmap.Add(face);

              for(exp3.Init(face.Oriented(TopAbs_FORWARD), TopAbs_WIRE);
                  exp3.More(); exp3.Next()) {
                // for(exp3.Init(face, TopAbs_WIRE); exp3.More(); exp3.Next()){
                TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
                if(_wmap.FindIndex(wire) < 1) {
                  _wmap.Add(wire);

                  for(exp4.Init(wire, TopAbs_EDGE); exp4.More(); exp4.Next()) {
                    TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
                    if(_emap.FindIndex(edge) < 1) {
                      _emap.Add(edge);

                      for(exp5.Init(edge, TopAbs_VERTEX); exp5.More();
                          exp5.Next()) {
                        TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
                        if(_vmap.FindIndex(vertex) < 1) _vmap.Add(vertex);
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
  for(exp1.Init(shape, TopAbs_SHELL, TopAbs_SOLID); exp1.More(); exp1.Next()) {
    const TopoDS_Shape &shell = exp1.Current();
    if(_shmap.FindIndex(shell) < 1) {
      _shmap.Add(shell);

      for(exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next()) {
        TopoDS_Face face = TopoDS::Face(exp2.Current());
        if(_fmap.FindIndex(face) < 1) {
          _fmap.Add(face);

          for(exp3.Init(face, TopAbs_WIRE); exp3.More(); exp3.Next()) {
            TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
            if(_wmap.FindIndex(wire) < 1) {
              _wmap.Add(wire);

              for(exp4.Init(wire, TopAbs_EDGE); exp4.More(); exp4.Next()) {
                TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
                if(_emap.FindIndex(edge) < 1) {
                  _emap.Add(edge);

                  for(exp5.Init(edge, TopAbs_VERTEX); exp5.More();
                      exp5.Next()) {
                    TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
                    if(_vmap.FindIndex(vertex) < 1) _vmap.Add(vertex);
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
  for(exp2.Init(shape, TopAbs_FACE, TopAbs_SHELL); exp2.More(); exp2.Next()) {
    TopoDS_Face face = TopoDS::Face(exp2.Current());
    if(_fmap.FindIndex(face) < 1) {
      _fmap.Add(face);

      for(exp3.Init(face, TopAbs_WIRE); exp3.More(); exp3.Next()) {
        TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
        if(_wmap.FindIndex(wire) < 1) {
          _wmap.Add(wire);

          for(exp4.Init(wire, TopAbs_EDGE); exp4.More(); exp4.Next()) {
            TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
            if(_emap.FindIndex(edge) < 1) {
              _emap.Add(edge);

              for(exp5.Init(edge, TopAbs_VERTEX); exp5.More(); exp5.Next()) {
                TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
                if(_vmap.FindIndex(vertex) < 1) _vmap.Add(vertex);
              }
            }
          }
        }
      }
    }
  }

  // Free Wires
  for(exp3.Init(shape, TopAbs_WIRE, TopAbs_FACE); exp3.More(); exp3.Next()) {
    TopoDS_Wire wire = TopoDS::Wire(exp3.Current());
    if(_wmap.FindIndex(wire) < 1) {
      _wmap.Add(wire);

      for(exp4.Init(wire, TopAbs_EDGE); exp4.More(); exp4.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
        if(_emap.FindIndex(edge) < 1) {
          _emap.Add(edge);

          for(exp5.Init(edge, TopAbs_VERTEX); exp5.More(); exp5.Next()) {
            TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
            if(_vmap.FindIndex(vertex) < 1) _vmap.Add(vertex);
          }
        }
      }
    }
  }

  // Free Edges
  for(exp4.Init(shape, TopAbs_EDGE, TopAbs_WIRE); exp4.More(); exp4.Next()) {
    TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
    if(_emap.FindIndex(edge) < 1) {
      _emap.Add(edge);

      for(exp5.Init(edge, TopAbs_VERTEX); exp5.More(); exp5.Next()) {
        TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
        if(_vmap.FindIndex(vertex) < 1) _vmap.Add(vertex);
      }
    }
  }

  // Free Vertices
  for(exp5.Init(shape, TopAbs_VERTEX, TopAbs_EDGE); exp5.More(); exp5.Next()) {
    TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
    if(_vmap.FindIndex(vertex) < 1) { _vmap.Add(vertex); }
  }
}

void OCC_Internals::_healShape(TopoDS_Shape &myshape, double tolerance,
                               bool fixDegenerated, bool fixSmallEdges,
                               bool fixSmallFaces, bool sewFaces,
                               bool makeSolids, double scaling)
{
  if(scaling != 1.0) {
    Msg::Info("Scaling geometry (factor: %g)", scaling);
    gp_Trsf t;
    t.SetScaleFactor(scaling);
    BRepBuilderAPI_Transform trsf(myshape, t);
    myshape = trsf.Shape();
  }

  if(!fixDegenerated && !fixSmallEdges && !fixSmallFaces && !sewFaces &&
     !makeSolids)
    return;

  Msg::Info("Healing shapes (tolerance: %g)", tolerance);
  double t1 = Cpu(), w1 = TimeOfDay();

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
  for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()) {
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    GProp_GProps system;
    BRepGProp::SurfaceProperties(face, system);
    surfacecont += system.Mass();
  }

  if(fixDegenerated) {
    Msg::Info(" - Fixing degenerated edges and faces");

    {
      ShapeBuild_ReShape rebuild;
      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge)) rebuild.Remove(edge);
      }
      myshape = rebuild.Apply(myshape);
    }
    _somap.Clear();
    _shmap.Clear();
    _fmap.Clear();
    _wmap.Clear();
    _emap.Clear();
    _vmap.Clear();
    _addShapeToMaps(myshape);

    {
      ShapeBuild_ReShape rebuild;
      for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()) {
        TopoDS_Face face = TopoDS::Face(exp0.Current());

        ShapeFix_Face sff(face);
        sff.FixAddNaturalBoundMode() = Standard_True;
        sff.FixSmallAreaWireMode() = Standard_True;
        sff.Perform();

        if(sff.Status(ShapeExtend_DONE1) || sff.Status(ShapeExtend_DONE2) ||
           sff.Status(ShapeExtend_DONE3) || sff.Status(ShapeExtend_DONE4) ||
           sff.Status(ShapeExtend_DONE5)) {
          Msg::Info(" . Repaired face %d", _fmap.FindIndex(face));
          if(sff.Status(ShapeExtend_DONE1))
            Msg::Info(" . Some wires are fixed");
          else if(sff.Status(ShapeExtend_DONE2))
            Msg::Info(" . Orientation of wires fixed");
          else if(sff.Status(ShapeExtend_DONE3))
            Msg::Info(" . Missing seam added");
          else if(sff.Status(ShapeExtend_DONE4))
            Msg::Info(" . Small area wire removed");
          else if(sff.Status(ShapeExtend_DONE5))
            Msg::Info(" . Natural bounds added");
          TopoDS_Face newface = sff.Face();

          rebuild.Replace(face, newface);
        }
      }
      myshape = rebuild.Apply(myshape);
    }

    {
      ShapeBuild_ReShape rebuild;
      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge)) rebuild.Remove(edge);
      }
      myshape = rebuild.Apply(myshape);
    }
  }

  if(fixSmallEdges) {
    Msg::Info(" - Fixing small edges");
    ShapeBuild_ReShape rebuild;

    for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()) {
      TopoDS_Face face = TopoDS::Face(exp0.Current());

      for(exp1.Init(face, TopAbs_WIRE); exp1.More(); exp1.Next()) {
        TopoDS_Wire oldwire = TopoDS::Wire(exp1.Current());
        ShapeFix_Wire sfw(oldwire, face, tolerance);
        sfw.ModifyTopologyMode() = Standard_True;

        sfw.ClosedWireMode() = Standard_True;

        bool replace = false;
        replace = sfw.FixReorder() || replace;
        replace = sfw.FixConnected() || replace;

        if(sfw.FixSmall(Standard_False, tolerance) &&
           !(sfw.StatusSmall(ShapeExtend_FAIL1) ||
             sfw.StatusSmall(ShapeExtend_FAIL2) ||
             sfw.StatusSmall(ShapeExtend_FAIL3))) {
          Msg::Info(" . Fixed small edge in wire %d", _wmap.FindIndex(oldwire));
          replace = true;
        }
        else if(sfw.StatusSmall(ShapeExtend_FAIL1))
          Msg::Warning(
            "Failed to fix small edge in wire %d, edge cannot be checked "
            "(no 3d curve and no pcurve)",
            _wmap.FindIndex(oldwire));
        else if(sfw.StatusSmall(ShapeExtend_FAIL2))
          Msg::Warning(
            "Failed to fix small edge in wire %d, "
            "edge is null-length and has different vertives at begin and "
            "end, and lockvtx is True or ModifiyTopologyMode is False",
            _wmap.FindIndex(oldwire));
        else if(sfw.StatusSmall(ShapeExtend_FAIL3))
          Msg::Warning(
            "Failed to fix small edge in wire, CheckConnected has failed",
            _wmap.FindIndex(oldwire));

        replace = sfw.FixEdgeCurves() || replace;
        replace = sfw.FixDegenerated() || replace;
        replace = sfw.FixSelfIntersection() || replace;
        replace = sfw.FixLacking(Standard_True) || replace;
        if(replace) {
          TopoDS_Wire newwire = sfw.Wire();
          rebuild.Replace(oldwire, newwire);
        }
      }
    }

    myshape = rebuild.Apply(myshape);
    _somap.Clear();
    _shmap.Clear();
    _fmap.Clear();
    _wmap.Clear();
    _emap.Clear();
    _vmap.Clear();
    _addShapeToMaps(myshape);

    {
      ShapeBuild_ReShape rebuild;

      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(_vmap.FindIndex(TopExp::FirstVertex(edge)) ==
           _vmap.FindIndex(TopExp::LastVertex(edge))) {
          GProp_GProps system;
          BRepGProp::LinearProperties(edge, system);
          if(system.Mass() < tolerance) {
            Msg::Info(
              "  - Removing degenerated edge %d from vertex %d to vertex %d",
              _emap.FindIndex(edge), _vmap.FindIndex(TopExp::FirstVertex(edge)),
              _vmap.FindIndex(TopExp::LastVertex(edge)));
            rebuild.Remove(edge);
          }
        }
      }
      myshape = rebuild.Apply(myshape);
    }

    {
      ShapeBuild_ReShape rebuild;
      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        if(BRep_Tool::Degenerated(edge)) rebuild.Remove(edge);
      }
      myshape = rebuild.Apply(myshape);
    }

    ShapeFix_Wireframe sfwf;
    sfwf.SetPrecision(tolerance);
    sfwf.Load(myshape);
    sfwf.ModeDropSmallEdges() = Standard_True;

    if(sfwf.FixWireGaps()) {
      Msg::Info(" - Fixing wire gaps");
      if(sfwf.StatusWireGaps(ShapeExtend_OK)) Msg::Info("  no gaps found");
      if(sfwf.StatusWireGaps(ShapeExtend_DONE1))
        Msg::Info(" . Some 2D gaps fixed");
      if(sfwf.StatusWireGaps(ShapeExtend_DONE2))
        Msg::Info(" . Some 3D gaps fixed");
      if(sfwf.StatusWireGaps(ShapeExtend_FAIL1))
        Msg::Info(" . Failed to fix some 2D gaps");
      if(sfwf.StatusWireGaps(ShapeExtend_FAIL2))
        Msg::Info(" . Failed to fix some 3D gaps");
    }

    sfwf.SetPrecision(tolerance);

    if(sfwf.FixSmallEdges()) {
      Msg::Info(" - Fixing wire frames");
      if(sfwf.StatusSmallEdges(ShapeExtend_OK))
        Msg::Info(" . No small edges found");
      if(sfwf.StatusSmallEdges(ShapeExtend_DONE1))
        Msg::Info(" . Some small edges fixed");
      if(sfwf.StatusSmallEdges(ShapeExtend_FAIL1))
        Msg::Info(" . Failed to fix some small edges");
    }

    myshape = sfwf.Shape();
  }

  if(fixSmallFaces) {
    Msg::Info(" - Fixing spot and strip faces");
    ShapeFix_FixSmallFace sffsm;
    sffsm.Init(myshape);
    sffsm.SetPrecision(tolerance);
    sffsm.Perform();
    myshape = sffsm.FixShape();
  }

  if(sewFaces) {
    Msg::Info(" - Sewing faces");

    BRepOffsetAPI_Sewing sewedObj(tolerance);

    for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()) {
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      sewedObj.Add(face);
    }

    sewedObj.Perform();

    if(!sewedObj.SewedShape().IsNull())
      myshape = sewedObj.SewedShape();
    else
      Msg::Info(" . Could not sew");
  }

  {
    ShapeBuild_ReShape rebuild;
    for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
      if(BRep_Tool::Degenerated(edge)) rebuild.Remove(edge);
    }
    myshape = rebuild.Apply(myshape);
  }

  if(makeSolids) {
    Msg::Info(" - Making solids");

    BRepBuilderAPI_MakeSolid ms;
    int count = 0;
    for(exp0.Init(myshape, TopAbs_SHELL); exp0.More(); exp0.Next()) {
      count++;
      ms.Add(TopoDS::Shell(exp0.Current()));
    }

    if(!count) { Msg::Info(" . Could not make solid (no shells)"); }
    else {
      BRepCheck_Analyzer ba(ms);
      if(ba.IsValid()) {
        ShapeFix_Shape sfs;
        sfs.Init(ms);
        sfs.SetPrecision(tolerance);
        sfs.SetMaxTolerance(tolerance);
        sfs.Perform();
        myshape = sfs.Shape();
        for(exp0.Init(myshape, TopAbs_SOLID); exp0.More(); exp0.Next()) {
          TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
          TopoDS_Solid newsolid = solid;
          BRepLib::OrientClosedSolid(newsolid);
          ShapeBuild_ReShape rebuild;
          rebuild.Replace(solid, newsolid);
          myshape = rebuild.Apply(myshape, TopAbs_COMPSOLID);
        }
      }
      else
        Msg::Info(" . Could not make solid");
    }
  }

  double newsurfacecont = 0;
  for(exp0.Init(myshape, TopAbs_FACE); exp0.More(); exp0.Next()) {
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

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::Info("Done healing shapes (Wall %gs, CPU %gs):", w2 - w1, t2 - t1);
  Msg::Info(" - Compounds          : %d (%d)", nnrc, nrc);
  Msg::Info(" - Composite solids   : %d (%d)", nnrcs, nrcs);
  Msg::Info(" - Solids             : %d (%d)", nnrso, nrso);
  Msg::Info(" - Shells             : %d (%d)", nnrsh, nrsh);
  Msg::Info(" - Wires              : %d (%d)", nnrw, nrw);
  Msg::Info(" - Faces              : %d (%d)", nnrf, nrf);
  Msg::Info(" - Edges              : %d (%d)", nnre, nre);
  Msg::Info(" - Vertices           : %d (%d)", nnrv, nrv);
  Msg::Info(" - Total surface area : %g (%g)", newsurfacecont, surfacecont);
}

bool OCC_Internals::healShapes(
  const std::vector<std::pair<int, int> > &inDimTags,
  std::vector<std::pair<int, int> > &outDimTags, double tolerance,
  bool fixDegenerated, bool fixSmallEdges, bool fixSmallFaces, bool sewFaces,
  bool makeSolids)
{
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  if(inDimTags.empty()) {
    // construct a compound with all the shapes with tags
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
    for(int i = 1; i <= _vmap.Extent(); i++) b.Add(c, _vmap(i));
    for(int i = 1; i <= _emap.Extent(); i++) b.Add(c, _emap(i));
    for(int i = 1; i <= _wmap.Extent(); i++) b.Add(c, _wmap(i));
    for(int i = 1; i <= _fmap.Extent(); i++) b.Add(c, _fmap(i));
    for(int i = 1; i <= _shmap.Extent(); i++) b.Add(c, _shmap(i));
    for(int i = 1; i <= _somap.Extent(); i++) b.Add(c, _somap(i));
    // unbind everything
    unbind();
  }
  else {
    // construct a compound with the given shapes
    for(std::size_t i = 0; i < inDimTags.size(); i++) {
      int dim = inDimTags[i].first;
      int tag = inDimTags[i].second;
      if(!_isBound(dim, tag)) {
        Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                   dim, tag);
        return false;
      }
      TopoDS_Shape shape = _find(dim, tag);
      b.Add(c, shape);
    }
  }

  _healShape(c, tolerance, fixDegenerated, fixSmallEdges, fixSmallFaces,
             sewFaces, makeSolids, 1.0);
  _multiBind(c, -1, outDimTags, false, true);
  return true;
}

static bool makeSTL(const TopoDS_Face &s, std::vector<SPoint2> *verticesUV,
                    std::vector<SPoint3> *verticesXYZ,
                    std::vector<SVector3> *normals, std::vector<int> &triangles)
{
  if(CTX::instance()->geom.occDisableSTL) return false;

  double lin = CTX::instance()->mesh.stlLinearDeflection;
  double ang = CTX::instance()->mesh.stlAngularDeflection;

#if OCC_VERSION_HEX > 0x070300
  BRepMesh_IncrementalMesh aMesher(s, lin, Standard_False, ang, Standard_True);
#elif OCC_VERSION_HEX > 0x070000
  Bnd_Box aBox;
  BRepBndLib::Add(s, aBox);
  BRepMesh_FastDiscret::Parameters parameters;
  parameters.Deflection = lin;
  parameters.Angle = ang;
  parameters.Relative = Standard_False;
  BRepMesh_FastDiscret aMesher(aBox, parameters);
  aMesher.Perform(s);
#else
  Bnd_Box aBox;
  BRepBndLib::Add(s, aBox);
  BRepMesh_FastDiscret aMesher(lin, ang, aBox, Standard_False, Standard_False,
                               Standard_True, Standard_False);
  aMesher.Perform(s);
#endif

  TopLoc_Location loc;
  Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(s, loc);

  if(triangulation.IsNull()) return false;

  if(verticesUV && !triangulation->HasUVNodes()) return false;

  if(normals && !triangulation->HasUVNodes()) return false;

  int start = 0;
  if(verticesUV) start = verticesUV->size();
  if(verticesXYZ) start = verticesXYZ->size();
  for(int i = 1; i <= triangulation->NbNodes(); i++) {
    if(verticesUV) {
#if OCC_VERSION_HEX >= 0x070600
      gp_Pnt2d p = triangulation->UVNode(i);
#else
      gp_Pnt2d p = (triangulation->UVNodes())(i);
#endif
      verticesUV->push_back(SPoint2(p.X(), p.Y()));
    }
    if(verticesXYZ) {
#if OCC_VERSION_HEX >= 0x070600
      gp_Pnt pp = triangulation->Node(i);
#else
      gp_Pnt pp = (triangulation->Nodes())(i);
#endif
      double x = pp.X(), y = pp.Y(), z = pp.Z();
      loc.Transformation().Transforms(x, y, z);
      verticesXYZ->push_back(SPoint3(x, y, z));
    }
    if(normals) {
#if OCC_VERSION_HEX >= 0x070600
      gp_Pnt2d p = triangulation->UVNode(i);
#else
      gp_Pnt2d p = (triangulation->UVNodes())(i);
#endif
      Handle(Geom_Surface) sur = BRep_Tool::Surface(s);
      gp_Pnt pnt;
      gp_Vec du, dv;
      sur->D1(p.X(), p.Y(), pnt, du, dv);
      SVector3 t1(du.X(), du.Y(), du.Z());
      SVector3 t2(dv.X(), dv.Y(), dv.Z());
      SVector3 n(crossprod(t1, t2));
      n.normalize();
      if(s.Orientation() == TopAbs_REVERSED) n *= -1.;
      normals->push_back(n);
    }
  }
  for(int i = 1; i <= triangulation->NbTriangles(); i++) {
#if OCC_VERSION_HEX >= 0x070600
    Poly_Triangle triangle = triangulation->Triangle(i);
#else
    Poly_Triangle triangle = (triangulation->Triangles())(i);
#endif
    int p1, p2, p3;
    triangle.Get(p1, p2, p3);
    triangles.push_back(start + p1 - 1);
    if(s.Orientation() == TopAbs_REVERSED) {
      triangles.push_back(start + p3 - 1);
      triangles.push_back(start + p2 - 1);
    }
    else {
      triangles.push_back(start + p2 - 1);
      triangles.push_back(start + p3 - 1);
    }
  }
  return true;
}

bool OCC_Internals::makeEdgeSTLFromFace(const TopoDS_Edge &c,
                                        const TopoDS_Face &s,
                                        std::vector<SPoint3> *verticesXYZ)
{
  TopLoc_Location transf;
  Handle(Poly_Triangulation) trian = BRep_Tool::Triangulation(s, transf);
  if(trian.IsNull()) return false;

  Handle(Poly_PolygonOnTriangulation) edgepoly =
    BRep_Tool::PolygonOnTriangulation(c, trian, transf);
  if(edgepoly.IsNull()) return false;
  if(edgepoly->NbNodes() < 2) return false;

  for(int i = 1; i <= edgepoly->NbNodes(); i++) {
#if OCC_VERSION_HEX > 0x070600
    int j = edgepoly->Node(i);
#else
    int j = (edgepoly->Nodes())(i);
#endif
#if OCC_VERSION_HEX >= 0x070600
    gp_Pnt pp = trian->Node(j);
#else
    gp_Pnt pp = (trian->Nodes())(j);
#endif
    if(!transf.IsIdentity()) { pp.Transform(transf); }
    verticesXYZ->push_back(SPoint3(pp.X(), pp.Y(), pp.Z()));
  }
  return true;
}

bool OCC_Internals::makeFaceSTL(const TopoDS_Face &s,
                                std::vector<SPoint2> &vertices_uv,
                                std::vector<int> &triangles)
{
  return makeSTL(s, &vertices_uv, nullptr, nullptr, triangles);
}

bool OCC_Internals::makeFaceSTL(const TopoDS_Face &s,
                                std::vector<SPoint2> &vertices_uv,
                                std::vector<SPoint3> &vertices,
                                std::vector<SVector3> &normals,
                                std::vector<int> &triangles)
{
  return makeSTL(s, &vertices_uv, &vertices, &normals, triangles);
}

bool OCC_Internals::makeFaceSTL(const TopoDS_Face &s,
                                std::vector<SPoint3> &vertices,
                                std::vector<SVector3> &normals,
                                std::vector<int> &triangles)
{
  return makeSTL(s, nullptr, &vertices, &normals, triangles);
}

bool OCC_Internals::_makeSTL(const TopoDS_Shape &s,
                             std::vector<SPoint3> &vertices,
                             std::vector<SVector3> &normals,
                             std::vector<int> &triangles)
{
  bool ret = true;
  TopExp_Explorer exp0;
  for(exp0.Init(s, TopAbs_FACE); exp0.More(); exp0.Next()) {
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    bool tmp = makeSTL(TopoDS::Face(face.Oriented(TopAbs_FORWARD)), nullptr,
                       &vertices, &normals, triangles);
    if(!tmp) ret = false;
  }
  return ret;
}

bool OCC_Internals::makeRectangleSTL(double x, double y, double z, double dx,
                                     double dy, double roundedRadius,
                                     std::vector<SPoint3> &vertices,
                                     std::vector<SVector3> &normals,
                                     std::vector<int> &triangles)
{
  TopoDS_Face result;
  if(!makeRectangle(result, x, y, z, dx, dy, roundedRadius)) return false;
  if(!makeFaceSTL(result, vertices, normals, triangles)) return false;
  return true;
}

bool OCC_Internals::makeDiskSTL(double xc, double yc, double zc, double rx,
                                double ry, std::vector<SPoint3> &vertices,
                                std::vector<SVector3> &normals,
                                std::vector<int> &triangles)
{
  TopoDS_Face result;
  if(!makeDisk(result, xc, yc, zc, rx, ry)) return false;
  if(!makeFaceSTL(result, vertices, normals, triangles)) return false;
  return true;
}

bool OCC_Internals::makeSphereSTL(double xc, double yc, double zc,
                                  double radius, double angle1, double angle2,
                                  double angle3, std::vector<SPoint3> &vertices,
                                  std::vector<SVector3> &normals,
                                  std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!makeSphere(result, xc, yc, zc, radius, angle1, angle2, angle3))
    return false;
  if(!_makeSTL(result, vertices, normals, triangles)) return false;
  return true;
}

bool OCC_Internals::makeBoxSTL(double x, double y, double z, double dx,
                               double dy, double dz,
                               std::vector<SPoint3> &vertices,
                               std::vector<SVector3> &normals,
                               std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!makeBox(result, x, y, z, dx, dy, dz)) return false;
  if(!_makeSTL(result, vertices, normals, triangles)) return false;
  return true;
}

bool OCC_Internals::makeCylinderSTL(double x, double y, double z, double dx,
                                    double dy, double dz, double r,
                                    double angle,
                                    std::vector<SPoint3> &vertices,
                                    std::vector<SVector3> &normals,
                                    std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!makeCylinder(result, x, y, z, dx, dy, dz, r, angle)) return false;
  if(!_makeSTL(result, vertices, normals, triangles)) return false;
  return true;
}

bool OCC_Internals::makeConeSTL(double x, double y, double z, double dx,
                                double dy, double dz, double r1, double r2,
                                double angle, std::vector<SPoint3> &vertices,
                                std::vector<SVector3> &normals,
                                std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!makeCone(result, x, y, z, dx, dy, dz, r1, r2, angle)) return false;
  if(!_makeSTL(result, vertices, normals, triangles)) return false;
  return true;
}

bool OCC_Internals::makeWedgeSTL(double x, double y, double z, double dx,
                                 double dy, double dz, double ltx,
                                 std::vector<SPoint3> &vertices,
                                 std::vector<SVector3> &normals,
                                 std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!makeWedge(result, x, y, z, dx, dy, dz, ltx)) return false;
  if(!_makeSTL(result, vertices, normals, triangles)) return false;
  return true;
}

bool OCC_Internals::makeTorusSTL(double x, double y, double z, double r1,
                                 double r2, double angle,
                                 std::vector<SPoint3> &vertices,
                                 std::vector<SVector3> &normals,
                                 std::vector<int> &triangles)
{
  TopoDS_Solid result;
  if(!makeTorus(result, x, y, z, r1, r2, angle)) return false;
  if(!_makeSTL(result, vertices, normals, triangles)) return false;
  return true;
}

void OCC_Internals::fixSTLBounds(double &xmin, double &ymin, double &zmin,
                                 double &xmax, double &ymax, double &zmax)
{
  // When an STL exists, OCC enlarges the bounding box by the allowed linear
  // deflection given to BRepMesh_IncrementalMesh. This is "safe", but on simple
  // polyhedral geometries (a cube!) it will consistently lead to enlarging the
  // bounding box by twice this value in all directions. Since we use bounds()
  // mostly for locating entities, it's better to remove the tolerance (with the
  // risk that the bbox is a bit too small for curved boundaries - but that's
  // fine)
  double eps = CTX::instance()->mesh.stlLinearDeflection;
  // OCC also enlarges the bounding box by Precision::Confusion(): remove it as
  // well
  eps += Precision::Confusion();
  xmin += eps;
  xmax -= eps;
  ymin += eps;
  ymax -= eps;
  zmin += eps;
  zmax -= eps;
}

#endif

void GModel::createOCCInternals()
{
  if(_occ_internals) delete _occ_internals;
  _occ_internals = new OCC_Internals;
}

void GModel::deleteOCCInternals()
{
  if(_occ_internals) delete _occ_internals;
  _occ_internals = nullptr;
}

void GModel::resetOCCInternals()
{
  if(!_occ_internals) return;
  _occ_internals->reset();
}

int GModel::readOCCBREP(const std::string &fn)
{
  if(!_occ_internals) _occ_internals = new OCC_Internals;
  std::vector<std::pair<int, int> > outDimTags;
  _occ_internals->importShapes(fn, false, outDimTags, "brep");
  _occ_internals->synchronize(this);
  snapVertices();
  return 1;
}

int GModel::readOCCSTEP(const std::string &fn)
{
  if(!_occ_internals) _occ_internals = new OCC_Internals;
  std::vector<std::pair<int, int> > outDimTags;
  _occ_internals->importShapes(fn, false, outDimTags, "step");
  _occ_internals->synchronize(this);
  return 1;
}

int GModel::readOCCIGES(const std::string &fn)
{
  if(!_occ_internals) _occ_internals = new OCC_Internals;
  std::vector<std::pair<int, int> > outDimTags;
  _occ_internals->importShapes(fn, false, outDimTags, "iges");
  _occ_internals->synchronize(this);
  return 1;
}

int GModel::writeOCCBREP(const std::string &fn)
{
  if(!_occ_internals) {
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  _occ_internals->exportShapes(this, fn, "brep");
  return 1;
}

int GModel::writeOCCSTEP(const std::string &fn)
{
  if(!_occ_internals) {
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  _occ_internals->exportShapes(this, fn, "step");
  return 1;
}

int GModel::importOCCShape(const void *shape)
{
  if(!_occ_internals) _occ_internals = new OCC_Internals;
#if defined(HAVE_OCC)
  std::vector<std::pair<int, int> > outDimTags;
  _occ_internals->importShapes((TopoDS_Shape *)shape, false, outDimTags);
#else
  Msg::Error("Gmsh requires OpenCASCADE to import TopoDS_Shape");
#endif
  _occ_internals->synchronize(this);
  snapVertices();
  return 1;
}

GVertex *GModel::getVertexForOCCShape(const void *shape)
{
  if(!_occ_internals) return nullptr;
#if defined(HAVE_OCC)
  return _occ_internals->getVertexForOCCShape(this, *(TopoDS_Vertex *)shape);
#else
  return 0;
#endif
}

GEdge *GModel::getEdgeForOCCShape(const void *shape)
{
  if(!_occ_internals) return nullptr;
#if defined(HAVE_OCC)
  return _occ_internals->getEdgeForOCCShape(this, *(TopoDS_Edge *)shape);
#else
  return 0;
#endif
}

GFace *GModel::getFaceForOCCShape(const void *shape)
{
  if(!_occ_internals) return nullptr;
#if defined(HAVE_OCC)
  return _occ_internals->getFaceForOCCShape(this, *(TopoDS_Face *)shape);
#else
  return 0;
#endif
}

GRegion *GModel::getRegionForOCCShape(const void *shape)
{
  if(!_occ_internals) return nullptr;
#if defined(HAVE_OCC)
  return _occ_internals->getRegionForOCCShape(this, *(TopoDS_Solid *)shape);
#else
  return 0;
#endif
}
