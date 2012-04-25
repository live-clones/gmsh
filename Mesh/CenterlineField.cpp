// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Emilie Marchandise
//

#include "CenterlineField.h"

#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "OS.h"
#include "GModel.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MVertex.h"
#include "MLine.h"
#include "GEntity.h"
#include "Field.h"
#include "GFace.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "GEdgeCompound.h"
#include "GFaceCompound.h"
#include "meshGFace.h"
#include "meshGEdge.h"
#include "MQuadrangle.h"
#include "MElement.h"
#include "Context.h"
#if defined(HAVE_ANN)
#include <ANN/ANN.h>

#include <algorithm>

void erase(std::vector<MLine*>& lines, MLine* l) {
  std::vector<MLine*>::iterator it = std::remove(lines.begin(), lines.end(), l);
  lines.erase(it, lines.end());
}
double computeLength(std::vector<MLine*> lines){

  double length= 0.0;
  for (unsigned int i = 0; i< lines.size(); i++){
    length += lines[i]->getLength();
  }
  return length;
}

bool isClosed(std::set<MEdge, Less_Edge> &theCut){

  std::multiset<MVertex*> boundV;
  std::set<MEdge,Less_Edge>::iterator it = theCut.begin();
  for (; it!= theCut.end(); it++){
    boundV.insert(it->getVertex(0));
    boundV.insert(it->getVertex(1));
  }
  std::multiset<MVertex*>::iterator itb = boundV.begin();
  for ( ; itb != boundV.end(); ++itb){
    if (boundV.count(*itb) != 2) {
      return false;
    }
  }
  return true;

  // std::list<MEdge> segments;
  // std::map<MVertex*, MEdge> boundv;
  // std::set<MEdge,Less_Edge>::iterator it = theCut.begin();
  // for (; it!= theCut.end(); it++){
  //   segments.push_back(*it);
  // }

  // // find a lonely MEdge
  // for (std::list<MEdge>::iterator it = segments.begin();
  //      it != segments.end(); ++it){
  //   MVertex *vL = it->getVertex(0);
  //   MVertex *vR = it->getVertex(1);
  //   std::map<MVertex*,MEdge>::iterator it1 = boundv.find(vL);
  //   if (it1 == boundv.end()) boundv.insert(std::make_pair(vL,*it));
  //   else  boundv.erase(it1);
  //   std::map<MVertex*,MEdge>::iterator it2 = boundv.find(vR);
  //   if (it2 == boundv.end()) boundv.insert(std::make_pair(vR,*it));
  //   else boundv.erase(it2);
  // }

  // if (boundv.size() == 0) return true;
  // else return false;

}

void orderMLines(std::vector<MLine*> &lines, MVertex *vB, MVertex *vE){

  std::vector<MLine*> _m;
  std::list<MLine*> segments;
  std::map<MVertex*, MLine*> boundv;
  std::vector<int> _orientation;

  // store all lines in a list : segments
  for (unsigned int i = 0; i < lines.size(); i++){
    segments.push_back(lines[i]);
  }

  // find a lonely MLine
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
    MVertex *v = (boundv.begin())->first;
    if ( v == vB) firstLine = (boundv.begin())->second;
    else{
      MVertex *v = (boundv.rbegin())->first;
      if (v == vB) firstLine = (boundv.rbegin())->second;
      else{ Msg::Error("begin vertex not found for branch"); exit(1);}
    }
    for (std::list<MLine*>::iterator it = segments.begin();
         it != segments.end(); ++it){
      if (*it == firstLine){
        segments.erase(it);
        break;
      }
    }
  }
  else{
    Msg::Error("line is wrong (it has %d end points)",  boundv.size());
  }

  // loop over all segments to order segments and store it in the list _m
  _m.push_back(firstLine);
  _orientation.push_back(1);
  MVertex *first = _m[0]->getVertex(0);
  MVertex *last = _m[0]->getVertex(1);
  while (first != last){
    if (segments.empty())break;
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
        Msg::Error("lines is wrong");
        return;
      }
    }
  }

  //lines is now a list of ordered MLines
  lines = _m;

  //special case reverse orientation
  if (lines.size() < 2) return;
  if (_orientation[0] && lines[0]->getVertex(1) != lines[1]->getVertex(1)
      && lines[0]->getVertex(1) != lines[1]->getVertex(0)){
    for (unsigned int i = 0; i < lines.size(); i++)
      _orientation[i] = !_orientation[i];
  }

  // if (junctions.find(lines[0]->getVertex(0)) != junctions.end()) vB =  lines[0]->getVertex(0);
  // else if (junctions.find(lines[0]->getVertex(1)) != junctions.end()) vB =  lines[0]->getVertex(1);
  // else printf("no vB junc found %d %d \n", lines[0]->getVertex(0)->getNum(), lines[0]->getVertex(1)->getNum());
  // if (junctions.find(lines[lines.size()-1]->getVertex(0)) != junctions.end()) vE =  lines[lines.size()-1]->getVertex(0);
  // else if (junctions.find(lines[lines.size()-1]->getVertex(1)) != junctions.end()) vE =  lines[lines.size()-1]->getVertex(1);
  // else printf("no vE junc found %d %d \n", lines[0]->getVertex(0)->getNum(), lines[0]->getVertex(1)->getNum());
  // printf("in order vB= %d =%d \n", vB->getNum(), vE->getNum());
}

static void recurConnectByMEdge(const MEdge &e,
				std::multimap<MEdge, MTriangle*, Less_Edge> &e2e,
				std::set<MTriangle*> &group,
				std::set<MEdge, Less_Edge> &touched,
				std::set<MEdge, Less_Edge> &theCut)
{
  if (touched.find(e) != touched.end()) return;
  touched.insert(e);
  for (std::multimap <MEdge, MTriangle*, Less_Edge>::iterator it = e2e.lower_bound(e);
       it != e2e.upper_bound(e); ++it){
    group.insert(it->second);
    for (int i = 0; i < it->second->getNumEdges(); ++i){
      MEdge me = it->second->getEdge(i);
      if (theCut.find(me) != theCut.end()){
	touched.insert(me); //break;
      }
      else recurConnectByMEdge(me, e2e, group, touched, theCut);
    }
  }
}


void cutTriangle(MTriangle *tri,
		 std::map<MEdge,MVertex*,Less_Edge> &cutEdges,
		 std::set<MVertex*> &cutVertices,
		 std::vector<MTriangle*> &newTris,
		 std::set<MEdge,Less_Edge> &newCut){

  MVertex *c[3] = {0,0,0};
  for (int j=0;j<3;j++){
    MEdge ed = tri->getEdge(j);
    std::map<MEdge,MVertex*,Less_Edge> :: iterator it = cutEdges.find(ed);
    if (it != cutEdges.end()){
      c[j] = it->second;

    }
  }
  MVertex *old_v0  = tri->getVertex(0);
  MVertex *old_v1  = tri->getVertex(1);
  MVertex *old_v2  = tri->getVertex(2);
  if (c[0] && c[1]){
    newTris.push_back(new MTriangle (c[0],old_v1,c[1]));
    newTris.push_back(new MTriangle (old_v0,c[0],old_v2));
    newTris.push_back(new MTriangle (old_v2,c[0],c[1]));
    newCut.insert(MEdge(c[0],c[1]));
  }
  else if (c[0] && c[2]){
    newTris.push_back(new MTriangle (old_v0,c[0],c[2]));
    newTris.push_back(new MTriangle (c[0],old_v1,old_v2));
    newTris.push_back(new MTriangle (old_v2,c[2],c[0]));
    newCut.insert(MEdge(c[0],c[2]));
  }
  else if (c[1] && c[2]){
    newTris.push_back(new MTriangle (old_v2,c[2],c[1]));
    newTris.push_back(new MTriangle (old_v0,old_v1,c[2]));
    newTris.push_back(new MTriangle (c[2],old_v1,c[1]));
    newCut.insert(MEdge(c[1],c[2]));
  }
  else if (c[0]){
    newTris.push_back(new MTriangle (old_v0,c[0],old_v2));
    newTris.push_back(new MTriangle (old_v2,c[0],old_v1));
    if (cutVertices.find (old_v0) != cutVertices.end()){
      newCut.insert(MEdge(c[0],old_v0));
    }
    else if (cutVertices.find (old_v1) != cutVertices.end()) {
      newCut.insert(MEdge(c[0],old_v1));
    }
    else if (cutVertices.find (old_v2) != cutVertices.end()){
      newCut.insert(MEdge(c[0],old_v2));
    }
  }
  else if (c[1]){
    newTris.push_back(new MTriangle (old_v1,c[1],old_v0));
    newTris.push_back(new MTriangle (old_v0,c[1],old_v2));
    if (cutVertices.find (old_v0) != cutVertices.end()){
      newCut.insert(MEdge(c[1],old_v0));
    }
    else if (cutVertices.find (old_v1) != cutVertices.end()) {
      newCut.insert(MEdge(old_v1, c[1]));
    }
    else if (cutVertices.find (old_v2) != cutVertices.end()){
      newCut.insert(MEdge(c[1],old_v2));
    }
  }
  else if (c[2]){
      newTris.push_back(new MTriangle (old_v0,old_v1, c[2]));
      newTris.push_back(new MTriangle (old_v1,old_v2, c[2]));
    if (cutVertices.find (old_v0) != cutVertices.end()){
      newCut.insert(MEdge(c[2],old_v0));
    }
    else if (cutVertices.find (old_v1) != cutVertices.end()) {
      newCut.insert(MEdge(c[2], old_v1));
    }
    else if (cutVertices.find (old_v2) != cutVertices.end()){
      newCut.insert(MEdge(c[2], old_v2));
    }
  }
  else {
    newTris.push_back(tri);
    //newTris.push_back(new MTriangle (old_v0, old_v1,old_v2));
    if (cutVertices.find (old_v0) != cutVertices.end() &&
	cutVertices.find (old_v1) != cutVertices.end())
      newCut.insert(MEdge(old_v0,old_v1));
    else if (cutVertices.find (old_v1) != cutVertices.end() &&
	cutVertices.find (old_v2) != cutVertices.end())
      newCut.insert(MEdge(old_v1,old_v2));
    else if (cutVertices.find (old_v2) != cutVertices.end() &&
	cutVertices.find (old_v0) != cutVertices.end())
      newCut.insert(MEdge(old_v2,old_v0));
  }
}

Centerline::Centerline(std::string fileName): kdtree(0), kdtreeR(0), nodes(0), nodesR(0){

  recombine = CTX::instance()->mesh.recombineAll;

  index = new ANNidx[1];
  dist = new ANNdist[1];

  printf("centerline filename =%s \n", fileName.c_str());
  importFile(fileName);
  buildKdTree();
  nbPoints = 25;
  hLayer = 0.3;
  nbElemLayer = 3;

  update_needed = false;
  is_cut = 0;
  is_closed = 0;
  is_extruded = 0;

}
Centerline::Centerline(): kdtree(0), kdtreeR(0), nodes(0), nodesR(0){

  index = new ANNidx[1];
  dist = new ANNdist[1];

  recombine = CTX::instance()->mesh.recombineAll;
  fileName = "centerlines.vtk";//default
  nbPoints = 25;
  hLayer = 0.3;
  nbElemLayer = 3;
  is_cut = 0;
  is_closed = 0;
  is_extruded = 0;

  // callbacks["closeVolume"] = new FieldCallbackGeneric<Centerline>(this, &Centerline::closeVolume, "Create In/Outlet planar faces \n");
  // callbacks["extrudeWall"] = new FieldCallbackGeneric<Centerline>(this, &Centerline::extrudeWall, "Extrude wall \n");
  // callbacks["cutMesh"] = new FieldCallbackGeneric<Centerline>(this, &Centerline::cutMesh, "Cut the initial mesh in different mesh partitions using the centerlines \n");

  options["closeVolume"] = new FieldOptionInt(is_closed, "Action: Create In/Outlet planar faces");
  options["extrudeWall"] = new FieldOptionInt(is_extruded, "Action: Extrude wall");
  options["cutMesh"] = new FieldOptionInt(is_cut, "Action: Cut the initial mesh in different mesh partitions using the centerlines");
  callbacks["run"] = new FieldCallbackGeneric<Centerline>(this, &Centerline::run, "Run actions (closeVolume, extrudeWall, cutMesh) \n");

  options["FileName"] = new FieldOptionString (fileName, "File name for the centerlines", &update_needed);
  options["nbPoints"] = new FieldOptionInt(nbPoints, "Number of mesh elements in a circle");
  options["nbElemLayer"] = new FieldOptionInt(nbElemLayer, "Number of mesh elements the extruded layer");
  options["hLayer"] = new FieldOptionDouble(hLayer, "Thickness (% of radius) of the extruded layer");

}

Centerline::~Centerline(){
  if (mod) delete mod;
  if(kdtree) delete kdtree;
  if(kdtreeR) delete kdtreeR;
  if(nodes) annDeallocPts(nodes);
  if(nodesR) annDeallocPts(nodesR);
  delete[]index;
  delete[]dist;
  
}

void Centerline::importFile(std::string fileName){

  current = GModel::current();
  std::vector<GFace*> currentFaces = current->bindingsGetFaces();
  for (unsigned int i = 0; i < currentFaces.size(); i++){
    GFace *gf = currentFaces[i];
     if (gf->geomType() == GEntity::DiscreteSurface){
     	for(unsigned int j = 0; j < gf->triangles.size(); j++)
     	  triangles.push_back(gf->triangles[j]);
	if (is_cut){
	  gf->triangles.clear();
	  gf->deleteVertexArrays();
	  current->remove(gf);
	}
     }
  }

  if(triangles.empty()){
    Msg::Error("Current GModel has no triangles ...");
    exit(1);
  }

  mod = new GModel();
  mod->load(fileName);
  mod->removeDuplicateMeshVertices(1.e-8);
  current->setAsCurrent();

  int maxN = 0.0;
  std::vector<GEdge*> modEdges = mod->bindingsGetEdges();
  MVertex *vin = modEdges[0]->lines[0]->getVertex(0);
  ptin = SPoint3(vin->x(), vin->y(), vin->z());
  for (unsigned int i = 0; i < modEdges.size(); i++){
    GEdge *ge = modEdges[i];
    for(unsigned int j = 0; j < ge->lines.size(); j++){
      MLine *l = ge->lines[j];
      MVertex *v0 = l->getVertex(0);
      MVertex *v1 = l->getVertex(1);
      std::map<MVertex*, int>::iterator it0 = colorp.find(v0);
      std::map<MVertex*, int>::iterator it1 = colorp.find(v1);
      if (it0 == colorp.end() || it1 == colorp.end()){
	lines.push_back(l);
	colorl.insert(std::make_pair(l, ge->tag()));
	maxN = std::max(maxN, ge->tag());
       }
      if (it0 == colorp.end()) colorp.insert(std::make_pair(v0, ge->tag()));
      if (it1 == colorp.end()) colorp.insert(std::make_pair(v1, ge->tag()));
    }
 }

  createBranches(maxN);

}


void Centerline::createBranches(int maxN){

  //sort colored lines and create edges
  std::vector<std::vector<MLine*> > color_edges;
  color_edges.resize(maxN);
  std::multiset<MVertex*> allV;
  std::map<MLine*, int>::iterator itl = colorl.begin();
  while (itl != colorl.end()){
    int color = itl->second;
    MLine* l = itl->first;
    allV.insert(l->getVertex(0));
    allV.insert(l->getVertex(1));
    color_edges[color-1].push_back(l);
    itl++;
  }

  //detect junctions
  std::multiset<MVertex*>::iterator it = allV.begin();
  for ( ; it != allV.end(); ++it){
    if (allV.count(*it) != 2) {
      junctions.insert(*it);
    }
  }

  //split edges
  int tag = 0;
  for(unsigned int i = 0; i < color_edges.size(); ++i){
    std::vector<MLine*> lines = color_edges[i];
    while (!lines.empty()) {
      std::vector<MLine*> myLines;
      std::vector<MLine*>::iterator itl = lines.begin();
      MVertex *vB = (*itl)->getVertex(0);
      MVertex *vE = (*itl)->getVertex(1);
      myLines.push_back(*itl);
      erase(lines, *itl);
      itl = lines.begin();
      while ( !( junctions.find(vE) != junctions.end() &&
		 junctions.find(vB) != junctions.end()) ) {
  	MVertex *v1 = (*itl)->getVertex(0);
  	MVertex *v2 = (*itl)->getVertex(1);
	bool goVE = (junctions.find(vE) == junctions.end()) ? true : false ;
	bool goVB = (junctions.find(vB) == junctions.end()) ? true : false;
      	if (v1 == vE && goVE){
    	  myLines.push_back(*itl);
  	  erase(lines, *itl);
	  itl = lines.begin();
  	  vE = v2;
  	}
  	else if ( v2 == vE && goVE){
    	  myLines.push_back(*itl);
  	  erase(lines, *itl);
	  itl = lines.begin();
  	  vE = v1;
  	}
  	else if ( v1 == vB && goVB){
    	  myLines.push_back(*itl);
  	  erase(lines, *itl);
	  itl = lines.begin();
  	  vB = v2;
  	}
  	else if ( v2 == vB && goVB){
   	  myLines.push_back(*itl);
	  erase(lines, *itl);
	  itl = lines.begin();
  	  vB = v1;
  	}
	else itl++;
      }
      if (vB == vE) { Msg::Error("Begin and end points branch are the same \n");break;}
      orderMLines(myLines, vB, vE);
      std::vector<Branch> children;
      Branch newBranch ={ tag++, myLines, computeLength(myLines), vB, vE, children, 1.e6, 0.0};
      edges.push_back(newBranch) ;
    }
  }
  printf("*** Centerline in/outlets =%d branches =%d \n", (int)color_edges.size()+1, (int)edges.size());

  //create children
  for(unsigned int i = 0; i < edges.size(); ++i) {
    MVertex *vE = edges[i].vE;
    std::vector<Branch> myChildren;
    for (std::vector<Branch>::iterator it = edges.begin(); it != edges.end(); ++it){
      Branch myBranch = *it;
      if (myBranch.vB == vE) myChildren.push_back(myBranch);
    }
    edges[i].children = myChildren;
  }

  //compute radius
  distanceToSurface();
  computeRadii();

  //print for debug
  printSplit();

}

void Centerline::distanceToSurface(){
  Msg::Info("Centerline: computing distance to surface mesh ");

  //COMPUTE WITH REVERSE ANN TREE (SURFACE POINTS IN TREE)
  std::set<MVertex*> allVS;
  for(unsigned int j = 0; j < triangles.size(); j++)
    for(int k = 0; k<3; k++) allVS.insert(triangles[j]->getVertex(k));
  int nbSNodes = allVS.size();
  nodesR = annAllocPts(nbSNodes, 3);
  int ind = 0;
  std::set<MVertex*>::iterator itp = allVS.begin();
  while (itp != allVS.end()){
    MVertex *v = *itp;
    nodesR[ind][0] = v->x();
    nodesR[ind][1] = v->y();
    nodesR[ind][2] = v->z();
    itp++; ind++;
  }
  kdtreeR = new ANNkd_tree(nodesR, nbSNodes, 3);

  for(unsigned int i = 0; i < lines.size(); i++){
    MLine *l = lines[i];
    MVertex *v1 = l->getVertex(0);
    MVertex *v2 = l->getVertex(1);
    double midp[3] = {0.5*(v1->x()+v2->x()), 0.5*(v1->y()+v1->y()),0.5*(v1->z()+v2->z())};
    kdtreeR->annkSearch(midp, 1, index, dist);
    double minRad = sqrt(dist[0]);
    radiusl.insert(std::make_pair(lines[i], minRad));
  }

}
void Centerline::computeRadii(){

  for(unsigned int i = 0; i < edges.size(); ++i) {
    std::vector<MLine*> lines = edges[i].lines;
    for(unsigned int j = 0; j < lines.size(); ++j) {
      MLine *l = lines[j];
      std::map<MLine*,double>::iterator itr = radiusl.find(l);
      if (itr != radiusl.end()){
	edges[i].minRad = std::min(itr->second, edges[i].minRad);
	edges[i].maxRad = std::max(itr->second, edges[i].maxRad);
      }
      else printf("ARGG line not found \n");
    }
  }

}
void Centerline::buildKdTree(){

  FILE * f = fopen("myPOINTS.pos","w");
  fprintf(f, "View \"\"{\n");

  int nbPL = 3;  //10 points per line
  //int nbNodes  = (lines.size()+1) + (nbPL*lines.size());
  int nbNodes  = (colorp.size()) + (nbPL*lines.size());

  nodes = annAllocPts(nbNodes, 3);
  int ind = 0;
  std::map<MVertex*, int>::iterator itp = colorp.begin();
  while (itp != colorp.end()){
     MVertex *v = itp->first;
     nodes[ind][0] = v->x();
     nodes[ind][1] = v->y();
     nodes[ind][2] = v->z();
     itp++; ind++;
  }
  for(unsigned int k = 0; k < lines.size(); ++k){
   MVertex *v0 = lines[k]->getVertex(0);
   MVertex *v1 = lines[k]->getVertex(1);
   SVector3 P0(v0->x(),v0->y(), v0->z());
   SVector3 P1(v1->x(),v1->y(), v1->z());
   for (int j= 1; j < nbPL+1; j++){
     double inc = (double)j/(double)(nbPL+1);
     SVector3 Pj = P0+inc*(P1-P0);
     nodes[ind][0] = Pj.x();
     nodes[ind][1] = Pj.y();
     nodes[ind][2] = Pj.z();
     ind++;
   }
 }

 kdtree = new ANNkd_tree(nodes, nbNodes, 3);

 for(int i = 0; i < nbNodes; ++i){
   fprintf(f, "SP(%g,%g,%g){%g};\n",
	   nodes[i][0], nodes[i][1],nodes[i][2],1.0);
 }
 fprintf(f,"};\n");
 fclose(f);

}

void Centerline::createSplitCompounds(){

  //number of discrete vertices, edges, faces and regions for the mesh
  NV = current->getMaxElementaryNumber(0);
  NE = current->getMaxElementaryNumber(1);
  NF = current->getMaxElementaryNumber(2);
  NR = current->getMaxElementaryNumber(3);

  // Remesh new faces (Compound Lines and Compound Surfaces)
  Msg::Info("Centerline: create split compounds:");

  //Parametrize Compound Lines
  for (int i=0; i < NE; i++){
    std::vector<GEdge*>e_compound;
    GEdge *pe = current->getEdgeByTag(i+1);//current edge
    e_compound.push_back(pe);
    int num_gec = NE+i+1;
    Msg::Info("Create Compound Line (%d) = %d discrete edge",
              num_gec, pe->tag());
    GEdge *gec = current->addCompoundEdge(e_compound,num_gec);
    //GEdgeCompound *gec = new GEdgeCompound(current, num_gec, e_compound);
    //current->add(gec);
  }

  // Parametrize Compound surfaces
  std::list<GEdge*> U0;
  for (int i=0; i < NF; i++){
    std::vector<GFace*> f_compound;
    GFace *pf =  current->getFaceByTag(i+1);//current face
    f_compound.push_back(pf);
    int num_gfc = NF+i+1;
    Msg::Info("Create Compound Surface (%d) = %d discrete face",
              num_gfc, pf->tag());

    GFace *gfc = current->addCompoundFace(f_compound, 7, 0, num_gfc); //1=conf_spectral 4=convex_circle
    ////GFaceCompound::typeOfCompound typ = GFaceCompound::CONVEX_CIRCLE; 
    ////GFaceCompound::typeOfCompound typ = GFaceCompound::HARMONIC_PLANE; 
    //GFaceCompound::typeOfCompound typ = GFaceCompound::CONFORMAL_SPECTRAL; 
    //GFaceCompound *gfc = new GFaceCompound(current, num_gfc, f_compound, U0,typ, 0);
    //current->add(gfc);

    gfc->meshAttributes.recombine = recombine;
    gfc->addPhysicalEntity(100);
    current->setPhysicalName("wall", 2, 100);

  }

}

void Centerline::cleanMesh(){


  return;  // does not work yet !
  ////////////////////////////////

  if (!is_cut || !is_closed) return;

  for (int i=0; i < NF; i++){
    std::ostringstream oss;
    oss << "new" << NF+i+1 ;
    std::string name = oss.str();
    current->setPhysicalName(name, 2, i+1);
  }
  Msg::Info("Writing new splitted mesh mySPLITMESH.msh");
  current->writeMSH("mySPLITMESH.msh", 2.2, false, false);

  std::set<MVertex*> allNod;
  discreteFace * mySplitMesh;
  std::vector<std::set<MVertex*> > inOutNod;
  std::vector<discreteFace* > inOutMesh;

  mySplitMesh= new discreteFace(current, 2*NF+1);
  mySplitMesh->addPhysicalEntity(2*NF+1);
  current->setPhysicalName("surface mesh", 2, 2*NF+1);
  current->add(mySplitMesh);
  for (unsigned int i=0; i < discFaces.size(); i++){
    GFace *gfc =  current->getFaceByTag(NF+i+1);
    for(unsigned int j = 0; j < gfc->triangles.size(); ++j){
      MTriangle *t = gfc->triangles[j];
      std::vector<MVertex *> v(3);
      for(int k = 0; k < 3; k++){
	v[k] = t->getVertex(k);
	allNod.insert(v[k]);
      }
      mySplitMesh->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
    }
    for(unsigned int j = 0; j < gfc->quadrangles.size(); ++j){
      MQuadrangle *q = gfc->quadrangles[j];
      std::vector<MVertex *> v(4);
      for(int k = 0; k < 4; k++){
	v[k] = q->getVertex(k);
	allNod.insert(v[k]);
      }
      mySplitMesh->quadrangles.push_back(new MQuadrangle(v[0], v[1], v[2], v[3]));
    }
  }

  //Removing discrete Vertices - Edges - Faces
  for (int i=0; i < NV; i++){
    GVertex *gv = current->getVertexByTag(i+1);
    current->remove(gv);
  }
  for (int i=0; i < NE; i++){
    GEdge *ge = current->getEdgeByTag(i+1);
    GEdge *gec = current->getEdgeByTag(NE+i+1);
    current->remove(ge);
    current->remove(gec);
  }
  for (int i=0; i < NF; i++){
    GFace *gf  = current->getFaceByTag(i+1);
    current->remove(gf);
  }
  for (unsigned int i=0; i < discFaces.size(); i++){
    GFace *gfc = current->getFaceByTag(NF+i+1);
    current->remove(gfc);
  }

  //Put new mesh in a new discreteFace
 for(std::set<MVertex*>::iterator it = allNod.begin(); it != allNod.end(); ++it)
   mySplitMesh->mesh_vertices.push_back(*it);
 mySplitMesh->meshStatistics.status = GFace::DONE;

 current->createTopologyFromMesh();

}
void Centerline::createFaces(){

  std::vector<std::vector<MTriangle*> > faces;

  std::multimap<MEdge, MTriangle*, Less_Edge> e2e;
  for(unsigned int i = 0; i < triangles.size(); ++i)
    for(int j = 0; j < 3; j++)
      e2e.insert(std::make_pair(triangles[i]->getEdge(j), triangles[i]));
  while(!e2e.empty()){
    std::set<MTriangle*> group;
    std::set<MEdge, Less_Edge> touched;
    group.clear();
    touched.clear();
    std::multimap<MEdge, MTriangle*, Less_Edge>::iterator ite = e2e.begin();
    MEdge me = ite->first;
    while (theCut.find(me) != theCut.end()){
      ite++;
      me = ite->first;
    }
    recurConnectByMEdge(me,e2e, group, touched, theCut);
    std::vector<MTriangle*> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    faces.push_back(temp);
    for(std::set<MEdge, Less_Edge>::iterator it = touched.begin();
        it != touched.end(); ++it)
      e2e.erase(*it);
  }
  Msg::Info("Centerline action (cutMesh) has cut surface mesh in %d faces ", (int)faces.size());

  //create discFaces
  for(unsigned int i = 0; i < faces.size(); ++i){
    int numF = current->getMaxElementaryNumber(2) + 1;
    discreteFace *f = new discreteFace(current, numF);
    current->add(f);
    discFaces.push_back(f);
    std::set<MVertex*> myVertices;
    std::vector<MTriangle*> myFace = faces[i];
    for(unsigned int j= 0; j< myFace.size(); j++){
      MTriangle *t = myFace[j];
      f->triangles.push_back(t);
      for (int k= 0; k< 3; k++){
	MVertex *v = t->getVertex(k);
	myVertices.insert(v);
	v->setEntity(f);
      }
    }
    f->mesh_vertices.insert(f->mesh_vertices.begin(),
  			    myVertices.begin(), myVertices.end());
  }

}

void Centerline::createClosedVolume(){

  //identify the boundary edges by looping over all discreteFaces
  std::vector<GEdge*> boundEdges;
  double dist_inlet = 1.e6;
  GEdge *gin = NULL;
  for (int i= 0; i< NF; i++){
    GFace *gf = current->getFaceByTag(i+1);
    std::list<GEdge*> l_edges = gf->edges();
    for(std::list<GEdge*>::iterator it = l_edges.begin(); it != l_edges.end(); it++){
      std::vector<GEdge*>::iterator ite = std::find(boundEdges.begin(), boundEdges.end(), *it);
      if (ite != boundEdges.end()) boundEdges.erase(ite);
      else boundEdges.push_back(*it);
      GVertex *gv = (*it)->getBeginVertex();
      SPoint3 pt(gv->x(), gv->y(), gv->z());
      double dist = pt.distance(ptin);
      if(dist < dist_inlet){
	dist_inlet = dist;
	gin = *it;
      }			      
    }
  }
 
  current->setFactory("Gmsh");
  std::vector<std::vector<GFace *> > myFaceLoops;
  std::vector<GFace *> myFaces;
  for (unsigned int i = 0; i<  boundEdges.size(); i++){
    std::vector<std::vector<GEdge *> > myEdgeLoops;
    std::vector<GEdge *> myEdges;
    GEdge * gec;
    if(is_cut) gec = current->getEdgeByTag(NE+boundEdges[i]->tag());
    else gec = current->getEdgeByTag(boundEdges[i]->tag());
    myEdges.push_back(gec);
    myEdgeLoops.push_back(myEdges);
    GFace *newFace = current->addPlanarFace(myEdgeLoops);
    if (gin==boundEdges[i]) {
      newFace->addPhysicalEntity(200);
      current->setPhysicalName("inlet", 2, 200);
    }
    else{
      newFace->addPhysicalEntity(300);
      current->setPhysicalName("outlets", 2, 300);
    }
    myFaces.push_back(newFace);
  }

 Msg::Info("Centerline action (closeVolume) has created %d in/out planar faces ", (int)boundEdges.size());

  for (int i = 0; i < NF; i++){
    GFace * gf = current->getFaceByTag(NF+i+1);
     myFaces.push_back(gf);
  }
  myFaceLoops.push_back(myFaces);
  GRegion *reg = current->addVolume(myFaceLoops);
  reg->addPhysicalEntity(reg->tag());
  current->setPhysicalName("lumenVolume", 3, reg->tag());

  Msg::Info("Centerline action (closeVolume) has created volume %d ", reg->tag());

}

void Centerline::extrudeBoundaryLayerWall(){
  
  Msg::Info("Centerline: extrude boundary layer wall %d %g ", nbElemLayer,  hLayer);

  //orient extrude direction outward
  int dir = 0;
  MElement *e = current->getFaceByTag(1)->getMeshElement(0);
  SVector3 ne = e->getFace(0).normal();
  SVector3 ps(e->getVertex(0)->x(), e->getVertex(0)->y(), e->getVertex(0)->z());
  double xyz[3] = {ps.x(), ps.y(), ps.z()};
  kdtree->annkSearch(xyz, 1, index, dist);
  SVector3 pc(nodes[index[0]][0], nodes[index[0]][1], nodes[index[0]][2]);
  SVector3 nc = ps-pc;
  if (dot(ne,nc) < 0) dir = 1;
  if (dir ==1 && hLayer > 0 ) hLayer *= -1.0;

  for (int i= 0; i< NF; i++){
    GFace *gfc ; 
    if (is_cut) gfc = current->getFaceByTag(NF+i+1);//at this moment compound is not meshed yet exist yet
    else gfc = current->getFaceByTag(i+1);
    current->setFactory("Gmsh");
    current->extrudeBoundaryLayer(gfc, nbElemLayer,  hLayer, dir, -5);
    //view -5 to scale hLayer by radius in BoundaryLayers.cpp
  }

}


void Centerline::run(){

  if (update_needed){
    std::ifstream input;
    input.open(fileName.c_str());
    if(StatFile(fileName)) Msg::Fatal("Centerline file '%s' does not exist", fileName.c_str());
    importFile(fileName);
    buildKdTree();
    update_needed = false;
  }

  if (is_cut) cutMesh();
  else{
    current->createTopologyFromMesh();
    NV = current->getMaxElementaryNumber(0);
    NE = current->getMaxElementaryNumber(1);
    NF = current->getMaxElementaryNumber(2);
    NR = current->getMaxElementaryNumber(3);  
  }

  if (is_closed) createClosedVolume();
  if (is_extruded) extrudeBoundaryLayerWall();

}

void Centerline::cutMesh(){

  is_cut = 1;

  // std::vector<GFace*> currentFaces =  current->bindingsGetFaces();
  // for (int i=0; i< currentFaces.size(); i++){
  //   printf("gf =%d \n", currentFaces[i]->tag());
  //   if(currentFaces[i]->geomType() == GEntity::CompoundSurface) {
  //     std::list<GFace*> cFaces = ((GFaceCompound*)currentFaces[i])->getCompounds();
  //     for (std::list<GFace*>::iterator it = cFaces.begin(); it!= cFaces.end(); it++) {
  //   	printf("comp  = %d\n", (*it)->tag());
  //     }
  //     if (cFaces.size() > 0) currentGFC.push_back(currentFaces[i]);
  //   }
  // }

  Msg::Info("Splitting surface mesh (%d tris) with centerline %s ", triangles.size(), fileName.c_str());

  //splitMesh
  for(unsigned int i = 0; i < edges.size(); i++){
    std::vector<MLine*> lines = edges[i].lines;
    double L = edges[i].length;
    double D = (edges[i].minRad+edges[i].maxRad);
    double AR = L/D;
    printf("*** Centerline branch %d (AR=%g):  ", edges[i].tag, AR);
    printf("children (%d) = ", edges[i].children.size());
    for (int k= 0; k< edges[i].children.size() ; k++) printf("%d ", edges[i].children[k].tag);
    printf("\n");
   
    int nbSplit = (int)floor(AR/2. + 0.5); 
    if( AR > 3.0){
      double li  = L/nbSplit;
      double lc = 0.0;
      for (unsigned int j= 0; j < lines.size(); j++){
	lc += lines[j]->getLength();
	if (lc > li && nbSplit > 1) {
	  MVertex *v1 = lines[j]->getVertex(0);
	  MVertex *v2 = lines[j]->getVertex(1);
	  SVector3 pt(v1->x(), v1->y(), v1->z());
	  SVector3 dir(v2->x()-v1->x(),v2->y()-v1->y(),v2->z()-v1->z());
	  printf("->> cut length %d split \n",  nbSplit);
	  std::map<MLine*,double>::iterator itr = radiusl.find(lines[j]);
	  bool cutted = cutByDisk(pt, dir, itr->second);
	  nbSplit--;
	  lc = 0.0;
	}
      }
    }
    if(edges[i].children.size() > 0.0 && AR > 1.0){
      MVertex *v1 = lines[lines.size()-1]->getVertex(1);//end vertex
      MVertex *v2;
      if(AR < 1.5) v2 = lines[0]->getVertex(0);
      else if (lines.size() > 4) v2 = lines[lines.size()-4]->getVertex(0);
      else v2 = lines[lines.size()-1]->getVertex(0);
      SVector3 pt(v1->x(), v1->y(), v1->z());
      SVector3 dir(v2->x()-v1->x(),v2->y()-v1->y(),v2->z()-v1->z());
      printf("-->> cut bifurcation \n");
      std::map<MLine*,double>::iterator itr = radiusl.find(lines[lines.size()-1]);
      bool cutted = cutByDisk(pt, dir, itr->second);
      if(!cutted){
	int l = lines.size()-1-lines.size()/(4*nbSplit);
	v1 = lines[l]->getVertex(1);
	v2 = lines[l]->getVertex(0);
	pt = SVector3(v1->x(), v1->y(), v1->z());
	dir = SVector3(v2->x()-v1->x(),v2->y()-v1->y(),v2->z()-v1->z());
	printf("-->> cut bifurcation NEW \n");
	itr = radiusl.find(lines[l]);
	cutted = cutByDisk(pt, dir, itr->second);
      }
    }
 }

  //create discreteFaces
  createFaces();
  current->createTopologyFromFaces(discFaces);
  current->exportDiscreteGEOInternals();

  //write
  Msg::Info("Writing splitted mesh 'myPARTS.msh'");
  current->writeMSH("myPARTS.msh", 2.2, false, false);

  //create compounds
  createSplitCompounds();

  Msg::Info("Splitting mesh by centerlines done ");

}

bool Centerline::cutByDisk(SVector3 &PT, SVector3 &NORM, double &maxRad){

  double a = NORM.x();
  double b = NORM.y();
  double c = NORM.z();
  double d = -a * PT.x() - b * PT.y() - c * PT.z();
  //printf("cut disk (R=%g)= %g %g %g %g \n", maxRad, a, b, c, d);

  int maxStep = 40;
  const double EPS = 0.007;

  std::set<MEdge,Less_Edge> allEdges;
  for(unsigned int i = 0; i < triangles.size(); i++)
    for ( unsigned int j= 0; j <  3; j++)
      allEdges.insert(triangles[i]->getEdge(j));
  bool closedCut = false;
  int step = 0;
  while (!closedCut && step < maxStep){
    double rad = 1.1*maxRad+0.05*step*maxRad;
    std::map<MEdge,MVertex*,Less_Edge> cutEdges;
    std::set<MVertex*> cutVertices;
    std::vector<MTriangle*> newTris;
    std::set<MEdge,Less_Edge> newCut;
    cutEdges.clear();
    cutVertices.clear();
    newTris.clear();
    newCut.clear();
    for (std::set<MEdge,Less_Edge>::iterator it = allEdges.begin();
	 it != allEdges.end() ; ++it){
      MEdge me = *it;
      SVector3 P1(me.getVertex(0)->x(),me.getVertex(0)->y(), me.getVertex(0)->z());
      SVector3 P2(me.getVertex(1)->x(),me.getVertex(1)->y(), me.getVertex(1)->z());
      double V1 = a * P1.x() + b * P1.y() + c * P1.z() + d;
      double V2 = a * P2.x() + b * P2.y() + c * P2.z() + d;
      bool inters = (V1*V2<=0.0) ? true: false;
      bool inDisk = ((norm(P1-PT) < rad ) || (norm(P2-PT) < rad)) ? true : false;
      double rdist = -V1/(V2-V1);
      if (inters && rdist > EPS && rdist < 1.-EPS){
	SVector3 PZ = P1+rdist*(P2-P1);
	MVertex *newv = new MVertex (PZ.x(), PZ.y(), PZ.z());
	if (inDisk) cutEdges.insert(std::make_pair(*it,newv));
      }
      else if (inters && rdist <= EPS && inDisk )
	cutVertices.insert(me.getVertex(0));
      else if (inters && rdist >= 1.-EPS && inDisk)
	cutVertices.insert(me.getVertex(1));
    }
    for(unsigned int i = 0; i < triangles.size(); i++){
      cutTriangle(triangles[i], cutEdges,cutVertices, newTris, newCut);
    }
    if (isClosed(newCut)) {
      triangles.clear();
      triangles = newTris;
      theCut.insert(newCut.begin(),newCut.end());
      break;
    }
    else {
      step++;
      //if (step == maxStep) {printf("no closed cut %d \n", (int)newCut.size()); };
      // // triangles = newTris;
      // // theCut.insert(newCut.begin(),newCut.end());
      // char name[256];
      // sprintf(name, "myCUT-%d.pos", step);
      // FILE * f2 = fopen(name,"w");
      // fprintf(f2, "View \"\"{\n");
      // std::set<MEdge,Less_Edge>::iterator itp =  newCut.begin();
      // while (itp != newCut.end()){
      // 	MEdge l = *itp;
      // 	fprintf(f2, "SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",
      // 		  l.getVertex(0)->x(), l.getVertex(0)->y(), l.getVertex(0)->z(),
      // 		  l.getVertex(1)->x(), l.getVertex(1)->y(), l.getVertex(1)->z(),
      // 		  1.0,1.0);
      // 	  itp++;
      // 	}
      // 	fprintf(f2,"};\n");
      // 	fclose(f2);
    }
  }

 
  if (step < maxStep){
    //printf("cutByDisk OK step =%d  \n", step);
    return true;
  }
  else {
    //printf("cutByDisk not succeeded \n");
    return false;
  }

}

double Centerline::operator() (double x, double y, double z, GEntity *ge){

  if (update_needed){
     std::ifstream input;
     input.open(fileName.c_str());
     if(StatFile(fileName)) Msg::Fatal("Centerline file '%s' does not exist", fileName.c_str());
     importFile(fileName);
     buildKdTree();
     update_needed = false;
   }

   double xyz[3] = {x,y,z};

   //take xyz = closest point on boundary in case we are on the planar in/out faces
   bool isCompound = false;
   if(ge){
     if (ge->dim() == 2 && ge->geomType() == GEntity::CompoundSurface) isCompound = true; 
     std::list<GFace*> cFaces;
     if (isCompound) cFaces = ((GFaceCompound*)ge)->getCompounds();
     if ( ge->dim() == 3 || (ge->dim() == 2 && ge->geomType() == GEntity::Plane) ||
	  (isCompound && (*cFaces.begin())->geomType() == GEntity::Plane) ){
       int num_neighbours = 1;
       kdtreeR->annkSearch(xyz, num_neighbours, index, dist);
       xyz[0] = nodesR[index[0]][0];
       xyz[1] = nodesR[index[0]][1];
       xyz[2] = nodesR[index[0]][2];
     }
   }

   int num_neighbours = 1;
   kdtree->annkSearch(xyz, num_neighbours, index, dist);
   double d = sqrt(dist[0]);
   double lc = 2*M_PI*d/nbPoints;

   if(!ge) { return d;}
   else  return lc;

}


void  Centerline::operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge){

  if (update_needed){
     std::ifstream input;
     input.open(fileName.c_str());
     if(StatFile(fileName)) Msg::Fatal("Centerline file '%s' does not exist", fileName.c_str());
     importFile(fileName);
     buildKdTree();
     update_needed = false;
   }

   double xyz[3] = {x,y,z};

   //take xyz = closest point on boundary in case we are on the planar IN/OUT FACES or in VOLUME
   bool onTubularSurface = true;
   double ds = 0.0;
   bool isCompound = (ge->dim() == 2 && ge->geomType() == GEntity::CompoundSurface) ? true: false;
   std::list<GFace*> cFaces;
   if (isCompound) cFaces = ((GFaceCompound*)ge)->getCompounds();
   if ( ge->dim() == 3 || (ge->dim() == 2 && ge->geomType() == GEntity::Plane) ||
	(isCompound && (*cFaces.begin())->geomType() == GEntity::Plane) ){
     onTubularSurface = false;
     kdtreeR->annkSearch(xyz, 1, index, dist);
     ds = sqrt(dist[0]);
     xyz[0] = nodesR[index[0]][0];
     xyz[1] = nodesR[index[0]][1];
     xyz[2] = nodesR[index[0]][2];
   }

   ANNidxArray index2 = new ANNidx[2];
   ANNdistArray dist2 = new ANNdist[2];
   kdtree->annkSearch(xyz, 2, index2, dist2);
   double radMax = sqrt(dist2[0]);
   SVector3  p0(nodes[index2[0]][0], nodes[index2[0]][1], nodes[index2[0]][2]);
   SVector3  p1(nodes[index2[1]][0], nodes[index2[1]][1], nodes[index2[1]][2]);
   
   //dir_a = direction along the centerline
   //dir_n = normal direction of the disk
   //dir_t = tangential direction of the disk
   SVector3 dir_a = p1-p0;
   SVector3 dir_n(x-p0.x(), y-p0.y(), z-p0.z()); 
   SVector3 dir_t;
   buildOrthoBasis2(dir_a, dir_n, dir_t);
   
   double lc = 2*M_PI*radMax/nbPoints;
   double lc_a = 3.5*lc;
   double lc_n, lc_t;

   if (onTubularSurface){
     lc_n = lc_t = lc;
   }
   else{
     double e = radMax/4.;
     double hn = e/10.;
     double rm = std::max(radMax-ds, radMax-e);
     lc_t = 2*M_PI*rm/nbPoints;
     //lc_n = lc_t = lc;
     //double ratio = 1.02; //1. + (lc_t-hn)/e;
     //printf("ratio =%g \n", ratio);
     //lc_n = ds*(ratio-1) + hn;
     if (ds < e) lc_n = hn; 
     else lc_n = lc_t;
   }
   double lam_a = 1./(lc_a*lc_a);
   double lam_n = 1./(lc_n*lc_n);
   double lam_t = 1./(lc_t*lc_t);
   
   metr = SMetric3(lam_a,lam_n,lam_t, dir_a, dir_n, dir_t);

   delete[]index2;
   delete[]dist2;

   return;
}

/**************************************************/
/******************Temporary code******************/
/**************************************************/
void Centerline::operator()(double x,double y,double z,SVector3& v1,SVector3& v2,SVector3& v3,GEntity* ge){
  if(update_needed){
    std::ifstream input;
	input.open(fileName.c_str());
	if(StatFile(fileName)) Msg::Fatal("Centerline file '%s' does not exist", fileName.c_str());
	importFile(fileName);
	buildKdTree();
	update_needed = false;
  }
	
  double xyz[3] = {x,y,z};
	
  //take xyz = closest point on boundary in case we are on the planar IN/OUT FACES or in VOLUME
  bool onTubularSurface = true;
  double ds = 0.0;
  bool isCompound = (ge->dim() == 2 && ge->geomType() == GEntity::CompoundSurface) ? true: false;
  std::list<GFace*> cFaces;
  if(isCompound) cFaces = ((GFaceCompound*)ge)->getCompounds();
  if(ge->dim()==3 || (ge->dim()==2&&ge->geomType()==GEntity::Plane) || (isCompound&&(*cFaces.begin())->geomType()==GEntity::Plane)){
	onTubularSurface = false;
	kdtreeR->annkSearch(xyz, 1, index, dist);
	ds = sqrt(dist[0]);
	xyz[0] = nodesR[index[0]][0];
	xyz[1] = nodesR[index[0]][1];
	xyz[2] = nodesR[index[0]][2];
  }
	
  ANNidxArray index2 = new ANNidx[2];
  ANNdistArray dist2 = new ANNdist[2];
  kdtree->annkSearch(xyz, 2, index2, dist2);
  double radMax = sqrt(dist2[0]);
  SVector3  p0(nodes[index2[0]][0], nodes[index2[0]][1], nodes[index2[0]][2]);
  SVector3  p1(nodes[index2[1]][0], nodes[index2[1]][1], nodes[index2[1]][2]);
	
  //dir_a = direction along the centerline
  //dir_n = normal direction of the disk
  //dir_t = tangential direction of the disk
  SVector3 dir_a = p1-p0;
  SVector3 dir_n(x-p0.x(), y-p0.y(), z-p0.z()); 
  SVector3 dir_t;
  buildOrthoBasis2(dir_a, dir_n, dir_t);
	
  double lc = 2*M_PI*radMax/nbPoints;
  double lc_a = 3.*lc;
  double lc_n, lc_t;
  if(onTubularSurface){
    lc_n = lc_t = lc;
  }
  else{
    double e = radMax/3.;
	double hn = e/10.;
	double rm = std::max(radMax-ds, radMax-e);
	lc_t = 2*M_PI*rm/nbPoints;
	//lc_n = lc_t = lc;
	//double ratio = 1.02; //1. + (lc_t-hn)/e;
	//printf("ratio =%g \n", ratio);
	//lc_n = ds*(ratio-1) + hn;
	if(ds<e) lc_n = hn; 
	else lc_n = lc_t;
  }
  double lam_a = 1./(lc_a*lc_a);
  double lam_n = 1./(lc_n*lc_n);
  double lam_t = 1./(lc_t*lc_t);
	
  v1 = dir_a;
  v2 = dir_n;
  v3 = dir_t;
	
  delete[]index2;
  delete[]dist2;
	
  return;
}
/*************************************************/
/*************************************************/
/*************************************************/

void Centerline::printSplit() const{

  FILE * f = fopen("mySPLIT.pos","w");
  fprintf(f, "View \"\"{\n");
  for(unsigned int i = 0; i < edges.size(); ++i){
    std::vector<MLine*> lines = edges[i].lines;
    for(unsigned int k = 0; k < lines.size(); ++k){
      MLine *l = lines[k];
      fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",
	      l->getVertex(0)->x(), l->getVertex(0)->y(), l->getVertex(0)->z(),
	      l->getVertex(1)->x(), l->getVertex(1)->y(), l->getVertex(1)->z(),
	      (double)edges[i].tag, (double)edges[i].tag);
    }
  }
  fprintf(f,"};\n");
  fclose(f);

  // FILE * f3 = fopen("myJUNCTIONS.pos","w");
  // fprintf(f3, "View \"\"{\n");
  //  std::set<MVertex*>::const_iterator itj = junctions.begin();
  //  while (itj != junctions.end()){
  //    MVertex *v =  *itj;
  //    fprintf(f3, "SP(%g,%g,%g){%g};\n",
  // 	     v->x(),  v->y(), v->z(),
  // 	     (double)v->getNum());
  //    itj++;
  // }
  // fprintf(f3,"};\n");
  // fclose(f3);

  FILE * f4 = fopen("myRADII.pos","w");
  fprintf(f4, "View \"\"{\n");
  for(unsigned int i = 0; i < lines.size(); ++i){
    MLine *l = lines[i];
    std::map<MLine*,double>::const_iterator itc =  radiusl.find(l);
    fprintf(f4, "SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",
 	    l->getVertex(0)->x(), l->getVertex(0)->y(), l->getVertex(0)->z(),
 	    l->getVertex(1)->x(), l->getVertex(1)->y(), l->getVertex(1)->z(),
 	    itc->second,itc->second);
  }
  fprintf(f4,"};\n");
  fclose(f4);

}

#endif
