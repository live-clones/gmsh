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
    //printf("MLIne %d %d = (%g, %g, %g) (%g, %g, %g)\n",vL->getNum(), vR->getNum(), vL->x(),vL->y(),vL->z(), vR->x(),vR->y(),vR->z() );
    std::map<MVertex*,MLine*>::iterator it1 = boundv.find(vL);
    if (it1==boundv.end()) boundv.insert(std::make_pair(vL,*it));
    else boundv.erase(it1);
    std::map<MVertex*,MLine*>::iterator it2 = boundv.find(vR);
    if (it2==boundv.end())       boundv.insert(std::make_pair(vR,*it));
    else boundv.erase(it2);
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
    if (!found  && _orientation[0]){ //reverse orientation of first Line
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

void discreteEdge::setBoundVertices(std::vector<discreteVertex*> vertices)
{

  if (boundv.size()==2){ 
    //printf("Found a regular open Curve \n");
    std::vector<GVertex*> bound_vertices;
    for (std::map<MVertex*,MLine*>::const_iterator iter = boundv.begin(); iter != boundv.end(); iter++){
      MVertex* vE = (iter)->first;
      bool existVertex  = false;
      for (std::vector<discreteVertex*>::iterator point = vertices.begin(); point != vertices.end(); point++) {
	//printf("Discrete point =%d bound vE=%d\n", (*point)->tag(), vE->getNum());
	if ((*point)->tag() == vE->getNum()){
	  bound_vertices.push_back((*point));
	  existVertex = true;
	  break;
	}
      }
      if(!existVertex){ 
	printf(" !!! bound vertex does not exist, create one \n");
	GVertex *gvB = new discreteVertex(model(),vE->getNum());
	bound_vertices.push_back(gvB);
	gvB->mesh_vertices.push_back(vE);
	gvB->points.push_back(new MPoint(gvB->mesh_vertices.back()));
	model()->add(gvB);
	mesh_vertices.erase(std::find(mesh_vertices.begin(), mesh_vertices.end(), vE));
     }
    }
 
    //printf("set bound  vertices %d %d \n",bound_vertices[0]->tag(),bound_vertices[1]->tag());
    v0 = bound_vertices[0]; 
    v1 = bound_vertices[1];
  }
  else if (boundv.size()==0){ 
    //printf("Found a closed Curve \n");

    std::vector<MLine*>::const_iterator it = lines.begin();
    MVertex* vE = (*it)->getVertex(0);
    GVertex *gvB = new discreteVertex(model(),vE->getNum());
    gvB->mesh_vertices.push_back(vE);
    gvB->points.push_back(new MPoint(gvB->mesh_vertices.back()));
    model()->add(gvB);
    mesh_vertices.erase(std::find(mesh_vertices.begin(), mesh_vertices.end(), vE));

    //printf("set bound  vertices %d %d , coord = %g %g %g\n",gvB->tag(),gvB->tag(), gvB->x(), gvB->y(), gvB->z());
    v0 = gvB; 
    v1 = gvB;
    
  }

  v0->addEdge(this);
  v1->addEdge(this);

  return;
}

void discreteEdge::parametrize() 
{

  for (int i=0;i<lines.size()+1;i++){
    _pars.push_back(i);
  }   

  /*
    +---------------+--------------+----------- ... ----------+
    _pars[0]=0   _pars[1]=1    _pars[2]=2             _pars[N+1]=N+1
  */
  
  //    for (int i=0;i<lines.size()+1;i++){
  //      printf("_pars[%d]=%g\n",i, _pars[i] );
  //    }

  printf("dans discrete edge %d line.size =%d \n", this->tag(), lines.size());

//   std::vector<MVertex*> new_mshv;  
//   for(int i = 0; i < mesh_vertices.size(); i++){
//     MVertex *v = mesh_vertices[i];
//     int param = i+1;
//     MVertex *newv = new MEdgeVertex(v->x(),v->y(),v->z(), this, param);
//     new_mshv.push_back(newv);
//     newv->setNum(v->getNum());
//     v= newv;
//   }
//   mesh_vertices = new_mshv;

//   std::vector<MVertex*> new_mshv;
//   for(int i = 0; i < mesh_vertices.size(); i++){
//     MVertex *vi = mesh_vertices[i]; 
//     MVertex *mev = new MEdgeVertex(vi->x(),vi->y(),vi->z(), this, i+1);
//     new_mshv.push_back(mev);
//     mev->setNum(vi->getNum());

//     newLines.push_back(new MLine(v1, newv));
//     newLines.push_back(new MLine(newv, v2));
//     delete ge->lines[i];
//    for(std::list<GFace*>::iterator it = l_faces.begin(); it != l_faces.end(); ++it){
//       for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
// 	MTriangle *t = (*it)->triangles[i];
// 	for (int j = 0; j < 3; j++){
// 	  MVertex *v  = t->getVertex(j);
// 	  if (v == vi)	v = mev;
// 	}
//       }
//     }
//     delete vi ;
//   }
//   mesh_vertices = new_mshv;


// std::vector<MLine*> newLines;
// newLines.push_back(new MLine(v1, newv));
// delete lines[i];
// newLines.push_back(new MLine(newv, v2));
// lines = newLines;

  
//   for (int i = 0; i < mesh_vertices.size(); i++){
//       double t1;
//       mesh_vertices[i]->getParameter(0,t1);
//       printf("** AFTER v1=%d  t1=%g\n",  mesh_vertices[i]->getNum(),t1 );
//   }

//   for (int i = 0; i < lines.size(); i++){
//       printf("** AFTER LINES v1=%d  v2=%d\n",  lines[i]->getVertex(0)->getIndex(), lines[i]->getVertex(1)->getIndex()  );
//   }

  //exit(1);
 
}

void discreteEdge::getLocalParameter ( const double &t,
				       int &iLine,
				       double & tLoc) const
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

Range<double> discreteEdge::parBounds(int i) const {

 return Range<double>(0, lines.size()); 
 
}
