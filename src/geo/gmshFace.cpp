// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GModel.h"
#include "gmshFace.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Context.h"
#include "MTriangle.h"
#include "VertexArray.h"

#if defined(HAVE_MESH)
#include "meshGFace.h"
#include "meshGEdge.h"
#include "Field.h"
#endif

gmshFace::gmshFace(GModel *m, Surface *s) : GFace(m, s->Num)
{
  resetNativePtr(s);
  gmshFace::resetMeshAttributes();
}

bool gmshFace::degenerate(int dim) const
{
  std::vector<GEdge *> const &eds = edges();
  int numNonDegenerate = 0;
  for(auto ge : eds) {
    if(!ge->degenerate(0)) numNonDegenerate++;
  }
  return numNonDegenerate <= 1;
}

void gmshFace::resetNativePtr(Surface *s)
{
  _s = s;
  l_edges.clear();
  l_dirs.clear();
  edgeLoops.clear();

  std::vector<GEdge *> eds;
  std::vector<int> nums;
  for(int i = 0; i < List_Nbr(_s->Generatrices); i++) {
    Curve *c;
    List_Read(_s->Generatrices, i, &c);
    GEdge *e = model()->getEdgeByTag(abs(c->Num));
    if(e) {
      eds.push_back(e);
      nums.push_back(c->Num);
    }
    else
      Msg::Error("Unknown curve %d", c->Num);
  }
  for(int i = 0; i < List_Nbr(_s->GeneratricesByTag); i++) {
    int j;
    List_Read(_s->GeneratricesByTag, i, &j);
    GEdge *e = model()->getEdgeByTag(abs(j));
    if(e) {
      eds.push_back(e);
      nums.push_back(j);
    }
    else
      Msg::Error("Unknown curve %d", j);
  }

  std::vector<GEdge *> l_wire;
  l_wire.reserve(eds.size());

  GVertex *first = nullptr;
  for(std::size_t i = 0; i < eds.size(); i++) {
    GEdge *e = eds[i];
    int num = nums[i];
    GVertex *start = (num > 0) ? e->getBeginVertex() : e->getEndVertex();
    GVertex *next = (num > 0) ? e->getEndVertex() : e->getBeginVertex();
    if(!first) first = start;
    l_wire.push_back(e);
    if(next == first) {
      edgeLoops.push_back(GEdgeLoop(l_wire));
      l_wire.clear();
      first = nullptr;
    }
    l_edges.push_back(e);
    e->addFace(this);
    l_dirs.push_back((num > 0) ? 1 : -1);
    if(List_Nbr(_s->Generatrices) == 2) {
      e->meshAttributes.minimumMeshSegments =
        std::max(e->meshAttributes.minimumMeshSegments, 2);
    }
  }

  // always compute and store the mean plane for plane surfaces (using
  // the bounding vertices)
  if(_s->Typ == MSH_SURF_PLAN) computeMeanPlane();

  // compute parametric bounds for plane surfaces
  _parBounds[0] = Range<double>(0., 1.);
  _parBounds[1] = Range<double>(0., 1.);
  if(_s->Typ == MSH_SURF_PLAN) {
    SBoundingBox3d bb;
    for(auto ge: l_edges) {
      if(ge->geomType() != DiscreteCurve &&
         ge->geomType() != BoundaryLayerCurve) {
        Range<double> t_bounds = ge->parBounds(0);
        const int N = 5;
        double t0 = t_bounds.low(), dt = t_bounds.high() - t_bounds.low();
        for(int i = 0; i < N; i++) {
          double t = t0 + dt / (double)(N - 1) * i;
          GPoint p = ge->point(t);
          SPoint2 uv = parFromPoint(SPoint3(p.x(), p.y(), p.z()));
          bb += SPoint3(uv.x(), uv.y(), 0.);
        }
      }
    }
    if(!bb.empty()) {
      _parBounds[0] = Range<double>(bb.min().x(), bb.max().x());
      _parBounds[1] = Range<double>(bb.min().y(), bb.max().y());
    }
  }

}

double gmshFace::getMetricEigenvalue(const SPoint2 &pt)
{
  if(!_s->geometry) return 1;
  return _s->geometry->getMetricEigenvalue(pt);
}

void gmshFace::resetMeshAttributes()
{
  meshAttributes.recombine = _s->Recombine;
  meshAttributes.recombineAngle = _s->RecombineAngle;
  meshAttributes.method = _s->Method;
  meshAttributes.extrude = _s->Extrude;
  if(meshAttributes.method == MESH_TRANSFINITE) {
    meshAttributes.transfiniteArrangement = _s->Recombine_Dir;
    meshAttributes.transfiniteSmoothing = _s->TransfiniteSmoothing;
    meshAttributes.corners.clear();
    for(int i = 0; i < List_Nbr(_s->TrsfPoints); i++) {
      Vertex *corn;
      List_Read(_s->TrsfPoints, i, &corn);
      GVertex *gv = model()->getVertexByTag(corn->Num);
      if(gv)
        meshAttributes.corners.push_back(gv);
      else
        Msg::Error("Unknown point %d in transfinite attributes", corn->Num);
    }
  }
  meshAttributes.reverseMesh = _s->ReverseMesh;
  meshAttributes.algorithm = _s->MeshAlgorithm;
  meshAttributes.meshSizeFromBoundary = _s->MeshSizeFromBoundary;
  meshAttributes.transfinite3 = false;
}

SVector3 gmshFace::normal(const SPoint2 &param) const
{
  if(_s->Typ != MSH_SURF_PLAN) {
    Vertex vu = InterpolateSurface(_s, param[0], param[1], 1, 1);
    Vertex vv = InterpolateSurface(_s, param[0], param[1], 1, 2);
    Vertex n = vu % vv;
    n.norme();
    return SVector3(n.Pos.X, n.Pos.Y, n.Pos.Z);
  }
  else {
    // We cannot use InterpolateSurface() for plane surfaces since it
    // relies on the mean plane, which does not respect the
    // orientation

    // FIXME: move this test at the end of the MeanPlane computation
    // routine--and store the correct normal, damn it!

    double n[3] = {meanPlane.a, meanPlane.b, meanPlane.c};
    norme(n);
    GPoint pt = point(param.x(), param.y());
    double v[3] = {pt.x(), pt.y(), pt.z()};
    int NP = 10, tries = 0;
    while(1) {
      tries++;
      double angle = 0.;
      for(int i = 0; i < List_Nbr(_s->Generatrices); i++) {
        Curve *c;
        List_Read(_s->Generatrices, i, &c);
        int N = (c->Typ == MSH_SEGM_LINE && List_Nbr(c->Control_Points) == 2) ?
                  1 :
                  NP;
        for(int j = 0; j < N; j++) {
          double u1 = (double)j / (double)N;
          double u2 = (double)(j + 1) / (double)N;
          Vertex p1 = InterpolateCurve(c, u1, 0);
          Vertex p2 = InterpolateCurve(c, u2, 0);
          double v1[3] = {p1.Pos.X, p1.Pos.Y, p1.Pos.Z};
          double v2[3] = {p2.Pos.X, p2.Pos.Y, p2.Pos.Z};
          angle += angle_plan(v, v1, v2, n);
        }
      }
      if(fabs(angle) < 0.5) { // we're outside
        NP *= 2;
        Msg::Debug(
          "Could not compute normal of surface %d - retrying with %d points",
          tag(), NP);
        if(tries > 10) {
          Msg::Warning("Could not orient normal of surface %d", tag());
          return SVector3(n[0], n[1], n[2]);
        }
      }
      else if(angle > 0)
        return SVector3(n[0], n[1], n[2]);
      else
        return SVector3(-n[0], -n[1], -n[2]);
    }
  }
}

Pair<SVector3, SVector3> gmshFace::firstDer(const SPoint2 &param) const
{
  if(_s->Typ == MSH_SURF_PLAN && !_s->geometry) {
    double x, y, z, VX[3], VY[3];
    getMeanPlaneData(VX, VY, x, y, z);
    return Pair<SVector3, SVector3>(SVector3(VX[0], VX[1], VX[2]),
                                    SVector3(VY[0], VY[1], VY[2]));
  }
  else {
    Vertex vu = InterpolateSurface(_s, param[0], param[1], 1, 1);
    Vertex vv = InterpolateSurface(_s, param[0], param[1], 1, 2);
    return Pair<SVector3, SVector3>(SVector3(vu.Pos.X, vu.Pos.Y, vu.Pos.Z),
                                    SVector3(vv.Pos.X, vv.Pos.Y, vv.Pos.Z));
  }
}

void gmshFace::secondDer(const SPoint2 &param, SVector3 &dudu, SVector3 &dvdv,
                         SVector3 &dudv) const
{
  if(_s->Typ == MSH_SURF_PLAN && !_s->geometry) {
    dudu = SVector3(0., 0., 0.);
    dvdv = SVector3(0., 0., 0.);
    dudv = SVector3(0., 0., 0.);
  }
  else {
    Vertex vuu = InterpolateSurface(_s, param[0], param[1], 2, 1);
    Vertex vvv = InterpolateSurface(_s, param[0], param[1], 2, 2);
    Vertex vuv = InterpolateSurface(_s, param[0], param[1], 2, 3);
    dudu = SVector3(vuu.Pos.X, vuu.Pos.Y, vuu.Pos.Z);
    dvdv = SVector3(vvv.Pos.X, vvv.Pos.Y, vvv.Pos.Z);
    dudv = SVector3(vuv.Pos.X, vuv.Pos.Y, vuv.Pos.Z);
  }
}

GPoint gmshFace::point(double par1, double par2) const
{
  double pp[2] = {par1, par2};
  if(_s->Typ == MSH_SURF_PLAN && !_s->geometry) {
    double x, y, z, VX[3], VY[3];
    getMeanPlaneData(VX, VY, x, y, z);
    return GPoint(x + VX[0] * par1 + VY[0] * par2,
                  y + VX[1] * par1 + VY[1] * par2,
                  z + VX[2] * par1 + VY[2] * par2, this, pp);
  }
  else {
    Vertex v = InterpolateSurface(_s, par1, par2, 0, 0);
    return GPoint(v.Pos.X, v.Pos.Y, v.Pos.Z, this, pp);
  }
}

GPoint gmshFace::closestPoint(const SPoint3 &qp,
                              const double initialGuess[2]) const
{
#if defined(HAVE_ALGLIB)
  return GFace::closestPoint(qp, initialGuess);
#endif
  if(_s->Typ == MSH_SURF_PLAN && !_s->geometry) {
    double XP = qp.x();
    double YP = qp.y();
    double ZP = qp.z();
    double VX[3], VY[3], x, y, z;
    getMeanPlaneData(VX, VY, x, y, z);
    double M[3][2] = {{VX[0], VY[0]}, {VX[1], VY[1]}, {VX[2], VY[2]}};
    double MN[2][2];
    double B[3] = {XP - x, YP - y, ZP - z};
    double BN[2], UV[2];
    for(int i = 0; i < 2; i++) {
      BN[i] = 0;
      for(int k = 0; k < 3; k++) { BN[i] += B[k] * M[k][i]; }
    }
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        MN[i][j] = 0;
        for(int k = 0; k < 3; k++) { MN[i][j] += M[k][i] * M[k][j]; }
      }
    }
    sys2x2(MN, BN, UV);
    return GPoint(XP, YP, ZP, this, UV);
  }

  Vertex v;
  v.Pos.X = qp.x();
  v.Pos.Y = qp.y();
  v.Pos.Z = qp.z();
  double u[2] = {initialGuess[0], initialGuess[1]};
  bool result = ProjectPointOnSurface(_s, v, u);
  if(!result) return GPoint(-1.e22, -1.e22, -1.e22, nullptr, u);
  return GPoint(v.Pos.X, v.Pos.Y, v.Pos.Z, this, u);
}

SPoint2 gmshFace::parFromPoint(const SPoint3 &qp, bool onSurface,
                               bool convTestXYZ) const
{
  if(_s->Typ == MSH_SURF_PLAN) {
    double x, y, z, VX[3], VY[3];
    getMeanPlaneData(VX, VY, x, y, z);
    double const vec[3] = {qp.x() - x, qp.y() - y, qp.z() - z};
    double const u = prosca(vec, VX);
    double const v = prosca(vec, VY);
    return SPoint2(u, v);
  }
  else {
    return GFace::parFromPoint(qp, onSurface, convTestXYZ);
  }
}

GEntity::GeomType gmshFace::geomType() const
{
  switch(_s->Typ) {
  case MSH_SURF_PLAN:
    if(_s->geometry)
      return ParametricSurface;
    else
      return Plane;
  case MSH_SURF_REGL:
  case MSH_SURF_TRIC: return RuledSurface;
  case MSH_SURF_DISCRETE: return DiscreteSurface;
  case MSH_SURF_BND_LAYER: return BoundaryLayerSurface;
  default: return Unknown;
  }
}

bool gmshFace::haveParametrization()
{
  return geomType() != BoundaryLayerSurface;
}

bool gmshFace::containsPoint(const SPoint3 &pt) const
{
  if(_s->Typ == MSH_SURF_PLAN) {
    // OK to use the normal from the mean plane here: we compensate for the
    // (possibly wrong) orientation at the end
    double n[3] = {meanPlane.a, meanPlane.b, meanPlane.c};
    norme(n);
    double angle = 0.;
    double v[3] = {pt.x(), pt.y(), pt.z()};
    for(int i = 0; i < List_Nbr(_s->Generatrices); i++) {
      Curve *c;
      List_Read(_s->Generatrices, i, &c);
      int N = (c->Typ == MSH_SEGM_LINE) ? 1 : 10;
      for(int j = 0; j < N; j++) {
        double u1 = (double)j / (double)N;
        double u2 = (double)(j + 1) / (double)N;
        Vertex p1 = InterpolateCurve(c, u1, 0);
        Vertex p2 = InterpolateCurve(c, u2, 0);
        double v1[3] = {p1.Pos.X, p1.Pos.Y, p1.Pos.Z};
        double v2[3] = {p2.Pos.X, p2.Pos.Y, p2.Pos.Z};
        angle += angle_plan(v, v1, v2, n);
      }
    }
    // we're inside if angle equals 2 * pi
    if(fabs(angle) > 2 * M_PI - 0.5 && fabs(angle) < 2 * M_PI + 0.5)
      return true;
    return false;
  }

  return false;
}
