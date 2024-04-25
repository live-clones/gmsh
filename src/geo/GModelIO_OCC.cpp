// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <numeric>
#include <utility>
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
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepCheck_Analyzer.hxx>
#include <BRepExtrema_DistShapeShape.hxx>
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
#include <BRepOffsetAPI_MakeOffset.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakeWedge.hxx>
#include <BRepTools.hxx>
#include <BRepTools_WireExplorer.hxx>
#include <BRep_Tool.hxx>
#include <Bnd_Box.hxx>
#include <ElCLib.hxx>
#include <GProp_GProps.hxx>
#include <Geom2d_Curve.hxx>
#include <ChFi2d_ChamferAPI.hxx>
#include <ChFi2d_FilletAPI.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <GeomConvert.hxx>
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
#include <StepData_StepModel.hxx>
#include <Interface_EntityIterator.hxx>
#include <HeaderSection_FileName.hxx>
#include <HeaderSection_FileDescription.hxx>
#include <HeaderSection_FileSchema.hxx>
#include <APIHeaderSection_MakeHeader.hxx>
#include <ShapeAnalysis_Edge.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeExtend_WireData.hxx>
#include <ShapeFix_FixSmallFace.hxx>
#include <ShapeFix_Shape.hxx>
#include <ShapeFix_Wireframe.hxx>
#include <Standard_Version.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_HArray1OfBoolean.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec.hxx>
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

#include "OCCAttributes.h"

#if OCC_VERSION_HEX < 0x060900
#error "Gmsh requires OpenCASCADE >= 6.9"
#endif

#if OCC_VERSION_HEX > 0x070100
#include <BOPAlgo_Alerts.hxx>
#endif

#if OCC_VERSION_HEX > 0x070300
#include <BRepMesh_IncrementalMesh.hxx>
#else
#include <BRepMesh_FastDiscret.hxx>
#endif

#if OCC_VERSION_HEX < 0x070400
#include <ShapeUpgrade_UnifySameDomain.hxx>
#endif

#if OCC_VERSION_HEX >= 0x070500
#include <BRepAlgoAPI_Defeaturing.hxx>
#include <Message_ProgressIndicator.hxx>
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

#if defined(HAVE_TINYXML2)
#include "tinyxml2.h"
#endif

OCC_Internals::OCC_Internals()
{
  for(int i = 0; i < 6; i++)
    _maxTag[i] = CTX::instance()->geom.firstEntityTag - 1;
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
  _unbind();
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
  _maxTag[dim + 2] = CTX::instance()->geom.firstEntityTag - 1;
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

void OCC_Internals::_bind(const TopoDS_Vertex &vertex, int tag, bool recursive)
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

void OCC_Internals::_bind(const TopoDS_Edge &edge, int tag, bool recursive)
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
        _bind(vertex, t, recursive);
      }
    }
  }
}

void OCC_Internals::_bind(const TopoDS_Wire &wire, int tag, bool recursive)
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
        _bind(edge, t, recursive);
      }
    }
  }
}

void OCC_Internals::_bind(const TopoDS_Face &face, int tag, bool recursive)
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
        _bind(wire, t, recursive);
      }
    }
    for(exp0.Init(face, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(!_edgeTag.IsBound(edge)) {
        int t = getMaxTag(1) + 1;
        _bind(edge, t, recursive);
      }
    }
  }
}

void OCC_Internals::_bind(const TopoDS_Shell &shell, int tag, bool recursive)
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
      // this leaves the old shell bound in _shellTag, but we cannot remove it
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
        _bind(face, t, recursive);
      }
    }
  }
}

void OCC_Internals::_bind(const TopoDS_Solid &solid, int tag, bool recursive)
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
      // this leaves the old solid bound in _solidTag, but we cannot remove it
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
        _bind(shell, t, recursive);
      }
    }
    for(exp0.Init(solid, TopAbs_FACE); exp0.More(); exp0.Next()) {
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(!_faceTag.IsBound(face)) {
        int t = getMaxTag(2) + 1;
        _bind(face, t, recursive);
      }
    }
  }
}

void OCC_Internals::_bind(TopoDS_Shape shape, int dim, int tag, bool recursive)
{
  switch(dim) {
  case 0: _bind(TopoDS::Vertex(shape), tag, recursive); break;
  case 1: _bind(TopoDS::Edge(shape), tag, recursive); break;
  case 2: _bind(TopoDS::Face(shape), tag, recursive); break;
  case 3: _bind(TopoDS::Solid(shape), tag, recursive); break;
  case -1: _bind(TopoDS::Wire(shape), tag, recursive); break;
  case -2: _bind(TopoDS::Shell(shape), tag, recursive); break;
  default: break;
  }
}

void OCC_Internals::_unbind(const TopoDS_Vertex &vertex, int tag,
                            bool recursive)
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

void OCC_Internals::_unbind(const TopoDS_Edge &edge, int tag, bool recursive)
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
        _unbind(vertex, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::_unbind(const TopoDS_Wire &wire, int tag, bool recursive)
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
        _unbind(edge, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::_unbind(const TopoDS_Face &face, int tag, bool recursive)
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
        _unbind(wire, t, recursive);
      }
    }
    for(exp0.Init(face, TopAbs_EDGE); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
      if(_edgeTag.IsBound(edge)) {
        int t = _edgeTag.Find(edge);
        _unbind(edge, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::_unbind(const TopoDS_Shell &shell, int tag, bool recursive)
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
        _unbind(face, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::_unbind(const TopoDS_Solid &solid, int tag, bool recursive)
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
        _unbind(shell, t, recursive);
      }
    }
    for(exp0.Init(solid, TopAbs_FACE); exp0.More(); exp0.Next()) {
      TopoDS_Face face = TopoDS::Face(exp0.Current());
      if(_faceTag.IsBound(face)) {
        int t = _faceTag.Find(face);
        _unbind(face, t, recursive);
      }
    }
  }
  _changed = true;
}

void OCC_Internals::_unbind(TopoDS_Shape shape, int dim, int tag,
                            bool recursive)
{
  switch(dim) {
  case 0: _unbind(TopoDS::Vertex(shape), tag, recursive); break;
  case 1: _unbind(TopoDS::Edge(shape), tag, recursive); break;
  case 2: _unbind(TopoDS::Face(shape), tag, recursive); break;
  case 3: _unbind(TopoDS::Solid(shape), tag, recursive); break;
  case -1: _unbind(TopoDS::Wire(shape), tag, recursive); break;
  case -2: _unbind(TopoDS::Shell(shape), tag, recursive); break;
  default: break;
  }
}

void OCC_Internals::_unbindWithoutChecks(TopoDS_Shape shape)
{
  TopExp_Explorer exp0;
  for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()) {
    TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
    if(_solidTag.IsBound(solid)) {
      int tag = _solidTag.Find(solid);
      _solidTag.UnBind(solid);
      _tagSolid.UnBind(tag);
      _toRemove.insert(std::make_pair(3, tag));
      _changed = true;
    }
  }
  for(exp0.Init(shape, TopAbs_SHELL); exp0.More(); exp0.Next()) {
    TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
    if(_shellTag.IsBound(shell)) {
      int tag = _shellTag.Find(shell);
      _shellTag.UnBind(shell);
      _tagShell.UnBind(tag);
      _toRemove.insert(std::make_pair(-2, tag));
      _changed = true;
    }
  }
  for(exp0.Init(shape, TopAbs_FACE); exp0.More(); exp0.Next()) {
    TopoDS_Face face = TopoDS::Face(exp0.Current());
    if(_faceTag.IsBound(face)) {
      int tag = _faceTag.Find(face);
      _faceTag.UnBind(face);
      _tagFace.UnBind(tag);
      _toRemove.insert(std::make_pair(2, tag));
      _changed = true;
    }
  }
  for(exp0.Init(shape, TopAbs_WIRE); exp0.More(); exp0.Next()) {
    TopoDS_Wire wire = TopoDS::Wire(exp0.Current());
    if(_wireTag.IsBound(wire)) {
      int tag = _wireTag.Find(wire);
      _wireTag.UnBind(wire);
      _tagWire.UnBind(tag);
      _toRemove.insert(std::make_pair(-1, tag));
      _changed = true;
    }
  }
  for(exp0.Init(shape, TopAbs_EDGE); exp0.More(); exp0.Next()) {
    TopoDS_Edge edge = TopoDS::Edge(exp0.Current());
    if(_edgeTag.IsBound(edge)) {
      int tag = _edgeTag.Find(edge);
      _edgeTag.UnBind(edge);
      _tagEdge.UnBind(tag);
      _toRemove.insert(std::make_pair(1, tag));
      _changed = true;
    }
  }
  for(exp0.Init(shape, TopAbs_VERTEX); exp0.More(); exp0.Next()) {
    TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
    if(_vertexTag.IsBound(vertex)) {
      int tag = _vertexTag.Find(vertex);
      _vertexTag.UnBind(vertex);
      _tagVertex.UnBind(tag);
      _toRemove.insert(std::make_pair(0, tag));
      _changed = true;
    }
  }
  for(int d = -2; d <= 3; d++) _recomputeMaxTag(d);
}

void OCC_Internals::_unbind()
{
  for(int i = 0; i < 6; i++)
    _maxTag[i] = CTX::instance()->geom.firstEntityTag - 1;

  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp;
  exp.Initialize(_tagVertex);
  for(; exp.More(); exp.Next()) _toRemove.insert(std::make_pair(0, exp.Key()));
  exp.Initialize(_tagEdge);
  for(; exp.More(); exp.Next()) _toRemove.insert(std::make_pair(1, exp.Key()));
  exp.Initialize(_tagFace);
  for(; exp.More(); exp.Next()) _toRemove.insert(std::make_pair(2, exp.Key()));
  exp.Initialize(_tagSolid);
  for(; exp.More(); exp.Next()) _toRemove.insert(std::make_pair(3, exp.Key()));
  exp.Initialize(_tagWire);
  for(; exp.More(); exp.Next()) _toRemove.insert(std::make_pair(-1, exp.Key()));
  exp.Initialize(_tagShell);
  for(; exp.More(); exp.Next()) _toRemove.insert(std::make_pair(-2, exp.Key()));

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
                               std::vector<std::pair<int, int>> &outDimTags,
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
    if(!exists) _bind(solid, t, recursive);
    if(!exists || !returnNewOnly) outDimTags.push_back(std::make_pair(3, t));
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
    if(!exists) _bind(face, t, recursive);
    if(!exists || !returnNewOnly) outDimTags.push_back(std::make_pair(2, t));
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
    if(!exists) _bind(edge, t, recursive);
    if(!exists || !returnNewOnly) outDimTags.push_back(std::make_pair(1, t));
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
    if(!exists) _bind(vertex, t, recursive);
    if(!exists || !returnNewOnly) outDimTags.push_back(std::make_pair(0, t));
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
  _bind(result, tag, true);
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
  _bind(result, tag, true);
  return true;
}

bool OCC_Internals::addLine(int &tag, const std::vector<int> &pointTags)
{
  if(pointTags.size() == 2) return addLine(tag, pointTags[0], pointTags[1]);

  // FIXME: if tag < 0 we could create multiple lines
  Msg::Error("OpenCASCADE polyline currently not supported");
  return false;
}

bool OCC_Internals::addCircleArc(int &tag, int startTag, int middleTag,
                                 int endTag, bool center)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }
  if(!_tagVertex.IsBound(startTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", startTag);
    return false;
  }
  if(!_tagVertex.IsBound(middleTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", middleTag);
    return false;
  }
  if(!_tagVertex.IsBound(endTag)) {
    Msg::Error("Unknown OpenCASCADE point with tag %d", endTag);
    return false;
  }

  TopoDS_Edge result;
  TopoDS_Vertex start = TopoDS::Vertex(_tagVertex.Find(startTag));
  TopoDS_Vertex middle = TopoDS::Vertex(_tagVertex.Find(middleTag));
  TopoDS_Vertex end = TopoDS::Vertex(_tagVertex.Find(endTag));
  gp_Pnt aP1 = BRep_Tool::Pnt(start);
  gp_Pnt aP2 = BRep_Tool::Pnt(middle);
  gp_Pnt aP3 = BRep_Tool::Pnt(end);

  gp_Pln p;
  try {
    p = gce_MakePln(aP1, aP2, aP3).Value();
  } catch(...) {
    Msg::Info("Could not make plane from 3 points - assuming z=%g", aP2.Z());
    gp_Dir N_dir(0., 0., 1.);
    p = gce_MakePln(aP2, N_dir).Value();
  }

  try {
    gp_Circ Circ;
    if(center) {
      Standard_Real Radius = aP1.Distance(aP2);
      gce_MakeCirc MC(aP2, p, Radius);
      if(!MC.IsDone()) {
        Msg::Error("Could not build circle using two points and center");
        return false;
      }
      Circ = MC.Value();
    }
    else {
      gce_MakeCirc MC(aP1, aP2, aP3);
      if(!MC.IsDone()) {
        Msg::Error("Could not build circle through three points");
        return false;
      }
      Circ = MC.Value();
    }
    Handle(Geom_Circle) C = new Geom_Circle(Circ);
    Standard_Real Alpha1 = ElCLib::Parameter(Circ, aP1);
    Standard_Real Alpha2 = ElCLib::Parameter(Circ, aP3);
    bool Sense = false;
    if(!center) {
      Standard_Real AlphaC = ElCLib::Parameter(Circ, aP2);
      if(AlphaC > Alpha1 && AlphaC < Alpha2) Sense = true;
    }
    Handle(Geom_TrimmedCurve) arc =
      new Geom_TrimmedCurve(C, Alpha1, Alpha2, Sense);
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
  _bind(result, tag, true);
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
      Msg::Error("Cannot create ellipse arc with start and end point on the "
                 "major axis");
      return false;
    }
    Standard_Real x1u = Square(x1.Dot(u.XYZ()));
    Standard_Real x1v = Square(x1.Dot(v.XYZ()));
    Standard_Real x2u = Square(x2.Dot(u.XYZ()));
    Standard_Real x2v = Square(x2.Dot(v.XYZ()));
    if(IsEqual(x1u, x2u) || IsEqual(x1v, x2v)) {
      Msg::Error("Cannot create ellipse arc with start and end point symmetric "
                 "with respect to major or minor axis");
      return false;
    }
    Standard_Real a2 = (x1v * x2u - x1u * x2v) / (x1v - x2v);
    Standard_Real b2 = (x1u * x2v - x1v * x2u) / (x1u - x2u);
    if(a2 <= 0.0 || b2 <= 0.0) {
      Msg::Error("Invalid radii during creation of ellipse arc");
      return false;
    }
    Standard_Real a; // major radius
    Standard_Real b; // minor radius
    gp_Ax2 Axes; // ellipse local coordinate system
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
  _bind(result, tag, true);
  return true;
}

bool OCC_Internals::addCircle(int &tag, double x, double y, double z, double r,
                              double angle1, double angle2,
                              const std::vector<double> &N,
                              const std::vector<double> &V)
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
    gp_Circ circ;
    gp_Pnt center(x, y, z);
    if(N.size() == 3 && V.size() == 3) {
      gp_Dir N_dir(N[0], N[1], N[2]);
      gp_Dir x_dir(V[0], V[1], V[2]);
      gp_Ax2 axis(center, N_dir, x_dir);
      circ.SetPosition(axis);
    }
    else if(N.size() == 3) {
      gp_Dir N_dir(N[0], N[1], N[2]);
      gp_Ax2 axis(center, N_dir);
      circ.SetPosition(axis);
    }
    else {
      gp_Dir N_dir(0., 0., 1.);
      gp_Dir x_dir(1., 0., 0.);
      gp_Ax2 axis(center, N_dir, x_dir);
      circ.SetPosition(axis);
    }
    circ.SetRadius(r);
    if(angle1 == 0. && angle2 == 2 * M_PI) {
      result = BRepBuilderAPI_MakeEdge(circ);
    }
    else {
      Handle(Geom_Circle) C = new Geom_Circle(circ);
      Handle(Geom_TrimmedCurve) arc =
        new Geom_TrimmedCurve(C, angle1, angle2, true);
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
  _bind(result, tag, true);
  return true;
}

bool OCC_Internals::addEllipse(int &tag, double x, double y, double z,
                               double rx, double ry, double angle1,
                               double angle2, const std::vector<double> &N,
                               const std::vector<double> &V)
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
    gp_Elips el;
    gp_Pnt center(x, y, z);
    if(N.size() == 3 && V.size() == 3) {
      gp_Dir N_dir(N[0], N[1], N[2]);
      gp_Dir x_dir(V[0], V[1], V[2]);
      gp_Ax2 axis(center, N_dir, x_dir);
      el.SetPosition(axis);
    }
    else if(N.size() == 3) {
      gp_Dir N_dir(N[0], N[1], N[2]);
      gp_Ax2 axis(center, N_dir);
      el.SetPosition(axis);
    }
    else {
      gp_Dir N_dir(0., 0., 1.);
      gp_Dir x_dir(1., 0., 0.);
      gp_Ax2 axis(center, N_dir, x_dir);
      el.SetPosition(axis);
    }
    el.SetMajorRadius(rx);
    el.SetMinorRadius(ry);
    if(angle1 == 0 && angle2 == 2 * M_PI) {
      result = BRepBuilderAPI_MakeEdge(el);
    }
    else {
      Handle(Geom_Ellipse) E = new Geom_Ellipse(el);
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
  _bind(result, tag, true);
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
                                const std::vector<int> &multiplicities,
                                const std::vector<SVector3> &tangents)
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
      if(tangents.size() == 2) {
        gp_Vec t1(tangents[0].x(), tangents[0].y(), tangents[0].z());
        gp_Vec tN(tangents[1].x(), tangents[1].y(), tangents[1].z());
        intp.Load(t1, tN);
      }
      else if(tangents.size() == pointTags.size()) {
        TColgp_Array1OfVec Tangents(1, tangents.size());
        Handle(TColStd_HArray1OfBoolean) TangentFlags =
          new TColStd_HArray1OfBoolean(1, tangents.size());
        for(std::size_t i = 1; i <= tangents.size(); i++) {
          gp_Vec t(tangents[i - 1].x(), tangents[i - 1].y(),
                   tangents[i - 1].z());
          Tangents.SetValue(i, t);
          if(tangents[i - 1].normSq() < 1e-12) {
            TangentFlags->SetValue(i, Standard_False);
          }
          else {
            TangentFlags->SetValue(i, Standard_True);
          }
        }
        intp.Load(Tangents, TangentFlags);
      }
      else if(!tangents.empty()) {
        Msg::Warning(
          "Wrong number of tangent constraints for spline (%lu != %lu)",
          tangents.size(), pointTags.size());
      }
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
                                   CTX::instance()->geom.tolerance) &&
         !curve->StartPoint().IsEqual(curve->EndPoint(),
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
  _bind(result, tag, true);
  return true;
}

bool OCC_Internals::addSpline(int &tag, const std::vector<int> &pointTags,
                              const std::vector<SVector3> &tangents)
{
  std::vector<double> weights;
  std::vector<double> knots;
  std::vector<int> multiplicities;
  return _addBSpline(tag, pointTags, 0, -1, weights, knots, multiplicities,
                     tangents);
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
      k.resize(np);
      for(std::size_t i = 0; i < k.size(); i++) k[i] = i;
      m.resize(k.size(), 1);
    }
  }
  return _addBSpline(tag, pointTags, 2, d, w, k, m);
}

bool OCC_Internals::addWire(int &tag, const std::vector<int> &curveTags,
                            bool checkClosed)
{
  if(tag >= 0 && _tagWire.IsBound(tag)) {
    Msg::Error("OpenCASCADE wire or curve loop with tag %d already exists",
               tag);
    return false;
  }

  // Note: contrary to shells wires are always "sewed", i.e., a valid wire is
  // constructed if points are geometrically at the same location (even if they
  // are not topologically identical); there is thus no need to add a "sewing"
  // option.
  try {
    BRepBuilderAPI_MakeWire w;
    TopoDS_Wire wire;
    bool reversed = false;
    for(std::size_t i = 0; i < curveTags.size(); i++) {
      // all curve tags are > 0 for OCC, and the orientation of the wire is
      // dictated by the orientation of the first curve in the wire; to improve
      // compatibility between GEO and OCC factories, if the first curve has a
      // negative tag, we reverse the wire
      int t = std::abs(curveTags[i]);
      if(i == 0 && curveTags[i] < 0) reversed = true;
      if(!_tagEdge.IsBound(t)) {
        Msg::Error("Unknown OpenCASCADE curve with tag %d", t);
        return false;
      }
      TopoDS_Edge edge = TopoDS::Edge(_tagEdge.Find(t));
      w.Add(edge);
    }
    w.Build();
    if(!w.IsDone()) {
      Msg::Error("Could not create wire");
      return false;
    }
    wire = w.Wire();
    if(checkClosed && !wire.Closed()) {
      Msg::Error("Curve loop is not closed");
      return false;
    }
    if(tag < 0) tag = getMaxTag(-1) + 1;
    if(reversed) {
      Msg::Debug("Reversing wire %d because its first curve was provided "
                 "with a negative tag",
                 tag);
      ShapeExtend_WireData sw(wire);
      sw.Reverse();
      wire = sw.Wire();
    }
    _bind(wire, tag, true);
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
  _bind(result, tag, true);
  return true;
}

static bool makeDisk(TopoDS_Face &result, double xc, double yc, double zc,
                     double rx, double ry,
                     const std::vector<double> &N = std::vector<double>(),
                     const std::vector<double> &V = std::vector<double>())
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
    gp_Elips el;
    gp_Pnt center(xc, yc, zc);
    if(N.size() == 3 && V.size() == 3) {
      gp_Dir N_dir(N[0], N[1], N[2]);
      gp_Dir x_dir(V[0], V[1], V[2]);
      gp_Ax2 axis(center, N_dir, x_dir);
      el.SetPosition(axis);
    }
    else if(N.size() == 3) {
      gp_Dir N_dir(N[0], N[1], N[2]);
      gp_Ax2 axis(center, N_dir);
      el.SetPosition(axis);
    }
    else {
      gp_Dir N_dir(0., 0., 1.);
      gp_Dir x_dir(1., 0., 0.);
      gp_Ax2 axis(center, N_dir, x_dir);
      el.SetPosition(axis);
    }
    el.SetMajorRadius(rx);
    el.SetMinorRadius(ry);
    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(el);
    TopoDS_Wire wire = BRepBuilderAPI_MakeWire(edge);
    result = BRepBuilderAPI_MakeFace(wire);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

bool OCC_Internals::addDisk(int &tag, double xc, double yc, double zc,
                            double rx, double ry, const std::vector<double> &N,
                            const std::vector<double> &V)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }
  TopoDS_Face result;
  if(!makeDisk(result, xc, yc, zc, rx, ry, N, V)) return false;
  if(tag < 0) tag = getMaxTag(2) + 1;
  _bind(result, tag, true);
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
      Msg::Error("Unknown OpenCASCADE curve loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    wires.push_back(wire);
  }

  TopoDS_Face result;
  if(wires.size() == 0) {
    Msg::Error("Plane surface requires at least one curve loop");
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
      Msg::Error("Could not create surface");
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
  _bind(result, tag, true);
  return true;
}

bool OCC_Internals::addSurfaceFilling(
  int &tag, int wireTag, const std::vector<int> &pointTags,
  const std::vector<int> &surfaceTags,
  const std::vector<int> &surfaceContinuity, const int degree,
  const int numPointsOnCurves, const int numIter, const bool anisotropic,
  const double tol2d, const double tol3d, const double tolAng,
  const double tolCurv, const int maxDegree, const int maxSegments)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  TopoDS_Face result;
  try {
    BRepOffsetAPI_MakeFilling f(degree, numPointsOnCurves, numIter, anisotropic,
                                tol2d, tol3d, tolAng, tolCurv, maxDegree,
                                maxSegments);
    // bounding edge constraints
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE curve loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    BRepTools_WireExplorer exp0; // guarantees edges are ordered
    std::size_t i = 0;
    for(exp0.Init(wire); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = exp0.Current();
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
    // underlying surface, and remake a new face explicitly with the wire
    TopoDS_Face tmp = TopoDS::Face(f.Shape());
    Handle(Geom_Surface) s = BRep_Tool::Surface(tmp);
    ShapeFix_Face sff;
    sff.Init(s, CTX::instance()->geom.tolerance);
    sff.Add(wire);
    sff.Perform();
    bool reverse = sff.FixOrientation();
    result = sff.Face();
    if(reverse) result.Orientation(TopAbs_REVERSED);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  _bind(result, tag, true);
  return true;
}

bool OCC_Internals::addBSplineFilling(int &tag, int wireTag,
                                      const std::string &type)
{
  if(tag >= 0 && _tagFace.IsBound(tag)) {
    Msg::Error("OpenCASCADE surface with tag %d already exists", tag);
    return false;
  }

  // TODO: make this a parameter
  int degree = 0; // 0 = use the degree of the input curves

  const double tol = CTX::instance()->geom.tolerance;
  TopoDS_Face result;
  try {
    GeomFill_BSplineCurves f;
    if(!_tagWire.IsBound(wireTag)) {
      Msg::Error("Unknown OpenCASCADE curve loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    std::vector<Handle(Geom_BSplineCurve)> bsplines;
    BRepTools_WireExplorer exp0; // guarantees edges are ordered
    for(exp0.Init(wire); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = exp0.Current();
      double s0, s1;
      Handle(Geom_Curve) curve = BRep_Tool::Curve(edge, s0, s1);
      Handle(Geom_BSplineCurve) bspline;
      bool approx = false;
      if(curve->DynamicType() == STANDARD_TYPE(Geom_BSplineCurve)) {
        bspline = Handle(Geom_BSplineCurve)::DownCast(curve);
        if(bspline->Degree() < degree) approx = true;
      }
      else {
        approx = true;
      }
      if(approx) {
        // cannot directly use GeomConvert::CurveToBSplineCurve because it does
        // not handle infinite curves (e.g. straight lines)
        BRepBuilderAPI_NurbsConvert nurbs(edge);
        TopoDS_Edge edge2 = TopoDS::Edge(nurbs.ModifiedShape(edge));
        curve = BRep_Tool::Curve(edge2, s0, s1);
        if(curve->DynamicType() != STANDARD_TYPE(Geom_BSplineCurve)) {
          Msg::Error("Could not convert bounding curve for BSpline filling to "
                     "a BSpline");
          return false;
        }
        bspline = Handle(Geom_BSplineCurve)::DownCast(curve);
        if(bspline->Degree() < degree) bspline->IncreaseDegree(degree);
      }
      // if trimmed, create an approximation
      TopoDS_Vertex v0 = TopExp::FirstVertex(edge);
      TopoDS_Vertex v1 = TopExp::LastVertex(edge);
      if(!bspline->StartPoint().IsEqual(BRep_Tool::Pnt(v0), tol) ||
         !bspline->EndPoint().IsEqual(BRep_Tool::Pnt(v1), tol)) {
        bspline = GeomConvert::SplitBSplineCurve(bspline, s0, s1, 1e-6);
      }
      bsplines.push_back(bspline);
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
      // workaround bug in 3-sided case in GeomFill_BSplineCurves, which fails
      // to detect correct ordering when the first curve should be reversed:
      if(!bsplines[0]->EndPoint().IsEqual(bsplines[1]->StartPoint(), tol) &&
         !bsplines[0]->EndPoint().IsEqual(bsplines[1]->EndPoint(), tol)) {
        f.Init(bsplines[0], bsplines[2], bsplines[1], t);
      }
      else {
        f.Init(bsplines[0], bsplines[1], bsplines[2], t);
      }
    }
    else if(bsplines.size() == 2) {
      f.Init(bsplines[0], bsplines[1], t);
    }
    else {
      Msg::Error(
        "BSpline filling requires between 2 and 4 boundary BSpline curves");
      return false;
    }
    ShapeFix_Face sff;
    sff.Init(f.Surface(), tol);
    sff.Add(wire);
    sff.Perform();
    bool reverse = sff.FixOrientation();
    result = sff.Face();
    if(reverse) result.Orientation(TopAbs_REVERSED);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  _bind(result, tag, true);
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
      Msg::Error("Unknown OpenCASCADE curve loop with tag %d", wireTag);
      return false;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
    BRepTools_WireExplorer exp0; // guarantees edges are ordered
    std::vector<Handle(Geom_BezierCurve)> beziers;
    for(exp0.Init(wire); exp0.More(); exp0.Next()) {
      TopoDS_Edge edge = exp0.Current();
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
    ShapeFix_Face sff;
    sff.Init(f.Surface(), CTX::instance()->geom.tolerance);
    sff.Add(wire);
    sff.Perform();
    bool reverse = sff.FixOrientation();
    result = sff.Face();
    if(reverse) result.Orientation(TopAbs_REVERSED);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }

  if(tag < 0) tag = getMaxTag(2) + 1;
  _bind(result, tag, true);
  return true;
}

static bool makeEdgeOnSurface(const TopoDS_Edge &edge,
                              const Handle(Geom_Surface) & surf, bool curve3D,
                              TopoDS_Edge &edgeOnSurf)
{
  try {
    Standard_Real first, last;
    Handle(Geom_Curve) c = BRep_Tool::Curve(edge, first, last);
    if(curve3D) {
      // use the 3D curves in the wire and project them onto the patch
      Handle(Geom_Curve) cProj = GeomProjLib::Project(
        new Geom_TrimmedCurve(c, first, last, Standard_True, Standard_False),
        surf);
      edgeOnSurf = BRepBuilderAPI_MakeEdge(cProj, cProj->FirstParameter(),
                                           cProj->LastParameter());
    }
    else {
      // assume the 3D curve is actually a 2D curve in the parametric plane of
      // the surface: to retrieve the 2D curve, project the 3D curve on the z=0
      // plane
      Handle(Geom_Plane) p = new Geom_Plane(0, 0, 1, 0);
      TopLoc_Location loc;
      Handle(Geom2d_Curve) c2d =
        BRep_Tool::CurveOnSurface(edge, p, loc, first, last);
      // BRep_Tool::CurveOnPlane(edge, p, loc, first, last); // OCCT >= 7.2
      edgeOnSurf = BRepBuilderAPI_MakeEdge(c2d, surf, first, last);
    }
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  return true;
}

static bool makeTrimmedSurface(const Handle(Geom_Surface) & surf,
                               const std::vector<TopoDS_Wire> &wires,
                               bool wire3D, TopoDS_Face &result)
{
  if(wires.empty()) { // natural bounds
    result = BRepBuilderAPI_MakeFace(surf, CTX::instance()->geom.tolerance);
#if 0
    // Activate this to use input points as corners if they are on the corners
    // of the patch. (Since the natural "Replace(old_vertex, new_vertex)" on the
    // face does not work, we do it on each edge. Sigh...)  Since when buiding
    // multi-patch models a fragment or sewing will eventually be necessary to
    // glue the patches, it's not that useful - let's leave this commented out.
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
      BRepTools_WireExplorer exp0; // guarantees edges are ordered
      for(exp0.Init(wires[i]); exp0.More(); exp0.Next()) {
        TopoDS_Edge edge = exp0.Current(), edgeOnSurf;
        if(makeEdgeOnSurface(edge, surf, wire3D, edgeOnSurf)) {
          w.Add(edgeOnSurf);
        }
      }
      w.Build();
      if(!w.IsDone()) {
        Msg::Error("Could not create wire");
        return false;
      }
      TopoDS_Wire wire = w.Wire();
      wiresProj.push_back(wire);
    }
    BRepBuilderAPI_MakeFace f(surf, wiresProj[0]);
    for(std::size_t i = 1; i < wiresProj.size(); i++) f.Add(wiresProj[i]);
    f.Build();
    if(!f.IsDone()) {
      Msg::Error("Could not create surface");
      return false;
    }
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
      Msg::Error("Unknown OpenCASCADE curve loop with tag %d", wireTag);
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
  _bind(result, tag, true);
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
      Msg::Error("Unknown OpenCASCADE curve loop with tag %d", wireTag);
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
  _bind(result, tag, true);
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
      Msg::Error("Unknown OpenCASCADE curve loop with tag %d", wireTag);
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
  _bind(result, tag, true);
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
    // this allows one to build a shell made of surfaces that share
    // geometrically identical (but topologically different) curves.
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
      if(first) { first = false; }
      else {
        tag = getMaxTag(-2) + 1;
        Msg::Warning("Creating additional surface loop %d", tag);
      }
      if(tag < 0) tag = getMaxTag(-2) + 1;
      _bind(shell, tag, true);
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
    if(tag < 0) tag = getMaxTag(-2) + 1;
    _bind(shell, tag, true);
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
  _bind(result, tag, true);
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
  _bind(result, tag, true);
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
  _bind(result, tag, true);
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
    gp_Pnt p(x, y, z);
    gp_Vec v(dx / H, dy / H, dz / H);
    gp_Ax2 axis(p, v);
    BRepPrimAPI_MakeCylinder c(axis, r, H, angle);
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
  _bind(result, tag, true);
  return true;
}

static bool makeTorus(TopoDS_Solid &result, double x, double y, double z,
                      double r1, double r2, double angle,
                      const std::vector<double> &N = std::vector<double>())
{
  if(r1 <= 0 || r2 <= 0) {
    Msg::Error("Torus radii should be positive");
    return false;
  }
  try {
    gp_Pnt p(x, y, z);
    std::vector<double> NN(N);
    if(NN.size() != 3) {
      NN.resize(3);
      NN[0] = 0.;
      NN[1] = 0.;
      NN[2] = 1.;
    }
    gp_Vec v(NN[0], NN[1], NN[2]);
    gp_Ax2 axis(p, v);
    BRepPrimAPI_MakeTorus t(axis, r1, r2, angle);
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
                             double r2, double angle,
                             const std::vector<double> &N)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!makeTorus(result, x, y, z, r1, r2, angle, N)) return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  _bind(result, tag, true);
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
  _bind(result, tag, true);
  return true;
}

static bool makeWedge(TopoDS_Solid &result, double x, double y, double z,
                      double dx, double dy, double dz, double ltx,
                      const std::vector<double> &N = std::vector<double>())
{
  try {
    gp_Pnt p(x, y, z);
    std::vector<double> NN(N);
    if(NN.size() != 3) {
      NN.resize(3);
      NN[0] = 0.;
      NN[1] = 0.;
      NN[2] = 1.;
    }
    gp_Vec v(NN[0], NN[1], NN[2]);
    gp_Ax2 axis(p, v);
    BRepPrimAPI_MakeWedge w(axis, dx, dy, dz, ltx);
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
                             double dy, double dz, double ltx,
                             const std::vector<double> &N)
{
  if(tag >= 0 && _tagSolid.IsBound(tag)) {
    Msg::Error("OpenCASCADE volume with tag %d already exists", tag);
    return false;
  }
  TopoDS_Solid result;
  if(!makeWedge(result, x, y, z, dx, dy, dz, ltx, N)) return false;
  if(tag < 0) tag = getMaxTag(3) + 1;
  _bind(result, tag, true);
  return true;
}

bool OCC_Internals::addThruSections(
  int tag, const std::vector<int> &wireTags, bool makeSolid, bool makeRuled,
  std::vector<std::pair<int, int>> &outDimTags, int maxDegree,
  const std::string &continuity, const std::string &parametrization,
  bool smoothing)
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
    if(continuity == "C0")
      ts.SetContinuity(GeomAbs_C0);
    else if(continuity == "G1")
      ts.SetContinuity(GeomAbs_G1);
    else if(continuity == "C1")
      ts.SetContinuity(GeomAbs_C1);
    else if(continuity == "G2")
      ts.SetContinuity(GeomAbs_G2);
    else if(continuity == "C2")
      ts.SetContinuity(GeomAbs_C2);
    else if(continuity == "C3")
      ts.SetContinuity(GeomAbs_C3);
    else if(continuity == "CN")
      ts.SetContinuity(GeomAbs_CN);

    // ts.SetCriteriumWeight(1, 1, 1);

    if(maxDegree > 0)
      ts.SetMaxDegree(maxDegree);
    else if(CTX::instance()->geom.occThruSectionsDegree > 0)
      ts.SetMaxDegree(CTX::instance()->geom.occThruSectionsDegree);

    if(parametrization == "ChordLength")
      ts.SetParType(Approx_ChordLength);
    else if(parametrization == "Centripetal")
      ts.SetParType(Approx_Centripetal);
    else if(parametrization == "IsoParametric")
      ts.SetParType(Approx_IsoParametric);

    ts.SetSmoothing(smoothing ? Standard_True : Standard_False);

    for(std::size_t i = 0; i < wireTags.size(); i++) {
      if(!_tagWire.IsBound(wireTags[i])) {
        Msg::Error("Unknown OpenCASCADE wire or curve loop with tag %d",
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
                                  std::vector<std::pair<int, int>> &outDimTags)
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
                             std::vector<std::vector<TopoDS_Shape>> &lateral)
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
  double angle, int wireTag, std::vector<std::pair<int, int>> &outDimTags,
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
  std::vector<std::vector<TopoDS_Shape>> lateral;
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
      if(trihedron == "DiscreteTrihedron")
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
        outDimTags.push_back(std::make_pair(dim - 1, _find(dim - 1, top[i])));
      if(_isBound(dim, body[i]))
        outDimTags.push_back(std::make_pair(dim, _find(dim, body[i])));
      if(CTX::instance()->geom.extrudeReturnLateral &&
         top.size() == lateral.size()) {
        for(std::size_t j = 0; j < lateral[i].size(); j++) {
          if(_isBound(dim - 1, lateral[i][j]))
            outDimTags.push_back(
              std::make_pair(dim - 1, _find(dim - 1, lateral[i][j])));
        }
      }
    }
  }
  return true;
}

bool OCC_Internals::_extrude(int mode,
                             const std::vector<std::pair<int, int>> &inDimTags,
                             double x, double y, double z, double dx, double dy,
                             double dz, double ax, double ay, double az,
                             double angle, int wireTag,
                             std::vector<std::pair<int, int>> &outDimTags,
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
      std::vector<std::pair<int, int>> out;
      if(_extrudePerDim(mode, dim, inTags[dim], x, y, z, dx, dy, dz, ax, ay, az,
                        angle, wireTag, out, e, trihedron)) {
        outDimTags.insert(outDimTags.end(), out.begin(), out.end());
      }
    }
  }
  return true;
}

bool OCC_Internals::extrude(const std::vector<std::pair<int, int>> &inDimTags,
                            double dx, double dy, double dz,
                            std::vector<std::pair<int, int>> &outDimTags,
                            ExtrudeParams *e)
{
  return _extrude(0, inDimTags, 0., 0., 0., dx, dy, dz, 0., 0., 0., 0., 0,
                  outDimTags, e);
}

bool OCC_Internals::revolve(const std::vector<std::pair<int, int>> &inDimTags,
                            double x, double y, double z, double ax, double ay,
                            double az, double angle,
                            std::vector<std::pair<int, int>> &outDimTags,
                            ExtrudeParams *e)
{
  return _extrude(1, inDimTags, x, y, z, 0., 0., 0., ax, ay, az, angle, 0,
                  outDimTags, e);
}

bool OCC_Internals::addPipe(const std::vector<std::pair<int, int>> &inDimTags,
                            int wireTag,
                            std::vector<std::pair<int, int>> &outDimTags,
                            const std::string &trihedron)
{
  std::string t = trihedron;
  if(t.empty()) t = CTX::instance()->geom.pipeDefaultTrihedron;
  return _extrude(2, inDimTags, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., wireTag,
                  outDimTags, nullptr, t);
}

bool OCC_Internals::_fillet(int mode, const std::vector<int> &volumeTags,
                            const std::vector<int> &curveTags,
                            const std::vector<int> &surfaceTags,
                            const std::vector<double> &param,
                            std::vector<std::pair<int, int>> &outDimTags,
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
    if(removeVolume) _unbind(shape, 3, volumeTags[i], true);
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
                           std::vector<std::pair<int, int>> &outDimTags,
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
                            std::vector<std::pair<int, int>> &outDimTags,
                            bool removeVolume)
{
  return _fillet(1, volumeTags, curveTags, surfaceTags, distances, outDimTags,
                 removeVolume);
}

bool OCC_Internals::defeature(const std::vector<int> &volumeTags,
                              const std::vector<int> &surfaceTags,
                              std::vector<std::pair<int, int>> &outDimTags,
                              bool removeVolume)
{
#if OCC_VERSION_HEX >= 0x070500
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
    if(CTX::instance()->geom.occAutoFix) {
      // make sure the volume is finite
      ShapeFix_Solid fix(TopoDS::Solid(shape));
      fix.Perform();
      shape = fix.Solid();
    }
    b.Add(c, shape);
  }
  BRepAlgoAPI_Defeaturing defeat;
  defeat.SetShape(c);
  for(std::size_t i = 0; i < surfaceTags.size(); i++) {
    if(!_isBound(2, surfaceTags[i])) {
      Msg::Error("Unknown OpenCASCADE surface with tag %d", surfaceTags[i]);
      return false;
    }
    TopoDS_Face face = TopoDS::Face(_tagFace.Find(surfaceTags[i]));
    defeat.AddFaceToRemove(face);
  }

  if(removeVolume) {
    for(std::size_t i = 0; i < volumeTags.size(); i++) {
      TopoDS_Shape shape = _find(3, volumeTags[i]);
      _unbind(shape, 3, volumeTags[i], true);
    }
  }

  defeat.SetRunParallel(CTX::instance()->geom.occParallel);
  defeat.Build();
  if(!defeat.IsDone()) {
    std::ostringstream os;
    defeat.DumpErrors(os);
    std::string s = ReplaceSubString("\n", " ", os.str());
    Msg::Error("Could not defeature shapes%s%s", os.str().size() ? " - " : "",
               s.c_str());
    return false;
  }
  if(defeat.HasWarnings()) {
    std::ostringstream os;
    defeat.DumpWarnings(os);
    std::string s = ReplaceSubString("\n", " ", os.str());
    Msg::Warning("%s", s.c_str());
  }

  TopoDS_Shape result = defeat.Shape();

  if(result.IsNull()) {
    Msg::Error("Defeaturing produced empty shape");
    return false;
  }

  // TODO: if removeVolume and CTX::instance()->geom.occBooleanPreserveNumbering
  // are set we could use Generated(), Modified() and IsDeleted() in a similar
  // way as what we do for boolean operation, in order to try to preserve tags

  _multiBind(result, -1, outDimTags, true, true);
  return true;
#else
  Msg::Error("Defeaturing requires OpenCASCADE >= 7.5.0");
  return false;
#endif
}

bool OCC_Internals::fillet2D(int &tag, const int edgeTag1, const int edgeTag2,
                             double radius)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }

  if(!_tagEdge.IsBound(edgeTag1)) {
    Msg::Error("Unknown OpenCASCADE curve with tag %d", edgeTag1);
    return false;
  }
  TopoDS_Edge ed1 = TopoDS::Edge(_tagEdge.Find(edgeTag1));

  if(!_tagEdge.IsBound(edgeTag2)) {
    Msg::Error("Unknown OpenCASCADE curve with tag %d", edgeTag2);
    return false;
  }
  TopoDS_Edge ed2 = TopoDS::Edge(_tagEdge.Find(edgeTag2));

  BRepBuilderAPI_MakeWire w;
  TopoDS_Wire wire;
  w.Add(ed1);
  w.Add(ed2);
  w.Build();
  if(!w.IsDone()) {
    Msg::Error(
      "Could not create temporary wire from given edges. Are edges connected?");
    return false;
  }
  wire = w.Wire();

  TopoDS_Face face;
  BRepBuilderAPI_MakeFace mf(wire);

  mf.Build();
  if(!mf.IsDone()) {
    Msg::Error(
      "Could not create temporary face from given edges. Are edges planar?");
    return false;
  }
  face = mf.Face();
  if(CTX::instance()->geom.occAutoFix) {
    // make sure wires are oriented correctly
    ShapeFix_Face fix(face);
    fix.Perform();
    face = fix.Face();
  }

  Handle(Geom_Surface) gSurface = BRep_Tool::Surface(face);
  Handle(Geom_ElementarySurface) aElementarySurface =
    Handle(Geom_ElementarySurface)::DownCast(gSurface);
  gp_Dir normal = aElementarySurface->Axis().Direction();
  if(face.Orientation() == TopAbs_REVERSED) { normal = -normal; }

  TopoDS_Vertex v1 = ShapeAnalysis_Edge().FirstVertex(ed1);
  gp_Pnt point = BRep_Tool().Pnt(v1);

  gp_Pln p(point, normal);

  ChFi2d_FilletAPI f(ed1, ed2, p);
  if(!f.Perform(radius)) {
    Msg::Error("Could not compute fillet");
    return false;
  }

  TopoDS_Edge filletEd = f.Result(point, ed1, ed2, -1);

  _unbind(_find(1, edgeTag1), 1, edgeTag1, true);
  _unbind(_find(1, edgeTag2), 1, edgeTag2, true);

  _bind(ed1, edgeTag1, true);
  _bind(ed2, edgeTag2, true);

  if(tag < 0) tag = getMaxTag(1) + 1;
  _bind(filletEd, tag, true);

  return true;
}

bool OCC_Internals::chamfer2D(int &tag, const int edgeTag1, const int edgeTag2,
                              double distance1, double distance2)
{
  if(tag >= 0 && _tagEdge.IsBound(tag)) {
    Msg::Error("OpenCASCADE curve with tag %d already exists", tag);
    return false;
  }

  if(!_tagEdge.IsBound(edgeTag1)) {
    Msg::Error("Unknown OpenCASCADE curve with tag %d", edgeTag1);
    return false;
  }
  TopoDS_Edge ed1 = TopoDS::Edge(_tagEdge.Find(edgeTag1));

  if(!_tagEdge.IsBound(edgeTag2)) {
    Msg::Error("Unknown OpenCASCADE curve with tag %d", edgeTag2);
    return false;
  }
  TopoDS_Edge ed2 = TopoDS::Edge(_tagEdge.Find(edgeTag2));

  ChFi2d_ChamferAPI cha(ed1, ed2);

  if(!cha.Perform()) {
    Msg::Error("Could not compute chamfer");
    return false;
  }

  TopoDS_Edge chamferEd = cha.Result(ed1, ed2, distance1, distance2);

  _unbind(_find(1, edgeTag1), 1, edgeTag1, true);
  _unbind(_find(1, edgeTag2), 1, edgeTag2, true);

  _bind(ed1, edgeTag1, true);
  _bind(ed2, edgeTag2, true);

  if(tag < 0) tag = getMaxTag(1) + 1;
  _bind(chamferEd, tag, true);

  return true;
}

bool OCC_Internals::offsetCurve(const int curveLoopTag, double offset,
                                std::vector<std::pair<int, int>> &outDimTags)
{
  if(!_tagWire.IsBound(curveLoopTag)) {
    Msg::Error("Unknown OpenCASCADE curve loop with tag %d", curveLoopTag);
    return false;
  }
  TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(curveLoopTag));

  BRepOffsetAPI_MakeOffset of(wire, GeomAbs_Arc);
  of.Perform(offset);
  if(!of.IsDone()) {
    Msg::Error("Could not compute offset curve");
    return false;
  }

  _multiBind(of.Shape(), -1, outDimTags, true, true);

  return true;
}

#if OCC_VERSION_HEX >= 0x070500

class OCCBooleanProgress : public Message_ProgressIndicator {
private:
  std::string _name;
public:
  OCCBooleanProgress(std::string name) : _name(name)
  {
    Msg::StartProgressMeter(100);
  }
  ~OCCBooleanProgress() { Msg::StopProgressMeter(); }
  void Show(const Message_ProgressScope &theScope,
            const Standard_Boolean theToForce)
  {
    const char *str = theScope.Name();
    Msg::ProgressMeter((int)(100. * GetPosition()), true, "%s%s%s",
                       _name.c_str(), str ? " - " : " ", str ? str : " ");
  }
};

#endif

template <class T> static void _setBooleanOptions(T &algo)
{
  algo.SetRunParallel(CTX::instance()->geom.occParallel);
  if(CTX::instance()->geom.toleranceBoolean > 0.0)
    algo.SetFuzzyValue(CTX::instance()->geom.toleranceBoolean);
#if OCC_VERSION_HEX >= 0x070100
  if(CTX::instance()->geom.occBooleanNonDestructive)
    algo.SetNonDestructive(true);
#endif
#if OCC_VERSION_HEX >= 0x070200
  switch(CTX::instance()->geom.occBooleanGlue) {
  case 1: algo.SetGlue(BOPAlgo_GlueShift); break;
  case 2: algo.SetGlue(BOPAlgo_GlueFull); break;
  default: algo.SetGlue(BOPAlgo_GlueOff); break;
  }
#endif
#if OCC_VERSION_HEX >= 0x070300
  if(CTX::instance()->geom.occBooleanCheckInverted) algo.SetCheckInverted(true);
#endif
}

template <class T>
static bool _printBooleanErrors(T &algo, const std::string &what)
{
  std::ostringstream os;
#if OCC_VERSION_HEX >= 0x070200
  algo.DumpErrors(os);
#endif
  std::string s = ReplaceSubString("\n", " ", os.str());
  Msg::Error("%s failed%s%s", what.c_str(), os.str().size() ? " - " : "",
             s.c_str());
  return false;
}

template <class T>
static void _printBooleanWarnings(T &algo, const std::string &what)
{
#if OCC_VERSION_HEX >= 0x070200
  if(algo.HasWarnings()) {
    std::ostringstream os;
    algo.DumpWarnings(os);
    std::string s = ReplaceSubString("\n", " ", os.str());
    if(!s.empty()) Msg::Warning("%s - %s", what.c_str(), s.c_str());
  }
#endif
}

static void _filterTags(std::vector<std::pair<int, int>> &outDimTags,
                        int minDim)
{
  std::vector<std::pair<int, int>> tmp(outDimTags);
  outDimTags.clear();
  for(std::size_t i = 0; i < tmp.size(); i++) {
    if(tmp[i].first >= minDim) outDimTags.push_back(tmp[i]);
  }
}

bool OCC_Internals::booleanOperator(
  int tag, BooleanOperator op,
  const std::vector<std::pair<int, int>> &objectDimTags,
  const std::vector<std::pair<int, int>> &toolDimTags,
  std::vector<std::pair<int, int>> &outDimTags,
  std::vector<std::vector<std::pair<int, int>>> &outDimTagsMap,
  bool removeObject, bool removeTool)
{
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
      fuse.SetArguments(objectShapes);
      fuse.SetTools(toolShapes);
      _setBooleanOptions(fuse);
#if OCC_VERSION_HEX >= 0x070500
      OCCBooleanProgress progress("Union");
      fuse.Build(progress.Start());
#else
      fuse.Build();
#endif
      if(!fuse.IsDone()) return _printBooleanErrors(fuse, "Union");
      _printBooleanWarnings(fuse, "Union");
      if(CTX::instance()->geom.occBooleanSimplify >= 1) {
#if OCC_VERSION_HEX >= 0x070400
        // better than ShapeUpgrade_UnifySameDomain, as it preserves the history
        fuse.SimplifyResult();
        result = fuse.Shape();
#else
        // try to unify faces and edges of the shape (remove internal seams)
        // which lie on the same geometry
        result = fuse.Shape();
        ShapeUpgrade_UnifySameDomain unify(result);
        unify.Build();
        result = unify.Shape();
#endif
      }
      else {
        result = fuse.Shape();
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
      common.SetArguments(objectShapes);
      common.SetTools(toolShapes);
      _setBooleanOptions(common);
#if OCC_VERSION_HEX >= 0x070500
      OCCBooleanProgress progress("Intersection");
      common.Build(progress.Start());
#else
      common.Build();
#endif
      if(!common.IsDone()) return _printBooleanErrors(common, "Intersection");
      _printBooleanWarnings(common, "Intersection");
#if OCC_VERSION_HEX >= 0x070400
      if(CTX::instance()->geom.occBooleanSimplify >= 2) common.SimplifyResult();
#endif
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
      cut.SetArguments(objectShapes);
      cut.SetTools(toolShapes);
      _setBooleanOptions(cut);
#if OCC_VERSION_HEX >= 0x070500
      OCCBooleanProgress progress("Difference");
      cut.Build(progress.Start());
#else
      cut.Build();
#endif
      if(!cut.IsDone()) return _printBooleanErrors(cut, "Difference");
      _printBooleanWarnings(cut, "Difference");
#if OCC_VERSION_HEX >= 0x070400
      if(CTX::instance()->geom.occBooleanSimplify >= 2) cut.SimplifyResult();
#endif
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
      objectShapes.Append(toolShapes);
      toolShapes.Clear();
      fragments.SetArguments(objectShapes);
      _setBooleanOptions(fragments);
#if OCC_VERSION_HEX >= 0x070500
      OCCBooleanProgress progress("Fragments");
      fragments.Build(progress.Start());
#else
      fragments.Build();
#endif
#if OCC_VERSION_HEX > 0x070100
      if(fragments.HasErrors() &&
         fragments.HasError(STANDARD_TYPE(BOPAlgo_AlertTooFewArguments))) {
        Msg::Warning("Boolean fragments skipped - too few arguments");
        return true;
      }
#endif
      if(!fragments.IsDone())
        return _printBooleanErrors(fragments, "Fragments");
      _printBooleanWarnings(fragments, "Fragments");
#if OCC_VERSION_HEX >= 0x070400
      if(CTX::instance()->geom.occBooleanSimplify >= 2)
        fragments.SimplifyResult();
#endif
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

  std::vector<std::pair<int, int>> inDimTags;
  inDimTags.insert(inDimTags.end(), objectDimTags.begin(), objectDimTags.end());
  inDimTags.insert(inDimTags.end(), toolDimTags.begin(), toolDimTags.end());
  std::size_t numObjects = objectDimTags.size();

  if(tag >= 0 || !CTX::instance()->geom.occBooleanPreserveNumbering) {
    // if we specify the tag explicitly, or if we don't care about preserving
    // the numering, just go ahead and bind the resulting shape (and sub-shapes)
    for(std::size_t i = 0; i < inDimTags.size(); i++) {
      bool remove = (i < numObjects) ? removeObject : removeTool;
      if(remove) {
        int d = inDimTags[i].first;
        int t = inDimTags[i].second;
        if(_isBound(d, t)) {
          if(CTX::instance()->geom.occFastUnbind == 2)
            _unbindWithoutChecks(_find(d, t));
          else
            _unbind(_find(d, t), d, t, true);
        }
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
        if(remove) {
          if(CTX::instance()->geom.occFastUnbind == 2)
            _unbindWithoutChecks(mapOriginal[i]);
          else
            _unbind(mapOriginal[i], dim, tag, true);
        }
        Msg::Debug("BOOL (%d,%d) deleted", dim, tag);
      }
      else if(mapModified[i].Extent() == 0) { // not modified
        auto ins = _toPreserve.insert(std::make_pair(dim, tag));
        if(ins.second) // it's not yet in outDimTags
          outDimTags.push_back(std::make_pair(dim, tag));
        Msg::Debug("BOOL (%d,%d) not modified", dim, tag);
      }
      else if(mapModified[i].Extent() == 1) { // replaced by single one
        if(remove) {
          if(CTX::instance()->geom.occFastUnbind == 2)
            _unbindWithoutChecks(mapOriginal[i]);
          else
            _unbind(mapOriginal[i], dim, tag, true);
          _bind(mapModified[i].First(), dim, tag, false); // not recursive!
          int t = _find(dim, mapModified[i].First());
          if(tag != t)
            Msg::Info("Could not preserve tag of %dD object %d (->%d)", dim,
                      tag, t);
          auto ins = _toPreserve.insert(std::make_pair(dim, t));
          if(ins.second) // it's not yet in outDimTags
            outDimTags.push_back(std::make_pair(dim, t));
        }
        Msg::Debug("BOOL (%d,%d) replaced by 1", dim, tag);
      }
      else {
        if(remove) {
          if(CTX::instance()->geom.occFastUnbind == 2)
            _unbindWithoutChecks(mapOriginal[i]);
          else
            _unbind(mapOriginal[i], dim, tag, true);
        }
        Msg::Debug("BOOL (%d,%d) other", dim, tag);
      }
    }
    for(int d = -2; d <= 3; d++) _recomputeMaxTag(d);
    // bind all remaining entities and add the new ones to the returned list
    _multiBind(result, -1, outDimTags, false, true, true);
    _filterTags(outDimTags, minDim);
    _toPreserve.clear();
  }

  // return input/output correspondence maps
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    std::pair<int, int> dimTag(dim, tag);
    std::vector<std::pair<int, int>> dimTags;
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
          dimTags.push_back(std::make_pair(dim, t));
        }
      }
      TopTools_ListIteratorOfListOfShape it2(mapGenerated[i]);
      for(; it2.More(); it2.Next()) {
        if(_isBound(dim, it2.Value())) {
          int t = _find(dim, it2.Value());
          dimTags.push_back(std::make_pair(dim, t));
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
  int tag, const std::vector<std::pair<int, int>> &objectDimTags,
  const std::vector<std::pair<int, int>> &toolDimTags,
  std::vector<std::pair<int, int>> &outDimTags,
  std::vector<std::vector<std::pair<int, int>>> &outDimTagsMap,
  bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Union, objectDimTags, toolDimTags,
                         outDimTags, outDimTagsMap, removeObject, removeTool);
}

bool OCC_Internals::booleanIntersection(
  int tag, const std::vector<std::pair<int, int>> &objectDimTags,
  const std::vector<std::pair<int, int>> &toolDimTags,
  std::vector<std::pair<int, int>> &outDimTags,
  std::vector<std::vector<std::pair<int, int>>> &outDimTagsMap,
  bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Intersection, objectDimTags,
                         toolDimTags, outDimTags, outDimTagsMap, removeObject,
                         removeTool);
}

bool OCC_Internals::booleanDifference(
  int tag, const std::vector<std::pair<int, int>> &objectDimTags,
  const std::vector<std::pair<int, int>> &toolDimTags,
  std::vector<std::pair<int, int>> &outDimTags,
  std::vector<std::vector<std::pair<int, int>>> &outDimTagsMap,
  bool removeObject, bool removeTool)
{
  return booleanOperator(tag, OCC_Internals::Difference, objectDimTags,
                         toolDimTags, outDimTags, outDimTagsMap, removeObject,
                         removeTool);
}

bool OCC_Internals::booleanFragments(
  int tag, const std::vector<std::pair<int, int>> &objectDimTags,
  const std::vector<std::pair<int, int>> &toolDimTags,
  std::vector<std::pair<int, int>> &outDimTags,
  std::vector<std::vector<std::pair<int, int>>> &outDimTagsMap,
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

void OCC_Internals::_getAllDimTags(std::vector<std::pair<int, int>> &dimTags,
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
  std::vector<std::pair<int, int>> objectDimTags, toolDimTags, outDimTags;
  std::vector<std::vector<std::pair<int, int>>> outDimTagsMap;
  _getAllDimTags(objectDimTags, _getMaxDim());
  booleanFragments(-1, objectDimTags, toolDimTags, outDimTags, outDimTagsMap,
                   true, true);
}

bool OCC_Internals::mergeVertices(const std::vector<int> &tags)
{
  std::vector<std::pair<int, int>> objectDimTags, toolDimTags, outDimTags;
  std::vector<std::vector<std::pair<int, int>>> outDimTagsMap;
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
  const std::vector<std::pair<int, int>> &inDimTags,
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
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(CTX::instance()->geom.occFastUnbind) {
      // bypass safe _unbind checks by unbinding the shape and all its subshapes
      // without checking dependencies: this is a bit dangerous, as one could
      // translate e.g. the face of a cube (this is not allowed!) - which will
      // unbind the face of the cube. But the original face will actually be
      // re-bound (with a warning) at the next syncronization point, so it's not
      // too bad...
      _unbindWithoutChecks(inShapes[i]);
    }
    else {
      // safe, but slow: _unbind() has linear complexity with respect to the
      // number of entities in the model (due to the dependency checking of
      // upward adjencencies and the maximum tag update). Using this in a for
      // loop to translate copies of entities leads to quadratic complexity.
      _unbind(inShapes[i], dim, tag, true);
    }
    // TODO: it would be even better to code a rebind() function to reuse the
    // tags not only of the shape, but of all the sub-shapes as well
    _bind(outShapes[i], dim, tag, true);
  }

  return true;
}

bool OCC_Internals::translate(const std::vector<std::pair<int, int>> &inDimTags,
                              double dx, double dy, double dz)
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

bool OCC_Internals::rotate(const std::vector<std::pair<int, int>> &inDimTags,
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

bool OCC_Internals::dilate(const std::vector<std::pair<int, int>> &inDimTags,
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

bool OCC_Internals::symmetry(const std::vector<std::pair<int, int>> &inDimTags,
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

bool OCC_Internals::affine(const std::vector<std::pair<int, int>> &inDimTags,
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

bool OCC_Internals::copy(const std::vector<std::pair<int, int>> &inDimTags,
                         std::vector<std::pair<int, int>> &outDimTags)
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

  TopoDS_Shape result = BRepBuilderAPI_Copy(c).Shape();
  _multiBind(result, -1, outDimTags, true, true);
  return true;
}

bool OCC_Internals::remove(int dim, int tag, bool recursive)
{
  if(!_isBound(dim, tag)) {
    Msg::Warning("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
                 tag);
    return false;
  }
  _unbind(_find(dim, tag), dim, tag, recursive);
  return true;
}

bool OCC_Internals::remove(const std::vector<std::pair<int, int>> &dimTags,
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

static Handle_Interface_HArray1OfHAsciiString strToOccStrArray(std::string str)
{
  Handle_Interface_HArray1OfHAsciiString array =
    new Interface_HArray1OfHAsciiString(1, 1);
  array->SetValue(1, new TCollection_HAsciiString(str.c_str()));
  return array;
}

static Handle_TCollection_HAsciiString strToOccStr(std::string str)
{
  return new TCollection_HAsciiString(str.c_str());
}

static void setOCCStepHeaderFileName(Handle_HeaderSection_FileName &hfname)
{
  if(!CTX::instance()->geom.occStepModelName.empty()) {
    hfname->SetName(strToOccStr(CTX::instance()->geom.occStepModelName));
  }
  if(!CTX::instance()->geom.occStepTimeStamp.empty()) {
    hfname->SetTimeStamp(strToOccStr(CTX::instance()->geom.occStepTimeStamp));
  }
  if(!CTX::instance()->geom.occStepAuthor.empty()) {
    hfname->SetAuthor(strToOccStrArray(CTX::instance()->geom.occStepAuthor));
  }
  if(!CTX::instance()->geom.occStepOrganization.empty()) {
    hfname->SetOrganization(
      strToOccStrArray(CTX::instance()->geom.occStepOrganization));
  }
  if(!CTX::instance()->geom.occStepPreprocessorVersion.empty()) {
    hfname->SetPreprocessorVersion(
      strToOccStr(CTX::instance()->geom.occStepPreprocessorVersion));
  }
  if(!CTX::instance()->geom.occStepOriginatingSystem.empty()) {
    hfname->SetOriginatingSystem(
      strToOccStr(CTX::instance()->geom.occStepOriginatingSystem));
  }
  if(!CTX::instance()->geom.occStepAuthorization.empty()) {
    hfname->SetAuthorisation(
      strToOccStr(CTX::instance()->geom.occStepAuthorization));
  }
}

static void
setOCCSTEPHeaderDescription(Handle_HeaderSection_FileDescription &hdesc)
{
  if(!CTX::instance()->geom.occStepDescription.empty()) {
    hdesc->SetDescription(
      strToOccStrArray(CTX::instance()->geom.occStepDescription));
  }
  if(!CTX::instance()->geom.occStepImplementationLevel.empty()) {
    hdesc->SetImplementationLevel(
      strToOccStr(CTX::instance()->geom.occStepImplementationLevel));
  }
}

static void setOCCSTEPHeaderSchema(Handle_HeaderSection_FileSchema &hschema,
                                   const Interface_EntityIterator &header)
{
  if(!CTX::instance()->geom.occStepSchemaIdentifier.empty()) {
    hschema->SetSchemaIdentifiers(
      strToOccStrArray(CTX::instance()->geom.occStepSchemaIdentifier));
  }
  else {
    for(auto It = header; It.More(); It.Next()) {
      const Handle_Standard_Transient &entity = It.Value();
      if(entity->IsKind(STANDARD_TYPE(HeaderSection_FileSchema))) {
        hschema = Handle_HeaderSection_FileSchema::DownCast(entity);
        break;
      }
    }
  }
}

static void setOCCSTEPHeader(STEPControl_Writer &writer)
{
  Handle_StepData_StepModel model = writer.Model().get();
  APIHeaderSection_MakeHeader header = APIHeaderSection_MakeHeader();

  Handle_HeaderSection_FileName hfname = header.FnValue();
  Handle_HeaderSection_FileDescription hdesc = header.FdValue();
  Handle_HeaderSection_FileSchema hschema = header.FsValue();

  setOCCStepHeaderFileName(hfname);
  setOCCSTEPHeaderDescription(hdesc);
  setOCCSTEPHeaderSchema(hschema, model->Header());

  model->ClearHeader();
  model->AddHeaderEntity(hfname);
  model->AddHeaderEntity(hdesc);
  model->AddHeaderEntity(hschema);
}

#if defined(HAVE_OCC_CAF)

static void getColorRGB(const Quantity_Color &col, double &r, double &g,
                        double &b)
{
#if OCC_VERSION_HEX >= 0x070500
  // necessary to not alter RGB colors specified in STEP files (cf. #1399 and
  // #1723)
  col.Values(r, g, b, Quantity_TOC_sRGB);
#else
  r = col.Red();
  g = col.Green();
  b = col.Blue();
#endif
}

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

  TopLoc_Location partLoc = loc * shapeTool->GetLocation(label);

  TDF_Label ref;
  if(shapeTool->IsReference(label) && shapeTool->GetReferredShape(label, ref)) {
    setShapeAttributes(attributes, shapeTool, colorTool, materialTool, ref,
                       partLoc, phys, true);
  }
  else if(shapeTool->IsSimpleShape(label) &&
          (isRef || shapeTool->IsFree(label))) {
    TopoDS_Shape shape = shapeTool->GetShape(label);
    shape.Location(isRef ? loc : partLoc);

#if 0
    // this is necessary for endcaps.stp (cf. #693), but has a big performance
    // hit on STEP files with lots of references -- leaving out until we
    // understand why it's necessary: there should be a better way ;-)
    if(isRef && !loc.IsIdentity() && loc != shapeTool->GetLocation(label))
      shapeTool->SetShape(label, shape);
#endif

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
      Msg::Info(" - Label & material '%s' (%dD)", phys.c_str(), dim);
    }
    else if(phys.size()) {
      Msg::Info(" - Label '%s' (%dD)", phys.c_str(), dim);
    }
    if(phys.size()) { attributes->insert(new OCCAttributes(dim, shape, phys)); }

    Quantity_Color col;
    if(colorTool->GetColor(label, XCAFDoc_ColorGen, col)) {
      double r, g, b;
      getColorRGB(col, r, g, b);
      Msg::Info(" - Color (%g, %g, %g) (%dD)", r, g, b, dim);
      attributes->insert(new OCCAttributes(dim, shape, r, g, b, 1.));
    }
    else if(colorTool->GetColor(label, XCAFDoc_ColorSurf, col)) {
      double r, g, b;
      getColorRGB(col, r, g, b);
      Msg::Info(" - Color (%g, %g, %g) (%dD & Surfaces)", r, g, b, dim);
      attributes->insert(new OCCAttributes(dim, shape, r, g, b, 1., 1));
    }
    else if(colorTool->GetColor(label, XCAFDoc_ColorCurv, col)) {
      double r, g, b;
      getColorRGB(col, r, g, b);
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
          double r, g, b;
          getColorRGB(col, r, g, b);
          Msg::Info(" - Color (%g, %g, %g) (Surface)", r, g, b);
          TopoDS_Face face = TopoDS::Face(xp2.Current());
          attributes->insert(new OCCAttributes(2, face, r, g, b, 1.));
        }
        xp2.Next();
      }
    }
    else if(dim == 2) {
      TopExp_Explorer xp1(shape, TopAbs_EDGE);
      while(xp1.More()) {
        if(colorTool->GetColor(xp1.Current(), XCAFDoc_ColorGen, col) ||
           colorTool->GetColor(xp1.Current(), XCAFDoc_ColorSurf, col) ||
           colorTool->GetColor(xp1.Current(), XCAFDoc_ColorCurv, col)) {
          double r, g, b;
          getColorRGB(col, r, g, b);
          Msg::Info(" - Color (%g, %g, %g) (Curve)", r, g, b);
          TopoDS_Edge edge = TopoDS::Edge(xp1.Current());
          attributes->insert(new OCCAttributes(1, edge, r, g, b, 1.));
        }
        xp1.Next();
      }
    }
  }
  else {
    for(TDF_ChildIterator it(label); it.More(); it.Next()) {
      setShapeAttributes(attributes, shapeTool, colorTool, materialTool,
                         it.Value(), partLoc, phys, false);
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
                                 std::vector<std::pair<int, int>> &outDimTags,
                                 const std::string &format)
{
  std::vector<std::string> split = SplitFileName(fileName);

  TopoDS_Shape result;
  try {
    if(format == "brep" || split[2] == ".brep" || split[2] == ".BREP") {
      BRep_Builder aBuilder;
      BRepTools::Read(result, fileName.c_str(), aBuilder);
    }
    else if(format == "step" || split[2] == ".step" || split[2] == ".stp" ||
            split[2] == ".STEP" || split[2] == ".STP") {
      STEPControl_Reader reader;
      setTargetUnit(CTX::instance()->geom.occTargetUnit);
      Interface_Static::SetIVal("read.step.ideas", 1);
      Interface_Static::SetIVal("read.step.nonmanifold", 1);
#if defined(HAVE_OCC_CAF)
      // Interface_Static::SetIVal("read.stepcaf.subshapes.name", 1);
      STEPCAFControl_Reader cafreader;
      if(cafreader.ReadFile(fileName.c_str()) != IFSelect_RetDone) {
        Msg::Error("Could not read file '%s'", fileName.c_str());
        return false;
      }
      if(CTX::instance()->geom.occImportLabels)
        readAttributes(_attributes, cafreader, "STEP-XCAF");
      reader = cafreader.ChangeReader();
#else
      if(reader.ReadFile(fileName.c_str()) != IFSelect_RetDone) {
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
      if(reader.ReadFile(fileName.c_str()) != IFSelect_RetDone) {
        Msg::Error("Could not read file '%s'", fileName.c_str());
        return false;
      }
      if(CTX::instance()->geom.occImportLabels)
        readAttributes(_attributes, reader, "IGES-XCAF");
#else
      IGESControl_Reader reader;
      if(reader.ReadFile(fileName.c_str()) != IFSelect_RetDone) {
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
                                 std::vector<std::pair<int, int>> &outDimTags)
{
  if(!shape) return false;
  _multiBind(*shape, -1, outDimTags, highestDimOnly, true);
  return true;
}

void _writeXAO(TopoDS_Shape &shape, GModel *model, const std::string &fileName)
{
  std::ofstream file(fileName);
  if(!file.is_open()) {
    Msg::Error("Could not open file '%s'", fileName.c_str());
    return;
  }

  // TODO: In addition to saving physical group tags (see below), we could
  // further extend the XAO output by dumping OCCAttributes (extrusion
  // constraints, mesh sizes...).

  // We could also save the entity tag; for reading back this info we would then
  // either need to change/write a custom importShapes/synchronize() where tags
  // are explicitly given; or modify the bound tags in OCC_Internals so that
  // synchronize() can be used as-is; or add a "renumberEntities" function in
  // GModel.

  file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
  file << "<XAO version=\"1.0\" author=\"Gmsh\">" << std::endl;
  file << "  <geometry name=\"" << model->getName() << "\">" << std::endl;
  file << "    <shape format=\"BREP\"><![CDATA[";
#if OCC_VERSION_HEX < 0x070600
  BRepTools::Write(shape, file);
#else
  int v = CTX::instance()->geom.occBrepFormatVersion;
  BRepTools::Write(shape, file, Standard_True, Standard_True,
                   (v == 1) ? TopTools_FormatVersion_VERSION_1 :
                   (v == 2) ? TopTools_FormatVersion_VERSION_2 :
                   (v == 3) ? TopTools_FormatVersion_VERSION_3 :
                              TopTools_FormatVersion_CURRENT);
#endif
  file << "]]></shape>" << std::endl;
  file << "    <topology>" << std::endl;

  TopTools_IndexedMapOfShape mainMap;
  TopExp::MapShapes(shape, mainMap);
  TopExp_Explorer exp;
  std::set<std::pair<int, GEntity *>> topo[4];
  for(exp.Init(shape, TopAbs_VERTEX); exp.More(); exp.Next()) {
    TopoDS_Shape subShape = exp.Current();
    auto p = std::make_pair(mainMap.FindIndex(subShape),
                            model->getVertexForOCCShape(&subShape));
    if(p.first && p.second && !topo[0].count(p)) topo[0].insert(p);
  }
  for(exp.Init(shape, TopAbs_EDGE); exp.More(); exp.Next()) {
    TopoDS_Shape subShape = exp.Current();
    auto p = std::make_pair(mainMap.FindIndex(subShape),
                            model->getEdgeForOCCShape(&subShape));
    if(p.first && p.second && !topo[1].count(p)) topo[1].insert(p);
  }
  for(exp.Init(shape, TopAbs_FACE); exp.More(); exp.Next()) {
    TopoDS_Shape subShape = exp.Current();
    auto p = std::make_pair(mainMap.FindIndex(subShape),
                            model->getFaceForOCCShape(&subShape));
    if(p.first && p.second && !topo[2].count(p)) topo[2].insert(p);
  }
  for(exp.Init(shape, TopAbs_SOLID); exp.More(); exp.Next()) {
    TopoDS_Shape subShape = exp.Current();
    auto p = std::make_pair(mainMap.FindIndex(subShape),
                            model->getRegionForOCCShape(&subShape));
    if(p.first && p.second && !topo[3].count(p)) topo[3].insert(p);
  }
  std::map<int, std::vector<int>> groups[4];
  for(int dim = 0; dim <= 3; dim++) {
    std::string labels = (dim == 3) ? "solids" :
                         (dim == 2) ? "faces" :
                         (dim == 1) ? "edges" :
                                      "vertices";
    std::string label = (dim == 3) ? "solid" :
                        (dim == 2) ? "face" :
                        (dim == 1) ? "edge" :
                                     "vertex";
    file << "      <" << labels << " count=\"" << topo[dim].size() << "\">"
         << std::endl;
    int index = 0;
    for(auto p : topo[dim]) {
      std::string name =
        model->getElementaryName(p.second->dim(), p.second->tag());
      file << "        <" << label << " index=\"" << index << "\" "
           << "name=\"" << name << "\" "
           << "reference=\"" << p.first << "\"/>" << std::endl;
      for(auto &g : p.second->physicals) {
        groups[dim][std::abs(g)].push_back(index);
      }
      index++;
    }
    file << "      </" << labels << ">" << std::endl;
  }

  file << "    </topology>" << std::endl;
  file << "  </geometry>" << std::endl;
  file << "  <groups count=\""
       << groups[0].size() + groups[1].size() + groups[2].size() +
            groups[3].size()
       << "\">" << std::endl;
  for(int dim = 0; dim <= 3; dim++) {
    std::string label = (dim == 3) ? "solid" :
                        (dim == 2) ? "face" :
                        (dim == 1) ? "edge" :
                                     "vertex";
    for(auto g : groups[dim]) {
      std::string name = model->getPhysicalName(dim, g.first);
      if(name.empty()) { // create same unique name as for MED export
        std::ostringstream gs;
        gs << "G_" << dim << "D_" << g.first;
        name = gs.str();
      }
      file << "    <group name=\"" << name << "\" dimension=\"" << label;
#if 1
      // Gmsh XAO extension: also save the physical tag, so that XAO can be used
      // to serialize OCC geometries, ready to be used by GetDP, GmshFEM & co
      file << "\" tag=\"" << g.first;
#endif
      file << "\" count=\"" << g.second.size() << "\">" << std::endl;
      for(auto index : g.second) {
        file << "      <element index=\"" << index << "\"/>" << std::endl;
      }
      file << "    </group>" << std::endl;
    }
  }
  file << "  </groups>" << std::endl;
  file << "  <fields count=\"0\"/>" << std::endl;
  file << "</XAO>" << std::endl;
}

bool OCC_Internals::exportShapes(GModel *model, const std::string &fileName,
                                 const std::string &format, bool onlyVisible)
{
  // put all top-level OCC shapes from a GModel in a single compound (we use the
  // topology to only consider top-level shapes; otherwise we get duplicates in
  // the STEP export)
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(auto it = model->firstRegion(); it != model->lastRegion(); it++) {
    GRegion *gr = *it;
    if(onlyVisible) {
      if(!gr->getVisibility()) continue;
    }
    if(gr->getNativeType() == GEntity::OpenCascadeModel) {
      Msg::Debug("Adding volume %d to exported compound", gr->tag());
      b.Add(c, *(TopoDS_Solid *)gr->getNativePtr());
    }
  }
  for(auto it = model->firstFace(); it != model->lastFace(); it++) {
    GFace *gf = *it;
    if(onlyVisible) {
      if(!gf->getVisibility()) continue;
      auto regions = gf->regions();
      bool skip = false;
      for(auto gr : regions) {
        if(gr->getVisibility()) {
          skip = true;
          break;
        }
      }
      if(skip) continue;
    }
    else {
      if(gf->numRegions()) continue;
    }
    if(gf->getNativeType() == GEntity::OpenCascadeModel) {
      Msg::Debug("Adding surface %d to exported compound", gf->tag());
      b.Add(c, *(TopoDS_Face *)gf->getNativePtr());
    }
  }
  for(auto it = model->firstEdge(); it != model->lastEdge(); it++) {
    GEdge *ge = *it;
    if(onlyVisible) {
      if(!ge->getVisibility()) continue;
      auto faces = ge->faces();
      bool skip = false;
      for(auto gf : faces) {
        if(gf->getVisibility()) {
          skip = true;
          break;
        }
      }
      if(skip) continue;
    }
    else {
      if(ge->numFaces()) continue;
    }
    if(ge->getNativeType() == GEntity::OpenCascadeModel) {
      Msg::Debug("Adding curve %d to exported compound", ge->tag());
      b.Add(c, *(TopoDS_Edge *)ge->getNativePtr());
    }
  }
  for(auto it = model->firstVertex(); it != model->lastVertex(); it++) {
    GVertex *gv = *it;
    if(onlyVisible) {
      if(!gv->getVisibility()) continue;
      auto edges = gv->edges();
      bool skip = false;
      for(auto ge : edges) {
        if(ge->getVisibility()) {
          skip = true;
          break;
        }
      }
      if(skip) continue;
    }
    else {
      if(gv->numEdges()) continue;
    }
    if(gv->getNativeType() == GEntity::OpenCascadeModel) {
      Msg::Debug("Adding point %d to exported compound", gv->tag());
      b.Add(c, *(TopoDS_Vertex *)gv->getNativePtr());
    }
  }

  std::vector<std::string> split = SplitFileName(fileName);

  try {
    if(format == "brep" || split[2] == ".brep" || split[2] == ".BREP") {
#if OCC_VERSION_HEX < 0x070600
      BRepTools::Write(c, fileName.c_str());
#else
      int v = CTX::instance()->geom.occBrepFormatVersion;
      BRepTools::Write(c, fileName.c_str(), Standard_True, Standard_True,
                       (v == 1) ? TopTools_FormatVersion_VERSION_1 :
                       (v == 2) ? TopTools_FormatVersion_VERSION_2 :
                       (v == 3) ? TopTools_FormatVersion_VERSION_3 :
                                  TopTools_FormatVersion_CURRENT);
#endif
    }
    else if(format == "xao" || split[2] == ".xao" || split[2] == ".XAO") {
      _writeXAO(c, model, fileName);
    }
    else if(format == "step" || split[2] == ".step" || split[2] == ".stp" ||
            split[2] == ".STEP" || split[2] == ".STP") {
      STEPControl_Writer writer;
      setTargetUnit(CTX::instance()->geom.occTargetUnit);
      setOCCSTEPHeader(writer);

#if 0
      // this does not seem to solve the issue that entities get duplicated when
      // exporting STEP files (see issue #906), and leads to some regressions
      // (see issue #2673) - so leaving it out for now:
      Interface_Static::SetIVal("write.step.nonmanifold", 1);
#endif

      if(writer.Transfer(c, STEPControl_AsIs) == IFSelect_RetDone) {
        if(writer.Write(fileName.c_str()) != IFSelect_RetDone) {
          Msg::Error("Could not create file '%s'", fileName.c_str());
          return false;
        }
      }
      else {
        Msg::Error("Could not create STEP data");
        return false;
      }
    }
    else if(format == "iges" || split[2] == ".iges" || split[2] == ".igs" ||
            split[2] == ".IGES" || split[2] == ".IGS") {
      IGESControl_Writer writer;
      if(writer.AddShape(c)) {
        if(writer.Write(fileName.c_str()) != true) {
          Msg::Error("Could not create file '%s'", fileName.c_str());
          return false;
        }
      }
      else {
        Msg::Error("Could not create IGES data");
        return false;
      }
    }
    else {
      Msg::Error("Unknown format to export OpenCASCADE shapes: %s",
                 format.c_str());
      return false;
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

bool OCC_Internals::getEntities(std::vector<std::pair<int, int>> &dimTags,
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
      dimTags.push_back(std::make_pair(d, exp.Key()));
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
    // BRepBndLib can use the STL mesh if available, but unfortunately it
    // enlarges the box with the mesh deflection tolerance and the shape
    // tolerance, which makes it hard to get the expected minimal box in simple
    // cases (e.g. for plane surfaces), and always leads to boxes that are too
    // large; so we simply compute the box from the STL vertices. The downside
    // of this approach is that the bbox might be *smaller* than the actual box
    // for curved shapes, but this is preferable for us as boxes are mostly used
    // to find/identify entities
    if(vertices.size()) {
      SBoundingBox3d bbox;
      for(std::size_t i = 0; i < vertices.size(); i++) bbox += vertices[i];
      xmin = bbox.min().x();
      ymin = bbox.min().y();
      zmin = bbox.min().z();
      xmax = bbox.max().x();
      ymax = bbox.max().y();
      zmax = bbox.max().z();
      return true;
    }
  }
  Bnd_Box b;
  try {
    BRepBndLib::Add(shape, b);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return false;
  }
  b.Get(xmin, ymin, zmin, xmax, ymax, zmax);
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
  std::vector<std::pair<int, int>> &dimTags, int dim)
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
        dimTags.push_back(std::make_pair(d, exp.Key()));
    }
  }
  return true;
}

bool OCC_Internals::getCurveLoops(int surfaceTag,
                                  std::vector<int> &curveLoopTags,
                                  std::vector<std::vector<int>> &curveTags)
{
  if(!_tagFace.IsBound(surfaceTag)) {
    Msg::Error("Unknown OpenCASCADE surface with tag %d", surfaceTag);
    return false;
  }
  curveLoopTags.clear();
  curveTags.clear();
  TopoDS_Face face = TopoDS::Face(_tagFace.Find(surfaceTag));
  TopExp_Explorer exp0;
  for(exp0.Init(face, TopAbs_WIRE); exp0.More(); exp0.Next()) {
    TopoDS_Wire wire = TopoDS::Wire(exp0.Current());
    if(_wireTag.IsBound(wire)) { curveLoopTags.push_back(_wireTag.Find(wire)); }
    else {
      int t = getMaxTag(-1) + 1;
      _bind(wire, t);
      curveLoopTags.push_back(t);
    }
    curveTags.push_back(std::vector<int>());
    BRepTools_WireExplorer exp1; // guarantees edges are ordered
    for(exp1.Init(wire); exp1.More(); exp1.Next()) {
      TopoDS_Edge edge = exp1.Current();
      if(_edgeTag.IsBound(edge)) {
        curveTags.back().push_back(_edgeTag.Find(edge));
      }
      else {
        int t = getMaxTag(1) + 1;
        _bind(edge, t);
        curveTags.back().push_back(t);
      }
    }
  }
  return true;
}

bool OCC_Internals::getSurfaceLoops(int volumeTag,
                                    std::vector<int> &surfaceLoopTags,
                                    std::vector<std::vector<int>> &surfaceTags)
{
  if(!_tagSolid.IsBound(volumeTag)) {
    Msg::Error("Unknown OpenCASCADE volume with tag %d", volumeTag);
    return false;
  }
  surfaceLoopTags.clear();
  surfaceTags.clear();
  TopoDS_Solid solid = TopoDS::Solid(_tagSolid.Find(volumeTag));
  TopExp_Explorer exp0;
  for(exp0.Init(solid, TopAbs_SHELL); exp0.More(); exp0.Next()) {
    TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
    if(_shellTag.IsBound(shell)) {
      surfaceLoopTags.push_back(_shellTag.Find(shell));
    }
    else {
      int t = getMaxTag(-2) + 1;
      _bind(shell, t);
      surfaceLoopTags.push_back(t);
    }
    surfaceTags.push_back(std::vector<int>());
    TopExp_Explorer exp1;
    for(exp1.Init(shell, TopAbs_FACE); exp1.More(); exp1.Next()) {
      TopoDS_Face face = TopoDS::Face(exp1.Current());
      if(_faceTag.IsBound(face)) {
        surfaceTags.back().push_back(_faceTag.Find(face));
      }
      else {
        int t = getMaxTag(2) + 1;
        _bind(face, t);
        surfaceTags.back().push_back(t);
      }
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

bool OCC_Internals::getDistance(int dim1, int tag1, int dim2, int tag2,
                                double &distance, double &x1, double &y1,
                                double &z1, double &x2, double &y2, double &z2)
{
  if(!_isBound(dim1, tag1)) {
    Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim1,
               tag1);
    return false;
  }
  TopoDS_Shape shape1 = _find(dim1, tag1);

  if(!_isBound(dim2, tag2)) {
    Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim2,
               tag2);
    return false;
  }
  TopoDS_Shape shape2 = _find(dim2, tag2);

  BRepExtrema_DistShapeShape dist(shape1, shape2);
  if(dist.IsDone()) {
    double dmin = 1.e200;
    gp_Pnt pmin1, pmin2;
    for(int i = 1; i <= dist.NbSolution(); i++) {
      gp_Pnt p1 = dist.PointOnShape1(i);
      gp_Pnt p2 = dist.PointOnShape2(i);
      double d = p1.Distance(p2);
      if(d < dmin) {
        dmin = d;
        pmin1 = p1;
        pmin2 = p2;
      }
    }
    x1 = pmin1.X();
    y1 = pmin1.Y();
    z1 = pmin1.Z();
    x2 = pmin2.X();
    y2 = pmin2.Y();
    z2 = pmin2.Z();
    distance = dmin;
    return true;
  }

  return false;
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
  std::vector<std::pair<int, int>> toRemove;
  toRemove.insert(toRemove.end(), _toRemove.begin(), _toRemove.end());
  Msg::Debug("Sync is removing %d model entities", toRemove.size());
  // make sure to delete highest dimensional entities first (model->remove()
  // will not remove entities that are the boundary of others!)
  std::sort(toRemove.begin(), toRemove.end(), sortByInvDim);
  std::vector<GEntity *> removed;
  model->remove(toRemove, removed);
  Msg::Debug("Destroying %lu entities in model", removed.size());
  for(std::size_t i = 0; i < removed.size(); i++) delete removed[i];
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
        _bind(vertex, tag);
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
    if(!occv->useColor() && _attributes->getColor(0, vertex, col, boundary)) {
      occv->setColor(col);
    }
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
        _bind(edge, tag);
      }
      occe = new OCCEdge(model, edge, tag, v1, v2);
      model->add(occe);
    }
    _copyExtrudedAttributes(edge, occe);
    std::vector<std::string> labels;
    _attributes->getLabels(1, edge, labels);
    if(labels.size()) model->setElementaryName(1, occe->tag(), labels[0]);
    unsigned int col = 0, boundary = 0;
    if(!occe->useColor() && _attributes->getColor(1, edge, col, boundary)) {
      occe->setColor(col);
    }
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
        _bind(face, tag);
      }
      occf = new OCCFace(model, face, tag);
      model->add(occf);
    }
    _copyExtrudedAttributes(face, occf);
    std::vector<std::string> labels;
    _attributes->getLabels(2, face, labels);
    if(labels.size()) model->setElementaryName(2, occf->tag(), labels[0]);
    unsigned int col = 0, boundary = 0;
    if(!occf->useColor() && _attributes->getColor(2, face, col, boundary)) {
      occf->setColor(col);
      if(boundary == 2) {
        std::vector<GEdge *> edges = occf->edges();
        for(std::size_t j = 0; j < edges.size(); j++) {
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
        _bind(region, tag);
      }
      occr = new OCCRegion(model, region, tag);
      model->add(occr);
    }
    _copyExtrudedAttributes(region, occr);
    std::vector<std::string> labels;
    _attributes->getLabels(3, region, labels);
    if(labels.size()) model->setElementaryName(3, occr->tag(), labels[0]);
    unsigned int col = 0, boundary = 0;
    if(!occr->useColor() && _attributes->getColor(3, region, col, boundary)) {
      occr->setColor(col);
      if(boundary == 1) {
        std::vector<GFace *> faces = occr->faces();
        for(std::size_t j = 0; j < faces.size(); j++) {
          if(!faces[j]->useColor()) faces[j]->setColor(col);
        }
      }
      else if(boundary == 2) {
        std::vector<GEdge *> edges = occr->edges();
        for(std::size_t j = 0; j < edges.size(); j++) {
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
          Msg::Info(" . Repaired face");
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

    {
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
            Msg::Info(" . Fixed small edge in wire");
            replace = true;
          }
          else if(sfw.StatusSmall(ShapeExtend_FAIL1))
            Msg::Warning("Failed to fix small edge in wire, edge cannot be "
                         "checked (no 3d curve and no pcurve)");
          else if(sfw.StatusSmall(ShapeExtend_FAIL2))
            Msg::Warning("Failed to fix small edge in wire, edge is null-"
                         "length and has different vertives at begin and end, "
                         "and lockvtx is True or ModifiyTopologyMode is False");
          else if(sfw.StatusSmall(ShapeExtend_FAIL3))
            Msg::Warning("Failed to fix small edge in wire, CheckConnected has "
                         "failed");

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
    }

    {
      ShapeBuild_ReShape rebuild;

      for(exp1.Init(myshape, TopAbs_EDGE); exp1.More(); exp1.Next()) {
        TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
        GProp_GProps system;
        BRepGProp::LinearProperties(edge, system);
        if(system.Mass() < tolerance) {
          Msg::Info("  - Removing degenerated edge");
          rebuild.Remove(edge);
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
  const std::vector<std::pair<int, int>> &inDimTags,
  std::vector<std::pair<int, int>> &outDimTags, double tolerance,
  bool fixDegenerated, bool fixSmallEdges, bool fixSmallFaces, bool sewFaces,
  bool makeSolids)
{
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);

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

  std::vector<TopoDS_Shape> toHeal;
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(!_isBound(dim, tag)) {
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
                 tag);
      return false;
    }
    toHeal.push_back(_find(dim, tag));
  }

  // unbind everything
  _unbind();

  if(toHeal.empty()) { // heal all the shapes
    _healShape(c, tolerance, fixDegenerated, fixSmallEdges, fixSmallFaces,
               sewFaces, makeSolids, 1.0);
  }
  else {
    for(std::size_t i = 0; i < toHeal.size(); i++) {
      TopoDS_Shape olds = toHeal[i];
      TopoDS_Shape news = olds;
      _healShape(news, tolerance, fixDegenerated, fixSmallEdges, fixSmallFaces,
                 sewFaces, makeSolids, 1.0);
      ShapeBuild_ReShape rebuild;
      rebuild.Replace(olds, news);
      c = TopoDS::Compound(rebuild.Apply(c));
    }
  }

  // rebind
  _multiBind(c, -1, outDimTags, false, true);

  return true;
}

bool OCC_Internals::convertToNURBS(
  const std::vector<std::pair<int, int>> &inDimTags)
{
  for(std::size_t i = 0; i < inDimTags.size(); i++) {
    int dim = inDimTags[i].first;
    int tag = inDimTags[i].second;
    if(!_isBound(dim, tag)) {
      Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d", dim,
                 tag);
      return false;
    }
    TopoDS_Shape shape = _find(dim, tag);
    BRepBuilderAPI_NurbsConvert nurbs(shape);
    TopoDS_Shape res = nurbs.ModifiedShape(shape);
    _unbindWithoutChecks(shape);
    _bind(res, dim, tag, true);
  }

  return true;
}

static bool makeSTL(const TopoDS_Face &s, std::vector<SPoint2> *verticesUV,
                    std::vector<SPoint3> *verticesXYZ,
                    std::vector<SVector3> *normals, std::vector<int> &triangles)
{
  if(CTX::instance()->geom.occDisableSTL) return false;

  double lin = CTX::instance()->mesh.stlLinearDeflection;
  bool rel = CTX::instance()->mesh.stlLinearDeflectionRelative;
  double ang = CTX::instance()->mesh.stlAngularDeflection;

#if OCC_VERSION_HEX > 0x070300
  BRepMesh_IncrementalMesh aMesher(s, lin, rel, ang, Standard_True);
#elif OCC_VERSION_HEX > 0x070000
  Bnd_Box aBox;
  BRepBndLib::Add(s, aBox);
  BRepMesh_FastDiscret::Parameters parameters;
  parameters.Deflection = lin;
  parameters.Relative = rel;
  parameters.Angle = ang;
  BRepMesh_FastDiscret aMesher(aBox, parameters);
  aMesher.Perform(s);
#else
  Bnd_Box aBox;
  BRepBndLib::Add(s, aBox);
  BRepMesh_FastDiscret aMesher(lin, ang, aBox, Standard_False, Standard_False,
                               Standard_True, Standard_True);
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
  std::vector<std::pair<int, int>> outDimTags;
  _occ_internals->importShapes(fn, false, outDimTags, "brep");
  _occ_internals->synchronize(this);
  snapVertices();
  return 1;
}

int GModel::readOCCXAO(const std::string &fn)
{
  if(!_occ_internals) _occ_internals = new OCC_Internals;

    // We cannot use importShapes(fn) directly, as 1) we don't want to apply any
    // changes to the OCC shape through healing; and 2) we need access to GModel
    // to make the link between subshapes and model entities

#if defined(HAVE_OCC) && defined(HAVE_TINYXML2)
  // get XML elements
  using namespace tinyxml2;
  XMLDocument xmlDoc;
  if(xmlDoc.LoadFile(fn.c_str()) != XML_SUCCESS) {
    Msg::Error("Could not load XML file '%s'", fn.c_str());
    return 0;
  }
  XMLElement *xao = xmlDoc.FirstChildElement("XAO");
  if(!xao) {
    Msg::Error("No root XAO node in file '%s'", fn.c_str());
    return 0;
  }
  XMLElement *geometry = xao->FirstChildElement("geometry");
  if(!geometry) {
    Msg::Error("No geometry node in file '%s'", fn.c_str());
    return 0;
  }
  XMLElement *shape = geometry->FirstChildElement("shape");
  if(!shape) {
    Msg::Warning("No shape node in file '%s'", fn.c_str());
    return 0;
  }
  XMLElement *topology = geometry->FirstChildElement("topology");
  if(!topology) {
    Msg::Error("No topology node in file '%s'", fn.c_str());
    return 0;
  }
  XMLElement *groups = xao->FirstChildElement("groups");
  if(!groups) { Msg::Warning("No groups node in file '%s'", fn.c_str()); }

  // import BREP
  TopoDS_Shape mainShape;
  BRep_Builder aBuilder;
  const char *format = nullptr;
  if(shape->QueryAttribute("format", &format) == XML_SUCCESS) {
    if(std::string(format) != "BREP") {
      Msg::Warning("Shape format '%s' in file '%s' is not BREP", format,
                   fn.c_str());
    }
  }
  else {
    Msg::Warning("No shape format in file '%s'", fn.c_str());
  }

  const char *file = nullptr;
  if(shape->QueryAttribute("file", &file) == XML_SUCCESS) {
    std::string n = FixRelativePath(fn, file);
    if(StatFile(n)) {
      Msg::Error("BREP file '%s' does not exist", n.c_str());
      return 0;
    }
    else {
      Msg::Info("Reading BREP shape from file '%s'", n.c_str());
      BRepTools::Read(mainShape, n.c_str(), aBuilder);
    }
  }
  else {
    BRepTools::Read(mainShape, fn.c_str(), aBuilder);
  }
  std::vector<std::pair<int, int>> outDimTags;
  _occ_internals->importShapes(&mainShape, false, outDimTags);
  _occ_internals->synchronize(this);
  snapVertices();
  TopTools_IndexedMapOfShape mainMap;
  TopExp::MapShapes(mainShape, mainMap);
  std::map<int, GEntity *> entities[4];

  XMLElement *vertices = topology->FirstChildElement("vertices");
  if(vertices) {
    XMLElement *vertex = vertices->FirstChildElement("vertex");
    while(vertex) {
      int index = 0, ref = 0;
      if(vertex->QueryIntAttribute("index", &index) != XML_SUCCESS ||
         vertex->QueryIntAttribute("reference", &ref) != XML_SUCCESS) {
        Msg::Error("Missing index or reference for vertex");
      }
      else {
        TopoDS_Shape subShape = mainMap.FindKey(ref);
        GVertex *gv = getVertexForOCCShape(&subShape);
        if(gv) {
          entities[0][index] = gv;
          const char *name = nullptr;
          if(vertex->QueryAttribute("name", &name) == XML_SUCCESS)
            if(strlen(name)) setElementaryName(0, gv->tag(), name);
        }
        else {
          Msg::Error("Could not find model point for XAO reference %d", ref);
        }
      }
      vertex = vertex->NextSiblingElement("vertex");
    }
  }

  XMLElement *edges = topology->FirstChildElement("edges");
  if(edges) {
    XMLElement *edge = edges->FirstChildElement("edge");
    while(edge) {
      int index = 0, ref = 0;
      if(edge->QueryIntAttribute("index", &index) != XML_SUCCESS ||
         edge->QueryIntAttribute("reference", &ref) != XML_SUCCESS) {
        Msg::Error("Missing index or reference for edge");
      }
      else {
        TopoDS_Shape subShape = mainMap.FindKey(ref);
        GEdge *ge = getEdgeForOCCShape(&subShape);
        if(ge) {
          entities[1][index] = ge;
          const char *name = nullptr;
          if(edge->QueryAttribute("name", &name) == XML_SUCCESS)
            if(strlen(name)) setElementaryName(1, ge->tag(), name);
        }
        else {
          Msg::Error("Could not find model curve for XAO reference %d", ref);
        }
      }
      edge = edge->NextSiblingElement("edge");
    }
  }

  XMLElement *faces = topology->FirstChildElement("faces");
  if(faces) {
    XMLElement *face = faces->FirstChildElement("face");
    while(face) {
      int index = 0, ref = 0;
      if(face->QueryIntAttribute("index", &index) != XML_SUCCESS ||
         face->QueryIntAttribute("reference", &ref) != XML_SUCCESS) {
        Msg::Error("Missing index or reference for face");
      }
      else {
        TopoDS_Shape subShape = mainMap.FindKey(ref);
        GFace *gf = getFaceForOCCShape(&subShape);
        if(gf) {
          entities[2][index] = gf;
          const char *name = nullptr;
          if(face->QueryAttribute("name", &name) == XML_SUCCESS)
            if(strlen(name)) setElementaryName(2, gf->tag(), name);
        }
        else {
          Msg::Error("Could not find model surface for XAO reference %d", ref);
        }
      }
      face = face->NextSiblingElement("face");
    }
  }

  XMLElement *solids = topology->FirstChildElement("solids");
  if(solids) {
    XMLElement *solid = solids->FirstChildElement("solid");
    while(solid) {
      int index = 0, ref = 0;
      if(solid->QueryIntAttribute("index", &index) != XML_SUCCESS ||
         solid->QueryIntAttribute("reference", &ref) != XML_SUCCESS) {
        Msg::Error("Missing index or reference for solid");
      }
      else {
        TopoDS_Shape subShape = mainMap.FindKey(ref);
        GRegion *gr = getRegionForOCCShape(&subShape);
        if(gr) {
          entities[3][index] = gr;
          const char *name = nullptr;
          if(solid->QueryAttribute("name", &name) == XML_SUCCESS)
            if(strlen(name)) setElementaryName(3, gr->tag(), name);
        }
        else {
          Msg::Error("Could not find model volume for XAO reference %d", ref);
        }
      }
      solid = solid->NextSiblingElement("solid");
    }
  }

  auto getDim = [](const std::string &name) {
    if(name == "vertex")
      return 0;
    else if(name == "edge")
      return 1;
    else if(name == "face")
      return 2;
    else if(name == "solid")
      return 3;
    return -1;
  };

  if(groups) {
    XMLElement *group = groups->FirstChildElement("group");
    while(group) {
      const char *name = nullptr, *dimension = nullptr;
      if(group->QueryAttribute("name", &name) == XML_SUCCESS &&
         group->QueryAttribute("dimension", &dimension) == XML_SUCCESS &&
         getDim(dimension) >= 0) {
        int dim = getDim(dimension);
        int tag = 0;
        if(group->QueryIntAttribute("tag", &tag) == XML_SUCCESS) {
          // Gmsh XAO extension: Gmsh saves the physical tag when creating XAO
          // files
          tag = setPhysicalName(name, dim, tag);
        }
        else {
          tag = setPhysicalName(name, dim);
        }
        XMLElement *element = group->FirstChildElement("element");
        while(element) {
          int index = 0;
          if(element->QueryIntAttribute("index", &index) == XML_SUCCESS &&
             entities[dim].count(index)) {
            GEntity *ge = entities[dim][index];
            ge->physicals.push_back(tag);
          }
          else {
            Msg::Error("Unknown model entity of dimension %d at index %d", dim,
                       index);
          }
          element = element->NextSiblingElement("element");
        }
      }
      else {
        Msg::Error("Missing name or dimension for group");
      }
      group = group->NextSiblingElement("group");
    }
  }

#else
  Msg::Error("Gmsh requires OpenCASCADE and TinyXML2 to import XAO files");
  return 0;
#endif

  return 1;
}

int GModel::readOCCSTEP(const std::string &fn)
{
  if(!_occ_internals) _occ_internals = new OCC_Internals;
  std::vector<std::pair<int, int>> outDimTags;
  _occ_internals->importShapes(fn, false, outDimTags, "step");
  _occ_internals->synchronize(this);
  return 1;
}

int GModel::readOCCIGES(const std::string &fn)
{
  if(!_occ_internals) _occ_internals = new OCC_Internals;
  std::vector<std::pair<int, int>> outDimTags;
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
  _occ_internals->exportShapes(this, fn, "brep",
                               CTX::instance()->geom.occExportOnlyVisible);
  return 1;
}

int GModel::writeOCCXAO(const std::string &fn)
{
  if(!_occ_internals) {
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  _occ_internals->exportShapes(this, fn, "xao",
                               CTX::instance()->geom.occExportOnlyVisible);
  return 1;
}

int GModel::writeOCCSTEP(const std::string &fn)
{
  if(!_occ_internals) {
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  _occ_internals->exportShapes(this, fn, "step",
                               CTX::instance()->geom.occExportOnlyVisible);
  return 1;
}

int GModel::writeOCCIGES(const std::string &fn)
{
  if(!_occ_internals) {
    Msg::Error("No OpenCASCADE model found");
    return 0;
  }
  _occ_internals->exportShapes(this, fn, "iges",
                               CTX::instance()->geom.occExportOnlyVisible);
  return 1;
}

int GModel::importOCCShape(const void *shape)
{
  if(!_occ_internals) _occ_internals = new OCC_Internals;
#if defined(HAVE_OCC)
  std::vector<std::pair<int, int>> outDimTags;
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
