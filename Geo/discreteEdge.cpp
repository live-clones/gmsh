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
#include "OS.h"
#include "Curvature.h"
#include "GEdgeCompound.h"

#if defined(HAVE_MESH)
#include "meshGEdge.h"
#include "Context.h"
#endif

discreteEdge::discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1)
  : GEdge(model, num, _v0, _v1)
{
  createdTopo = false;
  Curve *c = Create_Curve(num, MSH_SEGM_DISCRETE, 0, 0, 0, -1, -1, 0., 1.);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
}

// topology is already set
void discreteEdge::setTopo(std::vector<MLine*> mlines)
{
  createdTopo = true;
  lines = mlines;
  _orientation = std::vector<int>(lines.size(),1);
}

void discreteEdge::createTopo()
{
  if(!createdTopo){
    orderMLines();
    setBoundVertices();
    createdTopo = true;
  }
}

// FULL OF BUGS !!!!!!
void discreteEdge::orderMLines()
{
  //printf("ordering line %d (%d,%d)\n", tag(),getBeginVertex()->mesh_vertices[0]->getNum(),getEndVertex()->mesh_vertices[0]->getNum());
  //if(lines.size() <= 1) return;

  std::vector<MLine*> _m;
  std::list<MLine*> segments;

  // store all lines in a list : segments
  for (unsigned int i = 0; i < lines.size(); i++) segments.push_back(lines[i]);

  // find a lonly MLine
  for (std::list<MLine*>::iterator it = segments.begin();
       it != segments.end(); ++it){
    MVertex *vL = (*it)->getVertex(0);
    MVertex *vR = (*it)->getVertex(1);

    std::map<MVertex*,MLine*>::iterator it1 = boundv.find(vL);
    if (it1 == boundv.end()) boundv.insert(std::make_pair(vL,*it));
    else  boundv.erase(it1);
    std::map<MVertex*,MLine*>::iterator it2 = boundv.find(vR);
    if (it2 == boundv.end()) boundv.insert(std::make_pair(vR,*it));
    else boundv.erase(it2);
  }
  // find the first MLine and erase it from the list segments

  MLine *firstLine;
  if (boundv.size() == 2){   // non periodic
    firstLine = (boundv.begin())->second;
    for (std::list<MLine*>::iterator it = segments.begin();
         it != segments.end(); ++it){
      if (*it == firstLine){
        segments.erase(it);
        break;
      }
    }
  }
  else if (boundv.size() == 0){ // periodic
    firstLine = *(segments.begin());
    segments.erase(segments.begin());
  }
  else{
    Msg::Error("EdgeCompound %d is wrong (it has %d end points)",
               tag(), boundv.size());
  }
  // loop over all segments to order segments and store it in the list _m
  _m.push_back(firstLine);
  _orientation.push_back(1);
  MVertex *first = _m[0]->getVertex(0);
  MVertex *last = _m[0]->getVertex(1);
  while (first != last){
    if (segments.empty()) break;
    bool found = false;
    for (std::list<MLine*>::iterator it = segments.begin();
         it != segments.end(); ++it){
      MLine *e = *it;
      if (e->getVertex(0) == last){
        _m.push_back(e);
        segments.erase(it);
        _orientation.push_back(1);
        last = e->getVertex(1);
        found = true;
        break;
      }
      else if (e->getVertex(1) == last){
        _m.push_back(e);
        segments.erase(it);
        _orientation.push_back(0);
        last = e->getVertex(0);
        found = true;
        break;
      }
    }
    if (!found  && _orientation[0]==1){ //reverse orientation of first Line
      if (_m.size() == 1 ){
        MVertex *temp = first;
        first = last;
        last = temp;
        _orientation[0] = 0;
      }
      else {
        Msg::Error("Discrete Edge %d is wrong",tag());
        return;
      }
    }
  }

  //lines is now a list of ordered MLines
  lines = _m;

  //mesh_vertices
  mesh_vertices.clear();
  for (unsigned int i = 0; i < lines.size()-1; ++i){
     MVertex *v1 = lines[i]->getVertex(0);
     MVertex *v2 = lines[i]->getVertex(1);
    if (std::find(mesh_vertices.begin(), mesh_vertices.end(), v1) ==
        mesh_vertices.end()) mesh_vertices.push_back(v1);
    if (std::find(mesh_vertices.begin(), mesh_vertices.end(), v2) ==
        mesh_vertices.end()) mesh_vertices.push_back(v2);
  }


  //special case reverse orientation
  if (lines.size() < 2) return;
  if (_orientation[0] && lines[0]->getVertex(1) != lines[1]->getVertex(1)
      && lines[0]->getVertex(1) != lines[1]->getVertex(0)){
    for (unsigned int i = 0; i < lines.size(); i++)
      _orientation[i] = !_orientation[i];
  }
}

void discreteEdge::setBoundVertices()
{
  if (boundv.size() == 2){
    std::vector<GVertex*> bound_vertices;
    for (std::map<MVertex*,MLine*>::const_iterator iter = boundv.begin();
         iter != boundv.end(); iter++){
      MVertex* vE = (iter)->first;
      bool existVertex  = false;
      for(GModel::viter point = model()->firstVertex();
          point != model()->lastVertex(); point++){
        if ((*point)->mesh_vertices[0]->getNum() == vE->getNum()){
          bound_vertices.push_back((*point));
          existVertex = true;
          break;
        }
      }
      if(!existVertex){
        GVertex *gvB = new discreteVertex
          (model(), model()->getMaxElementaryNumber(0) + 1);
        //printf("*** Created discreteVertex %d\n", gvB->tag());
        bound_vertices.push_back(gvB);
        vE->setEntity(gvB);
        gvB->mesh_vertices.push_back(vE);
        gvB->points.push_back(new MPoint(gvB->mesh_vertices.back()));
        model()->add(gvB);
      }
      std::vector<MVertex*>::iterator itve =
        std::find(mesh_vertices.begin(), mesh_vertices.end(), vE);
      if (itve != mesh_vertices.end()) mesh_vertices.erase(itve);

      for(GModel::eiter edge = model()->firstEdge(); edge != model()->lastEdge(); edge++){
        std::vector<MVertex*>::iterator itve =
          std::find((*edge)->mesh_vertices.begin(), (*edge)->mesh_vertices.end(), vE);
        if (itve != (*edge)->mesh_vertices.end()) (*edge)->mesh_vertices.erase(itve);
      }
      for(GModel::fiter face = model()->firstFace(); face != model()->lastFace(); face++){
        std::vector<MVertex*>::iterator itve =
          std::find((*face)->mesh_vertices.begin(), (*face)->mesh_vertices.end(), vE);
        if (itve != (*face)->mesh_vertices.end()) (*face)->mesh_vertices.erase(itve);
      }
      for(GModel::riter reg = model()->firstRegion(); reg != model()->lastRegion(); reg++){
        std::vector<MVertex*>::iterator itve =
          std::find((*reg)->mesh_vertices.begin(), (*reg)->mesh_vertices.end(), vE);
        if (itve != (*reg)->mesh_vertices.end()) (*reg)->mesh_vertices.erase(itve);
      }

    }
    v0 = bound_vertices[0];
    v1 = bound_vertices[1];
  }
  else if (boundv.size() == 0){
    GVertex* bound_vertex;
    std::vector<MLine*>::const_iterator it = lines.begin();
    MVertex* vE = (*it)->getVertex(0);
    bool existVertex  = false;
    for(GModel::viter point = model()->firstVertex();
        point != model()->lastVertex(); point++){
      if ((*point)->mesh_vertices[0]->getNum() == vE->getNum()){
        bound_vertex = (*point);
        existVertex = true;
        //printf("vertex exist (%g,%g,%g)\n", vE->x(), vE->y(), vE->z());
        break;
      }
    }
    if(!existVertex){
      GVertex *gvB = new discreteVertex
        (model(), model()->getMaxElementaryNumber(0) + 1);
      //printf("*** Created discreteVertex %d\n", gvB->tag());
      bound_vertex = gvB;
      vE->setEntity(gvB);
      gvB->mesh_vertices.push_back(vE);
      gvB->points.push_back(new MPoint(gvB->mesh_vertices.back()));
      model()->add(gvB);
    }
    std::vector<MVertex*>::iterator itve =
      std::find(mesh_vertices.begin(),mesh_vertices.end(), vE);
    if (itve != mesh_vertices.end()) mesh_vertices.erase(itve);

    for(GModel::eiter edge = model()->firstEdge();
        edge != model()->lastEdge(); edge++){
      std::vector<MVertex*>::iterator itve =
        std::find((*edge)->mesh_vertices.begin(), (*edge)->mesh_vertices.end(), vE);
      if (itve != (*edge)->mesh_vertices.end()) (*edge)->mesh_vertices.erase(itve);
    }
    for(GModel::fiter face = model()->firstFace();
        face != model()->lastFace(); face++){
      std::vector<MVertex*>::iterator itve =
        std::find((*face)->mesh_vertices.begin(), (*face)->mesh_vertices.end(), vE);
      if (itve != (*face)->mesh_vertices.end()) (*face)->mesh_vertices.erase(itve);
    }
    for(GModel::riter reg = model()->firstRegion();
        reg != model()->lastRegion(); reg++){
      std::vector<MVertex*>::iterator itve =
        std::find((*reg)->mesh_vertices.begin(), (*reg)->mesh_vertices.end(), vE);
      if (itve != (*reg)->mesh_vertices.end()) (*reg)->mesh_vertices.erase(itve);
    }

    v0 = bound_vertex;
    v1 = bound_vertex;
  }

  v0->addEdge(this);
  v1->addEdge(this);
}

/*
    +---------------+--------------+----------- ... ----------+
    _pars[0]=0   _pars[1]=1    _pars[2]=2             _pars[N+1]=N+1
*/
void discreteEdge::parametrize(std::map<GFace*, std::map<MVertex*, MVertex*,
                               std::less<MVertex*> > > &face2Vert,
                               std::map<GRegion*, std::map<MVertex*, MVertex*,
                               std::less<MVertex*> > > &region2Vert)
{
  if (_pars.empty()){
    for (unsigned int i = 0; i < lines.size() + 1; i++){
      _pars.push_back(i);
    }
  }
  //Replace MVertex by MedgeVertex
  std::map<MVertex*, MVertex*, std::less<MVertex*> > old2new;
  old2new.clear();
  std::vector<MVertex* > newVertices;
  std::vector<MLine*> newLines;

  MVertex *vL = getBeginVertex()->mesh_vertices[0];
  int i = 0;
  for(i = 0; i < (int)lines.size() - 1; i++){
    MVertex *vR = lines[i]->getVertex(_orientation[i]);
    int param = i+1;
    MVertex *vNEW = new MEdgeVertex(vR->x(),vR->y(),vR->z(), this,
                                    param, -1., vR->getNum());
    old2new.insert(std::make_pair(vR,vNEW));
    newVertices.push_back(vNEW);
    newLines.push_back(new MLine(vL, vNEW));
    _orientation[i] = 1;
    vL = vNEW;
  }
  MVertex *vR = getEndVertex()->mesh_vertices[0];
  newLines.push_back(new MLine(vL, vR));
  _orientation[i] = 1;

  deleteVertexArrays();
  model()->destroyMeshCaches();

  mesh_vertices = newVertices;
  lines.clear();
  lines = newLines;

  //  we need to recreate lines, triangles and tets
  //  that contain those new MEdgeVertices

   for(std::list<GFace*>::iterator iFace = l_faces.begin();
       iFace != l_faces.end(); ++iFace){


     face2Vert[*iFace].insert(old2new.begin(),old2new.end());

     // // for each face find correspondane face2Vertex
     // std::map<GFace*, std::map<MVertex*, MVertex*,
     //   std::less<MVertex*> > >::iterator itmap = face2Vert.find(*iFace);
     // if (itmap == face2Vert.end()) {
     //   face2Vert.insert(std::make_pair(*iFace, old2new));
     // }
     // else{
     //   std::map<MVertex*, MVertex*, std::less<MVertex*> > mapVert = itmap->second;
     //   for (std::map<MVertex*, MVertex*, std::less<MVertex*> >::iterator it =
     //          old2new.begin(); it != old2new.end(); it++)
     //     mapVert.insert(*it);
     //   itmap->second = mapVert;
     // }

     // do the same for regions
     for ( int j = 0; j < (*iFace)->numRegions(); j++){
       GRegion *r = (*iFace)->getRegion(j);
       region2Vert[r].insert(old2new.begin(),old2new.end());

       //     std::map<GRegion*,  std::map<MVertex*, MVertex*,
       //       std::less<MVertex*> > >::iterator itmap = region2Vert.find(r);
       //     if (itmap == region2Vert.end()) {
       // region2Vert.insert(std::make_pair(r, old2new));
       //     }
       //     else{
       // std::map<MVertex*, MVertex*, std::less<MVertex*> > mapVert = itmap->second;
       // for (std::map<MVertex*, MVertex*, std::less<MVertex*> >::iterator it =
       //              old2new.begin(); it != old2new.end(); it++)
       //   mapVert.insert(*it);
       // itmap->second = mapVert;
       //     }
     }
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
    if (_orientation[i] == 1 ) vR = lines[i]->getVertex(1);
    else vR = lines[i]->getVertex(0);
    int param = i+1;
    MVertex *vNEW = new MEdgeVertex(vR->x(),vR->y(),vR->z(), this,
                                    param, -1., vR->getNum());
    old2new.insert(std::make_pair(vR,vNEW));
    newVertices.push_back(vNEW);
    newLines.push_back(new MLine(vL, vNEW));
    _orientation[i] = 1;
    vL = vNEW;
  }
  MVertex *vR = getEndVertex()->mesh_vertices[0];
  newLines.push_back(new MLine(vL, vR));
  _orientation[i] = 1;

  deleteVertexArrays();
  model()->destroyMeshCaches();

  mesh_vertices = newVertices;
  lines.clear();
  lines = newLines;
}


void discreteEdge::computeNormals () const
{
  _normals.clear();
  for (unsigned int i= 0; i < mesh_vertices.size(); i++)
    _normals[mesh_vertices[i]] = SVector3(0.0,0.0,0.0);
  _normals[getBeginVertex()->mesh_vertices[0]] = SVector3(0.0,0.0,0.0);
  _normals[getBeginVertex()->mesh_vertices[0]] = SVector3(0.0,0.0,0.0);
  double J[3][3];

  for(std::list<GFace*>::const_iterator iFace = l_faces.begin();
      iFace != l_faces.end(); ++iFace){
    for (unsigned int i = 0; i < (*iFace)->triangles.size(); ++i){
      MTriangle *t = (*iFace)->triangles[i];
      for (int j = 0; j < 3; j++){
        std::map<MVertex*, SVector3, std::less<MVertex*> >::iterator
          itn = _normals.find(t->getVertex(j));
        if (itn != _normals.end()){
          t->getJacobian(0, 0, 0, J);
          SVector3 d1(J[0][0], J[0][1], J[0][2]);
          SVector3 d2(J[1][0], J[1][1], J[1][2]);
          SVector3 n = crossprod(d1, d2);
          n.normalize();
          _normals[t->getVertex(j)] += n;
        }
      }
    }
  }
  std::map<MVertex*,SVector3, std::less<MVertex*> >::iterator itn = _normals.begin();
  for ( ; itn != _normals.end(); ++itn){
    itn->second.normalize();
  }
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
  double tLoc;
  int iEdge;
  if(!getLocalParameter(par, iEdge, tLoc)) return MAX_LC;

  double c0, c1;
  Curvature& curvature  = Curvature::getInstance();
  if( !Curvature::valueAlreadyComputed() ) {
    Msg::Warning("Need to compute discrete curvature (in discreteEdge)");
    Curvature::typeOfCurvature type = Curvature::RUSIN; //RUSIN; //RBF
    curvature.computeCurvature(model(), type);
  }

  curvature.edgeNodalValues(lines[iEdge],c0, c1, 1);
  double cv = (1-tLoc)*c0 + tLoc*c1;

  return cv;
}

double discreteEdge::curvatures(const double par, SVector3 *dirMax, SVector3 *dirMin,
                                double *curvMax, double *curvMin) const
{
  if (getCompound()){
    return getCompound()->curvatures(par, dirMax, dirMin, curvMax, curvMin);
  }
  else{
    Msg::Error("Cannot evaluate curvatures and curvature directions on discrete edge");
    return false;
  }
}

Range<double> discreteEdge::parBounds(int i) const
{
  return Range<double>(0, (double)discrete_lines.size());
}

void discreteEdge::createGeometry()
{
  if (discrete_lines.empty()){

    createTopo();

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
      if (_orientation[i] == 1){
	discrete_lines.push_back(new MLine(v00,v01));
      }
      else{
        lines[i]->setVertex(0, v1);
        lines[i]->setVertex(1, v0);
        _orientation[i] = 1;
	discrete_lines.push_back(new MLine(v01,v00));
      }
    }
    // compute parameters and recompute the vertices
    _pars.push_back(0.0);
    for (unsigned int i = 1; i < discrete_lines.size(); i++){
      _pars.push_back((double)i);
      MVertex *newv = discrete_lines[i]->getVertex(0);
      discrete_vertices.push_back(newv);
    }
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
  /*
  if(tag()==47 || tag() == 50 || tag() == 51 || tag() == 53 || tag() == 56){
    for(unsigned int i =0; i<mesh_vertices.size(); i++){
      double p;
      mesh_vertices[i]->getParameter(0,p);
      printf("%f\t",p);
    }
    printf("\n\n");
  }
  */
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
