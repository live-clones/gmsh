// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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

#include <vector>
#include <list>

#if !defined(HAVE_GMSH_EMBEDDED)
#include "Geo.h"
#endif

discreteEdge::discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1)
  : GEdge(model, num, _v0, _v1)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  Curve *c = Create_Curve(num, MSH_SEGM_DISCRETE, 0, 0, 0, -1, -1, 0., 1.);
  Tree_Add(model->getGEOInternals()->Curves, &c);
  CreateReversedCurve(c);
#endif
}

void discreteEdge::orderMLines() 
{
  //printf(" *** ORDERING DISCRETE EDGE %d of size %d \n", this->tag(), lines.size());

  std::vector<MLine*> _m ;  
  std::list<MLine*> segments;

  //store all lines in a list : segments
  for (int i=0;i<lines.size();i++){
    //printf("BEFORE ORDERING segment i=%d, vert=%d, %d\n", i, lines[i]->getVertex(0)->getNum(), lines[i]->getVertex(1)->getNum() );
    segments.push_back(lines[i]);
  }

  // find a lonly MLine
  for (std::list<MLine*>::iterator it = segments.begin() ; it != segments.end() ; ++it){
    MVertex *vL = (*it)->getVertex(0);
    MVertex *vR = (*it)->getVertex(1);
    std::map<MVertex*,MLine*>::iterator it1 = boundv.find(vL);
    if (it1==boundv.end())       boundv.insert(std::make_pair(vL,*it));
    else  boundv.erase(it1);
    std::map<MVertex*,MLine*>::iterator it2 = boundv.find(vR);
    if (it2==boundv.end())    boundv.insert(std::make_pair(vR,*it));
    else    boundv.erase(it2);
  }   

  //find the first MLine and erase it from the list segments
  MLine *firstLine;
  if (boundv.size()==2){   // non periodic
    firstLine = (boundv.begin())->second;
    for (std::list<MLine*>::iterator it = segments.begin() ; it != segments.end() ; ++it){
      if (*it == firstLine){
	segments.erase(it);
	break;
      }
    }    
  }
  else if (boundv.size()==0) // periodic
    {
      firstLine = *(segments.begin());
      segments.erase(segments.begin());
    }
  else{
    Msg::Error("EdgeCompound %d is wrong (it has %d end points)",tag(),boundv.size());
  }

  //loop over all segments to order segments and store it in the list _m
  _m.push_back(firstLine); 
  _orientation.push_back(1);
  MVertex *first = _m[0]->getVertex(0);
  MVertex *last = _m[0]->getVertex(1);   
  //printf("first =%d last =%d \n", first->getNum(), last->getNum());
  while (first != last){
    if (segments.empty())break;
    bool found = false;
    for (std::list<MLine*>::iterator it = segments.begin() ; it != segments.end() ; ++it){
      MLine *e = *it;
      if (e->getVertex(0) == last){
	//printf("orientation 1: beginV=%d \n", e->getVertex(0)->getNum());
	_m.push_back(e); 
	segments.erase(it);
	_orientation.push_back(1);
	last = e->getVertex(1);
	found = true;
	break;
      }
      else if (e->getVertex(1) == last){
	//printf("orientation 0: endV=%d \n", e->getVertex(1)->getNum());
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

  //special case reverse orientation 
  if (lines.size() < 2) return;
  if (_orientation[0] && lines[0]->getVertex(1) != lines[1]->getVertex(1) 
      && lines[0]->getVertex(1) != lines[1]->getVertex(0)){  
    printf("coucou here \n");
    for (int i=0;i<lines.size();i++) _orientation[i] = !_orientation[i] ;
  }
 
//   for (int i=0;i<lines.size();i++){
//     printf("AFTER ORDERING segment or=%d, vert=%d, %d\n", (int)_orientation[i], lines[i]->getVertex(0)->getNum(), lines[i]->getVertex(1)->getNum() );
//   }


  return;

}

void discreteEdge::setBoundVertices()
{

  if (boundv.size()==2){ 
    //printf("Found a regular open Curve \n");
    std::vector<GVertex*> bound_vertices;
    for (std::map<MVertex*,MLine*>::const_iterator iter = boundv.begin(); iter != boundv.end(); iter++){
      MVertex* vE = (iter)->first;
      bool existVertex  = false;
      for(GModel::viter point = model()->firstVertex(); point != model()->lastVertex(); point++){
	//printf("Discrete point =%d %d  bound vE=%d %d\n",(*point)->tag(), (*point)->mesh_vertices[0]->getNum(), vE->getNum(), vE->getIndex());
	if ((*point)->mesh_vertices[0]->getNum() == vE->getNum()){
	  bound_vertices.push_back((*point));
	  existVertex = true;
	  break;
	}
      }
      if(!existVertex){ 
	//printf(" !!! bound vertex %d does not exist, create one \n", vE->getNum());
	GVertex *gvB = new discreteVertex(model(),vE->getNum());
	bound_vertices.push_back(gvB);
	vE->setEntity(gvB);
	gvB->mesh_vertices.push_back(vE);
	gvB->points.push_back(new MPoint(gvB->mesh_vertices.back()));
	model()->add(gvB);
     }
      std::vector<MVertex*>::iterator itve = std::find(mesh_vertices.begin(), mesh_vertices.end(), vE) ;
      if (itve != mesh_vertices.end()) mesh_vertices.erase(itve);

    }
 
    //printf("set bound  vertices %d %d size mesh-vertices =%d \n",bound_vertices[0]->tag(),bound_vertices[1]->tag(), mesh_vertices.size());
    v0 = bound_vertices[0]; 
    v1 = bound_vertices[1];
  }
  else if (boundv.size()==0){ 
    //printf("Found a closed Curve add vertex \n");

    std::vector<MLine*>::const_iterator it = lines.begin();
    MVertex* vE = (*it)->getVertex(0);
    GVertex *gvB = new discreteVertex(model(),vE->getNum());
    gvB->mesh_vertices.push_back(vE);
    gvB->points.push_back(new MPoint(gvB->mesh_vertices.back()));
    model()->add(gvB);
    mesh_vertices.erase(std::find(mesh_vertices.begin(), mesh_vertices.end(), vE));

    ///printf("set bound  vertices %d %d , coord = %g %g %g\n",gvB->tag(),gvB->tag(), gvB->x(), gvB->y(), gvB->z());
    v0 = gvB; 
    v1 = gvB;
    
  }

  v0->addEdge(this);
  v1->addEdge(this);

  return;
}


/*
    +---------------+--------------+----------- ... ----------+
    _pars[0]=0   _pars[1]=1    _pars[2]=2             _pars[N+1]=N+1
*/
void discreteEdge::parametrize() 
{

  
  for (int i=0;i<lines.size()+1;i++){
    _pars.push_back(i);
  } 

  //Replace MVertex by MedgeVertex
  //we need to recreate lines, triangles and tets 
  //that contain those new MEdgeVertices
  std::map<MVertex*, MVertex*> old2new;

  std::vector<MVertex*> newVertices;
  std::vector<MLine*> newLines;
  
  MVertex *vL = getBeginVertex()->mesh_vertices[0];
  int i = 0;
  for(i=0 ; i < lines.size()-1; i++){
    MVertex *vR ; 
    if (_orientation[i] == 1 ) vR = lines[i]->getVertex(1);
    else vR = lines[i]->getVertex(0);
    int param = i+1;
    MVertex *vNEW = new MEdgeVertex(vR->x(),vR->y(),vR->z(), this, param);
    old2new.insert(std::make_pair(vR,vNEW));
    newVertices.push_back(vNEW);
    vNEW->setNum(vR->getNum());
    newLines.push_back(new MLine(vL, vNEW));
    _orientation[i] = 1;
    //printf("i edge =%d , orientation=%d , mesh vertex =%p (%d) newv=%p (%d)  \n", i, _orientation[i], vL, vL->getNum(), vNEW, vNEW->getNum());
    vL = vNEW;
  }
   MVertex *vR = getEndVertex()->mesh_vertices[0];
   newLines.push_back(new MLine(vL, vR));
   _orientation[i] = 1;
   //printf("i edge =%d , orientation=%d , mesh vertex =%p (%d) newv=%p (%d)  \n", i, _orientation[i], vL, vL->getNum(), vR, vR->getNum());

   mesh_vertices = newVertices;
   deleteVertexArrays();
   lines.clear();
   lines = newLines;

   for(std::list<GFace*>::iterator iFace = l_faces.begin(); iFace != l_faces.end(); ++iFace){
     std::vector<MTriangle*> newTriangles;
     std::vector<MQuadrangle*> newQuadrangles;
     for (unsigned int i = 0; i < (*iFace)->getNumMeshElements(); ++i){
       MElement *e = (*iFace)->getMeshElement(i);
       int N = e->getNumVertices();
       MVertex *v[N];
       for(int j = 0; j < N; j++){
	 v[j] = e->getVertex(j);
       }
	//printf("old triangle v0=%p (%d) v1=%p (%d) v2=%p (%d) \n",v[0], v[0]->getNum() , v[1],v[1]->getNum() ,v[2], v[2]->getNum());
 	for (int j = 0; j < N; j++){	 
 	  std::map<MVertex*, MVertex*>::iterator itmap = old2new.find(v[j]);
 	  MVertex *vNEW;
 	  if (itmap != old2new.end())  {
 	    vNEW = itmap->second;
	    v[j]=vNEW;
  	  }
  	}
  	//printf(" new triangle v0=%p (%d) v1=%p (%d) v2=%p (%d) \n",v[0], v[0]->getNum() , v[1],v[1]->getNum() ,v[2], v[2]->getNum());
	if (N == 3) newTriangles.push_back(new  MTriangle(v[0], v[1], v[2]));  
	else if ( N == 4)  newQuadrangles.push_back(new  MQuadrangle(v[0], v[1], v[2], v[3]));

      }
     (*iFace)->deleteVertexArrays();
     (*iFace)->triangles.clear();
     (*iFace)->triangles = newTriangles;
     (*iFace)->quadrangles.clear();
     (*iFace)->quadrangles = newQuadrangles;
   }


   //for(std::list<GRegion*>::iterator iRegion = l_regions.begin(); iRegion != l_regions.end(); ++iRegion){
   for(GModel::riter iRegion = model()->firstRegion(); iRegion != model()->lastRegion(); iRegion++){
     std::vector<MTetrahedron*> newTetrahedra;
     std::vector<MHexahedron*> newHexahedra;
     std::vector<MPrism*> newPrisms;
     std::vector<MPyramid*> newPyramids;
     for (unsigned int i = 0; i < (*iRegion)->getNumMeshElements(); ++i){
       MElement *e = (*iRegion)->getMeshElement(i);
       int N = e->getNumVertices();
       MVertex *v[N];
       for(int j = 0; j < N; j++){
	 v[j] = e->getVertex(j);
       }
 	for (int j = 0; j < N; j++){	 
 	  std::map<MVertex*, MVertex*>::iterator itmap = old2new.find(v[j]);
 	  MVertex *vNEW;
 	  if (itmap != old2new.end())  {
 	    vNEW = itmap->second;
	    v[j]=vNEW;
  	  }
  	}
	if (N == 4) newTetrahedra.push_back(new  MTetrahedron(v[0], v[1], v[2], v[3]));  
	else if ( N == 5)  newPyramids.push_back(new  MPyramid(v[0], v[1], v[2], v[3], v[4]));
	else if ( N == 6)  newPrisms.push_back(new  MPrism(v[0], v[1], v[2], v[3], v[4], v[5]));
	else if ( N == 8)  newHexahedra.push_back(new  MHexahedron(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7]));
      }
     (*iRegion)->deleteVertexArrays();
     (*iRegion)->tetrahedra.clear();
     (*iRegion)->tetrahedra = newTetrahedra;
     (*iRegion)->pyramids.clear();
     (*iRegion)->pyramids = newPyramids;
     (*iRegion)->prisms.clear();
     (*iRegion)->prisms = newPrisms;
     (*iRegion)->hexahedra.clear();
     (*iRegion)->hexahedra = newHexahedra;

   }



//   for (int i = 0; i < mesh_vertices.size(); i++){
//       double t1;
//       mesh_vertices[i]->getParameter(0,t1);
//       printf("** AFTER v1=%d  t1=%g\n",  mesh_vertices[i]->getNum(),t1 );
//   }
 
 
}

void discreteEdge::getLocalParameter(const double &t, int &iLine, 
                                     double &tLoc) const
{
  for (iLine=0 ; iLine<lines.size() ;iLine++){
    double tmin = _pars[iLine];
    double tmax = _pars[iLine+1];
    if (t >= tmin && t <= tmax){      
      tLoc = _orientation[iLine] ? (t-tmin)/(tmax-tmin)  :  1 - (t-tmin)/(tmax-tmin)  ;
      //printf("getlocal param t=%g, iLine=%d, tLoc=%g \n", t, iLine, tLoc);
      return;
    }
  }
}

GPoint discreteEdge::point(double par) const 
{
  
  double tLoc;
  int iEdge;
  getLocalParameter(par,iEdge,tLoc);

  double x, y, z;
  MVertex *vB = lines[iEdge]->getVertex(0);
  MVertex *vE = lines[iEdge]->getVertex(1);

  x = vB->x() + tLoc * (vE->x()- vB->x());
  y = vB->y() + tLoc * (vE->y()- vB->y());
  z = vB->z() + tLoc * (vE->z()- vB->z());

  //printf("dans point par=%d iEdge =%d, tLoc=%d \n", par, iEdge, tLoc);
  //printf("Discrete Edge POint par=%g, x= %g, y = %g, z = %g \n", par, x,y,z);
  return GPoint(x,y,z);
}

SVector3 discreteEdge::firstDer(double par) const 
{
  double tLoc;
  int iEdge;
  getLocalParameter(par,iEdge,tLoc);

  MVertex *vB = lines[iEdge]->getVertex(0);
  MVertex *vE = lines[iEdge]->getVertex(1);

  double dx,dy,dz;
  double dt = sqrt((vE->x()-vB->x())*(vE->x()-vB->x()) + (vE->y()-vB->y())*(vE->y()-vB->y()) + (vE->z()-vB->z())*(vE->z()-vB->z()));
  dx = (vE->x() - vB->x() ) /dt;
  dy = (vE->y() - vB->y() ) /dt;
  dz = (vE->z() - vB->z() ) /dt;

  //printf("firstDer discreteEdge  par=%g, dx=%g, dy=%g dz=%g dt=%g \n", par,dx,dy,dz, dt);
  return SVector3(dx,dy,dz);
}

Range<double> discreteEdge::parBounds(int i) const 
{
  return Range<double>(0, lines.size()); 
}
