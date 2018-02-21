// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <vector>
#include <list>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteEdge.h"
#include "MLine.h"
#include "Numeric.h"
#include "MPoint.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MPrism.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPyramid.h"
#include "GModelIO_GEO.h"
#include "Geo.h"
#include "OS.h"

#if defined(HAVE_MESH)
#include "meshGEdge.h"
#include "Context.h"
#endif

discreteEdge::discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1)
  : GEdge(model, num, _v0, _v1)
{
  createdTopo = false;
  Curve *c = CreateCurve(num, MSH_SEGM_DISCRETE, 0, 0, 0, -1, -1, 0., 1.);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
}

// topology is already set
void discreteEdge::setTopo(std::vector<MLine*> mlines)
{
  createdTopo = true;
  lines = mlines;
}

void discreteEdge::createTopo()
{
  if(!createdTopo){
    orderMLines();
    createdTopo = true;
  }
}

void discreteEdge::orderMLines()
{
  // FIXME
  //  return;
  size_t ss = lines.size();
  std::vector<MEdge> ed;
  std::vector<std::vector<MVertex*> >vs;
  for (unsigned int i = 0; i < lines.size(); i++) {
    ed.push_back(MEdge(lines[i]->getVertex(0),lines[i]->getVertex(1)));
    delete lines[i];
  }
  lines.clear();

  if (!SortEdgeConsecutive (ed,vs))
    Msg::Warning ("Discrete edge segments cannot be ordered");

  unsigned int START = 0;
  for ( ; START < vs[0].size(); START++) if (vs[0][START]->onWhat()->dim() == 0) break;

  if (vs.size() != 1)
    Msg::Warning ("Discrete Edge %d is mutiply connected",tag());

  unsigned int i = START;
  while (lines.size() != ss){
    if (vs[0][i] != vs[0][(i+1)% vs[0].size()])
      lines.push_back(new MLine(vs[0][i],vs[0][(i+1)% vs[0].size()]));
    i++;
  }

  mesh_vertices.clear();
  //  printf("discrete edge %d :",tag());
  for (unsigned int i = 0; i < lines.size()-1; ++i){
    MVertex *v11 = lines[i]->getVertex(1);
    //    printf("%d ",v11->getNum());
    mesh_vertices.push_back(v11);
  }
  //  printf("\n");
}

/// We Rewrite WHAT FOLLOWS : THIS WAS WRONG (PAB -JFR)

bool discreteEdge::getLocalParameter(const double &t, int &iLine,
                                     double &tLoc) const
{
  for (iLine = 0; iLine < (int)discrete_lines.size(); iLine++){
    double tmin = _pars[iLine];
    double tmax = _pars[iLine+1];
    if (t >= tmin && t <= tmax){
      tLoc = (t-tmin)/(tmax-tmin);
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

  //linear Lagrange mesh
  x = vB->x() + tLoc * (vE->x()- vB->x());
  y = vB->y() + tLoc * (vE->y()- vB->y());
  z = vB->z() + tLoc * (vE->z()- vB->z());
  return GPoint(x,y,z,this,par);
}

SVector3 discreteEdge::firstDer(double par) const
{

  double tLoc;
  int iEdge;
  if(!getLocalParameter(par, iEdge, tLoc)) return SVector3();

  MVertex *vB = discrete_lines[iEdge]->getVertex(0);
  MVertex *vE = discrete_lines[iEdge]->getVertex(1);

  if(!vB || !vE) return SVector3();

  // printf("%d / %d  %p %p\n",iEdge, discrete_lines.size(),vE,vB);

  double dx, dy, dz;
  //  double dt = 1.0;
  dx = (vE->x() - vB->x());// / dt;
  dy = (vE->y() - vB->y());// / dt;
  dz = (vE->z() - vB->z());// / dt;

  SVector3 der(dx, dy, dz);
  return der;
}

double discreteEdge::curvature(double par) const
{
  Msg::Error("Curvature for discrete edge not implemented yet");
  return 0.;
}

double discreteEdge::curvatures(const double par, SVector3 *dirMax, SVector3 *dirMin,
                                double *curvMax, double *curvMin) const
{
  Msg::Error("Cannot evaluate curvatures and curvature directions on discrete edge");
  return false;
}

Range<double> discreteEdge::parBounds(int i) const
{
  return Range<double>(0, (double)discrete_lines.size());
}

void discreteEdge::createGeometry()
{
  if (discrete_lines.empty()){

    createTopo();

    bool reverse = lines[0]->getVertex(0) == getEndVertex()->mesh_vertices[0];

    // copy the mesh
    for (unsigned int i = 0; i < mesh_vertices.size(); i++){
      MEdgeVertex *v = new MEdgeVertex(mesh_vertices[i]->x(), mesh_vertices[i]->y(),
                                       mesh_vertices[i]->z(), this, (double)(i+1));
      v2v[mesh_vertices[i]] = v;
    }

    std::vector<MLine*> _temp;
    for (unsigned int i = 0; i < lines.size(); i++){
      MVertex *v0 = lines[i]->getVertex(0);
      MVertex *v1 = lines[i]->getVertex(1);
      MVertex *v00 = (v2v.find(v0) == v2v.end()) ? v0 : v2v[v0];
      MVertex *v01 = (v2v.find(v1) == v2v.end()) ? v1 : v2v[v1];
      if (reverse)
	discrete_lines.insert(discrete_lines.begin(), new MLine(v01,v00));
      else
	discrete_lines.push_back(new MLine(v00,v01));

    }
    // compute parameters and recompute the vertices
    _pars.push_back(0.0);
    for (unsigned int i = 1; i < discrete_lines.size(); i++){
      _pars.push_back((double)i);
      MVertex *newv = discrete_lines[i]->getVertex(0);
      discrete_vertices.push_back(newv);
    }
    _pars.push_back((double)discrete_lines.size());
    mesh_vertices.clear();
    lines.clear();
  }
}

MVertex * discreteEdge::getGeometricalVertex (MVertex *v)
{
  printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAARGHHHH\n");


  std::map<MVertex*,MVertex*>::const_iterator it = v2v.find(v);
  if (it == v2v.end()){
    Msg::Error("fatality %ld %ld %ld", v2v.size(), mesh_vertices.size(),
               discrete_vertices.size());
  }
  return it->second;
}

void discreteEdge::interpolateInGeometry(MVertex *v, MVertex **v1,
                                         MVertex **v2, double &xi) const
{
  double t;
  if (v->onWhat() != this)Msg::Fatal("%s %d",__FILE__,__LINE__);
  v->getParameter (0,t);
  int i = (int) t;
  MLine *l = discrete_lines [i];
  *v1 = l->getVertex(0);
  *v2 = l->getVertex(1);
  xi = t - i;
}

void discreteEdge::mesh(bool verbose)
{
#if defined(HAVE_MESH)
  if (!CTX::instance()->meshDiscrete) return;
  meshGEdge mesher;
  mesher(this);
#endif
}

void discreteEdge::writeGEO(FILE *fp)
{
  if (getBeginVertex() && getEndVertex())
    fprintf(fp, "Discrete Line(%d) = {%d,%d};\n", tag(),
            getBeginVertex()->tag(), getEndVertex()->tag());
}
