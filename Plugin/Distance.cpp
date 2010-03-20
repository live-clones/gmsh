// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include <stdlib.h>
#include "Gmsh.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "Distance.h"
#include "simpleFunction.h"
#include "distanceTerm.h"
#include "Context.h"
#include "Numeric.h"
#include "dofManager.h"
#include "linearSystemGMM.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDistancePlugin()
  {
    return new GMSH_DistancePlugin();
  }
}

std::string GMSH_DistancePlugin::getHelp() const
{
  return "Plugin(Distance) computes distances to boundaries in "
    "a mesh.\n\n"
    "Plugin(Distance) creates a bunch of files.";
}

PView *GMSH_DistancePlugin::execute(PView *v)
{
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities);

  int numnodes = 0;
  for(unsigned int i = 0; i < entities.size() - 1; i++)
    numnodes += entities[i]->mesh_vertices.size();
  int totNumNodes = numnodes + entities[entities.size() - 1]->mesh_vertices.size();

  std::map<MVertex*,double* > distance_map; 
  std::map<MVertex*,double > distance_map2;
  std::vector<SPoint3> pts;
  std::vector<double> distances;
  pts.clear(); 
  distances.clear();
  distances.reserve(totNumNodes);
  pts.reserve(totNumNodes);
  for (int i = 0; i < totNumNodes; i++) distances.push_back(1.e22);

  int k = 0;
  int maxDim = 0;
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity* ge = entities[i]; 
    maxDim = std::max(maxDim, ge->dim());
    for(unsigned int j = 0; j < ge->mesh_vertices.size(); j++){
      MVertex *v = ge->mesh_vertices[j];
      pts.push_back(SPoint3(v->x(), v->y(),v->z()));
      distance_map.insert(std::make_pair(v, &(distances[k])));
      distance_map2.insert(std::make_pair(v, 0.0));
      k++;
    }
  }

  // Compute geometrical distance to mesh boundaries

  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->dim() == (maxDim - 1)) {
      GEntity* g2 = entities[i];
      for(unsigned int k = 0; k < g2->getNumMeshElements(); k++){ 
	std::vector<double> iDistances;
	std::vector<SPoint3> iClosePts;
	MElement *e = g2->getMeshElement(k);
	MVertex *v1 = e->getVertex(0);
	MVertex *v2 = e->getVertex(1);
	SPoint3 p1(v1->x(), v1->y(), v1->z());
	SPoint3 p2(v2->x(), v2->y(), v2->z());
	if(e->getNumVertices() == 2){
	  signedDistancesPointsLine(iDistances, iClosePts, pts, p1,p2);
	}
	else if(e->getNumVertices() == 3){
	  MVertex *v3 = e->getVertex(2);
	  SPoint3 p3 (v3->x(),v3->y(),v3->z());
	  signedDistancesPointsTriangle(iDistances, iClosePts, pts, p1, p2, p3);
	}
	for (unsigned int kk = 0; kk< pts.size(); kk++) {
	  if (std::abs(iDistances[kk]) < distances[kk])
	    distances[kk] = std::abs(iDistances[kk]);
	}
      }
    }
  }

//   std::map<int, std::vector<GEntity*> > groups[4];
//   getPhysicalGroups(groups);
//   std::map<int, std::vector<GEntity*> >::const_iterator it = groups[1].find(100);
//   if(it == groups[1].end()) return 0;
//   const std::vector<GEntity *> &physEntities = it->second;
//   for(unsigned int i = 0; i < physEntities.size(); i++){
//     GEntity* g2 = physEntities[i];
//     for(unsigned int i = 0; i < g2->getNumMeshElements(); i++){ 
//       std::vector<double> iDistances;
//       std::vector<SPoint3> iClosePts;
//       MElement *e = g2->getMeshElement(i);
//       MVertex *v1 = e->getVertex(0);
//       MVertex *v2 = e->getVertex(1);
//       SPoint3 p1 (v1->x(),v1->y(),v1->z());
//       SPoint3 p2 (v2->x(),v2->y(),v2->z());
//       signedDistancesPointsLine(iDistances, iClosePts, pts, p1,p2);     
//       for (int k = 0; k< pts.size(); k++) {
// 	if (std::abs(iDistances[k]) < distances[k] ) 
// 	  distances[k] = std::abs(iDistances[k]);
//       }
//     }
//   }


  // Compute PDE for distance function
  
#ifdef HAVE_TAUCS
  linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
#else
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
  lsys->setNoisy(1);
  lsys->setGmres(1);
  lsys->setPrec(5.e-8);
#endif

  dofManager<double> myAssembler(lsys);

  SBoundingBox3d bbox;
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->dim() < maxDim) {
      GEntity *ge = entities[i];
      for(unsigned int j = 0; j < ge->mesh_vertices.size(); j++){
	MVertex *v = ge->mesh_vertices[j];
	myAssembler.fixVertex(v, 0, 1, 0.0);
	bbox += SPoint3(v->x(),v->y(),v->z());
      }
    }
  }

  for(unsigned int ii = 0; ii < entities.size(); ii++){
    if(entities[ii]->dim() == maxDim) {
      GEntity *ge = entities[ii];
      for(unsigned int i = 0; i < ge->getNumMeshElements(); ++i){
	MElement *t = ge->getMeshElement(i);
	for(int k = 0; k < t->getNumVertices(); k++){
          myAssembler.numberVertex(t->getVertex(k), 0, 1);
	}
      }    
    }  
  }

  double L = norm(SVector3(bbox.max(), bbox.min())); 
  double mu = L/28;
  printf("L=%g \n", L);

  simpleFunction<double> DIFF(mu * mu), MONE(1.0);
  distanceTerm distance(GModel::current(), 1, &DIFF, &MONE);
  
  for(unsigned int ii = 0; ii < entities.size(); ii++){
    if(entities[ii]->dim() == maxDim) {
      GEntity *ge = entities[ii];
      for(unsigned int i = 0; i < ge->getNumMeshElements(); ++i){
	SElement se(ge->getMeshElement(i));
	distance.addToMatrix(myAssembler, &se);
      }
      groupOfElements g((GFace*)ge);
      distance.addToRightHandSide(myAssembler, g);
    }
  }

  Msg::Info("Distance Computation: Assembly done");
  lsys->systemSolve();
  Msg::Info("Distance Computation: System solved");
  
  for(std::map<MVertex*,double >::iterator itv = distance_map2.begin(); 
      itv !=distance_map2.end() ; ++itv){
    MVertex *v = itv->first;
    double value = std::min(0.9999, myAssembler.getDofValue(v, 0, 1));
    double dist = -mu * log(1. - value);
    itv->second = dist;
  }

  lsys->clear();
  
  //Writing pos files

  Msg::Info("Writing distance-GEOM.pos");
  FILE * f2 = fopen("distance-GEOM.pos","w");
  fprintf(f2,"View \"distance GEOM\"{\n");
  int j = 0;
  for(std::vector<double>::iterator it = distances.begin(); it != distances.end(); it++){
    fprintf(f2,"SP(%g,%g,%g){%g};\n", pts[j].x(), pts[j].y(), pts[j].z(), *it);
    j++;
  }
  fprintf(f2,"};\n");
  fclose(f2);

  Msg::Info("Writing distance-bgm.pos");
  FILE * f3 = fopen("distance-bgm.pos","w");
  fprintf(f3,"View \"distance\"{\n");
  for(unsigned int ii = 0; ii < entities.size(); ii++){
    if(entities[ii]->dim() == maxDim) {
      for(unsigned int i = 0; i < entities[ii]->getNumMeshElements(); i++){ 
	MElement *e = entities[ii]->getMeshElement(i);
	if (maxDim == 3) fprintf(f3,"SS(");
	else if (maxDim == 2) fprintf(f3,"ST(");
	std::vector<double> dist;
	for(int j = 0; j < e->getNumVertices(); j++) {
	  MVertex *v =  e->getVertex(j);
	  if(j) fprintf(f3,",%g,%g,%g",v->x(),v->y(), v->z());
	  else fprintf(f3,"%g,%g,%g", v->x(),v->y(), v->z());
	  std::map<MVertex*, double*>::iterator it = distance_map.find(v);
	  dist.push_back(*(it->second));
	}
	fprintf(f3,"){");
	for (unsigned int i = 0; i < dist.size(); i++){
	  if (i) fprintf(f3,",%g", dist[i]);
	  else fprintf(f3,"%g", dist[i]);
	}   
	fprintf(f3,"};\n");
      }
    }
  }
  fprintf(f3,"};\n");
  fclose(f3);

  Msg::Info("Writing distance-bgm2.pos");
  FILE * f4 = fopen("distance-bgm2.pos","w");
  fprintf(f4,"View \"distance\"{\n");
  for(unsigned int ii = 0; ii < entities.size(); ii++){
    if(entities[ii]->dim() == maxDim) {
      for(unsigned int i = 0; i < entities[ii]->getNumMeshElements(); i++){ 
	MElement *e = entities[ii]->getMeshElement(i);
	if (maxDim == 3) fprintf(f4,"SS(");
	else if (maxDim == 2) fprintf(f4,"ST(");
	std::vector<double> dist;
	for(int j = 0; j < e->getNumVertices(); j++) {
	  MVertex *v =  e->getVertex(j);
	  if(j) fprintf(f4,",%g,%g,%g",v->x(),v->y(), v->z());
	  else fprintf(f4,"%g,%g,%g", v->x(),v->y(), v->z());
	  std::map<MVertex*, double>::iterator it = distance_map2.find(v);
	  dist.push_back(it->second);
	}
	fprintf(f4,"){");
	for (unsigned int i = 0; i < dist.size(); i++){
	  if (i) fprintf(f4,",%g", dist[i]);
	  else fprintf(f4,"%g", dist[i]);
	}   
	fprintf(f4,"};\n");
      }
    }
  }
  fprintf(f4,"};\n");
  fclose(f4);

// #if defined(HAVE_ANN)
//   Msg::Info("Computing Distance function to the boundaries with ANN");
//   std::map<MVertex*,double > distance; 

//  // add all points from boundaries into kdtree
//   ANNpointArray kdnodes = annAllocPts(numnodes, 4);
//   k = 0;
//   for(unsigned int i = 0; i < entities.size()-1; i++)
//     for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
//       MVertex *v =  entities[i]->mesh_vertices[j];
//       distance.insert(std::make_pair(v, 0.0));
//       kdnodes[k][0] = v->x();
//       kdnodes[k][1] = v->y();
//       kdnodes[k][2] = v->z();
//       k++;
//     }  
//   ANNkd_tree *kdtree = new ANNkd_tree(kdnodes, numnodes, 3);

//   // compute the distances with the kdtree
//   ANNidxArray index = new ANNidx[1];
//   ANNdistArray dist = new ANNdist[1];
//   GEntity* ga = entities[entities.size()-1];
//   for(unsigned int j = 0; j < ga->mesh_vertices.size(); j++){
//     MVertex *v = ga->mesh_vertices[j];
//     double xyz[3] = {v->x(), v->y(), v->z()};
//     kdtree->annkSearch(xyz, 1, index, dist);
//     double d = sqrt(dist[0]);
//     distance.insert(std::make_pair(v, d));
//   }
//   delete [] index;
//   delete [] dist;
//   delete kdtree;
//   annDeallocPts(kdnodes);

//   //write distance in msh file
//   Msg::Info("Writing distance-ANN.pos");
//   FILE * f = fopen("distance-ANN.pos","w");
//   fprintf(f,"View \"distance ANN\"{\n");
//   for(std::map<MVertex*, double>::iterator it = distance.begin(); it != distance.end(); it++) {
//     fprintf(f,"SP(%g,%g,%g){%g};\n",
// 	    it->first->x(), it->first->y(), it->first->z(),
// 	    it->second);     
//   }
//   fprintf(f,"};\n");
//   fclose(f);

// #endif

//   Msg::Info("Writing distance-bgm.pos");
//   FILE * f2 = fopen("distance-bgm.pos","w");
//   fprintf(f2,"View \"distance\"{\n");
//   GEntity* ge = entities[entities.size()-1];
//   for(unsigned int i = 0; i < ge->getNumMeshElements(); i++){ 
//     MElement *e = ge->getMeshElement(i);
//     fprintf(f2,"ST(");//TO DO CHANGE this
//     std::vector<double> dist;
//     for(int j = 0; j < e->getNumVertices(); j++) {
//       MVertex *v =  e->getVertex(j);
//       if(j) fprintf(f2,",%g,%g,%g",v->x(),v->y(), v->z());
//       else fprintf(f2,"%g,%g,%g", v->x(),v->y(), v->z());
//       std::map<MVertex*, double>::iterator it = distance.find(v);
//       dist.push_back(it->second);
//     }
//     fprintf(f2,"){");
//     for (int i=0; i<dist.size(); i++){
//       if (i) fprintf(f2,",%g", dist[i]);
//       else fprintf(f2,"%g", dist[i]);
//     }   
//     fprintf(f2,"};\n");
//   }
//   fprintf(f2,"};\n");
//   fclose(f2);

  return 0;
}
