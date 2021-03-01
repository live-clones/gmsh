// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_OCC.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "OCCRegion.h"
#include "Context.h"

#if defined(HAVE_OCC)

#include <Bnd_Box.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>
#include <TopExp_Explorer.hxx>
#include <BRep_Builder.hxx>
#include <BRepBndLib.hxx>
#include <BRepTools.hxx>

OCCRegion::OCCRegion(GModel *m, TopoDS_Solid s, int num)
  : GRegion(m, num), _s(s)
{
  _setup();

  // if(tag() == 1) writeBREP("v1.brep");
}

OCCRegion::~OCCRegion()
{
  if(model()->getOCCInternals() && !model()->isBeingDestroyed())
    model()->getOCCInternals()->unbind(_s, tag()); // potentially slow
}

void OCCRegion::_setup()
{
  l_faces.clear();
  TopExp_Explorer exp2, exp3;
  for(exp2.Init(_s, TopAbs_SHELL); exp2.More(); exp2.Next()) {
    const TopoDS_Shape &shell = exp2.Current();
    Msg::Debug("OCC volume %d - new shell", tag());
    for(exp3.Init(shell, TopAbs_FACE); exp3.More(); exp3.Next()) {
      TopoDS_Face face = TopoDS::Face(exp3.Current());
      GFace *f = nullptr;
      if(model()->getOCCInternals())
        f = model()->getOCCInternals()->getFaceForOCCShape(model(), face);
      if(!f) { Msg::Error("Unknown surface in volume %d", tag()); }
      else if(face.Orientation() == TopAbs_INTERNAL) {
        Msg::Debug("Adding embedded surface %d in volume %d", f->tag(), tag());
        embedded_faces.push_back(f);
      }
      else {
        l_faces.push_back(f);
        f->addRegion(this);
      }
    }
  }

  for(exp3.Init(_s, TopAbs_EDGE, TopAbs_FACE); exp3.More(); exp3.Next()) {
    TopoDS_Edge edge = TopoDS::Edge(exp3.Current());
    GEdge *e = nullptr;
    if(model()->getOCCInternals())
      e = model()->getOCCInternals()->getEdgeForOCCShape(model(), edge);
    if(!e) { Msg::Error("Unknown curve in volume %d", tag()); }
    else if(edge.Orientation() == TopAbs_INTERNAL) {
      Msg::Debug("Adding embedded curve %d in volume %d", e->tag(), tag());
      embedded_edges.push_back(e);
      // OCCEdge *occe = (OCCEdge*)e;
      // occe->setTrimmed(this);
    }
  }

  for(exp3.Init(_s, TopAbs_VERTEX, TopAbs_FACE); exp3.More(); exp3.Next()) {
    TopoDS_Vertex vertex = TopoDS::Vertex(exp3.Current());
    GVertex *v = nullptr;
    if(model()->getOCCInternals())
      v = model()->getOCCInternals()->getVertexForOCCShape(model(), vertex);
    if(!v) { Msg::Error("Unknown point in volume %d", tag()); }
    else if(vertex.Orientation() == TopAbs_INTERNAL) {
      Msg::Debug("Adding embedded point %d in volume %d", v->tag(), tag());
      embedded_vertices.push_back(v);
    }
  }

  Msg::Debug("OCC volume %d with %d surfaces", tag(), l_faces.size());
}

SBoundingBox3d OCCRegion::bounds(bool fast)
{
  if(CTX::instance()->geom.occBoundsUseSTL) {
    // if a triangulation exist on a shape, OCC will use it to compute more
    // accurate bounds
    std::vector<GFace *> f = faces();
    for(std::size_t i = 0; i < f.size(); i++) f[i]->buildSTLTriangulation();
  }

  Bnd_Box b;
  try {
    BRepBndLib::Add(_s, b);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return SBoundingBox3d();
  }
  double xmin, ymin, zmin, xmax, ymax, zmax;
  b.Get(xmin, ymin, zmin, xmax, ymax, zmax);

  if(CTX::instance()->geom.occBoundsUseSTL)
    model()->getOCCInternals()->fixSTLBounds(xmin, ymin, zmin, xmax, ymax,
                                             zmax);

  SBoundingBox3d bbox(xmin, ymin, zmin, xmax, ymax, zmax);
  return bbox;
}

GEntity::GeomType OCCRegion::geomType() const { return Volume; }

void OCCRegion::writeBREP(const char *filename)
{
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  b.Add(c, _s);
  BRepTools::Write(c, filename);
}

#endif
