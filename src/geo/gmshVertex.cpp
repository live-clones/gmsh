// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GFace.h"
#include "GEdge.h"
#include "gmshVertex.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "GmshMessage.h"
#include "MVertex.h"
#include "MPoint.h"

gmshVertex::gmshVertex(GModel *m, Vertex *v) : GVertex(m, v->Num, v->lc), _v(v)
{
  gmshVertex::resetMeshAttributes();
}

void gmshVertex::resetNativePtr(Vertex *v) { _v = v; }

void gmshVertex::resetMeshAttributes() { meshSize = _v->lc; }

GPoint gmshVertex::point() const
{
  return GPoint(_v->Pos.X, _v->Pos.Y, _v->Pos.Z, this);
}

double gmshVertex::x() const { return _v->Pos.X; }

double gmshVertex::y() const { return _v->Pos.Y; }

double gmshVertex::z() const { return _v->Pos.Z; }

void gmshVertex::setPosition(GPoint &p)
{
  _v->Pos.X = p.x();
  _v->Pos.Y = p.y();
  _v->Pos.Z = p.z();
  if(mesh_vertices.size()) {
    mesh_vertices[0]->x() = p.x();
    mesh_vertices[0]->y() = p.y();
    mesh_vertices[0]->z() = p.z();
  }
}

GEntity::GeomType gmshVertex::geomType() const
{
  if(_v->Typ == MSH_POINT_BND_LAYER)
    return BoundaryLayerPoint;
  else
    return Point;
}

void gmshVertex::setPrescribedMeshSizeAtVertex(double l)
{
  meshSize = l;
  _v->lc = meshSize;
}

SPoint2 gmshVertex::reparamOnFace(const GFace *face, int dir) const
{
  Surface *s = (Surface *)face->getNativePtr();

  if(s->geometry) {
    // It is not always right if it is periodic.
    if(l_edges.size() == 1 && (*l_edges.begin())->getBeginVertex() ==
                                (*l_edges.begin())->getEndVertex()) {
      Range<double> bb = (*l_edges.begin())->parBounds(0);
      return (*l_edges.begin())->reparamOnFace(face, bb.low(), dir);
    }
    return _v->pntOnGeometry;
  }

  if(s->Typ == MSH_SURF_REGL) {
    Curve *C[4];
    for(int i = 0; i < 4; i++) List_Read(s->Generatrices, i, &C[i]);

    double U, V;
    if((C[0]->beg == _v && C[3]->beg == _v) ||
       (C[0]->end == _v && C[3]->beg == _v) ||
       (C[0]->beg == _v && C[3]->end == _v) ||
       (C[0]->end == _v && C[3]->end == _v)) {
      U = V = 0;
    }
    else if((C[0]->beg == _v && C[1]->beg == _v) ||
            (C[0]->end == _v && C[1]->beg == _v) ||
            (C[0]->beg == _v && C[1]->end == _v) ||
            (C[0]->end == _v && C[1]->end == _v)) {
      U = 1;
      V = 0;
    }
    else if((C[2]->beg == _v && C[1]->beg == _v) ||
            (C[2]->end == _v && C[1]->beg == _v) ||
            (C[2]->beg == _v && C[1]->end == _v) ||
            (C[2]->end == _v && C[1]->end == _v)) {
      U = 1;
      V = 1;
    }
    else if((C[2]->beg == _v && C[3]->beg == _v) ||
            (C[2]->end == _v && C[3]->beg == _v) ||
            (C[2]->beg == _v && C[3]->end == _v) ||
            (C[2]->end == _v && C[3]->end == _v)) {
      U = 0;
      V = 1;
    }
    else {
      Msg::Info("Reparameterizing point %d on face %d", _v->Num, s->Num);
      return GVertex::reparamOnFace(face, dir);
    }
    return SPoint2(U, V);
  }
  else if(s->Typ == MSH_SURF_TRIC) {
    Curve *C[3];
    for(int i = 0; i < 3; i++) List_Read(s->Generatrices, i, &C[i]);

    double U, V;
    if((C[0]->beg == _v && C[2]->beg == _v) ||
       (C[0]->end == _v && C[2]->beg == _v) ||
       (C[0]->beg == _v && C[2]->end == _v) ||
       (C[0]->end == _v && C[2]->end == _v)) {
      U = V = 0;
    }
    else if((C[0]->beg == _v && C[1]->beg == _v) ||
            (C[0]->end == _v && C[1]->beg == _v) ||
            (C[0]->beg == _v && C[1]->end == _v) ||
            (C[0]->end == _v && C[1]->end == _v)) {
      U = 1;
      V = 0;
    }
    else if((C[2]->beg == _v && C[1]->beg == _v) ||
            (C[2]->end == _v && C[1]->beg == _v) ||
            (C[2]->beg == _v && C[1]->end == _v) ||
            (C[2]->end == _v && C[1]->end == _v)) {
      U = 1;
      V = 1;
    }
    else {
      Msg::Info("Reparameterizing point %d on face %d", _v->Num, s->Num);
      return GVertex::reparamOnFace(face, dir);
    }
    return SPoint2(U, V);
  }
  else {
    return GVertex::reparamOnFace(face, dir);
  }
}

void gmshVertex::writeGEO(FILE *fp, const std::string &meshSizeParameter)
{
  double xx, yy, zz;
  if(_v->geometry) {
    xx = _v->pntOnGeometry.x();
    yy = _v->pntOnGeometry.y();
    zz = 0.;
  }
  else {
    xx = x();
    yy = y();
    zz = z();
  }

  if(meshSizeParameter.size())
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g, %s};\n", tag(),
            xx, yy, zz, meshSizeParameter.c_str());
  else if(_v->lc != MAX_LC)
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g, %.16g};\n", tag(),
            xx, yy, zz, _v->lc);
  else
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g};\n", tag(),
            xx, yy, zz);
}

void gmshVertex::writePY(FILE *fp, const std::string &meshSizeParameter)
{
  double xx, yy, zz;
  const char *fct;
  if(_v->geometry) {
    xx = _v->pntOnGeometry.x();
    yy = _v->pntOnGeometry.y();
    zz = 0.;
    fct = "gmsh.model.geo.addPointOnGeometry(1, "; // TODO geometryTag
  }
  else {
    xx = x();
    yy = y();
    zz = z();
    fct = "gmsh.model.geo.addPoint(";
  }

  if(meshSizeParameter.size())
    fprintf(fp, "%s%.16g, %.16g, %.16g, %s, %d)\n",
            fct, xx, yy, zz, meshSizeParameter.c_str(), tag());
  else if(prescribedMeshSizeAtVertex() != MAX_LC)
    fprintf(fp, "%s%.16g, %.16g, %.16g, %.16g, %d)\n",
            fct, xx, yy, zz, prescribedMeshSizeAtVertex(), tag());
  else
    fprintf(fp, "%s%.16g, %.16g, %.16g, tag=%d)\n",
            fct, xx, yy, zz, tag());
}
