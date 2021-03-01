// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include "GModel.h"
#include "GFace.h"
#include "gmshEdge.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "GmshMessage.h"
#include "Context.h"
#include "decasteljau.h"

static void setMeshSizeFromCurvePoints(GEdge &edge, const Curve &curve)
{
  if(!CTX::instance()->mesh.lcFromParametricPoints) return;
  switch(curve.Typ) {
  case MSH_SEGM_LINE:
  case MSH_SEGM_SPLN:
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_NURBS:
  case MSH_SEGM_BEZIER: {
    int n = List_Nbr(curve.Control_Points);
    std::vector<double> lc(n), u_lc(n);
    for(int i = 0; i < n; ++i) {
      Vertex *v;
      List_Read(curve.Control_Points, i, &v);
      u_lc[i] = i * 1. / (n - 1);
      lc[i] = v->lc;
    }
    edge.setMeshSizeParametric(u_lc, lc);
    break;
  }
  default: break;
  }
}

gmshEdge::gmshEdge(GModel *m, Curve *c, GVertex *v1, GVertex *v2)
  : GEdge(m, c->Num, v1, v2), _c(c)
{
  gmshEdge::resetMeshAttributes();
  setMeshSizeFromCurvePoints(*this, *c);
}

void gmshEdge::resetNativePtr(Curve *c, GVertex *v1, GVertex *v2)
{
  _c = c;
  _v0 = v1;
  _v1 = v2;
  if(_v0) _v0->addEdge(this);
  if(_v1 && _v1 != _v0) _v1->addEdge(this);
  setMeshSizeFromCurvePoints(*this, *c);
}

bool gmshEdge::degenerate(int dim) const
{
  if(_c->beg == _c->end && _c->Typ == MSH_SEGM_LINE &&
     List_Nbr(_c->Control_Points) == 0) {
    Msg::Info("Curve %d is degenerate", tag());
    return true;
  }
  return false;
}

void gmshEdge::resetMeshAttributes()
{
  meshAttributes.method = _c->Method;
  meshAttributes.nbPointsTransfinite = _c->nbPointsTransfinite;
  meshAttributes.typeTransfinite = _c->typeTransfinite;
  meshAttributes.coeffTransfinite = _c->coeffTransfinite;
  meshAttributes.extrude = _c->Extrude;
  meshAttributes.reverseMesh = _c->ReverseMesh;
}

Range<double> gmshEdge::parBounds(int i) const
{
  return Range<double>(_c->ubeg, _c->uend);
}

GPoint gmshEdge::point(double par) const
{
  Vertex a = InterpolateCurve(_c, par, 0);
  return GPoint(a.Pos.X, a.Pos.Y, a.Pos.Z, this, par);
}

SVector3 gmshEdge::firstDer(double par) const
{
  Vertex a = InterpolateCurve(_c, par, 1);
  return SVector3(a.Pos.X, a.Pos.Y, a.Pos.Z);
}

SVector3 gmshEdge::secondDer(double par) const
{
  Vertex a = InterpolateCurve(_c, par, 2);
  return SVector3(a.Pos.X, a.Pos.Y, a.Pos.Z);
}

GEntity::GeomType gmshEdge::geomType() const
{
  switch(_c->Typ) {
  case MSH_SEGM_LINE: return Line;
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV: return Circle;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV: return Ellipse;
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
  case MSH_SEGM_NURBS:
  case MSH_SEGM_SPLN: return Nurb;
  case MSH_SEGM_BND_LAYER: return BoundaryLayerCurve;
  case MSH_SEGM_DISCRETE: return DiscreteCurve;
  default: return Unknown;
  }
}

bool gmshEdge::haveParametrization()
{
  return geomType() != BoundaryLayerCurve;
}

std::string gmshEdge::getAdditionalInfoString(bool multline)
{
  std::string info = GEdge::getAdditionalInfoString(multline);

  if(List_Nbr(_c->Control_Points) > 2) {
    std::ostringstream sstream;
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
    sstream << "Control points: ";
    for(int i = 0; i < List_Nbr(_c->Control_Points); i++) {
      if(i) sstream << ", ";
      Vertex *v;
      List_Read(_c->Control_Points, i, &v);
      sstream << v->Num;
    }
    info += sstream.str();
  }

  return info;
}

int gmshEdge::minimumMeshSegments() const
{
  int np;
  if(geomType() == Line) { np = GEdge::minimumMeshSegments(); }
  else if(geomType() == Circle || geomType() == Ellipse) {
    double a = fabs(_c->Circle.t1 - _c->Circle.t2);
    double n = CTX::instance()->mesh.minCircleNodes;
    if(a > 6.28)
      np = n;
    else
      np = (int)(0.99 + (n - 1) * a / (2 * M_PI));
  }
  else {
    np = CTX::instance()->mesh.minCurveNodes - 1;
  }
  return std::max(np, meshAttributes.minimumMeshSegments);
}

int gmshEdge::minimumDrawSegments() const
{
  int n = List_Nbr(_c->Control_Points) - 1;
  if(!n) n = GEdge::minimumDrawSegments();

  if(geomType() == Line && !_c->geometry)
    return n;
  else
    return CTX::instance()->geom.numSubEdges * n;
}

SPoint2 gmshEdge::reparamOnFace(const GFace *face, double epar, int dir) const
{
  Surface *s = (Surface *)face->getNativePtr();

  bool periodic = (_c->end == _c->beg);
  if(s->geometry) {
    switch(_c->Typ) {
    case MSH_SEGM_LINE: {
      Vertex *v[3];
      List_Read(_c->Control_Points, 0, &v[1]);
      List_Read(_c->Control_Points, 1, &v[2]);
      SPoint2 p = v[1]->pntOnGeometry +
                  (v[2]->pntOnGeometry - v[1]->pntOnGeometry) * epar;
      return p;
    }
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER: {
      int NbControlPoints = List_Nbr(_c->Control_Points);
      int NbCurves = NbControlPoints + (periodic ? -1 : 1);
      int iCurve = (int)floor(epar * (double)NbCurves);
      if(iCurve >= NbCurves)
        iCurve = NbCurves - 1;
      else if(iCurve < 0) // ? does it happen ?
        iCurve = 0;
      double t1 = (double)(iCurve) / (double)(NbCurves);
      double t2 = (double)(iCurve + 1) / (double)(NbCurves);
      double t = (epar - t1) / (t2 - t1);
      Vertex *v[4];
      for(int j = 0; j < 4; j++) {
        int k = iCurve - (periodic ? 1 : 2) + j;
        if(k < 0) k = periodic ? k + NbControlPoints - 1 : 0;
        if(k >= NbControlPoints)
          k = periodic ? k - NbControlPoints + 1 : NbControlPoints - 1;
        List_Read(_c->Control_Points, k, &v[j]);
      }
      return InterpolateCubicSpline(v, t, _c->mat, t1, t2, _c->geometry, 0);
    }
    case MSH_SEGM_SPLN: {
      Vertex temp1, temp2;
      int N = List_Nbr(_c->Control_Points);
      int i = (int)((double)(N - 1) * epar);
      if(i < 0) i = 0;
      if(i >= N - 1) i = N - 2;
      double t1 = (double)(i) / (double)(N - 1);
      double t2 = (double)(i + 1) / (double)(N - 1);
      double t = (epar - t1) / (t2 - t1);
      Vertex *v[4];
      List_Read(_c->Control_Points, i, &v[1]);
      List_Read(_c->Control_Points, i + 1, &v[2]);
      if(!i) {
        if(_c->beg == _c->end) { List_Read(_c->Control_Points, N - 2, &v[0]); }
        else {
          v[0] = &temp1;
          v[0]->pntOnGeometry = v[1]->pntOnGeometry * 2. - v[2]->pntOnGeometry;
        }
      }
      else {
        List_Read(_c->Control_Points, i - 1, &v[0]);
      }
      if(i == N - 2) {
        if(_c->beg == _c->end) { List_Read(_c->Control_Points, 1, &v[3]); }
        else {
          v[3] = &temp2;
          v[3]->pntOnGeometry = v[2]->pntOnGeometry * 2. - v[1]->pntOnGeometry;
        }
      }
      else {
        List_Read(_c->Control_Points, i + 2, &v[3]);
      }
      return InterpolateCubicSpline(v, t, _c->mat, t1, t2, _c->geometry, 0);
    }
    default:
      Msg::Error("Unknown curve type in reparamOnFace");
      return SPoint2();
    }
  }

  if(s->Typ == MSH_SURF_REGL) {
    Curve *C[4];
    for(int i = 0; i < 4; i++) List_Read(s->Generatrices, i, &C[i]);

    double U, V;
    if(C[0]->Num == _c->Num) {
      U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg);
      V = 0;
    }
    else if(C[0]->Num == -_c->Num) {
      U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg);
      V = 0;
    }
    else if(C[1]->Num == _c->Num) {
      V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg);
      U = 1;
    }
    else if(C[1]->Num == -_c->Num) {
      V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg);
      U = 1;
    }
    else if(C[2]->Num == _c->Num) {
      U = 1 - (epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg);
      V = 1;
    }
    else if(C[2]->Num == -_c->Num) {
      U = 1 - (C[2]->uend - epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg);
      V = 1;
    }
    else if(C[3]->Num == _c->Num) {
      V = 1 - (epar - C[3]->ubeg) / (C[3]->uend - C[3]->ubeg);
      U = 0;
    }
    else if(C[3]->Num == -_c->Num) {
      V = 1 - (C[3]->uend - epar - C[3]->ubeg) / (C[3]->uend - C[3]->ubeg);
      U = 0;
    }
    else {
      Msg::Info("Reparameterizing curve %d on surface %d", _c->Num, s->Num);
      return GEdge::reparamOnFace(face, epar, dir);
    }
    return SPoint2(U, V);
  }
  else if(s->Typ == MSH_SURF_TRIC) {
    Curve *C[3];
    for(int i = 0; i < 3; i++) List_Read(s->Generatrices, i, &C[i]);
    double U, V;
    if(CTX::instance()->geom.oldRuledSurface) {
      if(C[0]->Num == _c->Num) {
        U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg);
        V = 0;
      }
      else if(C[0]->Num == -_c->Num) {
        U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg);
        V = 0;
      }
      else if(C[1]->Num == _c->Num) {
        V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg);
        U = 1;
      }
      else if(C[1]->Num == -_c->Num) {
        V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg);
        U = 1;
      }
      else if(C[2]->Num == _c->Num) {
        U = 1 - (epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg);
        V = 1;
      }
      else if(C[2]->Num == -_c->Num) {
        U = 1 - (C[2]->uend - epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg);
        V = 1;
      }
      else {
        Msg::Info("Reparameterizing curve %d on surface %d", _c->Num, s->Num);
        return GEdge::reparamOnFace(face, epar, dir);
      }
    }
    else {
      // FIXME: workaround for exact extrusions
      bool hack = false;
      if(CTX::instance()->geom.exactExtrusion && s->Extrude &&
         s->Extrude->geo.Mode == EXTRUDED_ENTITY && s->Typ != MSH_SURF_PLAN)
        hack = true;
      if(C[0]->Num == _c->Num) {
        U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg);
        V = 0;
      }
      else if(C[0]->Num == -_c->Num) {
        U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg);
        V = 0;
      }
      else if(C[1]->Num == _c->Num) {
        V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg);
        U = 1;
      }
      else if(C[1]->Num == -_c->Num) {
        V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg);
        U = 1;
      }
      else if(C[2]->Num == _c->Num) {
        U = 1 - (epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg);
        V = hack ? 1 : U;
      }
      else if(C[2]->Num == -_c->Num) {
        U = 1 - (C[2]->uend - epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg);
        V = hack ? 1 : U;
      }
      else {
        Msg::Info("Reparameterizing curve %d on surface %d", _c->Num, s->Num);
        return GEdge::reparamOnFace(face, epar, dir);
      }
    }
    return SPoint2(U, V);
  }
  else {
    return GEdge::reparamOnFace(face, epar, dir);
  }
}

void gmshEdge::writeGEO(FILE *fp)
{
  if(!_c || _c->Num < 0 || _c->Typ == MSH_SEGM_DISCRETE) return;
  switch(_c->Typ) {
  case MSH_SEGM_LINE: fprintf(fp, "Line(%d) = ", _c->Num); break;
  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV: fprintf(fp, "Circle(%d) = ", _c->Num); break;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV: fprintf(fp, "Ellipse(%d) = ", _c->Num); break;
  case MSH_SEGM_NURBS:
    fprintf(fp, "Nurbs(%d) = {", _c->Num);
    for(int i = 0; i < List_Nbr(_c->Control_Points); i++) {
      Vertex *v;
      List_Read(_c->Control_Points, i, &v);
      if(!i)
        fprintf(fp, "%d", v->Num);
      else
        fprintf(fp, ", %d", v->Num);
      if(i % 8 == 7 && i != List_Nbr(_c->Control_Points) - 1) fprintf(fp, "\n");
    }
    fprintf(fp, "}\n");
    fprintf(fp, "  Knots {");
    for(int j = 0; j < List_Nbr(_c->Control_Points) + _c->degre + 1; j++) {
      if(!j)
        fprintf(fp, "%.16g", _c->k[j]);
      else
        fprintf(fp, ", %.16g", _c->k[j]);
      if(j % 5 == 4 && j != List_Nbr(_c->Control_Points) + _c->degre)
        fprintf(fp, "\n        ");
    }
    fprintf(fp, "}\n");
    fprintf(fp, "  Order %d;\n", _c->degre);
    return;
  case MSH_SEGM_SPLN: fprintf(fp, "Spline(%d) = ", _c->Num); break;
  case MSH_SEGM_BSPLN: fprintf(fp, "BSpline(%d) = ", _c->Num); break;
  case MSH_SEGM_BEZIER: fprintf(fp, "Bezier(%d) = ", _c->Num); break;
  default: Msg::Error("Unknown curve type %d", _c->Typ); return;
  }
  for(int i = 0; i < List_Nbr(_c->Control_Points); i++) {
    Vertex *v;
    List_Read(_c->Control_Points, i, &v);
    if(i)
      fprintf(fp, ", %d", v->Num);
    else
      fprintf(fp, "{%d", v->Num);
    if(i % 8 == 7) fprintf(fp, "\n");
  }
  fprintf(fp, "};\n");

  if(meshAttributes.method == MESH_TRANSFINITE) {
    fprintf(fp, "Transfinite Line {%d} = %d",
            tag() * (meshAttributes.typeTransfinite > 0 ? 1 : -1),
            meshAttributes.nbPointsTransfinite);
    if(meshAttributes.typeTransfinite) {
      if(std::abs(meshAttributes.typeTransfinite) == 1)
        fprintf(fp, " Using Progression ");
      else if(std::abs(meshAttributes.typeTransfinite) == 2)
        fprintf(fp, " Using Bump ");
      fprintf(fp, "%g", meshAttributes.coeffTransfinite);
    }
    fprintf(fp, ";\n");
  }

  if(meshAttributes.reverseMesh) fprintf(fp, "Reverse Line {%d};\n", tag());
}

static inline SPoint3 curveGetPoint(Curve *c, int i)
{
  Vertex *v;
  List_Read(c->Control_Points, i, &v);
  return SPoint3(v->Pos.X, v->Pos.Y, v->Pos.Z);
}

void gmshEdge::discretize(double tol, std::vector<SPoint3> &pts,
                          std::vector<double> &ts)
{
  switch(_c->Typ) {
  case MSH_SEGM_LINE: {
    int NPt = List_Nbr(_c->Control_Points);
    pts.resize(NPt);
    ts.resize(NPt);
    for(int i = 0; i < NPt; ++i) {
      pts[i] = curveGetPoint(_c, i);
      ts[i] = i / (double)(NPt - 1);
    }
    return;
  }
  case MSH_SEGM_BEZIER: {
    int NbCurves = (List_Nbr(_c->Control_Points) - 1) / 3;
    for(int iCurve = 0; iCurve < NbCurves; ++iCurve) {
      double t1 = (iCurve) / (double)(NbCurves);
      double t2 = (iCurve + 1) / (double)(NbCurves);
      SPoint3 pt[4];
      for(int i = 0; i < 4; i++) { pt[i] = curveGetPoint(_c, iCurve * 3 + i); }
      std::vector<double> lts;
      std::vector<SPoint3> lpts;
      decasteljau(tol, pt[0], pt[1], pt[2], pt[3], lpts, lts);
      for(size_t i = (iCurve == 0 ? 0 : 1); i < lpts.size(); ++i) {
        pts.push_back(lpts[i]);
        ts.push_back(t1 + lts[i] * (t2 - t1));
      }
    }
    break;
  }
  case MSH_SEGM_BSPLN: {
    bool periodic = (_c->end == _c->beg);
    int NbControlPoints = List_Nbr(_c->Control_Points);
    int NbCurves = NbControlPoints + (periodic ? -1 : 1);
    SPoint3 pt[4];
    for(int iCurve = 0; iCurve < NbCurves; ++iCurve) {
      double t1 = (iCurve) / (double)(NbCurves);
      double t2 = (iCurve + 1) / (double)(NbCurves);
      for(int i = 0; i < 4; i++) {
        int k;
        if(periodic) {
          k = (iCurve - 1 + i) % (NbControlPoints - 1);
          if(k < 0) k += NbControlPoints - 1;
        }
        else {
          k = std::max(0, std::min(iCurve - 2 + i, NbControlPoints - 1));
        }
        pt[i] = curveGetPoint(_c, k);
      }
      SPoint3 bpt[4] = {(pt[0] + pt[1] * 4 + pt[2]) * (1. / 6.),
                        (pt[1] * 2 + pt[2]) * (1. / 3.),
                        (pt[1] + pt[2] * 2) * (1. / 3.),
                        (pt[1] + pt[2] * 4 + pt[3]) * (1. / 6.)};
      std::vector<double> lts;
      std::vector<SPoint3> lpts;
      decasteljau(tol, bpt[0], bpt[1], bpt[2], bpt[3], lpts, lts);
      for(size_t i = (iCurve == 0 ? 0 : 1); i < lpts.size(); ++i) {
        pts.push_back(lpts[i]);
        ts.push_back(t1 + lts[i] * (t2 - t1));
      }
    }
    break;
  }
  case MSH_SEGM_SPLN: {
    int NbCurves = List_Nbr(_c->Control_Points) - 1;
    SPoint3 pt[4];
    for(int iCurve = 0; iCurve < NbCurves; ++iCurve) {
      double t1 = (iCurve) / (double)(NbCurves);
      double t2 = (iCurve + 1) / (double)(NbCurves);
      pt[1] = curveGetPoint(_c, iCurve);
      pt[2] = curveGetPoint(_c, iCurve + 1);
      if(iCurve == 0) {
        if(_c->beg == _c->end)
          pt[0] = curveGetPoint(_c, NbCurves - 1);
        else
          pt[0] = SPoint3(pt[1] * 2 - pt[2]);
      }
      else
        pt[0] = curveGetPoint(_c, iCurve - 1);
      if(iCurve == NbCurves - 1) {
        if(_c->beg == _c->end)
          pt[3] = curveGetPoint(_c, 1);
        else
          pt[3] = SPoint3(2 * pt[2] - pt[1]);
      }
      else
        pt[3] = curveGetPoint(_c, iCurve + 2);
      SPoint3 bpt[4] = {pt[1], (pt[1] * 6 + pt[2] - pt[0]) * (1. / 6.),
                        (pt[2] * 6 - pt[3] + pt[1]) * (1. / 6.), pt[2]};
      std::vector<double> lts;
      std::vector<SPoint3> lpts;
      decasteljau(tol, bpt[0], bpt[1], bpt[2], bpt[3], lpts, lts);
      for(size_t i = (iCurve == 0 ? 0 : 1); i < lpts.size(); ++i) {
        pts.push_back(lpts[i]);
        ts.push_back(t1 + lts[i] * (t2 - t1));
      }
    }
    break;
  }
  default: GEdge::discretize(tol, pts, ts);
  }
}
