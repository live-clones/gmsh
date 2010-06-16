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

StringXNumber DistanceOptions_Number[] = {
  {GMSH_FULLRC, "Point", NULL, 0.},
  {GMSH_FULLRC, "Line", NULL, 0.},
  {GMSH_FULLRC, "Face", NULL, 0.},
  {GMSH_FULLRC, "Computation", NULL, 0.},
  //{GMSH_FULLRC, "Scale", NULL, 0.},
  //{GMSH_FULLRC, "Min Scale", NULL, 1.e-3},
  //{GMSH_FULLRC, "Max Scale", NULL, 1}
};

StringXString DistanceOptions_String[] = {
  {GMSH_FULLRC, "Filename", NULL, "distance.pos"}
};


extern "C"
{
  GMSH_Plugin *GMSH_RegisterDistancePlugin()
  {
    return new GMSH_DistancePlugin();
  }
}

std::string GMSH_DistancePlugin::getHelp() const
{
  return "Plugin(Distance) computes distances to elementary entities in "
    "a mesh.\n\n"
    
    "Define the elementary entities to which the distance is computed \n\n";

  "Computation=0 computes the geometrical distance (Warning: this is an euclidian distance and not the geodesic distance), and  Computation=1 solves a PDE on the mesh\n\n";

  "Plugin(Distance) creates a new distance view.";
}

int GMSH_DistancePlugin::getNbOptions() const
{
  return sizeof(DistanceOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DistancePlugin::getOption(int iopt)
{
  return &DistanceOptions_Number[iopt];
}

int GMSH_DistancePlugin::getNbOptionsStr() const
{
  return sizeof(DistanceOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_DistancePlugin::getOptionStr(int iopt)
{
  return &DistanceOptions_String[iopt];
}

PView *GMSH_DistancePlugin::execute(PView *v)
{

  std::string fileName = DistanceOptions_String[0].def;
  int id_pt =     (int) DistanceOptions_Number[0].def;
  int id_line =   (int) DistanceOptions_Number[1].def;
  int id_face =   (int) DistanceOptions_Number[2].def;
  int type =   (int) DistanceOptions_Number[3].def;

  PView *view = new PView();
  PViewDataList *data = getDataList(view);
 
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities);

  int numnodes = 0;
  for(unsigned int i = 0; i < entities.size() - 1; i++)
    numnodes += entities[i]->mesh_vertices.size();
  int totNumNodes = numnodes + entities[entities.size() - 1]->mesh_vertices.size();

  std::map<MVertex*,double* > distance_map_GEOM; 
  std::map<MVertex*,double > distance_map_PDE;
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
      distance_map_GEOM.insert(std::make_pair(v, &(distances[k])));
      distance_map_PDE.insert(std::make_pair(v, 0.0));
      k++;
    }
  }
  
  // Compute geometrical distance to mesh boundaries
  //------------------------------------------------------
  if (type == 0){

    for(unsigned int i = 0; i < entities.size(); i++){
      GEntity* g2 = entities[i];
      int tag = g2->tag();
      int gDim = g2->dim();
      bool computeForEntity = false;
      if (id_pt==0 && id_line==0 && id_face==0 && gDim==maxDim-1 )
	computeForEntity = true;
      else if ( (tag==id_pt && gDim==0)|| (tag==id_line && gDim==1) || (tag==id_face && gDim==2) )
	computeForEntity = true;
      if (computeForEntity){
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
    //     for(unsigned int i = 0; i < g2->getNumMeshElements(); i++)

    data->setName("distance GEOM");
    Msg::Info("Writing %g", fileName.c_str());
    FILE * f3 = fopen( fileName.c_str(),"w");
    fprintf(f3,"View \"distance GEOM\"{\n");
    for(unsigned int ii = 0; ii < entities.size(); ii++){
      if(entities[ii]->dim() == maxDim) {
	for(unsigned int i = 0; i < entities[ii]->getNumMeshElements(); i++){ 
	  MElement *e = entities[ii]->getMeshElement(i);

	  int numNodes = e->getNumVertices();
	  std::vector<double> x(numNodes), y(numNodes), z(numNodes);
	  std::vector<double> *out = data->incrementList(1, e->getType());
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->x()); 
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->y()); 
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->z()); 

	  if (maxDim == 3) fprintf(f3,"SS(");
	  else if (maxDim == 2) fprintf(f3,"ST(");
	  std::vector<double> dist;
	  for(int j = 0; j < numNodes; j++) {
	    MVertex *v =  e->getVertex(j);
	    if(j) fprintf(f3,",%g,%g,%g",v->x(),v->y(), v->z());
	    else fprintf(f3,"%g,%g,%g", v->x(),v->y(), v->z());
	    std::map<MVertex*, double*>::iterator it = distance_map_GEOM.find(v);
	    dist.push_back(*(it->second));
	  }
	  fprintf(f3,"){");
	  for (unsigned int i = 0; i < dist.size(); i++){
	    out->push_back(dist[i]);
	    if (i) fprintf(f3,",%g", dist[i]);
	    else fprintf(f3,"%g", dist[i]);
	  }   
	  fprintf(f3,"};\n");
	}
      }
    }
    fprintf(f3,"};\n");
    fclose(f3);
  }
  
  // Compute PDE for distance function
  //-----------------------------------
  else if (type == 1){

#if defined(HAVE_SOLVER)
  
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
      GEntity* ge = entities[i];
      int tag = ge->tag();
      int gDim = ge->dim();
      bool fixForEntity = false;
      if(id_pt==0 && id_line==0 && id_face==0 && gDim < maxDim) 
	fixForEntity = true;
      else if ( (tag==id_pt && gDim==0)|| (tag==id_line && gDim==1) || (tag==id_face && gDim==2) )
	fixForEntity = true;
      if (fixForEntity){
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
    double mu = L/10; //28;

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
  
    for(std::map<MVertex*,double >::iterator itv = distance_map_PDE.begin(); 
	itv !=distance_map_PDE.end() ; ++itv){
      MVertex *v = itv->first;
      double value;
      myAssembler.getDofValue(v, 0, 1, value);
      value = std::min(0.9999, value);
      double dist = -mu * log(1. - value);
      itv->second = dist;
    }
    lsys->clear();

    data->setName("distance GEOM");
  
    Msg::Info("Writing %d", fileName.c_str());
    FILE * f4 = fopen(fileName.c_str(),"w");
    fprintf(f4,"View \"distance PDE\"{\n");
    for(unsigned int ii = 0; ii < entities.size(); ii++){
      if(entities[ii]->dim() == maxDim) {
	for(unsigned int i = 0; i < entities[ii]->getNumMeshElements(); i++){ 
	  MElement *e = entities[ii]->getMeshElement(i);

	  int numNodes = e->getNumVertices();
	  std::vector<double> x(numNodes), y(numNodes), z(numNodes);
	  std::vector<double> *out = data->incrementList(1, e->getType());
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->x()); 
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->y()); 
	  for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->z()); 

	  if (maxDim == 3) fprintf(f4,"SS(");
	  else if (maxDim == 2) fprintf(f4,"ST(");
	  std::vector<double> dist;
	  for(int j = 0; j < numNodes; j++) {
	    MVertex *v =  e->getVertex(j);
	    if(j) fprintf(f4,",%g,%g,%g",v->x(),v->y(), v->z());
	    else fprintf(f4,"%g,%g,%g", v->x(),v->y(), v->z());
	    std::map<MVertex*, double>::iterator it = distance_map_PDE.find(v);
	    dist.push_back(it->second);
	  }
	  fprintf(f4,"){");
	  for (unsigned int i = 0; i < dist.size(); i++){
	    out->push_back(dist[i]);
	    if (i) fprintf(f4,",%g", dist[i]);
	    else fprintf(f4,"%g", dist[i]);
	  }   
	  fprintf(f4,"};\n");
	}
      }
    }
    fprintf(f4,"};\n");
    fclose(f4);
#endif
  }

  //FILE *fp = fopen(fileName.c_str(), "rb");
  //data->readPOS(fp, 1.0, false);

  data->Time.push_back(0);
  data->setFileName(fileName.c_str());
  data->finalize();

  return view;
}
