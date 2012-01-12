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
#include <string>
#include "GModel.h"
#include "MElement.h"
#include "MVertex.h"
#include "MLine.h"
#include "GEntity.h"
#include "Field.h"

#if defined(HAVE_ANN)
#include <ANN/ANN.h>

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
  update_needed = false;

  options["FileName"] = new FieldOptionString (fileName, "File Name for the centerlines");
  fileName = "centerlines.vtk";//default
  //TODO get fileName from file 

  importFile(fileName);
  buildKdTree();

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
    
  for(unsigned int i = 0; i < entities.size(); i++){
     if( entities[i]->dim() == 1){
     for(unsigned int ele = 0; ele < entities[i]->getNumMeshElements(); ele++){ 
       MLine *l = (MLine*) entities[i]->getMeshElement(ele);
       MVertex *v0 = l->getVertex(0);
       MVertex *v1 = l->getVertex(1);
       std::map<MVertex*, int>::iterator it0 = color.find(v0);
       std::map<MVertex*, int>::iterator it1 = color.find(v1);
       if (it0 == color.end() || it1 == color.end()) lines.push_back(l);
       if (it0 == color.end()) color.insert(std::make_pair(v0, entities[i]->tag()));
       if (it1 == color.end()) color.insert(std::make_pair(v1, entities[i]->tag()));
     }
   }
 }
  current->setAsCurrent();

}
void Centerline::buildKdTree(){

  FILE * f = fopen("myPOINTS.pos","w");
  fprintf(f, "View \"\"{\n");

  int nbPL = 10;
  int nbNodes  = (lines.size()+1) + (nbPL*lines.size());

  nodes = annAllocPts(nbNodes, 3);
  int ind = 0;
  std::map<MVertex*,int >::iterator itmap = color.begin();
  while (itmap != color.end()){
     MVertex *v = itmap->first;
     nodes[ind][0] = v->x(); 
     nodes[ind][1] = v->y(); 
     nodes[ind][2] = v->z(); 
     itmap++; ind++;
  }
  //10 points per line
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

double Centerline::operator() (double x, double y, double z, GEntity *ge){

  double xyz[3] = {x,y,z };
  int num_neighbours = 1;
  kdtree->annkSearch(xyz, num_neighbours, index, dist);
  double d = sqrt(dist[0]);
  double lc = 2*M_PI*d/30.0; //30 mesh elements along circle
  return lc;

}

void  Centerline::operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge){
  return;
}

void Centerline::printSplit() const{

  FILE * f = fopen("centerlineSPLIT.pos","w");
  fprintf(f, "View \"\"{\n");

  for(unsigned int i = 0; i < lines.size(); ++i){
      MLine *l = lines[i];
      std::map<MVertex*,int>::const_iterator it0 = 
        color.find(l->getVertex(0));
      std::map<MVertex*,int>::const_iterator it1 = 
        color.find(l->getVertex(1));
      fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",
              l->getVertex(0)->x(), l->getVertex(0)->y(), l->getVertex(0)->z(),
              l->getVertex(1)->x(), l->getVertex(1)->y(), l->getVertex(1)->z(),
  	      (double)it0->second,(double)it1->second);
   }
  fprintf(f,"};\n");
  fclose(f);
 
}

#endif
