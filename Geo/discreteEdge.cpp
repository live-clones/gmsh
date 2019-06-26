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
  _split[0] = _split[1] = NULL;
}

discreteEdge::discreteEdge(GModel *model, int num) : GEdge(model, num)
{
  Curve *c = CreateCurve(num, MSH_SEGM_DISCRETE, 0, 0, 0, -1, -1, 0., 1.);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
  _split[0] = _split[1] = NULL;
}

discreteEdge::~discreteEdge()
{
  _split[0] = _split[1] = NULL;
}

void discreteEdge::orderMLines()
{
  size_t ss = lines.size();
  if(!ss) return;

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
    mesh_vertices.push_back(v11);
  }
  if(lines.empty()) {
    Msg::Error("No line elements in discrete curve %d", tag());
    return;
  }
  GVertex *g0 = dynamic_cast<GVertex *>(lines[0]->getVertex(0)->onWhat());
  if(g0) setBeginVertex(g0);
  GVertex *g1 =
    dynamic_cast<GVertex *>(lines[lines.size() - 1]->getVertex(1)->onWhat());
  if(g1) setEndVertex(g1);
  if(!g0 || !g1)
    Msg::Error("Discrete curve %d has non consecutive line elements", tag());

  deleteVertexArrays();
  model()->destroyMeshCaches();
}

bool discreteEdge::getLocalParameter(const double &t, int &iLine,
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

  if(!getLocalParameter(par, iEdge, tLoc)) return GPoint();

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

  if(!getLocalParameter(par, iEdge, tLoc)) return SVector3();

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

  if(!getLocalParameter(par, iEdge, tLoc)) return 0.0;

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

void discreteEdge::createGeometry()
{
  std::vector<MVertex *> discrete_vertices;
  std::vector<MLine *> discrete_lines;

  if(lines.empty()) return;

  if(!_discretization.empty()) return;

  printf("coucou1 %d\n",tag());
  orderMLines();
  printf("coucou2\n");

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

  std::vector<MLine *> _temp;
  discrete_lines.resize(lines.size());
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

  // compute parameters and recompute the vertices
  _discretization.push_back(SPoint3(discrete_lines[0]->getVertex(0)->x(),
                                    discrete_lines[0]->getVertex(0)->y(),
                                    discrete_lines[0]->getVertex(0)->z()));

  for(std::size_t i = 0; i < discrete_lines.size(); i++) {
    _discretization.push_back(SPoint3(discrete_lines[i]->getVertex(1)->x(),
                                      discrete_lines[i]->getVertex(1)->y(),
                                      discrete_lines[i]->getVertex(1)->z()));
  }

  _pars.push_back(0.0);
  for(std::size_t i = 1; i < discrete_lines.size(); i++) {
    _pars.push_back((double)i);
    MVertex *newv = discrete_lines[i]->getVertex(0);
    discrete_vertices.push_back(newv);
  }
  _pars.push_back((double)discrete_lines.size());
  //  mesh_vertices.clear();
  //  lines.clear();
  for(std::size_t i = 0; i < discrete_lines.size(); i++)
    delete discrete_lines[i];
  for(std::size_t i = 0; i < discrete_vertices.size(); i++)
    delete discrete_vertices[i];
  discrete_lines.clear();
  discrete_vertices.clear();
}

void discreteEdge::mesh(bool verbose)
{
#if defined(HAVE_MESH)
  if(_discretization.empty()) return;
  meshGEdge mesher;
  mesher(this);
#endif
}

bool discreteEdge::split(MVertex *v, GVertex *gv, int &TAG)
{
  GVertex *gv0 = getBeginVertex();
  GVertex *gv1 = getEndVertex();

  if(v != gv->mesh_vertices[0]) {
    Msg::Error("Wrong vertex for splitting discrete curve");
    return false;
  }
  discreteEdge *de_new[2];

  de_new[0] = new discreteEdge(model(), ++TAG, gv0, gv);
  de_new[1] = new discreteEdge(model(), ++TAG, gv, gv1);

  setSplit(de_new[0], de_new[1], gv);

  int current = 0;
  de_new[current]->lines.push_back(lines[0]);
  for(size_t i = 1; i < lines.size(); i++) {
    if(lines[i]->getVertex(0) == v) { current++; }
    else {
      de_new[current]->mesh_vertices.push_back(lines[i]->getVertex(0));
      lines[i]->getVertex(0)->setEntity(de_new[current]);
    }
    de_new[current]->lines.push_back(lines[i]);
  }
  lines.clear();
  mesh_vertices.clear();
  Msg::Info("Edge %d split in %d %d (%d and %d lines)\n", tag(),
            de_new[0]->tag(), de_new[1]->tag(), de_new[0]->lines.size(),
            de_new[1]->lines.size());

  std::vector<GFace *> f = faces();
  for(size_t i = 0; i < f.size(); i++) {
    std::vector<GEdge *> new_eds, old_eds;
    old_eds = f[i]->edges();
    for(size_t j = 0; j < old_eds.size(); j++) {
      if(old_eds[j] == this) {
        new_eds.push_back(de_new[0]);
        new_eds.push_back(de_new[1]);
        new_eds[0]->addFace(f[i]);
        new_eds[1]->addFace(f[i]);
      }
      else
        new_eds.push_back(old_eds[j]);
    }
    f[i]->set(new_eds);
  }
  model()->add(de_new[0]);
  model()->add(de_new[1]);
  model()->remove(this);
  return true;
}

void discreteEdge::unsplit(void)
{
  if(_split[2] != NULL) return;
  if(_split[0] == NULL) return;
  std::vector<GEdge *> l_edges;
  std::vector<GVertex *> l_vertices;
  getSplit(l_edges, l_vertices);
  // remove all internal model vertices
  for(size_t k = 0; k < l_vertices.size(); k++) {
    l_vertices[k]->mesh_vertices.clear();
    model()->remove(l_vertices[k]);
  }
  // remove all internal model edges
  for(size_t k = 0; k < l_edges.size(); k++) {
    for(size_t l = 0; l < l_edges[k]->lines.size(); l++) {
      lines.push_back(l_edges[k]->lines[l]);
      if(l_edges[k]->lines[l]->getVertex(0)->onWhat() != getBeginVertex() &&
         l_edges[k]->lines[l]->getVertex(0)->onWhat() != getEndVertex() &&
         l_edges[k]->lines[l]->getVertex(0)->onWhat() != this)
        l_edges[k]->lines[l]->getVertex(0)->setEntity(this);
      if(l_edges[k]->lines[l]->getVertex(1)->onWhat() != getBeginVertex() &&
         l_edges[k]->lines[l]->getVertex(1)->onWhat() != getEndVertex() &&
         l_edges[k]->lines[l]->getVertex(1)->onWhat() != this)
        l_edges[k]->lines[l]->getVertex(1)->setEntity(this);
      if(l_edges[k]->lines[l]->getVertex(1)->onWhat() == this &&
         std::find(mesh_vertices.begin(), mesh_vertices.end(),
                   l_edges[k]->lines[l]->getVertex(0)) == mesh_vertices.end())
        mesh_vertices.push_back(l_edges[k]->lines[l]->getVertex(1));
      if(l_edges[k]->lines[l]->getVertex(1)->onWhat() == this &&
         std::find(mesh_vertices.begin(), mesh_vertices.end(),
                   l_edges[k]->lines[l]->getVertex(1)) == mesh_vertices.end())
        mesh_vertices.push_back(l_edges[k]->lines[l]->getVertex(1));
    }
    l_edges[k]->lines.clear();
    l_edges[k]->mesh_vertices.clear();
    model()->remove(l_edges[k]);
  }
  // recompute the right edge 2 face topology

  std::vector<GFace *> f = faces();
  for(size_t i = 0; i < f.size(); i++) {
    std::vector<GEdge *> new_eds, old_eds;
    old_eds = f[i]->edges();
    new_eds.push_back(this);
    for(size_t j = 0; j < old_eds.size(); j++) {
      if(std::find(l_edges.begin(), l_edges.end(), old_eds[j]) ==
         l_edges.end()) {
        new_eds.push_back(old_eds[j]);
      }
    }
    f[i]->set(new_eds);
  }
}

void discreteEdge::writeParametrization(FILE *fp, bool binary)
{
  fprintf(fp, "%lu\n", _discretization.size());
  for(size_t i = 0; i < _discretization.size(); i++) {
    fprintf(fp, "%22.15E %22.15E %22.15E %22.15E\n", _discretization[i].x(), _discretization[i].y(),
            _discretization[i].z(), _pars[i]);
  }
}

void discreteEdge::readParametrization(FILE *fp, bool binary)
{
  int N;
  if(fscanf(fp, "%d", &N) != 1)
    return;

  _pars.resize(N);
  _discretization.resize(N);
  for(int i = 0; i < N; i++) {
    double x, y, z, t;
    if(fscanf(fp, "%lf %lf %lf %lf\n", &x, &y, &z, &t) != 4) {
      return;
    }
    _pars[i] = t;
    _discretization[i] = SPoint3(x, y, z);
  }
}
