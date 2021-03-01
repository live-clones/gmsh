// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteEdge.h"
#include "MLine.h"
#include "MEdge.h"
#include "GModelIO_GEO.h"
#include "Geo.h"

#if defined(HAVE_MESH)
#include "meshGEdge.h"
#include "Context.h"
#endif

discreteEdge::discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1)
  : GEdge(model, num, _v0, _v1)
{
  bool ok;
  Curve *c = CreateCurve(num, MSH_SEGM_DISCRETE, 0, nullptr, nullptr, -1, -1,
                         0., 1., ok);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
}

discreteEdge::discreteEdge(GModel *model, int num) : GEdge(model, num)
{
  bool ok;
  Curve *c = CreateCurve(num, MSH_SEGM_DISCRETE, 0, nullptr, nullptr, -1, -1,
                         0., 1., ok);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
}

discreteEdge::discreteEdge(GModel *model) : GEdge(model, 0)
{
  // used for temporary discrete edges, that should not lead to the creation of
  // the corresponding entity in GEO internals
}

bool discreteEdge::_getLocalParameter(const double &t, int &iLine,
                                      double &tLoc) const
{
  for(iLine = 0; iLine < (int)_discretization.size() - 1; iLine++) {
    double tmin = _pars[iLine];
    double tmax = _pars[iLine + 1];
    if(t >= tmin && t <= tmax) {
      tLoc = (t - tmin) / (tmax - tmin);
      return true;
    }
  }
  return false;
}

GPoint discreteEdge::point(double par) const
{
  double tLoc;
  int iEdge;

  if(!_getLocalParameter(par, iEdge, tLoc)) return GPoint();

  SPoint3 vB = _discretization[iEdge];
  SPoint3 vE = _discretization[iEdge + 1];

  // linear Lagrange mesh
  SPoint3 v = vB + (vE - vB) * tLoc;
  return GPoint(v.x(), v.y(), v.z(), this, par);
}

SVector3 discreteEdge::firstDer(double par) const
{
  double tLoc;
  int iEdge;

  if(!_getLocalParameter(par, iEdge, tLoc)) return SVector3();

  SPoint3 vB = _discretization[iEdge];
  SPoint3 vE = _discretization[iEdge + 1];

  double dx, dy, dz;
  dx = (vE.x() - vB.x()); // / dt;
  dy = (vE.y() - vB.y()); // / dt;
  dz = (vE.z() - vB.z()); // / dt;

  SVector3 der(dx, dy, dz);
  return der;
}

SPoint2 discreteEdge::reparamOnFace(const GFace *face, double epar,
                                    int dir) const
{
  GPoint p = point(epar);
  double guess[2];
  GPoint ps = face->closestPoint(SPoint3(p.x(), p.y(), p.z()), guess);
  return SPoint2(ps.u(), ps.v());
}

double discreteEdge::curvature(double par) const
{
  return 1.e-12;
  double tLoc;
  int iEdge;
  if(_discretization.size() <= 3)
    return 0.0; // no clue on how to compute curvature with so few data...

  if(!_getLocalParameter(par, iEdge, tLoc)) return 0.0;

  // Take 3 points x y z : radius of curvature is equal to  |x-y| |x-z| |z-y| /
  // area (x,y,z)

  int iEdgePlus = iEdge + 1, iEdgeMinus = iEdge - 1;

  if(iEdge == 0) {
    iEdge++;
    iEdgePlus++;
    iEdgeMinus++;
    if(periodic(0)) { iEdgeMinus = _discretization.size() - 2; }
  }
  else if(iEdge == (int)(_discretization.size() - 2)) {
    iEdge--;
    iEdgePlus--;
    iEdgeMinus--;
    if(periodic(0)) { iEdgePlus = 0; }
  }

  SPoint3 a =
    (_discretization[iEdgeMinus] + _discretization[iEdgeMinus + 1]) * .5;
  SPoint3 b = (_discretization[iEdge] + _discretization[iEdge + 1]) * .5;
  SPoint3 c =
    (_discretization[iEdgePlus] + _discretization[iEdgePlus + 1]) * .5;

  double A = b.distance(c);
  double B = c.distance(a);
  double C = a.distance(b);

  // radius of the circumcircle ...
  // Heron's formula for the area of a triangle
  double R =
    A * B * C / sqrt((A + B + C) * (-A + B + C) * (A - B + C) * (A + B - C));

  return R = 0.0 ? 1.E22 : 1. / R;
}

Range<double> discreteEdge::parBounds(int i) const
{
  return Range<double>(0, (double)(_discretization.size() - 1));
}

int discreteEdge::createGeometry()
{
  if(lines.empty()) return 0;

  if(!_discretization.empty()) return 0;

  bool sorted = true;

  std::vector<MVertex *> vertices;
  vertices.push_back(lines[0]->getVertex(0));
  for(std::size_t i = 0; i < lines.size(); i++) {
    if(lines[i]->getVertex(0) == vertices.back()) {
      vertices.push_back(lines[i]->getVertex(1));
    }
    else {
      sorted = false;
      break;
    }
  }

  if(!sorted) {
    Msg::Debug("Sorting nodes in discrete curve %d", tag());
    std::vector<MEdge> allEdges;
    for(std::size_t i = 0; i < lines.size(); i++) {
      allEdges.push_back(MEdge(lines[i]->getVertex(0), lines[i]->getVertex(1)));
    }
    std::vector<std::vector<MVertex *> > vs;
    SortEdgeConsecutive(allEdges, vs);
    if(vs.size() == 1) { vertices = vs[0]; }
    else {
      Msg::Error("Discrete curve %d has wrong topology", tag());
      return 1;
    }
  }

  GVertex *g0 = dynamic_cast<GVertex *>(vertices.front()->onWhat());
  GVertex *g1 = dynamic_cast<GVertex *>(vertices.back()->onWhat());

  if(g0) { setBeginVertex(g0); }
  else if(g1 && g1->xyz().distance(vertices.front()->point()) < 1e-14) {
    setBeginVertex(g1);
  }

  if(g1) { setEndVertex(g1); }
  else if(g0 && g0->xyz().distance(vertices.back()->point()) < 1e-14) {
    setEndVertex(g0);
  }

  if(!getBeginVertex() || !getEndVertex()) {
    Msg::Warning("Discrete curve %d has no begin or end point", tag());
    return 1;
  }

  for(std::size_t i = 0; i < vertices.size(); i++) {
    _discretization.push_back(
      SPoint3(vertices[i]->x(), vertices[i]->y(), vertices[i]->z()));
    _pars.push_back((double)i);
  }

  return 0;
}

void discreteEdge::mesh(bool verbose)
{
#if defined(HAVE_MESH)
  if(_discretization.empty()) return;
  meshGEdge mesher;
  mesher(this);
#endif
}

bool discreteEdge::writeParametrization(FILE *fp, bool binary)
{
  std::size_t N = _discretization.size();
  if(N != _pars.size()) {
    Msg::Error("Wrong number of parameters in STL mesh of curve %d", tag());
    return false;
  }
  if(binary) {
    fwrite(&N, sizeof(std::size_t), 1, fp);
    std::vector<double> d(4 * N);
    for(std::size_t i = 0; i < N; i++) {
      d[4 * i + 0] = _discretization[i].x();
      d[4 * i + 1] = _discretization[i].y();
      d[4 * i + 2] = _discretization[i].z();
      d[4 * i + 3] = _pars[i];
    }
    fwrite(&d[0], sizeof(double), 4 * N, fp);
  }
  else {
    fprintf(fp, "%lu\n", N);
    for(std::size_t i = 0; i < N; i++) {
      fprintf(fp, "%.16g %.16g %.16g %.16g\n", _discretization[i].x(),
              _discretization[i].y(), _discretization[i].z(), _pars[i]);
    }
  }
  return true;
}

bool discreteEdge::readParametrization(FILE *fp, bool binary)
{
  std::size_t N;
  if(binary) {
    if(fread(&N, sizeof(std::size_t), 1, fp) != 1) { return false; }
  }
  else {
    if(fscanf(fp, "%lu", &N) != 1) { return false; }
  }
  _pars.resize(N);
  _discretization.resize(N);

  std::vector<double> d(4 * N);
  if(binary) {
    if(fread(&d[0], sizeof(double), 4 * N, fp) != 4 * N) { return false; }
  }
  else {
    for(std::size_t i = 0; i < N; i++) {
      if(fscanf(fp, "%lf %lf %lf %lf\n", &d[4 * i + 0], &d[4 * i + 1],
                &d[4 * i + 2], &d[4 * i + 3]) != 4) {
        return false;
      }
    }
  }

  for(std::size_t i = 0; i < N; i++) {
    _discretization[i] = SPoint3(d[4 * i + 0], d[4 * i + 1], d[4 * i + 2]);
    _pars[i] = d[4 * i + 3];
  }
  return true;
}
