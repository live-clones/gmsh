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
#include "MElement.h"
#include "Distance.h"
#include "Context.h"
#include "Numeric.h"

#if defined(HAVE_SOLVER)
#include "simpleFunction.h"
#include "distanceTerm.h"
#include "dofManager.h"
#include "linearSystemGMM.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "orthogonalTerm.h"
#include "laplaceTerm.h"
#include "crossConfTerm.h"
#endif

StringXNumber DistanceOptions_Number[] = {
  {GMSH_FULLRC, "PhysPoint", NULL, 0.},
  {GMSH_FULLRC, "PhysLine", NULL, 0.},
  {GMSH_FULLRC, "PhysSurface", NULL, 0.},
  {GMSH_FULLRC, "Computation", NULL, -1},
  {GMSH_FULLRC, "MinScale", NULL, -1},
  {GMSH_FULLRC, "MaxScale", NULL, -1},
  {GMSH_FULLRC, "Orthogonal", NULL, -1}
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
GMSH_DistancePlugin::GMSH_DistancePlugin() 
{
  _fileName = "text";
  _minScale = 0.0;
  _maxScale = 0.0;
  _maxDim = 0;
  _data = NULL;
}

std::string GMSH_DistancePlugin::getHelp() const
{
  return "Plugin(Distance) computes distances to physical entities in "
    "a mesh.\n\n"
    
    "Define the physical entities to which the distance is computed. "
    "If Point=0, Line=0, and Surface=0, then the distance is computed "
    "to all the boundaries of the mesh (edges in 2D and faces in 3D).\n\n"

    "Computation<0. computes the geometrical euclidian distance "
    "(warning: different than the geodesic distance), and  Computation=a>0.0 "
    "solves a PDE on the mesh with the diffusion constant mu = a*bbox, with "
    "bbox being the max size of the bounding box of the mesh (see paper "
    "Legrand 2006).\n\n"

    "Min Scale and max Scale, scale the distance function. If min Scale<0 "
    "and max Scale<0, then no scaling is applied to the distance function.\n\n"

    "Plugin(Distance) creates a new distance view and also saves the view "
    "in the fileName.pos file.";
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

void GMSH_DistancePlugin::printView(std::vector<GEntity*> _entities,  
				    std::map<MVertex*,double > _distance_map )
{

  _fileName = DistanceOptions_String[0].def;    
  _minScale = (double) DistanceOptions_Number[4].def;
  _maxScale = (double) DistanceOptions_Number[5].def;

  double minDist=1.e4;
  double maxDist=0.0;
  for(std::map<MVertex*,double >::iterator itv = _distance_map.begin(); 
      itv != _distance_map.end() ; ++itv){
    double dist = itv->second;
    if (dist > maxDist) maxDist = dist;
    if (dist < minDist) minDist = dist;
    itv->second = dist;
  }

  Msg::Info("Writing %s",_fileName.c_str());
  FILE * fName = fopen(_fileName.c_str(),"w");
  fprintf(fName,"View \"distance \"{\n");
  for(unsigned int ii = 0; ii < _entities.size(); ii++){
    if(_entities[ii]->dim() == _maxDim) {
      for(unsigned int i = 0; i < _entities[ii]->getNumMeshElements(); i++){ 
	MElement *e = _entities[ii]->getMeshElement(i);
	
	int numNodes = e->getNumVertices();
	std::vector<double> x(numNodes), y(numNodes), z(numNodes);
	std::vector<double> *out = _data->incrementList(1, e->getType());
	for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->x()); 
	for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->y()); 
	for(int nod = 0; nod < numNodes; nod++) out->push_back((e->getVertex(nod))->z()); 
	
	if (_maxDim == 3) fprintf(fName,"SS(");
	else if (_maxDim == 2) fprintf(fName,"ST(");
	std::vector<double> dist;
	for(int j = 0; j < numNodes; j++) {
	  MVertex *v =  e->getVertex(j);
	  if(j) fprintf(fName,",%g,%g,%g",v->x(),v->y(), v->z());
	  else fprintf(fName,"%g,%g,%g", v->x(),v->y(), v->z());
	  std::map<MVertex*, double>::iterator it = _distance_map.find(v);
	  dist.push_back(it->second);
	}
	fprintf(fName,"){");
	for (unsigned int i = 0; i < dist.size(); i++){
	  if (_minScale > 0 && _maxScale > 0) 
	    dist[i]=_minScale+((dist[i]-minDist)/(maxDist-minDist))*(_maxScale-_minScale);
	  else if  (_minScale > 0 && _maxScale < 0)
	    dist[i]=_minScale+dist[i];
	  out->push_back(dist[i]);
	  if (i) fprintf(fName,",%g", dist[i]);
	  else fprintf(fName,"%g", dist[i]);
	}   
	fprintf(fName,"};\n");
      }
    }
  }
  fprintf(fName,"};\n");
  fclose(fName);

}

PView *GMSH_DistancePlugin::execute(PView *v)
{
  int id_pt =     (int) DistanceOptions_Number[0].def;
  int id_line =   (int) DistanceOptions_Number[1].def;
  int id_face =   (int) DistanceOptions_Number[2].def;
  double type =   (double) DistanceOptions_Number[3].def;
  int  ortho =   (int) DistanceOptions_Number[6].def;
  
  PView *view = new PView();
  _data = getDataList(view);

#if defined(HAVE_SOLVER)
#if defined(HAVE_TAUCS)
  linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
#else
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
  lsys->setNoisy(1);
  lsys->setGmres(1);
  lsys->setPrec(5.e-8);
#endif
  dofManager<double> * dofView = new dofManager<double>(lsys);
#endif
    
  std::vector<GEntity*> _entities;
  GModel::current()->getEntities(_entities);
  GEntity* ge = _entities[_entities.size()-1];
  int integrationPointTetra[2];
  if (type==-100){
    integrationPointTetra[0]=1;
    integrationPointTetra[1]=4;
  }
  else{
    integrationPointTetra[0]=0;
    integrationPointTetra[1]=0;
  }

  int numnodes = 0;
  for(unsigned int i = 0; i < _entities.size()-1; i++)
    numnodes += _entities[i]->mesh_vertices.size();
  int totNodes=numnodes + _entities[_entities.size()-1]->mesh_vertices.size();
  int order=ge->getMeshElement(0)->getPolynomialOrder();
  int totNumNodes = totNodes+ge->getNumMeshElements()*integrationPointTetra[order-1];

  if (totNumNodes ==0) {
    Msg::Error("This plugin needs a mesh !");
    return view;
  }
  
  std::map<MVertex*,double > _distance_map;
  std::vector<SPoint3> pts;
  std::vector<double> distances;
  std::vector<MVertex* > pt2Vertex;
  pts.clear(); 
  distances.clear();
  pt2Vertex.clear();
  pts.reserve(totNumNodes);
  distances.reserve(totNumNodes);
  pt2Vertex.reserve(totNumNodes);

  std::map<MVertex*,double> _distanceE_map;
  std::map<MVertex*,int> _isInYarn_map;
  std::vector<int> index;
  std::vector<double> distancesE;
  std::vector<int> isInYarn;
  std::vector<SPoint3> closePts;
  std::vector<double> distances2;
  std::vector<double> distancesE2;
  std::vector<int> isInYarn2;
  std::vector<SPoint3> closePts2;

  if (type==-100){
    index.clear();
    distancesE.clear();
    closePts.clear();
    isInYarn.clear();
    isInYarn.reserve(totNumNodes);
    closePts.reserve(totNumNodes);
    distancesE.reserve(totNumNodes);
    index.reserve(totNumNodes);
    distances2.clear();
    distancesE2.clear();
    closePts2.clear();
    isInYarn2.clear();
    distances2.reserve(totNumNodes);
    isInYarn2.reserve(totNumNodes);
    closePts2.reserve(totNumNodes);
    distancesE2.reserve(totNumNodes);
  }

  for (int i = 0; i < totNumNodes; i++) {
    distances.push_back(1.e22);
    if (type==-100){
      distancesE.push_back(1.e22);
      isInYarn.push_back(0);
      closePts.push_back(SPoint3(0.,0.,0.));
      distances2.push_back(1.e22);
      distancesE2.push_back(1.e22);
      isInYarn2.push_back(0);
      closePts2.push_back(SPoint3(0.,0.,0.));
    }
  }

  int k = 0;
  for(unsigned int i = 0; i < _entities.size(); i++){
    GEntity* ge = _entities[i]; 
    _maxDim = std::max(_maxDim, ge->dim());
    for(unsigned int j = 0; j < ge->mesh_vertices.size(); j++){
      MVertex *v = ge->mesh_vertices[j];
      pts.push_back(SPoint3(v->x(), v->y(),v->z()));
      _distance_map.insert(std::make_pair(v, 0.0));
      if (type==-100){
        index.push_back(v->getIndex());
        _isInYarn_map.insert(std::make_pair(v, 0));
        _distanceE_map.insert(std::make_pair(v, 0.0));
      }
      pt2Vertex[k] = v;
      k++;
    }
  }

  if (type==-100){
  double jac[3][3];
  for (unsigned int i = 0; i < ge->getNumMeshElements(); i++){ 
    MElement *e = ge->getMeshElement(i);
    IntPt *ptsi;
    int nptsi;
    double uvw[4][3];
    e->getIntegrationPoints(e->getPolynomialOrder(),&nptsi, &ptsi);
    for(int j = 0; j < 4; j++) {
      double xyz[3] = {e->getVertex(j)->x(),
                       e->getVertex(j)->y(),
                       e->getVertex(j)->z()};
      e->xyz2uvw(xyz, uvw[j]);
    }

    for(int ip = 0; ip < nptsi; ip++){
      const double u = ptsi[ip].pt[0];
      const double v = ptsi[ip].pt[1];
      const double w = ptsi[ip].pt[2];
      const double weight = ptsi[ip].weight;
      const double detJ = e->getJacobian(u, v, w, jac);
      SPoint3 p; 
      e->pnt(u, v, w, p);
      pts.push_back(p);
    }
  }
  }

  // Compute geometrical distance to mesh boundaries
  //------------------------------------------------------
  if (type < 0.0 ){

    bool existEntity = false;
    for(unsigned int i = 0; i < _entities.size(); i++){
      GEntity* g2 = _entities[i];
      int tag = g2->tag();
      int gDim = g2->dim();
      std::vector<int> phys = g2->getPhysicalEntities();
      bool computeForEntity = false;
      for(unsigned int k = 0; k< phys.size(); k++){
	int tagp = phys[k];
	if (id_pt==0 && id_line==0 && id_face==0 && gDim==_maxDim-1 )
	  computeForEntity = true;
	else if ( (tagp==id_pt && gDim==0)|| (tagp==id_line && gDim==1) ||
                  (tagp==id_face && gDim==2) )
	  computeForEntity = true;
      }
      if (computeForEntity){
	existEntity = true;
	for(unsigned int k = 0; k < g2->getNumMeshElements(); k++){ 
	  std::vector<double> iDistances;
	  std::vector<SPoint3> iClosePts;
          std::vector<double> iDistancesE;
          std::vector<int> iIsInYarn;
	  MElement *e = g2->getMeshElement(k);
	  MVertex *v1 = e->getVertex(0);
	  MVertex *v2 = e->getVertex(1);
	  SPoint3 p1(v1->x(), v1->y(), v1->z());
	  SPoint3 p2(v2->x(), v2->y(), v2->z());
	  if((e->getNumVertices() == 2 && order==1) || 
             (e->getNumVertices() == 3 && order==2)){
            if (type==-100){
//              if ( !((p1.x()==p2.x()) & (p1.y()==p2.y()) & (p1.z()==p2.z())) ){
              signedDistancesPointsEllipseLine(iDistances, iDistancesE,
                                               iIsInYarn, iClosePts, pts, p1,p2);
//              }
            }
            else{
	      signedDistancesPointsLine(iDistances, iClosePts, pts, p1,p2);
            }
	  }
	  else if(e->getNumVertices() == 3 && order==1){
	    MVertex *v3 = e->getVertex(2);
	    SPoint3 p3 (v3->x(),v3->y(),v3->z());
	    signedDistancesPointsTriangle(iDistances, iClosePts, pts, p1, p2, p3);
	  }
	  for (unsigned int kk = 0; kk< pts.size(); kk++) {
            if (type==-100){
            if( !((p1.x()==p2.x()) & (p1.y()==p2.y()) & (p1.z()==p2.z()))){
              if (iIsInYarn[kk]>0){
	        if (isInYarn[kk]==0){
                  distances[kk] = iDistances[kk];
	          distancesE[kk]= iDistancesE[kk];
                  isInYarn[kk] = iIsInYarn[kk];
                  closePts[kk]= SPoint3(iClosePts[kk].x(),iClosePts[kk].y(),
                                        iClosePts[kk].z());
	        }
                else{
	          if (isInYarn[kk]!=iIsInYarn[kk]){
	            if (isInYarn2[kk]==0){
		      distances2[kk] = iDistances[kk];
	              distancesE2[kk]= iDistancesE[kk];
                      isInYarn2[kk] = iIsInYarn[kk];
                      closePts2[kk]= SPoint3(iClosePts[kk].x(),iClosePts[kk].y(),
                                             iClosePts[kk].z());
	            }
                    else{
		      if (isInYarn2[kk]==iIsInYarn[kk]){
		        if (iDistancesE[kk] < distancesE2[kk]){
		          distances2[kk] = iDistances[kk];
		          distancesE2[kk]= iDistancesE[kk];
                          closePts2[kk]= SPoint3(iClosePts[kk].x(),iClosePts[kk].y(),
                                                 iClosePts[kk].z());
		        }
		      }
	            }
	          }
                  else{
	            if (iDistancesE[kk] < distancesE[kk]){ 
	 	      distances[kk] = iDistances[kk];
		      distancesE[kk]= iDistancesE[kk];
		      closePts[kk]= SPoint3(iClosePts[kk].x(),iClosePts[kk].y(),
                                            iClosePts[kk].z());
                    }
	          }
	        }
	      }
              else{
	        if (isInYarn[kk]==0){
	           if (iDistancesE[kk] < distancesE[kk]){
                      distances[kk] = iDistances[kk];
                      distancesE[kk]= iDistancesE[kk];
                      closePts[kk]= SPoint3(iClosePts[kk].x(),iClosePts[kk].y(),
                                            iClosePts[kk].z());
                   }
	        }
	      }
            }
            }
            else{
	      if (fabs(iDistances[kk]) < distances[kk]){
	        distances[kk] = fabs(iDistances[kk]);
	        MVertex *v = pt2Vertex[kk];
	        _distance_map[v] = distances[kk];
              }
	    }
	  }
	}
      }
    }
    if (type==-100){
      for (unsigned int kk = 0; kk< pts.size(); kk++) {
        if (isInYarn2[kk]>0){
          if (distancesE2[kk]>distancesE[kk]){
            distances[kk]=distances2[kk];
	    distancesE[kk]=distancesE2[kk];
	    isInYarn[kk]=isInYarn2[kk];
	    closePts[kk]=closePts2[kk];
          }
        }
        if (kk<totNodes){
          MVertex *v = pt2Vertex[kk];
	  _distance_map[v] = distancesE[kk];
          _distanceE_map[v] = distances[kk];
          _isInYarn_map[v] = isInYarn[kk];
        }
      }
    }
    if (!existEntity){
      if (id_pt != 0) Msg::Error("The Physical Point does not exist !");
      if (id_line != 0) Msg::Error("The Physical Line does not exist !");
      if (id_face != 0) Msg::Error("The Physical Surface does not exist !");
      return view;
    }
    printView(_entities, _distance_map);
    if (type==-100){
      Msg::Info("Writing integrationPointInYarn.pos");
      FILE* f5 = fopen("integrationPointInYarn.pos","w");
      FILE* f6 = fopen("integrationPointInYarn.bin","wb");
      FILE* f7 = fopen("integrationPointInYarn.txt","w");
      int j=0;
      fprintf(f5,"View \"integrationPointInYarn\"{\n");
      for (std::vector<int>::iterator it = isInYarn.begin(); it !=isInYarn.end(); it++) {
        if (j>=totNodes){
          int iPIY=*it;
          fwrite(&iPIY,sizeof(int),1,f6);
          fprintf(f7,"%d %lf %lf %lf\n",iPIY,pts[j].x(),  pts[j].y(),  pts[j].z());
          fprintf(f5,"SP(%g,%g,%g){%d};\n",
                  pts[j].x(),  pts[j].y(),  pts[j].z(),
                  *it);
        }
        j++;
      }
      fclose(f6);
      fclose(f7);
      fprintf(f5,"};\n");
      fclose(f5);
      
      Msg::Info("Writing isInYarn.pos");
      FILE * f4 = fopen("isInYarn.pos","w");
      fprintf(f4,"View \"isInYarn\"{\n");
      for(unsigned int i = 0; i < ge->getNumMeshElements(); i++){ 
        MElement *e = ge->getMeshElement(i);
        fprintf(f4,"SS(");
        std::vector<int> inYarn;
        for(int j = 0; j < e->getNumVertices(); j++) {
          MVertex *v =  e->getVertex(j);
          if(j) fprintf(f4,",%g,%g,%g",v->x(),v->y(), v->z());
          else fprintf(f4,"%g,%g,%g", v->x(),v->y(), v->z());
          std::map<MVertex*, int>::iterator it = _isInYarn_map.find(v);
          inYarn.push_back(it->second);
        }
        fprintf(f4,"){");
        for (unsigned int i=0; i<inYarn.size(); i++){
          if (i) fprintf(f4,",%d", inYarn[i]);
          else fprintf(f4,"%d", inYarn[i]);
        }
        fprintf(f4,"};\n");
      }
      fprintf(f4,"};\n");
      fclose(f4);
    }
    
  }
  
  // Compute PDE for distance function
  //-----------------------------------
  else if (type > 0.0){
    
#if defined(HAVE_SOLVER)
    
    bool existEntity = false;
    SBoundingBox3d bbox;
    for(unsigned int i = 0; i < _entities.size(); i++){
      GEntity* ge = _entities[i];
      int tag = ge->tag();
      int gDim = ge->dim();
      bool fixForEntity = false;
      std::vector<int> phys = ge->getPhysicalEntities();
      for(unsigned int k = 0; k< phys.size(); k++){
	int tagp = phys[k];
	if (id_pt==0 && id_line==0 && id_face==0 && gDim==_maxDim-1 )
	  fixForEntity = true;
	else if ( (tagp==id_pt && gDim==0)|| (tagp==id_line && gDim==1) || 
                  (tagp==id_face && gDim==2) )
	  fixForEntity = true;
      }
      if (fixForEntity){
	existEntity = true;
	for(unsigned int i = 0; i < ge->getNumMeshElements(); ++i){
	  MElement *t = ge->getMeshElement(i);
	  for(int k = 0; k < t->getNumVertices(); k++){
	    MVertex *v = t->getVertex(k);
	    dofView->fixVertex(v, 0, 1, 0.0);
	    bbox += SPoint3(v->x(),v->y(),v->z());
	  }
	}
      }
    }
    if (!existEntity){
      if (id_pt != 0) Msg::Error("The Physical Point does not exist !");
      if (id_line != 0) Msg::Error("The Physical Line does not exist !");
      if (id_face != 0) Msg::Error("The Physical Surface does not exist !");
      return view;
    }

    std::vector<MElement *> allElems;
    for(unsigned int ii = 0; ii < _entities.size(); ii++){
      if(_entities[ii]->dim() == _maxDim) {
	GEntity *ge = _entities[ii];
	for(unsigned int i = 0; i < ge->getNumMeshElements(); ++i){
	  MElement *t = ge->getMeshElement(i);
	  allElems.push_back(t);
	  for(int k = 0; k < t->getNumVertices(); k++){
	    dofView->numberVertex(t->getVertex(k), 0, 1);
	  }
	}    
      }  
    }
    
    double L = norm(SVector3(bbox.max(), bbox.min())); 
    double mu = type*L;
    
    simpleFunction<double> DIFF(mu*mu), ONE(1.0);
    distanceTerm distance(GModel::current(), 1, &DIFF, &ONE);
    
    for (std::vector<MElement* >::iterator it = allElems.begin(); it != allElems.end(); it++){
      SElement se((*it));
      distance.addToMatrix(*dofView, &se);
    }
    groupOfElements gr(allElems);
    distance.addToRightHandSide(*dofView, gr);
    
    Msg::Info("Distance Computation: Assembly done");
    lsys->systemSolve();
    Msg::Info("Distance Computation: System solved");
    
    for(std::map<MVertex*,double >::iterator itv = _distance_map.begin(); 
	itv != _distance_map.end() ; ++itv){
      MVertex *v = itv->first;
      double value;
      dofView->getDofValue(v, 0, 1, value);
      value = std::min(0.9999, value);
      double dist = -mu * log(1. - value);
      itv->second = dist;
    }
    
    printView(_entities, _distance_map);
    
#endif
  }

  _data->setName("distance");
  _data->Time.push_back(0);
  _data->setFileName(_fileName.c_str());
  _data->finalize();
  
  
  //compute also orthogonal vector to distance field
  // A Uortho = -C DIST 
  //------------------------------------------------
  if (ortho > 0){
#if defined(HAVE_SOLVER)
  
#ifdef HAVE_TAUCS
  linearSystemCSRTaucs<double> *lsys2 = new linearSystemCSRTaucs<double>;
#else
  linearSystemCSRGmm<double> *lsys2 = new linearSystemCSRGmm<double>;
  lsys->setNoisy(1);
  lsys->setGmres(1);
  lsys->setPrec(5.e-8);
#endif
  dofManager<double> myAssembler(lsys2);
  simpleFunction<double> ONE(1.0);
  
  double dMax = 1.0; //EMI TO CHANGE
  
  std::vector<MElement *> allElems;
  for(unsigned int ii = 0; ii < _entities.size(); ii++){
    if(_entities[ii]->dim() == _maxDim) {
      GEntity *ge = _entities[ii];
      for(unsigned int i = 0; i < ge->getNumMeshElements(); ++i){
	MElement *t = ge->getMeshElement(i);
	double vMean = 0.0;
	for(int k = 0; k < t->getNumVertices(); k++){
	  std::map<MVertex*, double>::iterator it = _distance_map.find(t->getVertex(k));
	  vMean += it->second;
	}
	vMean/=t->getNumVertices();
	if (vMean < dMax)   
	  allElems.push_back(ge->getMeshElement(i));
      }
    }
  }  
  int mid = (int)floor(allElems.size() / 2.);
  MElement *e = allElems[mid];
  MVertex *vFIX = e->getVertex(0);
  myAssembler.fixVertex(vFIX, 0, 1, 0.0);
  
  for (std::vector<MElement* >::iterator it = allElems.begin(); it != allElems.end(); it++){
    MElement *t = *it;
    for(int k = 0; k < t->getNumVertices(); k++)
      myAssembler.numberVertex(t->getVertex(k), 0, 1);
  }
  
  orthogonalTerm *ortho;
  ortho  = new orthogonalTerm(GModel::current(), 1, &ONE, &_distance_map);
  // if (type  < 0)
  //   ortho  = new orthogonalTerm(GModel::current(), 1, &ONE, view);
  // else
  //   ortho  = new orthogonalTerm(GModel::current(), 1, &ONE, dofView);
  
  for (std::vector<MElement* >::iterator it = allElems.begin(); it != allElems.end(); it++){
    SElement se((*it));
    ortho->addToMatrix(myAssembler, &se);
  }
  groupOfElements gr(allElems);
  ortho->addToRightHandSide(myAssembler, gr);
  
  Msg::Info("Orthogonal Computation: Assembly done");
  lsys2->systemSolve();
  Msg::Info("Orthogonal Computation: System solved");
  
  PView *view2 = new PView();
  PViewDataList *data2 = getDataList(view2);
  data2->setName("ortogonal field");
  
  Msg::Info("Writing  orthogonal.pos");
  FILE * f5 = fopen("orthogonal.pos","w");
  fprintf(f5,"View \"orthogonal\"{\n");
  for (std::vector<MElement* >::iterator it = allElems.begin(); it != allElems.end(); it++){
    MElement *e = *it;
    
    int numNodes = e->getNumVertices();
    std::vector<double> x(numNodes), y(numNodes), z(numNodes);
    std::vector<double> *out2 = data2->incrementList(1, e->getType());
    for(int nod = 0; nod < numNodes; nod++) out2->push_back((e->getVertex(nod))->x()); 
    for(int nod = 0; nod < numNodes; nod++) out2->push_back((e->getVertex(nod))->y()); 
    for(int nod = 0; nod < numNodes; nod++) out2->push_back((e->getVertex(nod))->z()); 
    
    if (_maxDim == 3) fprintf(f5,"SS(");
    else if (_maxDim == 2) fprintf(f5,"ST(");
    std::vector<double> orth;
    for(int j = 0; j < numNodes; j++) {
      MVertex *v =  e->getVertex(j);
      if(j) fprintf(f5,",%g,%g,%g",v->x(),v->y(), v->z());
      else fprintf(f5,"%g,%g,%g", v->x(),v->y(), v->z());
      double value;
      myAssembler.getDofValue(v, 0, 1,  value );
      orth.push_back(value);
    }
    fprintf(f5,"){");
    for (unsigned int i = 0; i < orth.size(); i++){
      out2->push_back(orth[i]);
      if (i) fprintf(f5,",%g", orth[i]);
      else fprintf(f5,"%g", orth[i]);
    }   
    fprintf(f5,"};\n");
  }
  fprintf(f5,"};\n");
  fclose(f5);

  lsys->clear();
  lsys2->clear();

  data2->Time.push_back(0);
  data2->setFileName("orthogonal.pos");
  data2->finalize();
  
#endif
  }

  //-------------------------------------------------
  
  return view;
}
