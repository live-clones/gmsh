// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
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
  //  return;
  std::vector<MEdge> ed;
  std::vector<std::vector<MVertex*> >vs;
  for (unsigned int i = 0; i < lines.size(); i++) {
    ed.push_back(MEdge(lines[i]->getVertex(0),lines[i]->getVertex(1)));
    delete lines[i];
  }
  lines.clear();
  
  if (!SortEdgeConsecutive (ed,vs))
    Msg::Warning ("Discrete edge segments cannot be ordered");
  
  if (vs.size() != 1) 
    Msg::Warning ("Discrete Edge %d is mutiply connected",tag());
  
  for (unsigned int i = 1; i < vs[0].size(); i++)
    lines.push_back(new MLine(vs[0][i-1],vs[0][i]));  
  
  mesh_vertices.clear();
  for (unsigned int i = 0; i < lines.size()-1; ++i){
     MVertex *v1 = lines[i]->getVertex(1);
     mesh_vertices.push_back(v1);
  }
}


void discreteEdge::parametrize(std::map<MVertex*, MVertex*>& old2new)
{
  if (_pars.empty()){
    for (unsigned int i = 0; i < lines.size() + 1; i++){
      _pars.push_back(i);
    }
  }

  std::vector<MVertex* > newVertices;
  std::vector<MLine*> newLines;

  MVertex *vL = getBeginVertex()->mesh_vertices[0];
  int i = 0;
  for(i = 0; i < (int)lines.size() - 1; i++){
    MVertex *vR;
    vR = lines[i]->getVertex(1);
    int param = i+1;
    MVertex *vNEW = new MEdgeVertex(vR->x(),vR->y(),vR->z(), this,
                                    param, vR->getNum());
    old2new.insert(std::make_pair(vR,vNEW));
    newVertices.push_back(vNEW);
    newLines.push_back(new MLine(vL, vNEW));
    vL = vNEW;
  }
  MVertex *vR = getEndVertex()->mesh_vertices[0];
  newLines.push_back(new MLine(vL, vR));

  deleteVertexArrays();
  model()->destroyMeshCaches();

  mesh_vertices = newVertices;
  lines.clear();
  lines = newLines;
}


/// WE REWRITE WHAT FOLLOWS : THIS WAS WRONG (PAB -JFR)

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
    //    printf("discrete  %d :",tag());    
    for (unsigned int i = 1; i < discrete_lines.size(); i++){
      _pars.push_back((double)i);
      MVertex *newv = discrete_lines[i]->getVertex(0);
      discrete_vertices.push_back(newv);
      //      printf("%d (%g %g)",newv->getNum(),newv->x(),newv->y());
    }
    //    printf("\n");
    _pars.push_back((double)discrete_lines.size());
  }
}

MVertex * discreteEdge::getGeometricalVertex (MVertex *v)
{
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

void discreteEdge::mesh(bool verbose){
#if defined(HAVE_MESH)
  if (!CTX::instance()->meshDiscrete) return;
  //  for(unsigned int i =0; i<discrete_vertices.size(); i++){
  //    double p;
  //    discrete_vertices[i]->getParameter(0,p);
  //    printf("%f\t",p);
  //  }
  //  printf("\n\n");
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
