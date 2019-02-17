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
  for(std::size_t i = 0; i < discrete_lines.size(); i++)
    delete discrete_lines[i];
  for(std::size_t i = 0; i < discrete_vertices.size(); i++)
    delete discrete_vertices[i];
  discrete_lines.clear();
  discrete_vertices.clear();
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
  if(lines.empty()){
    Msg::Error("No line elements in discrete curve %d", tag());
    return;
  }
  GVertex *g0 = dynamic_cast<GVertex *>(lines[0]->getVertex(0)->onWhat());
  if(g0) setBeginVertex(g0);
  GVertex *g1 = dynamic_cast<GVertex *>(lines[lines.size() - 1]->getVertex(1)->onWhat());
  if(g1) setEndVertex(g1);
  if(!g0 || !g1)
    Msg::Error("Discrete curve %d has non consecutive line elements", tag());
}

bool discreteEdge::getLocalParameter(const double &t, int &iLine,
                                     double &tLoc) const
{
  for(iLine = 0; iLine < (int)discrete_lines.size(); iLine++) {
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

  double x, y, z;
  MVertex *vB = discrete_lines[iEdge]->getVertex(0);
  MVertex *vE = discrete_lines[iEdge]->getVertex(1);
  if(!vB || !vE) return GPoint();

  // linear Lagrange mesh
  x = vB->x() + tLoc * (vE->x() - vB->x());
  y = vB->y() + tLoc * (vE->y() - vB->y());
  z = vB->z() + tLoc * (vE->z() - vB->z());
  return GPoint(x, y, z, this, par);
}

SVector3 discreteEdge::firstDer(double par) const
{
  double tLoc;
  int iEdge;

  if(!getLocalParameter(par, iEdge, tLoc)) return SVector3();

  MVertex *vB = discrete_lines[iEdge]->getVertex(0);
  MVertex *vE = discrete_lines[iEdge]->getVertex(1);

  if(!vB || !vE) return SVector3();

  double dx, dy, dz;
  dx = (vE->x() - vB->x()); // / dt;
  dy = (vE->y() - vB->y()); // / dt;
  dz = (vE->z() - vB->z()); // / dt;

  SVector3 der(dx, dy, dz);
  return der;
}

double discreteEdge::curvature(double par) const
{
  Msg::Error("Curvature for discrete curve not implemented yet");
  return 0.;
}

Range<double> discreteEdge::parBounds(int i) const
{
  return Range<double>(0, (double)discrete_lines.size());
}

void discreteEdge::createGeometry()
{
  if(lines.empty()) return;

  if(discrete_lines.empty()) {
    orderMLines();

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
    _pars.push_back(0.0);
    for(std::size_t i = 1; i < discrete_lines.size(); i++) {
      _pars.push_back((double)i);
      MVertex *newv = discrete_lines[i]->getVertex(0);
      discrete_vertices.push_back(newv);
    }
    _pars.push_back((double)discrete_lines.size());
    mesh_vertices.clear();
    lines.clear();
  }
}

void discreteEdge::mesh(bool verbose)
{
#if defined(HAVE_MESH)
  if(discrete_lines.empty()) return;
  meshGEdge mesher;
  mesher(this);
#endif
}
