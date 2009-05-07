// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Emilie Marchandise
//

#include <stdlib.h>
#include "GmshConfig.h"
#include "GEdgeCompound.h"
#include "Numeric.h"

GEdgeCompound::GEdgeCompound(GModel *m, int tag, std::vector<GEdge*> &compound)
  : GEdge(m, tag, 0 , 0), _compound(compound)
{
  orderEdges ();
  int N = _compound.size();
  v0 = _orientation[0] ?   _compound[0]->getBeginVertex() :     _compound[0]->getEndVertex();
  v1 = _orientation[N-1] ? _compound[N-1]->getEndVertex() :   _compound[N-1]->getBeginVertex();
  //printf("vertices of compound %d -> %d\n",v0->tag(),v1->tag());
  v0->addEdge(this);
  v1->addEdge(this);

  parametrize();
}

void GEdgeCompound::orderEdges()
{
  std::vector<GEdge*> _c ;  
  std::list<GEdge*> edges ;  

  for (int i=0;i<_compound.size();i++){
    //printf("set compound %d for edge %d \n", tag(), _compound[i]->tag());
    _compound[i]->setCompound(this);
    edges.push_back(_compound[i]);
  }

 // find a lonly edge
  std::map<GVertex*,GEdge*> tempv;
  for (std::list<GEdge*>::iterator it = edges.begin() ; it != edges.end() ; ++it){
    GVertex *v1 = (*it)->getBeginVertex();
    GVertex *v2 = (*it)->getEndVertex();
    //printf("BEFORE ORDERING segment vert=%d,  %d \n", v1->tag(), v2->tag());
    std::map<GVertex*,GEdge*>::iterator it1 = tempv.find(v1);
    if (it1==tempv.end()) {
      //printf("insert v1=%d \n", v1->tag());
      tempv.insert(std::make_pair(v1,*it));
    }
    else tempv.erase(it1);
    std::map<GVertex*,GEdge*>::iterator it2 = tempv.find(v2);
    if (it2==tempv.end()){
      //printf("insert v2=%d \n", v2->tag());
      tempv.insert(std::make_pair(v2,*it));
    }
    else tempv.erase(it2);
  }

 //find the first GEdge and erase it from the list edges
  GEdge *firstEdge;
  if (tempv.size()==2){   // non periodic
    firstEdge = (tempv.begin())->second;
    for (std::list<GEdge*>::iterator it = edges.begin() ; it != edges.end() ; ++it){
      if (*it == firstEdge){
	edges.erase(it);
	break;
      }
    }    
  }
  else if (tempv.size()==0) // periodic
    {
      firstEdge = *(edges.begin());
      edges.erase(edges.begin());
    }
  else{
    Msg::Error("EdgeCompound %d is wrong (it has %d end points)",tag(),tempv.size());
    exit(1);
  }

  //loop over all segments to order segments and store it in the list _c
  _c.push_back(firstEdge); 
  _orientation.push_back(1);
  GVertex *first = _c[0]->getBeginVertex();
  GVertex *last = _c[0]->getEndVertex();  
  
  while (first != last){
    if (edges.empty())break;
    bool found = false;
    for (std::list<GEdge*>::iterator it = edges.begin() ; it != edges.end() ; ++it){
      GEdge *e = *it;
     if (e->getBeginVertex() == last){
	_c.push_back(e); 
	edges.erase(it);
	_orientation.push_back(1);
	last = e->getEndVertex();
	found = true;
	break;
      }
      else if (e->getEndVertex() == last){
	_c.push_back(e); 
	edges.erase(it);
	_orientation.push_back(0);
	last = e->getBeginVertex();
	found = true;
	break;
      }
    }
    if (!found){
      if (_c.size() == 1 && _orientation[0]){
	GVertex *temp = first;
	first = last;
	last = temp;
	_orientation[0] = 0;
     }
      else {
	Msg::Error("Compound Edge %d is wrong",tag());
	return;
      }
    }
  }  

  //edges is now a list of ordered GEdges
  _compound = _c;

  //special case reverse orientation 
  if (_compound.size() < 2)return;
  if (_orientation[0] && _compound[0]->getEndVertex() != _compound[1]->getEndVertex() 
      && _compound[0]->getEndVertex() != _compound[1]->getBeginVertex()){  
    //    printf("coucou again\n");
    for (int i=0;i<_compound.size();i++){
      _orientation[i] = !_orientation[i] ;
    }
  }

//   for (int i=0;i<_compound.size();i++){
//     printf("i = %d , o %d e %d (%d,%d)\n",
// 	   i, (int)_orientation[i],
// 	   _compound[i]->tag(),
// 	   _compound[i]->getBeginVertex()->tag(),
// 	   _compound[i]->getEndVertex()->tag());
//  }
//   exit(1);
  
  return;

}

int GEdgeCompound::minimumMeshSegments() const{
  int N = 0;
  for (int i=0;i<_compound.size();i++)N +=_compound[i]->minimumMeshSegments();
  return N;
}
int GEdgeCompound::minimumDrawSegments() const{
  int N = 0;
  for (int i=0;i<_compound.size();i++)N +=_compound[i]->minimumDrawSegments();
  return N;
}


GEdgeCompound::~GEdgeCompound()
{
}

Range<double> GEdgeCompound::parBounds(int i) const { 
  return Range<double>(0, _pars[_compound.size()]); 
}

/*
  +--------+-----------+----------- ... ----+
  0      _pars[1]     _pars[2]              _pars[N-1]

*/

void GEdgeCompound::getLocalParameter ( const double &t,
					int &iEdge,
					double & tLoc) const
{

  for (iEdge=0 ; iEdge<_compound.size() ;iEdge++){
    //printf("iEdge=%d tmin=%g\n",iEdge,_pars[iEdge]);
    double tmin = _pars[iEdge];
    double tmax = _pars[iEdge+1];
    if (t >= tmin && t <= tmax){      
      Range<double> b = _compound[iEdge]->parBounds(0);
      tLoc = _orientation[iEdge] ?
	b.low()  + (t-tmin)/(tmax-tmin) * (b.high()-b.low()) :
	b.high() - (t-tmin)/(tmax-tmin) * (b.high()-b.low()) ;
      //printf("bhigh=%g, blow=%g, global t=%g , tLoc=%g ,iEdge=%d\n",b.high(), b.low(), t,tLoc,iEdge);
      return;
    }
  }
}

void GEdgeCompound::parametrize() 
{
  _pars.push_back(0.0);
  for (int i=0;i<_compound.size();i++){
    Range<double> b = _compound[i]->parBounds(0);
    _pars.push_back(_pars[_pars.size()-1]+(b.high() - b.low()));
  }   
  
  // for (int i=0;i<_compound.size()+1;i++){
  // printf("_pars[%d]=%g\n",i, _pars[i] );
  //}

}


double GEdgeCompound::curvature(double par) const
{
  double tLoc;
  int iEdge;
  getLocalParameter(par,iEdge,tLoc);
  return _compound[iEdge]->curvature(tLoc);
}

GPoint GEdgeCompound::point(double par) const
{
  double tLoc;
  int iEdge;
  getLocalParameter(par,iEdge,tLoc);
  //printf("compound %d par %g edge %d loc %g\n",tag(),par,iEdge,tLoc);
  return _compound[iEdge]->point(tLoc);
}

SVector3 GEdgeCompound::firstDer(double par) const
{
  double tLoc;
  int iEdge;
  getLocalParameter(par,iEdge,tLoc);
  return _compound[iEdge]->firstDer(tLoc);
} 

