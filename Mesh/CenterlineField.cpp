// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
#include "OS.h"
#include "GModel.h"
#include "MElement.h"
#include "MVertex.h"
#include "MLine.h"
#include "GEntity.h"
#include "Field.h"

#if defined(HAVE_ANN)
#include <ANN/ANN.h>

#include <algorithm>

void erase(std::vector<MLine*>& lines, MLine* l) {
  std::vector<MLine*>::iterator it = std::remove(lines.begin(), lines.end(), l);
  lines.erase(it, lines.end());
}
double computeLength(std::vector<MLine*> lines){

  double length= 0.0;
  for (int i = 0; i< lines.size(); i++){
    length += lines[i]->getInnerRadius(); 
  }
  return length;
}

void orderMLines(std::vector<MLine*> &lines) { //, std::set<MVertex*> & junctions, MVertex *vB, MVertex *vE){

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
    Msg::Error("line is wrong (it has %d end points)", 
               boundv.size());
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

Centerline::Centerline(std::string fileName): kdtree(0), nodes(0){

  index = new ANNidx[1];
  dist = new ANNdist[1];
  update_needed = false;

  importFile(fileName);
  buildKdTree();

}
Centerline::Centerline(): kdtree(0), nodes(0){

  index = new ANNidx[1];
  dist = new ANNdist[1];

  options["FileName"] = new FieldOptionString (fileName, "File name for the centerlines",  &update_needed);
  fileName = "centerlines.vtk";//default

}

Centerline::~Centerline(){
  if (mod) delete mod;
  if(kdtree) delete kdtree;
  if(nodes) annDeallocPts(nodes);
  delete[]index;
  delete[]dist;
}

void Centerline::importFile(std::string fileName){

  GModel *current = GModel::current();

  mod = new GModel();
  mod->readVTK(fileName.c_str());
  mod->removeDuplicateMeshVertices(1.e-8);
  std::vector<GEntity*> entities ;
  mod->getEntities(entities) ;  
  current->setAsCurrent();  

  int maxN = 0.0;
  for(unsigned int i = 0; i < entities.size(); i++){
     if( entities[i]->dim() == 1){
     for(unsigned int ele = 0; ele < entities[i]->getNumMeshElements(); ele++){ 
       MLine *l = (MLine*) entities[i]->getMeshElement(ele);
       MVertex *v0 = l->getVertex(0);
       MVertex *v1 = l->getVertex(1);
       std::map<MVertex*, int>::iterator it0 = colorp.find(v0);
       std::map<MVertex*, int>::iterator it1 = colorp.find(v1);
       if (it0 == colorp.end() || it1 == colorp.end()){
	 lines.push_back(l);
	 colorl.insert(std::make_pair(l, entities[i]->tag()));
	 maxN = std::max(maxN, entities[i]->tag());
       }
       if (it0 == colorp.end()) colorp.insert(std::make_pair(v0, entities[i]->tag()));
       if (it1 == colorp.end()) colorp.insert(std::make_pair(v1, entities[i]->tag()));
     }
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
  // printf("junctions =%d \n", junctions.size());
  // std::set<MVertex*>::iterator itt = junctions.begin();
  // for ( ; itt != junctions.end(); ++itt){
  //   MVertex *v = *itt;
  //   printf("JUNC = %d \n", v->getNum());
  // }
   
  //split edges
  int tag = 0;
  for(unsigned int i = 0; i < color_edges.size(); ++i){
    std::vector<MLine*> lines = color_edges[i];
    //printf("EDGE %d line = %d \n", lines.size());
    while (!lines.empty()) {
      std::vector<MLine*> myLines;
      std::vector<MLine*>::iterator itl = lines.begin();
      MVertex *vB = (*itl)->getVertex(0);
      MVertex *vE = (*itl)->getVertex(1);
      //printf("VB =%d vE = %d \n", vB->getNum(), vE->getNum());
      myLines.push_back(*itl);
      erase(lines, *itl); 
      itl = lines.begin();
      while ( !( junctions.find(vE) != junctions.end() &&
		 junctions.find(vB) != junctions.end()) ) {
  	MVertex *v1 = (*itl)->getVertex(0);
  	MVertex *v2 = (*itl)->getVertex(1);
	//printf("line %d, VB = %d vE = %d v1=%d v2=%d \n", (*itl)->getNum(), vB->getNum(), vE->getNum(), v1->getNum(), v2->getNum());
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
      orderMLines(myLines); 
      std::vector<Branch> children;
      Branch newBranch ={ tag++, myLines, computeLength(myLines), vB, vE, children, 1.e6, 0.0};
      //printf("branch = %d VB = %d VE %d \n", myLines.size(), vB->getNum(), vE->getNum());
      edges.push_back(newBranch) ;
    }
  }
  printf("in/outlets =%d branches =%d \n", color_edges.size(), edges.size());

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
  distanceToLines();
  computeRadii();

  //print info
  // for(unsigned int i = 0; i < edges.size(); ++i) {
  //   printf("EDGE =%d  tag=%d length = %g childs = %d \n", i, edges[i].tag, edges[i].length, edges[i].children.size());
  //    for(unsigned int j = 0; j < edges[i].children.size(); ++j) {
  //      printf("children (%d) =%d \n", edges[i].children.size(),  edges[i].children[j].tag);
  //    }
  // }
  // std::set<MVertex*>::iterator itj = junctions.begin();
  // for ( ; itj != junctions.end(); ++itj){
  //   MVertex *v = *itj;
  //   printf("JUNC = %d \n", v->getNum());
  // }

}

void Centerline::distanceToLines(){
  Msg::Info("Centerline: computing distance to lines ");

  //EMI TO DO DO THIS WITH ANN !
  //MUCH FASTER

  std::vector<SPoint3> pts;
  std::set<SPoint3> pts_set;
  std::vector<double> distances;
  std::vector<double> distancesE;
  std::vector<SPoint3> closePts;

  GModel *current = GModel::current();
  std::vector<GEntity*> _entities ;
  current->getEntities(_entities) ; 
  for(unsigned int i = 0; i < _entities.size(); i++){
    if( _entities[i]->dim() != 2) continue;
    for(unsigned int j = 0; j < _entities[i]->getNumMeshElements(); j++){ 
       MElement *e = _entities[i]->getMeshElement(j);
       for (int k = 0; k < e->getNumVertices(); k++){
	 MVertex *v = e->getVertex(k);
	 pts_set.insert(SPoint3(v->x(), v->y(),v->z()));
       }
    }
  }
  std::set<SPoint3>::iterator its =  pts_set.begin();
  for (; its != pts_set.end(); its++){
    pts.push_back(*its);
  } 
  if (pts.size() == 0) {Msg::Error("Centerline needs a GModel with a surface \n"); exit(1);}
 
  for(unsigned int i = 0; i < lines.size(); i++){
    std::vector<double> iDistances;
    std::vector<SPoint3> iClosePts;
    std::vector<double> iDistancesE;
    MLine *l = lines[i];
    MVertex *v1 = l->getVertex(0);
    MVertex *v2 = l->getVertex(1);
    SPoint3 p1(v1->x(), v1->y(), v1->z());
    SPoint3 p2(v2->x(), v2->y(), v2->z());
    signedDistancesPointsLine(iDistances, iClosePts, pts, p1,p2);

    double minRad = std::abs(iDistances[0]);
    for (unsigned int kk = 1; kk< pts.size(); kk++) {
      if (std::abs(iDistances[kk]) < minRad)
	minRad = std::abs(iDistances[kk]);
    }
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
	edges[i].maxRad = std::min(itr->second, edges[i].maxRad);
      }
      else printf("ARGG line not found \n");
    }    
  }

}
void Centerline::buildKdTree(){

  FILE * f = fopen("myPOINTS.pos","w");
  fprintf(f, "View \"\"{\n");

  int nbPL = 3;  //10 points per line
  int nbNodes  = (lines.size()+1) + (nbPL*lines.size());

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

 for(unsigned int i = 0; i < nbNodes; ++i){
   fprintf(f, "SP(%g,%g,%g){%g};\n",
	   nodes[i][0], nodes[i][1],nodes[i][2],1.0);
 }
 fprintf(f,"};\n");
  fclose(f);

}

void Centerline::splitMesh(){

 for(unsigned int i = 0; i < edges.size(); ++i){
   std::vector<MLine*> lines = edges[i].lines;
   MVertex *v1 = edges[i].vE;
   MVertex *v2;
   SPoint3 pt(v1->x(), v1->y(), v1->z());
   if (lines[0]->getVertex(0) == v1) v2 = lines[0]->getVertex(1);
   else if (lines[0]->getVertex(1) == v1) v2 = lines[0]->getVertex(0);
   else if (lines.back()->getVertex(0) == v1) v2 = lines.back()->getVertex(1);
   else if (lines.back()->getVertex(1) == v1) v2 = lines.back()->getVertex(0);
   SVector3 dir(v2->x()-v1->x(),v2->y()-v1->y(),v2->z()-v1->z());
   if(edges[i].children.size() > 0.0){
     cutByDisk(pt, dir, edges[i].maxRad);
   }
 }

}

void Centerline::cutByDisk(SPoint3 pt, SVector3 norm, double rad){
  
  printf("Cutting disk centered at pt  %g %g %g dir %g %g %g \n", pt.x(), pt.y(), pt.z(), norm.x(), norm.y(), norm.z());
  double a = norm.x();
  double b = norm.y();
  double c = norm.z();
  double d = -a * pt[0] - b * pt[1] - c * pt[2];
  printf("PLane = %g %g %g %g \n", a, b, c, d);
  exit(1);
  return;

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

  double xyz[3] = {x,y,z };
  int num_neighbours = 1;
  kdtree->annkSearch(xyz, num_neighbours, index, dist);
  double d = sqrt(dist[0]);
  double lc = 2*M_PI*d/30.0; //30 mesh elements along circle
  return lc;

}

void  Centerline::operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge){
  Msg::Error("This anisotropic operator of CenterlineField is not implemnted yet ");
  return;
}

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
	      (double)i, (double)i);
    }
  }
  fprintf(f,"};\n");
  fclose(f);

  FILE * f2 = fopen("myCOLORS.pos","w");
  fprintf(f2, "View \"\"{\n");
   std::map<MVertex*, int>::const_iterator itp = colorp.begin();
   while (itp != colorp.end()){
     MVertex *v =  itp->first;
     fprintf(f2, "SP(%g,%g,%g){%g};\n",
  	    v->x(),  v->y(), v->z(),
  	     (double)v->getNum());
     itp++; 
  }
  fprintf(f2,"};\n");
  fclose(f2);

  FILE * f3 = fopen("myJUNCTIONS.pos","w");
  fprintf(f3, "View \"\"{\n");
   std::set<MVertex*>::const_iterator itj = junctions.begin();
   while (itj != junctions.end()){
     MVertex *v =  *itj;
     fprintf(f3, "SP(%g,%g,%g){%g};\n",
	     v->x(),  v->y(), v->z(),
	     (double)v->getNum());
     itj++; 
  }
  fprintf(f3,"};\n");
  fclose(f3);

  FILE * f4 = fopen("myRADII.pos","w");
  fprintf(f4, "View \"\"{\n");
  for(unsigned int i = 0; i < lines.size(); ++i){
    MLine *l = lines[i];
    std::map<MLine*,double>::const_iterator itc =  radiusl.find(l);
    fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",
 	    l->getVertex(0)->x(), l->getVertex(0)->y(), l->getVertex(0)->z(),
 	    l->getVertex(1)->x(), l->getVertex(1)->y(), l->getVertex(1)->z(),
 	    itc->second,itc->second);
  }
  fprintf(f4,"};\n");
  fclose(f4);
 
}

#endif
