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

#if defined(HAVE_OCC)

#include <TopTools_DataMapIteratorOfDataMapOfShapeInteger.hxx>
#include <TopTools_DataMapIteratorOfDataMapOfIntegerShape.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_Copy.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakeWedge.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <BRepOffsetAPI_MakeFilling.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <gce_MakeCirc.hxx>
#include <gce_MakeElips.hxx>
#include <gce_MakePln.hxx>
#include <ElCLib.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomAPI_PointsToBSpline.hxx>

OCC_Internals::OCC_Internals()
{
  for(int i = 0; i < 6; i++)
    _maxTagConstraints[i] = 0;
}

void OCC_Internals::bind(TopoDS_Vertex vertex, int tag)
{
  _vertexTag.Bind(vertex, tag);
  _tagVertex.Bind(tag, vertex);
}

void OCC_Internals::bind(TopoDS_Edge edge, int tag)
{
  _edgeTag.Bind(edge, tag);
  _tagEdge.Bind(tag, edge);
}

void OCC_Internals::bind(TopoDS_Wire wire, int tag)
{
  _wireTag.Bind(wire, tag);
  _tagWire.Bind(tag, wire);
}

void OCC_Internals::bind(TopoDS_Face face, int tag)
{
  _faceTag.Bind(face, tag);
  _tagFace.Bind(tag, face);
}

void OCC_Internals::bind(TopoDS_Shell shell, int tag)
{
  _shellTag.Bind(shell, tag);
  _tagShell.Bind(tag, shell);
}

void OCC_Internals::bind(TopoDS_Solid solid, int tag)
{
  _solidTag.Bind(solid, tag);
  _tagSolid.Bind(tag, solid);
}

void OCC_Internals::bind(TopoDS_Shape shape, int dim, int tag)
{
  switch(dim){
  case 0: bind(TopoDS::Vertex(shape), tag); break;
  case 1: bind(TopoDS::Edge(shape), tag); break;
  case 2: bind(TopoDS::Face(shape), tag); break;
  case 3: bind(TopoDS::Solid(shape), tag); break;
  case -1: bind(TopoDS::Wire(shape), tag); break;
  case -2: bind(TopoDS::Shell(shape), tag); break;
  default: break;
  }
}

void OCC_Internals::unbind(TopoDS_Vertex vertex, int tag)
{
  _vertexTag.UnBind(vertex);
  _tagVertex.UnBind(tag);
}

void OCC_Internals::unbind(TopoDS_Edge edge, int tag)
{
  _edgeTag.UnBind(edge);
  _tagEdge.UnBind(tag);
}

void OCC_Internals::unbind(TopoDS_Wire wire, int tag)
{
  _wireTag.UnBind(wire);
  _tagWire.UnBind(tag);
}

void OCC_Internals::unbind(TopoDS_Face face, int tag)
{
  _faceTag.UnBind(face);
  _tagFace.UnBind(tag);
}

void OCC_Internals::unbind(TopoDS_Shell shell, int tag)
{
  _shellTag.UnBind(shell);
  _tagShell.UnBind(tag);
}

void OCC_Internals::unbind(TopoDS_Solid solid, int tag)
{
  _solidTag.UnBind(solid);
  _tagSolid.UnBind(tag);
}

void OCC_Internals::unbind(TopoDS_Shape shape, int dim, int tag)
{
  switch(dim){
  case 0: unbind(TopoDS::Vertex(shape), tag); break;
  case 1: unbind(TopoDS::Edge(shape), tag); break;
  case 2: unbind(TopoDS::Face(shape), tag); break;
  case 3: unbind(TopoDS::Solid(shape), tag); break;
  case -1: unbind(TopoDS::Wire(shape), tag); break;
  case -2: unbind(TopoDS::Shell(shape), tag); break;
  default: break;
  }
}

void OCC_Internals::bind(TopoDS_Shape shape, bool highestDimOnly, int tag,
                         std::vector<int> outTags[4])
{
  TopExp_Explorer exp0;
  bool first = true;
  for(exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next()){
    int t = tag;
    if(t <= 0){ t = getMaxTag(3) + 1; }
    else if(first){ first = false; }
    else{ Msg::Error("Cannot bind multiple regions to single tag %d", t); return; }
    bind(TopoDS::Solid(exp0.Current()), t);
    outTags[3].push_back(t);
  }
  if(highestDimOnly && outTags[3].size()) return;
  for(exp0.Init(shape, TopAbs_FACE); exp0.More(); exp0.Next()){
    int t = tag;
    if(t <= 0){ t = getMaxTag(2) + 1; }
    else if(first){ first = false; }
    else{ Msg::Error("Cannot bind multiple faces to single tag %d", t); return; }
    bind(TopoDS::Face(exp0.Current()), t);
    outTags[2].push_back(t);
  }
  if(highestDimOnly && outTags[2].size()) return;
  for(exp0.Init(shape, TopAbs_EDGE); exp0.More(); exp0.Next()){
    int t = tag;
    if(t <= 0){ t = getMaxTag(1) + 1; }
    else if(first){ first = false; }
    else{ Msg::Error("Cannot bind multiple edges to single tag %d", t); return; }
    bind(TopoDS::Edge(exp0.Current()), t);
    outTags[1].push_back(t);
  }
  if(highestDimOnly && outTags[1].size()) return;
  for(exp0.Init(shape, TopAbs_VERTEX); exp0.More(); exp0.Next()){
    int t = tag;
    if(t <= 0){ t = getMaxTag(0) + 1; }
    else if(first){ first = false; }
    else{ Msg::Error("Cannot bind multiple vertices to single tag %d", t); return; }
    bind(TopoDS::Vertex(exp0.Current()), t);
    outTags[0].push_back(t);
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

void OCC_Internals::setTagConstraints(int dim, int val)
{
  if(dim < -2 || dim > 3) return;
  _maxTagConstraints[dim + 2] = val;
}

int OCC_Internals::getMaxTag(int dim) const
{
  if(dim < -2 || dim > 3) return 0;
  int ret = _maxTagConstraints[dim + 2];
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
    ret = std::max(ret, exp.Key());
  return ret;
}

void OCC_Internals::addVertex(int tag, double x, double y, double z,
                              double meshSize)
{
  if(tag > 0 && _tagVertex.IsBound(tag)){
    Msg::Error("OpenCASCADE vertex with tag %d already exists", tag);
    return;
  }
  TopoDS_Vertex result;
  try{
    gp_Pnt aPnt(x, y, z);
    BRepBuilderAPI_MakeVertex v(aPnt);
    v.Build();
    if(!v.IsDone()){
      Msg::Error("Could not create vertex");
      return;
    }
    result = v.Vertex();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(0) + 1;
  bind(result, tag);
  if(meshSize > 0 && meshSize < MAX_LC)
    meshAttributes[0][tag].size = meshSize;
}

void OCC_Internals::addLine(int tag, int startTag, int endTag)
{
  if(tag > 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return;
  }
  if(!_tagVertex.IsBound(startTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", startTag);
    return;
  }
  if(!_tagVertex.IsBound(endTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", endTag);
    return;
  }

  TopoDS_Edge result;
  try{
    TopoDS_Vertex start = TopoDS::Vertex(_tagVertex.Find(startTag));
    TopoDS_Vertex end = TopoDS::Vertex(_tagVertex.Find(endTag));
    BRepBuilderAPI_MakeEdge e(start, end);
    e.Build();
    if(!e.IsDone()){
      Msg::Error("Could not create edge");
      return;
    }
    result = e.Edge();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(1) + 1;
  bind(result, tag);
}

void OCC_Internals::addLine(int tag, std::vector<int> vertexTags)
{
  if(vertexTags.size() == 2)
    addLine(tag, vertexTags[0], vertexTags[1]);
  else
    Msg::Error("OpenCASCADE polyline currently not supported");
  // FIXME: if tag < 0 we could create multiple lines
}

void OCC_Internals::_addArc(int tag, int startTag, int centerTag, int endTag,
                            int mode)
{
  if(tag > 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return;
  }
  if(!_tagVertex.IsBound(startTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", startTag);
    return;
  }
  if(!_tagVertex.IsBound(centerTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", centerTag);
    return;
  }
  if(!_tagVertex.IsBound(endTag)){
    Msg::Error("Unknown OpenCASCADE vertex with tag %d", endTag);
    return;
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
        return;
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
        return;
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
      return;
    }
    result = e.Edge();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(1) + 1;
  bind(result, tag);
}

void OCC_Internals::addCircleArc(int tag, int startTag, int centerTag, int endTag)
{
  _addArc(tag, startTag, centerTag, endTag, 0);
}

void OCC_Internals::addEllipseArc(int tag, int startTag, int centerTag, int endTag)
{
  _addArc(tag, startTag, centerTag, endTag, 1);
}

void OCC_Internals::addCircle(int tag, double x, double y, double z, double r,
                              double angle1, double angle2)
{
  if(tag > 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return;
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
        return;
      }
      result = e.Edge();
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(1) + 1;
  bind(result, tag);
}

void OCC_Internals::addEllipse(int tag, double x, double y, double z, double r1,
                               double r2, double angle1, double angle2)
{
  if(tag > 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return;
  }

  TopoDS_Edge result;
  try{
    gp_Dir N_dir(0., 0., 1.);
    gp_Dir x_dir(1., 0., 0.);
    gp_Pnt center(x, y, z);
    gp_Ax2 axis(center, N_dir, x_dir);
    gp_Elips elips(axis, r1, r2);
    if(angle1 == 0 && angle2 == 2 * M_PI){
      result = BRepBuilderAPI_MakeEdge(elips);
    }
    else{
      Handle(Geom_Ellipse) E = new Geom_Ellipse(elips);
      Handle(Geom_TrimmedCurve) arc = new Geom_TrimmedCurve(E, angle1, angle2, true);
      BRepBuilderAPI_MakeEdge e(arc);
      if(!e.IsDone()){
        Msg::Error("Could not create ellipse arc");
        return;
      }
      result = e.Edge();
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(1) + 1;
  bind(result, tag);
}

void OCC_Internals::_addSpline(int tag, std::vector<int> vertexTags, int mode)
{
  if(tag > 0 && _tagEdge.IsBound(tag)){
    Msg::Error("OpenCASCADE edge with tag %d already exists", tag);
    return;
  }
  if(vertexTags.size() < 2 || vertexTags.size() > 20){
    Msg::Error("Number of control points should be in [2,20]");
    return;
  }

  TopoDS_Edge result;
  try{
    TColgp_Array1OfPnt ctrlPoints(1, vertexTags.size());
    TopoDS_Vertex start, end;
    for(unsigned int i = 0; i < vertexTags.size(); i++){
      if(!_tagVertex.IsBound(vertexTags[i])){
        Msg::Error("Unknown OpenCASCADE vertex with tag %d", vertexTags[i]);
        return;
      }
      TopoDS_Vertex vertex = TopoDS::Vertex(_tagVertex.Find(vertexTags[i]));
      ctrlPoints.SetValue(i + 1, BRep_Tool::Pnt(vertex));
      if(i == 0) start = vertex;
      if(i == vertexTags.size() - 1) end = vertex;
    }
    if(mode == 0){
      Handle(Geom_BezierCurve) curve = new Geom_BezierCurve(ctrlPoints);
      BRepBuilderAPI_MakeEdge e(curve, start, end);
      if(!e.IsDone()){
        Msg::Error("Could not create Bezier curve");
        return;
      }
      result = e.Edge();
    }
    else{
      Handle(Geom_BSplineCurve) curve = GeomAPI_PointsToBSpline(ctrlPoints).Curve();
      BRepBuilderAPI_MakeEdge e(curve, start, end);
      if(!e.IsDone()){
        Msg::Error("Could not create BSpline curve");
        return;
      }
      result = e.Edge();
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(1) + 1;
  bind(result, tag);
}

void OCC_Internals::addBezier(int tag, std::vector<int> vertexTags)
{
  _addSpline(tag, vertexTags, 0);
}

void OCC_Internals::addBSpline(int tag, std::vector<int> vertexTags)
{
  _addSpline(tag, vertexTags, 1);
}

void OCC_Internals::addWire(int tag, std::vector<int> edgeTags, bool checkClosed)
{
  if(tag > 0 && _tagWire.IsBound(tag)){
    Msg::Error("OpenCASCADE wire or line loop with tag %d already exists", tag);
    return;
  }

  TopoDS_Wire result;
  try{
    BRepBuilderAPI_MakeWire w;
    for (unsigned int i = 0; i < edgeTags.size(); i++) {
      if(!_tagEdge.IsBound(edgeTags[i])){
        Msg::Error("Unknown OpenCASCADE edge with tag %d", edgeTags[i]);
        return;
      }
      TopoDS_Edge edge = TopoDS::Edge(_tagEdge.Find(edgeTags[i]));
      w.Add(edge);
    }
    result = w.Wire();
    if(checkClosed && !result.Closed()){
      Msg::Error("Line Loop is not closed");
      return;
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(-1) + 1;
  bind(result, tag);
}

void OCC_Internals::addLineLoop(int tag, std::vector<int> edgeTags)
{
  addWire(tag, edgeTags, true);
}

void OCC_Internals::addRectangle(int tag, double x1, double y1, double z1,
                                 double x2, double y2, double z2,
                                 double roundedRadius)
{
  if(tag > 0 && _tagFace.IsBound(tag)){
    Msg::Error("OpenCASCADE face with tag %d already exists", tag);
    return;
  }
  if(z1 != z2){
    Msg::Error("Rectangle currently requires z1=z2");
    return;
  }

  TopoDS_Face result;
  try{
    TopoDS_Wire wire;
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
    return;
  }
  if(tag <= 0) tag = getMaxTag(2) + 1;
  bind(result, tag);
}

void OCC_Internals::addDisk(int tag, double xc, double yc, double zc,
                            double rx, double ry)
{
  if(tag > 0 && _tagFace.IsBound(tag)){
    Msg::Error("OpenCASCADE face with tag %d already exists", tag);
    return;
  }

  TopoDS_Face result;
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
    return;
  }
  if(tag <= 0) tag = getMaxTag(2) + 1;
  bind(result, tag);
}

void OCC_Internals::addPlaneSurface(int tag, std::vector<int> wireTags)
{
  const bool autoFix = true;

  if(tag > 0 && _tagFace.IsBound(tag)){
    Msg::Error("OpenCASCADE face with tag %d already exists", tag);
    return;
  }

  std::vector<TopoDS_Wire> wires;
  for (unsigned int i = 0; i < wireTags.size(); i++) {
    if(!_tagWire.IsBound(wireTags[i])){
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTags[i]);
      return;
    }
    TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTags[i]));
    wires.push_back(wire);
  }

  TopoDS_Face result;
  if(wires.size() == 0){
    Msg::Error("Plane surface requires at least one line loop");
    return;
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
      BRepBuilderAPI_MakeFace f(aPlane);
      for(unsigned int i = 0; i < wires.size(); i++)
        f.Add(wires[i]);
      f.Build();
      if(!f.IsDone()){
        Msg::Error("Could not create face");
        return;
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
      return;
    }
  }
  if(tag <= 0) tag = getMaxTag(2) + 1;
  bind(result, tag);
}

void OCC_Internals::addSurfaceFilling(int tag, int wireTag)
{
  if(tag > 0 && _tagFace.IsBound(tag)){
    Msg::Error("OpenCASCADE face with tag %d already exists", tag);
    return;
  }

  TopoDS_Face result;
  try{
    BRepOffsetAPI_MakeFilling f;
    // add edge constraints
    if(!_tagWire.IsBound(wireTag)){
      Msg::Error("Unknown OpenCASCADE line loop with tag %d", wireTag);
      return;
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
      return;
    }
    result = TopoDS::Face(f.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }

  if(tag <= 0) tag = getMaxTag(2) + 1;
  bind(result, tag);
}

void OCC_Internals::addSurfaceLoop(int tag, std::vector<int> faceTags)
{
  const bool autoFix = true;

  if(tag > 0 && _tagShell.IsBound(tag)){
    Msg::Error("OpenCASCADE surface loop with tag %d already exists", tag);
    return;
  }

  TopoDS_Shape result;
  try{
    BRepBuilderAPI_Sewing s;
    for (unsigned int i = 0; i < faceTags.size(); i++) {
      if(!_tagFace.IsBound(faceTags[i])){
        Msg::Error("Unknown OpenCASCADE face with tag %d", faceTags[i]);
        return;
      }
      TopoDS_Face face = TopoDS::Face(_tagFace.Find(faceTags[i]));
      s.Add(face);
    }
    s.Perform();
    result = s.SewedShape();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
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
    bind(shell, t);
  }
}

void OCC_Internals::addVolume(int tag, std::vector<int> shellTags)
{
  const bool autoFix = true;

  if(tag > 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return;
  }

  TopoDS_Solid result;
  try{
    BRepBuilderAPI_MakeSolid s;
    for (unsigned int i = 0; i < shellTags.size(); i++) {
      if(!_tagShell.IsBound(shellTags[i])){
        Msg::Error("Unknown OpenCASCADE surface loop with tag %d", shellTags[i]);
        return;
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
    return;
  }
  if(tag <= 0) tag = getMaxTag(3) + 1;
  bind(result, tag);
}

void OCC_Internals::addSphere(int tag, double xc, double yc, double zc,
                              double radius, double angle)
{
  if(tag > 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return;
  }

  TopoDS_Solid result;
  try{
    gp_Pnt p(xc, yc, zc);
    BRepPrimAPI_MakeSphere s(p, radius, angle);
    s.Build();
    if(!s.IsDone()){
      Msg::Error("Could not create sphere");
      return;
    }
    result = TopoDS::Solid(s.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(3) + 1;
  bind(result, tag);
}

void OCC_Internals::addBlock(int tag, double x1, double y1, double z1,
                             double x2, double y2, double z2)
{
  if(tag > 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return;
  }

  TopoDS_Solid result;
  try{
    gp_Pnt P1(x1, y1, z1);
    gp_Pnt P2(x2, y2, z2);
    BRepPrimAPI_MakeBox b(P1, P2);
    b.Build();
    if(!b.IsDone()){
      Msg::Error("Could not create block");
      return;
    }
    result = TopoDS::Solid(b.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(3) + 1;
  bind(result, tag);
}

void OCC_Internals::addCylinder(int tag, double x1, double y1, double z1,
                                double x2, double y2, double z2, double r,
                                double angle)
{
  if(tag > 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return;
  }

  const double H = sqrt((x2 - x1) * (x2 - x1) +
                        (y2 - y1) * (y2 - y1) +
                        (z2 - z1) * (z2 - z1));
  if(!H){
    Msg::Error("Cannot build cylinder of zero height");
    return;
  }
  TopoDS_Solid result;
  try{
    gp_Pnt aP(x1, y1, z1);
    gp_Vec aV((x2 - x1) / H, (y2 - y1) / H, (z2 - z1) / H);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeCylinder c(anAxes, r, H, angle);
    c.Build();
    if(!c.IsDone()){
      Msg::Error("Could not create cylinder");
      return;
    }
    result = TopoDS::Solid(c.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(3) + 1;
  bind(result, tag);
}

void OCC_Internals::addTorus(int tag, double x, double y, double z,
                             double r1, double r2, double angle)
{
  if(tag > 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return;
  }
  TopoDS_Solid result;
  try{
    gp_Pnt aP(x, y, z);
    gp_Vec aV(0, 0, 1);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeTorus t(anAxes, r1, r2, angle);
    t.Build();
    if (!t.IsDone()) {
      Msg::Error("Could not create torus");
      return;
    }
    result = TopoDS::Solid(t.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(3) + 1;
  bind(result, tag);
}

void OCC_Internals::addCone(int tag, double x1, double y1, double z1,
                            double x2, double y2, double z2, double r1,
                            double r2, double angle)
{
  if(tag > 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return;
  }

  const double H = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) +
                        (z2 - z1) * (z2 - z1));
  if(!H){
    Msg::Error("Cannot build cone of zero height");
    return;
  }
  TopoDS_Solid result;
  try{
    gp_Pnt aP(x1, y1, z1);
    gp_Vec aV((x2 - x1) / H, (y2 - y1) / H, (z2 - z1) / H);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeCone c(anAxes, r1, r2, H, angle);
    c.Build();
    if(!c.IsDone()){
      Msg::Error("Could not create cone");
      return;
    }
    result = TopoDS::Solid(c.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(3) + 1;
  bind(result, tag);
}

void OCC_Internals::addWedge(int tag, double x, double y, double z, double dx, double dy,
                             double dz, double ltx)
{
  if(tag > 0 && _tagSolid.IsBound(tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return;
  }

  TopoDS_Solid result;
  try{
    gp_Pnt aP(x, y, z);
    gp_Vec aV(0, 0, 1);
    gp_Ax2 anAxes(aP, aV);
    BRepPrimAPI_MakeWedge w(anAxes, dx, dy, dz, ltx);
    w.Build();
    if(!w.IsDone()){
      Msg::Error("Could not create wedge");
      return;
    }
    result = TopoDS::Solid(w.Shape());
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }
  if(tag <= 0) tag = getMaxTag(3) + 1;
  bind(result, tag);
}

void OCC_Internals::addThruSections(int tag, std::vector<int> wireTags,
                                    std::vector<int> outTags[4],
                                    bool makeSolid, bool makeRuled)
{
  int dim = makeSolid ? 3 : 2;
  if(tag > 0 && isBound(dim, tag)){
    Msg::Error("OpenCASCADE entity of dimension %d with tag %d already exists",
               dim, tag);
    return;
  }
  if(wireTags.size() < 2){
    Msg::Error("ThruSections require at least 2 wires");
    return;
  }

  TopoDS_Shape result;
  try{
    BRepOffsetAPI_ThruSections ts(makeSolid, makeRuled);
    for (unsigned int i = 0; i < wireTags.size(); i++) {
      if(!_tagWire.IsBound(wireTags[i])){
        Msg::Error("Unknown OpenCASCADE wire or line loop with tag %d", wireTags[i]);
        return;
      }
      TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTags[i]));
      if(makeSolid && !wire.Closed()){
        Msg::Error("Making solid requires closed wires");
        return;
      }
      ts.AddWire(wire);
    }
    ts.CheckCompatibility(Standard_False);
    ts.Build();
    if(!ts.IsDone()){
      Msg::Error("Could not create ThruSection");
      return;
    }
    result = ts.Shape();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }

  bind(result, true, tag, outTags);
}

void OCC_Internals::addThickSolid(int tag, int solidTag,
                                  std::vector<int> excludeFaceTags, double offset)
{
  if(tag > 0 && isBound(3, tag)){
    Msg::Error("OpenCASCADE region with tag %d already exists", tag);
    return;
  }

  if(!isBound(3, solidTag)){
    Msg::Error("Unknown OpenCASCADE region with tag %d", solidTag);
    return;
  }
  TopoDS_Shape result;
  try{
    TopoDS_Shape shape = find(3, solidTag);
    TopTools_ListOfShape exclude;
    for(unsigned int i = 0; i < excludeFaceTags.size(); i++){
      if(!_tagFace.IsBound(excludeFaceTags[i])){
        Msg::Error("Unknown OpenCASCADE face with tag %d", excludeFaceTags[i]);
        return;
      }
      exclude.Append(_tagFace.Find(excludeFaceTags[i]));
    }
    BRepOffsetAPI_MakeThickSolid ts(shape, exclude, offset,
                                    CTX::instance()->geom.tolerance);
    ts.Build();
    if(!ts.IsDone()){
      Msg::Error("Could not build thick solid");
      return;
    }
    result = ts.Shape();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }

  std::vector<int> out[4];
  bind(result, true, tag, out);
}

void OCC_Internals::_extrude(int tag, int mode, std::vector<int> inTags[4],
                             double x, double y, double z,
                             double dx, double dy, double dz, double angle,
                             int wireTag, std::vector<int> outTags[4])
{
  for(int dim = 0; dim < 3; dim++){
    if(tag > 0 && inTags[dim].size() && isBound(tag, dim + 1)){
      Msg::Error("OpenCASCADE region of dimension %d with tag %d already exists",
                 dim + 1, tag);
      return;
    }
  }

  // build a single compound shape, so that we won't duplicate internal
  // boundaries
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < inTags[dim].size(); i++){
      if(!isBound(dim, inTags[dim][i])){
        Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                   dim, inTags[dim][i]);
        return;
      }
      TopoDS_Shape shape = find(dim, inTags[dim][i]);
      b.Add(c, shape);
    }
  }
  TopoDS_Shape result;
  try{
    if(mode == 0){ // extrude
      BRepPrimAPI_MakePrism p(c, gp_Vec(dx, dy, dz), Standard_False);
      p.Build();
      if(!p.IsDone()){
        Msg::Error("Could not extrude");
        return;
      }
      result = p.Shape();
    }
    else if(mode == 1){ // revolve
      gp_Ax1 axisOfRevolution(gp_Pnt(x, y, z), gp_Dir(dx, dy, dz));
      BRepPrimAPI_MakeRevol r(c, axisOfRevolution, angle, Standard_False);
      r.Build();
      if(!r.IsDone()){
        Msg::Error("Could not revolve");
        return;
      }
      result = r.Shape();
    }
    else if(mode == 2){ // pipe
      if(!_tagWire.IsBound(wireTag)){
        Msg::Error("Unknown OpenCASCADE wire with tag %d", wireTag);
        return;
      }
      TopoDS_Wire wire = TopoDS::Wire(_tagWire.Find(wireTag));
      BRepOffsetAPI_MakePipe p(wire, c);
      p.Build();
      if(!p.IsDone()){
        Msg::Error("Could not create pipe");
        return;
      }
      result = p.Shape();
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }

  bind(result, true, tag, outTags);
}

void OCC_Internals::extrude(int tag, std::vector<int> inTags[4],
                            double dx, double dy, double dz,
                            std::vector<int> outTags[4])
{
  _extrude(tag, 0, inTags, 0, 0, 0, dx, dy, dz, 0, 0, outTags);
}

void OCC_Internals::revolve(int tag, std::vector<int> inTags[4],
                            double x, double y, double z,
                            double dx, double dy, double dz, double angle,
                            std::vector<int> outTags[4])
{
  _extrude(tag, 1, inTags, x, y, z, dx, dy, dz, angle, 0, outTags);
}

void OCC_Internals::addPipe(int tag, std::vector<int> inTags[4],
                            int wireTag, std::vector<int> outTags[4])
{
  _extrude(tag, 2, inTags, 0, 0, 0, 0, 0, 0, 0, wireTag, outTags);
}

void OCC_Internals::fillet(std::vector<int> regionTags, std::vector<int> edgeTags,
                           double radius, std::vector<int> outTags[4])
{
  // build a single compound shape
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  for(unsigned int i = 0; i < regionTags.size(); i++){
    if(!isBound(3, regionTags[i])){
      Msg::Error("Unknown OpenCASCADE region with tag %d", regionTags[i]);
      return;
    }
    TopoDS_Shape shape = find(3, regionTags[i]);
    b.Add(c, shape);
  }
  TopoDS_Shape result;
  try{
    BRepFilletAPI_MakeFillet f(c);
    for(unsigned int i = 0; i < edgeTags.size(); i++){
      if(!_tagEdge.IsBound(edgeTags[i])){
        Msg::Error("Unknown OpenCASCADE edge with tag %d", edgeTags[i]);
        return;
      }
      TopoDS_Edge edge = TopoDS::Edge(_tagEdge.Find(edgeTags[i]));
      f.Add(edge);
    }
    for(int i = 1; i <= f.NbContours(); i++){
      f.SetRadius(radius, i, 1);
    }
    f.Build();
    if(!f.IsDone()) {
      Msg::Error("Could not compute fillet");
      return;
    }
    result = f.Shape();
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }

  if(result.IsNull()){
    Msg::Error("Fillet produces empty shape");
    return;
  }
  bind(result, true, -1, outTags);
}

void OCC_Internals::applyBooleanOperator(int tag, BooleanOperator op,
                                         std::vector<int> objectTags[4],
                                         std::vector<int> toolTags[4],
                                         std::vector<int> outTags[4],
                                         bool removeObject, bool removeTool)
{
  double tolerance = CTX::instance()->geom.toleranceBoolean;
  bool parallel = CTX::instance()->geom.occParallel;

  if(tag > 0){
    for(int dim = 0; dim < 4; dim++){
      if(objectTags[dim].size() && isBound(dim, tag)){
        Msg::Error("OpenCASCADE entity with tag %d already exists", tag);
        return;
      }
    }
  }

  std::vector<TopoDS_Shape> objects[4], tools[4];
  for(unsigned int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < objectTags[dim].size(); i++){
      if(!isBound(dim, objectTags[dim][i])){
        Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                   dim, objectTags[dim][i]);
        return;
      }
      else{
        TopoDS_Shape object = find(dim, objectTags[dim][i]);
        objects[dim].push_back(object);
        if(removeObject) unbind(object, dim, objectTags[dim][i]);
      }
    }
    for(unsigned int i = 0; i < toolTags[dim].size(); i++){
      if(!isBound(dim, toolTags[dim][i])){
        Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                   dim, toolTags[dim][i]);
        return;
      }
      else{
        TopoDS_Shape tool = find(dim, toolTags[dim][i]);
        tools[dim].push_back(tool);
        if(removeTool) unbind(tool, dim, toolTags[dim][i]);
      }
    }
  }

  TopoDS_Shape result;

#if OCC_VERSION_HEX >= 0x060900
  TopTools_ListOfShape objectShapes, toolShapes;
  for(int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < objects[dim].size(); i++){
      if(tolerance > 0.)
        objectShapes.Append(BRepBuilderAPI_Copy(objects[dim][i]).Shape());
      else
        objectShapes.Append(objects[dim][i]);
    }
    for(unsigned int i = 0; i < tools[dim].size(); i++){
      if(tolerance > 0.)
        toolShapes.Append(BRepBuilderAPI_Copy(tools[dim][i]).Shape());
      else
        toolShapes.Append(tools[dim][i]);
    }
  }
#endif

  try{
    switch(op){
    case OCC_Internals::Union :
      {
#if OCC_VERSION_HEX < 0x060900
        for(int dim = 0; dim < 4; dim++){
          if(objects[dim].empty() || tools[dim].empty()) continue;
          result = objects[dim][0];
          for(int i = 1; i < objects[dim].size(); i++){
            BRepAlgoAPI_Fuse fuse(result, objects[dim][i]);
            fuse.Build();
            if(!fuse.IsDone()) {
              Msg::Error("Fuse operation cannot be performed");
              return;
            }
            else{
              result = fuse.Shape();
            }
          }
          for(int i = 0; i < tools[dim].size(); i++){
            BRepAlgoAPI_Fuse fuse(result, tools[dim][i]);
            fuse.Build();
            if(!fuse.IsDone()) {
              Msg::Error("Fuse operation cannot be performed");
              return;
            }
            else{
              result = fuse.Shape();
            }
          }
        }
#else
        BRepAlgoAPI_Fuse fuse;
        fuse.SetRunParallel(parallel);
        fuse.SetArguments(objectShapes);
        fuse.SetTools(toolShapes);
        if(tolerance > 0.0)
          fuse.SetFuzzyValue(tolerance);
        fuse.Build();
        if(!fuse.IsDone()){
          Msg::Error("Fuse operation cannot be performed");
          return;
        }
        result = fuse.Shape();
#endif
      }
      break;
    case OCC_Internals::Intersection :
      {
#if OCC_VERSION_HEX < 0x060900
        for(int dim = 0; dim < 4; dim++){
          if(objects[dim].empty() || tools[dim].empty()) continue;
          if(objects[dim].size() != 1 || tools[dim].size() != 1){
            Msg::Error("Multi-intersection requires OCC >= 6.9");
            return;
          }
          else{
            BRepAlgoAPI_Common common(objects[dim][0], tools[dim][0]);
            common.Build();
            if(!common.IsDone()) {
              Msg::Error("Intersection operation cannot be performed");
            }
            result = common.Shape();
          }
        }
#else
        BRepAlgoAPI_Common common;
        common.SetRunParallel(parallel);
        common.SetArguments(objectShapes);
        common.SetTools(toolShapes);
        if(tolerance > 0.0)
          common.SetFuzzyValue(tolerance);
        common.Build();
        if(!common.IsDone()){
          Msg::Error("Intersection operation cannot be performed");
          return;
        }
        result = common.Shape();
#endif
      }
      break;

    case OCC_Internals::Difference :
    default:
      {
#if OCC_VERSION_HEX < 0x060900
        for(int dim = 0; dim < 4; dim++){
          if(objects[dim].empty() || tools[dim].empty()) continue;
          if(objects[dim].size() != 1 || tools[dim].size() != 1){
            Msg::Error("Multi-difference requires OCC >= 6.9");
            return;
          }
          else{
            BRepAlgoAPI_Cut cut(objects[dim][0], tools[dim][0]);
            cut.Build();
            if(!cut.IsDone()) {
              Msg::Error("Cut operation cannot be performed");
            }
            result = cut.Shape();
          }
        }
#else
        BRepAlgoAPI_Cut cut;
        cut.SetRunParallel(parallel);
        cut.SetArguments(objectShapes);
        cut.SetTools(toolShapes);
        if(tolerance > 0.0)
          cut.SetFuzzyValue(tolerance);
        cut.Build();
        if(!cut.IsDone()){
          Msg::Error("Intersection operation cannot be performed");
          return;
        }
        result = cut.Shape();
#endif
      }
      break;

    case OCC_Internals::Fragments :
      {
#if OCC_VERSION_HEX < 0x060900
        Msg::Error("Boolean fragments only available with OpenCASCADE >= 6.9");
        return;
#else
        BRepAlgoAPI_BuilderAlgo generalFuse;
        generalFuse.SetRunParallel(parallel);
        objectShapes.Append(toolShapes);
        generalFuse.SetArguments(objectShapes);
        if (tolerance > 0.0)
          generalFuse.SetFuzzyValue(tolerance);
        generalFuse.Build();
        if (!generalFuse.IsDone()){
          Msg::Error("Boolean fragments failed");
          return;
        }
        result = generalFuse.Shape();
#endif
      }
      break;
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }

  bind(result, true, tag, outTags);
}

void OCC_Internals::getBoundary(std::vector<int> inTags[4],
                                std::vector<int> outTags[4],
                                bool combined)
{
  for(int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < inTags[dim].size(); i++){
      if(!isBound(dim, inTags[dim][i])){
        Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                   dim, inTags[dim][i]);
        return;
      }
      TopoDS_Shape shape = find(dim, inTags[dim][i]);
      TopExp_Explorer exp0, exp1;
      switch(dim){
      case 3:
        for(exp0.Init(shape, TopAbs_SHELL); exp0.More(); exp0.Next()){
          TopoDS_Shell shell = TopoDS::Shell(exp0.Current());
          for(exp1.Init(shell, TopAbs_FACE); exp1.More(); exp1.Next()){
            TopoDS_Face face = TopoDS::Face(exp1.Current());
            int tag;
            if(_faceTag.IsBound(face)){
              tag = _faceTag.Find(face);
            }
            else{
              // bind with new tag
              tag = getMaxTag(2) + 1;
              bind(face, tag);
            }
            outTags[2].push_back(tag);
          }
        }
        break;
      case 2:
        for(exp0.Init(shape, TopAbs_WIRE); exp0.More(); exp0.Next()){
          TopoDS_Wire wire = TopoDS::Wire(exp0.Current());
          for(exp1.Init(wire, TopAbs_EDGE); exp1.More(); exp1.Next()){
            TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
            int tag;
            if(_edgeTag.IsBound(edge)){
              tag = _edgeTag.Find(edge);
            }
            else{
              // bind with new tag
              tag = getMaxTag(1) + 1;
              bind(edge, tag);
            }
            outTags[1].push_back(tag);
          }
        }
        break;
      case 1:
        for(exp0.Init(shape, TopAbs_VERTEX); exp0.More(); exp0.Next()){
          TopoDS_Vertex vertex = TopoDS::Vertex(exp0.Current());
          int tag;
          if(_vertexTag.IsBound(vertex)){
            tag = _vertexTag.Find(vertex);
          }
          else{
            // bind with new tag
            tag = getMaxTag(0) + 1;
            bind(vertex, tag);
          }
          outTags[0].push_back(tag);
        }
        break;
      }
    }
  }

  if(combined){
    Msg::Error("OCC TODO CombinedBoundary");
  }
}

void OCC_Internals::_transform(std::vector<int> inTags[4],
                               BRepBuilderAPI_Transform &tfo)
{
  for(unsigned int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < inTags[dim].size(); i++){
      int tag = inTags[dim][i];
      if(!isBound(dim, tag)){
        Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                   dim, tag);
        return;
      }
      tfo.Perform(find(dim, tag), Standard_False);
      if(!tfo.IsDone()){
        Msg::Error("Could not apply transformation");
        return;
      }
      bind(tfo.Shape(), dim, tag);
    }
  }
}

void OCC_Internals::translate(std::vector<int> inTags[4],
                              double dx, double dy, double dz)
{
  gp_Trsf t;
  t.SetTranslation(gp_Pnt(0, 0, 0), gp_Pnt(dx, dy, dz));
  BRepBuilderAPI_Transform tfo(t);
  _transform(inTags, tfo);
}

void OCC_Internals::rotate(std::vector<int> inTags[4],
                           double x, double y, double z,
                           double dx, double dy, double dz,
                           double angle)
{
  gp_Trsf t;
  gp_Ax1 axisOfRevolution(gp_Pnt(x, y, z), gp_Dir(dx, dy, dz));
  t.SetRotation(axisOfRevolution, angle);
  BRepBuilderAPI_Transform tfo(t);
  _transform(inTags, tfo);
}

void OCC_Internals::copy(std::vector<int> inTags[4], std::vector<int> outTags[4])
{
  for(unsigned int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < inTags[dim].size(); i++){
      int tag = inTags[dim][i];
      if(!isBound(dim, tag)){
        Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                   dim, tag);
        return;
      }
      TopoDS_Shape result = BRepBuilderAPI_Copy(find(dim, tag)).Shape();
      int newtag = getMaxTag(dim) + 1;
      bind(result, dim, newtag);
      outTags[dim].push_back(newtag);
    }
  }
}

void OCC_Internals::remove(std::vector<int> inTags[4])
{
  for(unsigned int dim = 0; dim < 4; dim++){
    for(unsigned int i = 0; i < inTags[dim].size(); i++){
      int tag = inTags[dim][i];
      if(!isBound(dim, tag)){
        Msg::Error("Unknown OpenCASCADE entity of dimension %d with tag %d",
                   dim, tag);
        return;
      }
      unbind(find(dim, tag), dim, tag);
    }
  }
}

void OCC_Internals::importShapes(const std::string &fileName, bool highestDimOnly,
                                 std::vector<int> outTags[4], const std::string &format)
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
        return;
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
        return;
      }
      reader.NbRootsForTransfer();
      reader.TransferRoots();
      result = reader.OneShape();
    }
    else{
      Msg::Error("Unknown file type '%s'", fileName.c_str());
      return;
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return;
  }

  BRepTools::Clean(result);
  _healShape(result, CTX::instance()->geom.tolerance,
             CTX::instance()->geom.occFixDegenerated,
             CTX::instance()->geom.occFixSmallEdges,
             CTX::instance()->geom.occFixSmallFaces,
             CTX::instance()->geom.occSewFaces,
             false, CTX::instance()->geom.occScaling);
  bind(result, highestDimOnly, -1, outTags);
}

void OCC_Internals::importShapes(const TopoDS_Shape *shape, bool highestDimOnly,
                                 std::vector<int> outTags[4])
{
  bind(*shape, highestDimOnly, -1, outTags);
}

void OCC_Internals::exportShapes(const std::string &fileName,
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
        }
      }
      else{
        Msg::Error("Could not create STEP data");
      }
    }
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
  }
}

void OCC_Internals::synchronize(GModel *model)
{
  int vTagMax = std::max(model->getMaxElementaryNumber(0), getMaxTag(0));
  int eTagMax = std::max(model->getMaxElementaryNumber(1), getMaxTag(1));
  int fTagMax = std::max(model->getMaxElementaryNumber(2), getMaxTag(2));
  int rTagMax = std::max(model->getMaxElementaryNumber(3), getMaxTag(3));

  _somap.Clear();
  _shmap.Clear();
  _fmap.Clear();
  _wmap.Clear();
  _emap.Clear();
  _vmap.Clear();

  // iterate over all shapes with tags, and import them into the (sub)shape _maps
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp0(_tagVertex);
  for(; exp0.More(); exp0.Next()) _addShapeToMaps(exp0.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp1(_tagEdge);
  for(; exp1.More(); exp1.Next()) _addShapeToMaps(exp1.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp2(_tagFace);
  for(; exp2.More(); exp2.Next()) _addShapeToMaps(exp2.Value());
  TopTools_DataMapIteratorOfDataMapOfIntegerShape exp3(_tagSolid);
  for(; exp3.More(); exp3.Next()) _addShapeToMaps(exp3.Value());

  // import all shapes in _maps into the GModel, preserving all explicit tags

  for(int i = 1; i <= _vmap.Extent(); i++){
    TopoDS_Vertex vertex = TopoDS::Vertex(_vmap(i));
    if(!getOCCVertexByNativePtr(model, vertex)){
      int tag;
      if(_vertexTag.IsBound(vertex)){
        tag = _vertexTag.Find(vertex);
      }
      else{
        tag = vTagMax + 1;
        vTagMax++;
      }
      std::map<int, meshAttribute>::iterator it =
        meshAttributes[0].find(tag);
      double lc = (it == meshAttributes[0].end()) ? MAX_LC : it->second.size;
      model->add(new OCCVertex(model, tag, vertex, lc));
    }
  }

  // building geom edges
  for(int i = 1; i <= _emap.Extent(); i++){
    TopoDS_Edge edge = TopoDS::Edge(_emap(i));
    if(!getOCCEdgeByNativePtr(model, edge)){
      GVertex *v1 = getOCCVertexByNativePtr(model, TopExp::FirstVertex(edge));
      GVertex *v2 = getOCCVertexByNativePtr(model, TopExp::LastVertex(edge));
      int tag;
      if(_edgeTag.IsBound(edge)){
        tag = _edgeTag.Find(edge);
      }
      else{
        tag = eTagMax + 1;
        eTagMax++;
      }
      model->add(new OCCEdge(model, edge, tag, v1, v2));
    }
  }

  // building geom faces
  for(int i = 1; i <= _fmap.Extent(); i++){
    TopoDS_Face face = TopoDS::Face(_fmap(i));
    if(!getOCCFaceByNativePtr(model, face)){
      int tag;
      if(_faceTag.IsBound(face)){
        tag = _faceTag.Find(face);
      }
      else{
        tag = fTagMax + 1;
        fTagMax++;
      }
      model->add(new OCCFace(model, face, tag));
    }
  }

  // building geom regions
  for(int i = 1; i <= _somap.Extent(); i++){
    TopoDS_Solid region = TopoDS::Solid(_somap(i));
    if(!getOCCRegionByNativePtr(model, region)){
      int tag;
      if(_solidTag.IsBound(region)){
        tag = _solidTag(region);
      }
      else{
        tag = rTagMax + 1;
        rTagMax++;
      }
      model->add(new OCCRegion(model, region, tag));
    }
  }
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

GVertex *OCC_Internals::getOCCVertexByNativePtr(GModel *model, TopoDS_Vertex toFind)
{
  if(_vertexTag.IsBound(toFind))
    return model->getVertexByTag(_vertexTag.Find(toFind));
  return 0;
}

GEdge *OCC_Internals::getOCCEdgeByNativePtr(GModel *model, TopoDS_Edge toFind)
{
  if(_edgeTag.IsBound(toFind))
    return model->getEdgeByTag(_edgeTag.Find(toFind));
  return 0;
}

GFace *OCC_Internals::getOCCFaceByNativePtr(GModel *model, TopoDS_Face toFind)
{
  if(_faceTag.IsBound(toFind))
    return model->getFaceByTag(_faceTag.Find(toFind));
  return 0;
}

GRegion *OCC_Internals::getOCCRegionByNativePtr(GModel *model, TopoDS_Solid toFind)
{
  if(_solidTag.IsBound(toFind))
    return model->getRegionByTag(_solidTag.Find(toFind));
  return 0;
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
  GVertex *gv = getOCCVertexByNativePtr(model, vertex);
  if(gv) return gv;
  _addShapeToMaps(vertex);
  buildShapeFromLists(vertex);
  buildGModel(model);
  return getOCCVertexByNativePtr(model, vertex);
}

GEdge *OCC_Internals::addEdgeToModel(GModel *model, TopoDS_Edge edge)
{
  GEdge *ge = getOCCEdgeByNativePtr(model, edge);
  if(ge) return ge;
  _addShapeToMaps(edge);
  buildShapeFromLists(edge);
  buildGModel(model);
  return getOCCEdgeByNativePtr(model, edge);
}

GFace* OCC_Internals::addFaceToModel(GModel *model, TopoDS_Face face)
{
  GFace *gf = getOCCFaceByNativePtr(model, face);
  if(gf) return gf;
  _addShapeToMaps(face);
  buildShapeFromLists(face);
  buildGModel(model);
  return getOCCFaceByNativePtr(model, face);
}

GRegion* OCC_Internals::addRegionToModel(GModel *model, TopoDS_Solid region)
{
  GRegion *gr = getOCCRegionByNativePtr(model, region);
  if(gr) return gr;

  //   FIXME THE PREVIOUS IMPLEMENTATION WAS BETTER FOR SOME USERS :-)
  buildShapeFromLists(region);
  model->destroy();
  buildLists();
  buildGModel(model);
  return getOCCRegionByNativePtr(model, region);
  //  _addShapeToMaps(region);
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

void GModel::_resetOCCInternals()
{
  if(!_occ_internals) return;
  _occ_internals->reset();
}

int GModel::importOCCInternals()
{
  if(!_occ_internals) return 0;
  _occ_internals->synchronize(this);
  return 1;
}

int GModel::readOCCBREP(const std::string &fn)
{
  if(!_occ_internals)
    _occ_internals = new OCC_Internals;
  std::vector<int> tags[4];
  _occ_internals->importShapes(fn, false, tags, "brep");
  _occ_internals->synchronize(this);
  snapVertices();
  return 1;
}

int GModel::readOCCSTEP(const std::string &fn)
{
  if(!_occ_internals)
    _occ_internals = new OCC_Internals;
  std::vector<int> tags[4];
  _occ_internals->importShapes(fn, false, tags, "step");
  _occ_internals->synchronize(this);
  return 1;
}

int GModel::readOCCIGES(const std::string &fn)
{
  if(!_occ_internals)
    _occ_internals = new OCC_Internals;
  std::vector<int> tags[4];
  _occ_internals->importShapes(fn, false, tags, "iges");
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
  std::vector<int> tags[4];
#if defined(HAVE_OCC)
  _occ_internals->importShapes((TopoDS_Shape*)shape, false, tags);
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
  return _occ_internals->getOCCVertexByNativePtr(this, *(TopoDS_Vertex*)shape);
#else
  return 0;
#endif
}

GEdge* GModel::getEdgeForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
#if defined(HAVE_OCC)
  return _occ_internals->getOCCEdgeByNativePtr(this, *(TopoDS_Edge*)shape);
#else
  return 0;
#endif
}

GFace* GModel::getFaceForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
#if defined(HAVE_OCC)
  return _occ_internals->getOCCFaceByNativePtr(this, *(TopoDS_Face*)shape);
#else
  return 0;
#endif
}

GRegion* GModel::getRegionForOCCShape(const void *shape)
{
  if(!_occ_internals) return 0;
#if defined(HAVE_OCC)
  return _occ_internals->getOCCRegionByNativePtr(this, *(TopoDS_Solid*)shape);
#else
  return 0;
#endif
}
