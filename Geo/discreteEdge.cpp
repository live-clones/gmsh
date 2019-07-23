// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteEdge.h"
#include "MLine.h"
#include "MPoint.h"
#include "GModelIO_GEO.h"
#include "Geo.h"

#if defined(HAVE_MESH)
#include "meshGEdge.h"
#include "Context.h"
#endif

discreteEdge::discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1)
  : GEdge(model, num, _v0, _v1)
{
  Curve *c = CreateCurve(num, MSH_SEGM_DISCRETE, 0, 0, 0, -1, -1, 0., 1.);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
}

discreteEdge::discreteEdge(GModel *model, int num) : GEdge(model, num)
{
  Curve *c = CreateCurve(num, MSH_SEGM_DISCRETE, 0, 0, 0, -1, -1, 0., 1.);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
}

bool discreteEdge::_orderMLines(bool isCompound)
{
  std::size_t ss = lines.size();
  if(!ss) return true;

  std::vector<MEdge> ed;
  std::vector<std::vector<MVertex *> > vs;
  for(std::size_t i = 0; i < lines.size(); i++) {
    ed.push_back(MEdge(lines[i]->getVertex(0), lines[i]->getVertex(1)));
    delete lines[i];
  }
  lines.clear();

  if(!SortEdgeConsecutive(ed, vs))
    Msg::Warning("Discrete curve elements cannot be ordered");

  if(vs.size() != 1)
    Msg::Warning("Discrete curve %d is mutiply connected", tag());

  std::size_t START = 0;
  for(; START < vs[0].size(); START++)
    if(vs[0][START]->onWhat()->dim() == 0) break;

  if(START == vs[0].size())
    Msg::Warning("Discrete curve %d topology is wrong", tag());

  std::size_t i = START;
  while(lines.size() != ss) {
    if(vs[0][i % vs[0].size()] != vs[0][(i + 1) % vs[0].size()])
      lines.push_back(
        new MLine(vs[0][i % vs[0].size()], vs[0][(i + 1) % vs[0].size()]));
    i++;
  }

  mesh_vertices.clear();
  for(std::size_t i = 0; i < lines.size() - 1; ++i) {
    MVertex *v11 = lines[i]->getVertex(1);
    if(v11->onWhat() == this || !v11->onWhat()){
      v11->setEntity(this);
      mesh_vertices.push_back(v11);
    }
    else if(!isCompound){
      // no error for compound, where the mesh_vertices are just pointing to the
      // original ones on their respective entities, and the vector will be
      // cleared without deleting its contents as soon as createGeometry is done
      Msg::Error("Discrete curve %d topology is wrong (node %lu classified "
                 "on %s %d)", tag(), v11->getNum(),
                 (v11->onWhat()->dim() == 3) ? "volume" :
                 (v11->onWhat()->dim() == 2) ? "surface" :
                 (v11->onWhat()->dim() == 1) ? "curve" : "point",
                 v11->onWhat()->tag());
    }
  }

  deleteVertexArrays();
  model()->destroyMeshCaches();

  if(lines.empty()) {
    Msg::Error("No line elements in discrete curve %d", tag());
    return false;
  }
  GVertex *g0 = dynamic_cast<GVertex *>(lines[0]->getVertex(0)->onWhat());
  if(g0) setBeginVertex(g0);
  GVertex *g1 =
    dynamic_cast<GVertex *>(lines[lines.size() - 1]->getVertex(1)->onWhat());
  if(g1) setEndVertex(g1);
  if(!g0 || !g1){
    Msg::Error("Discrete curve %d has non consecutive line elements", tag());
    return false;
  }
  return true;
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

  // SPoint3 a((discrete_lines[iEdgeMinus]->getVertex(0)->x() +
  //            discrete_lines[iEdgeMinus]->getVertex(1)->x()) *
  //             .5,
  //           (discrete_lines[iEdgeMinus]->getVertex(0)->y() +
  //            discrete_lines[iEdgeMinus]->getVertex(1)->y()) *
  //             .5,
  //           (discrete_lines[iEdgeMinus]->getVertex(0)->z() +
  //            discrete_lines[iEdgeMinus]->getVertex(1)->z()) *
  //             .5);
  // SPoint3 b((discrete_lines[iEdge]->getVertex(0)->x() +
  //            discrete_lines[iEdge]->getVertex(1)->x()) *
  //             .5,
  //           (discrete_lines[iEdge]->getVertex(0)->y() +
  //            discrete_lines[iEdge]->getVertex(1)->y()) *
  //             .5,
  //           (discrete_lines[iEdge]->getVertex(0)->z() +
  //            discrete_lines[iEdge]->getVertex(1)->z()) *
  //             .5);
  // SPoint3 c((discrete_lines[iEdgePlus]->getVertex(0)->x() +
  //            discrete_lines[iEdgePlus]->getVertex(1)->x()) *
  //             .5,
  //           (discrete_lines[iEdgePlus]->getVertex(0)->y() +
  //            discrete_lines[iEdgePlus]->getVertex(1)->y()) *
  //             .5,
  //           (discrete_lines[iEdgePlus]->getVertex(0)->z() +
  //            discrete_lines[iEdgePlus]->getVertex(1)->z()) *
  //             .5);

  double A = b.distance(c);
  double B = c.distance(a);
  double C = a.distance(b);

  // radius of the circumcircle ...
  // Heron's formula for the area of a triangle
  double R =
    A * B * C / sqrt((A + B + C) * (-A + B + C) * (A - B + C) * (A + B - C));

  // printf("R(%d,%g) = %g\n",tag(),par,R);

  return R = 0.0 ? 1.E22 : 1. / R;
}

Range<double> discreteEdge::parBounds(int i) const
{
  return Range<double>(0, (double)(_discretization.size() - 1));
}

int discreteEdge::createGeometry(bool isCompound)
{
  if(lines.empty()) return 0;

  if(!_discretization.empty()) return 0;

  // FIXME: createGeometry should *not* modify the mesh (and should thus not
  // call _orderMLines) - it should assume that the mesh is already correctly
  // ordered. Any reordering should be made explicitely before.

  if(!_orderMLines(isCompound))
    return -1;

  bool reverse = false;
  if(getEndVertex())
    reverse = (lines[0]->getVertex(0) == getEndVertex()->mesh_vertices[0]);

  std::map<MVertex *, MVertex *> old2new;

  for(std::size_t i = 0; i < lines.size(); i++) {
    for(std::size_t j = 0; j < 2; j++) {
      MVertex *v = lines[i]->getVertex(j);
      if(old2new.find(v) == old2new.end()) {
        MVertex *vnew = new MVertex(v->x(), v->y(), v->z(), this);
        old2new[v] = vnew;
      }
    }
  }

  std::vector<MLine *> discrete_lines(lines.size());
  for(std::size_t i = 0; i < lines.size(); i++) {
    MVertex *v0 = lines[i]->getVertex(0);
    MVertex *v1 = lines[i]->getVertex(1);
    MVertex *v00 = old2new[v0];
    MVertex *v01 = old2new[v1];
    if(reverse)
      discrete_lines[lines.size() - i - 1] = new MLine(v01, v00);
    else
      discrete_lines[i] = new MLine(v00, v01);
  }
  _discretization.push_back(SPoint3(discrete_lines[0]->getVertex(0)->x(),
                                    discrete_lines[0]->getVertex(0)->y(),
                                    discrete_lines[0]->getVertex(0)->z()));

  for(std::size_t i = 0; i < discrete_lines.size(); i++) {
    _discretization.push_back(SPoint3(discrete_lines[i]->getVertex(1)->x(),
                                      discrete_lines[i]->getVertex(1)->y(),
                                      discrete_lines[i]->getVertex(1)->z()));
  }
  for(std::size_t i = 0; i < discrete_lines.size(); i++)
    delete discrete_lines[i];

  _pars.push_back(0.0);
  for(std::size_t i = 1; i < discrete_lines.size(); i++) {
    _pars.push_back((double)i);
  }
  _pars.push_back((double)discrete_lines.size());

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
  if(N != _pars.size()){
    Msg::Error("Wrong number of parameters in STL mesh of curve %d", tag());
    return false;
  }
  if(binary){
    fwrite(&N, sizeof(std::size_t), 1, fp);
    std::vector<double> d(4 * N);
    for(std::size_t i = 0; i < N; i++){
      d[4 * i + 0] = _discretization[i].x();
      d[4 * i + 1] = _discretization[i].y();
      d[4 * i + 2] = _discretization[i].z();
      d[4 * i + 3] = _pars[i];
    }
    fwrite(&d[0], sizeof(double), 4 * N, fp);
  }
  else{
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
  if(binary){
    if(fread(&N, sizeof(std::size_t), 1, fp) != 1) { return false; }
  }
  else{
    if(fscanf(fp, "%lu", &N) != 1){ return false; }
  }
  _pars.resize(N);
  _discretization.resize(N);

  std::vector<double> d(4 * N);
  if(binary){
    if(fread(&d[0], sizeof(double), 4 * N, fp) != 4 * N){ return false; }
  }
  else{
    for(std::size_t i = 0; i < N; i++) {
      if(fscanf(fp, "%lf %lf %lf %lf\n", &d[4 * i + 0], &d[4 * i + 1],
                &d[4 * i + 2], &d[4 * i + 3]) != 4) { return false; }
    }
  }

  for(std::size_t i = 0; i < N; i++) {
    _discretization[i] = SPoint3(d[4 * i + 0], d[4 * i + 1], d[4 * i + 2]);
    _pars[i] = d[4 * i + 3];
  }
  return true;
}
