// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GModel.h"
#include "MVertex.h"
#include "MPoint.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"

#if defined(HAVE_OCC)

#include "GModelIO_OCC.h"
#include <gp_Pnt.hxx>

OCCVertex::OCCVertex(GModel *m, TopoDS_Vertex v, int num, double lc)
  : GVertex(m, num, lc), _v(v)
{
  gp_Pnt pnt = BRep_Tool::Pnt(_v);
  _x = pnt.X();
  _y = pnt.Y();
  _z = pnt.Z();
}

void OCCVertex::setPosition(GPoint &p)
{
  _x = p.x();
  _y = p.y();
  _z = p.z();
  if(mesh_vertices.size()) {
    mesh_vertices[0]->x() = p.x();
    mesh_vertices[0]->y() = p.y();
    mesh_vertices[0]->z() = p.z();
  }
}

SPoint2 OCCVertex::reparamOnFace(const GFace *gf, int dir) const
{
  std::vector<GEdge *> const &l = gf->edges();
  for(auto ge : l_edges) {
    if(std::find(l.begin(), l.end(), ge) != l.end()) {
      if(gf->getNativeType() == GEntity::OpenCascadeModel &&
         ge->getNativeType() == GEntity::OpenCascadeModel) {
        const TopoDS_Face *s = (TopoDS_Face *)gf->getNativePtr();
        const TopoDS_Edge *c = (TopoDS_Edge *)ge->getNativePtr();
        double s1, s0;
        Handle(Geom2d_Curve) curve2d =
          BRep_Tool::CurveOnSurface(*c, *s, s0, s1);
        if(ge->getBeginVertex() == this)
          return ge->reparamOnFace(gf, s0, dir);
        else if(ge->getEndVertex() == this)
          return ge->reparamOnFace(gf, s1, dir);
      }
      else {
        const GPoint pt = point();
        SPoint3 sp(pt.x(), pt.y(), pt.z());
        return gf->parFromPoint(sp);
      }
    }
  }

  // normally never here
  return GVertex::reparamOnFace(gf, dir);
}

#endif
