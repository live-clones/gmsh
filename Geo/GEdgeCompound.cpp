// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
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

GEdgeCompound::GEdgeCompound(GModel *m, int tag, std::vector<GEdge*> &compound, 
                             std::vector<int> &orientation)
  : GEdge(m, tag, 0, 0), _compound(compound), _orientation(orientation)
{
 
  int N = _compound.size();
  v0 = _orientation[0] ? _compound[0]->getBeginVertex() : _compound[0]->getEndVertex();
  v1 = _orientation[N-1] ? _compound[N-1]->getEndVertex() : _compound[N-1]->getBeginVertex();
  v0->addEdge(this);
  v1->addEdge(this);

  for (unsigned int i = 0; i < _compound.size(); i++)
    _compound[i]->setCompound(this);

  for(std::vector<GEdge*>::iterator it = _compound.begin(); it != _compound.end(); ++it){
    if(!(*it)){
      Msg::Error("Incorrect edge in compound edge %d\n", tag);
      Msg::Exit(1);
    }
  }

 parametrize();
}

GEdgeCompound::GEdgeCompound(GModel *m, int tag, std::vector<GEdge*> &compound)
  : GEdge(m, tag, 0 , 0), _compound(compound)
{
  orderEdges ();
  int N = _compound.size();
  v0 = _orientation[0] ? _compound[0]->getBeginVertex() : _compound[0]->getEndVertex();
  v1 = _orientation[N-1] ? _compound[N-1]->getEndVertex() :  _compound[N-1]->getBeginVertex();
  v0->addEdge(this);
  v1->addEdge(this);

  for (unsigned int i = 0; i < _compound.size(); i++)
    _compound[i]->setCompound(this);

  parametrize();
}

void GEdgeCompound::orderEdges()
{
  std::vector<GEdge*> _c ;  
  std::list<GEdge*> edges ;  

  for (unsigned int i = 0; i < _compound.size(); i++){
    edges.push_back(_compound[i]);
  }

  // find a lonely edge
  std::map<GVertex*,GEdge*> tempv;
  for (std::list<GEdge*>::iterator it = edges.begin() ; it != edges.end() ; ++it){
    GVertex *v1 = (*it)->getBeginVertex();
    GVertex *v2 = (*it)->getEndVertex();
    std::map<GVertex*,GEdge*>::iterator it1 = tempv.find(v1);
    if (it1==tempv.end()) {
      tempv.insert(std::make_pair(v1,*it));
    }
    else tempv.erase(it1);
    std::map<GVertex*,GEdge*>::iterator it2 = tempv.find(v2);
    if (it2==tempv.end()){
      tempv.insert(std::make_pair(v2,*it));
    }
    else tempv.erase(it2);
  }

  //find the first GEdge and erase it from the list edges
  GEdge *firstEdge;
  if (tempv.size() == 2){   // non periodic
    firstEdge = (tempv.begin())->second;
    for (std::list<GEdge*>::iterator it = edges.begin() ; it != edges.end() ; ++it){
      if (*it == firstEdge){
        edges.erase(it);
        break;
      }
    }    
  }
  else if (tempv.size() == 0){ // periodic
    firstEdge = *(edges.begin());
    edges.erase(edges.begin());
  }
  else{
    Msg::Error("EdgeCompound %d is wrong (it has %d end points)",tag(),tempv.size());
    return;
  }

  // loop over all segments to order segments and store it in the list _c
  _c.push_back(firstEdge); 
  _orientation.push_back(1);
  GVertex *first = _c[0]->getBeginVertex();
  GVertex *last = _c[0]->getEndVertex();  
  
  while (first != last){
    if (edges.empty())break;
    bool found = false;
    for (std::list<GEdge*>::iterator it = edges.begin() ; it != edges.end() ; ++it){
      GEdge *e = *it;
      std::list<GEdge*>::iterator itp;
     if (e->getBeginVertex() == last){
        _c.push_back(e); 
        itp = it;
        it++;
        edges.erase(itp);
        _orientation.push_back(1);
        last = e->getEndVertex();
        found = true;
        break;
      }
      else if (e->getEndVertex() == last){
        _c.push_back(e); 
        itp = it;
        it++;
        edges.erase(itp);
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
    for (unsigned int i = 0; i < _compound.size(); i++){
      _orientation[i] = !_orientation[i] ;
    }
  }
}

int GEdgeCompound::minimumMeshSegments() const
{
  // int N = 0;
  // for (unsigned int i = 0; i < _compound.size(); i++) 
  //   N +=_compound[i]->minimumMeshSegments();
  return 3;
}

int GEdgeCompound::minimumDrawSegments() const
{
  int N = 0;
  for (unsigned int i = 0; i < _compound.size(); i++)
    N += _compound[i]->minimumDrawSegments();
  return N;
}

GEdgeCompound::~GEdgeCompound()
{
}

Range<double> GEdgeCompound::parBounds(int i) const
{ 
  return Range<double>(0, _pars[_compound.size()]); 
}

/*
  +--------+-----------+----------- ... ----+
  0      _pars[1]     _pars[2]              _pars[N-1]

*/

void GEdgeCompound::getLocalParameter(const double &t,
                                      int &iEdge,
                                      double & tLoc) const
{
  for (iEdge = 0; iEdge < (int)_compound.size(); iEdge++){
    double tmin = _pars[iEdge];
    double tmax = _pars[iEdge+1];
    if (t >= tmin && t <= tmax){      
      Range<double> b = _compound[iEdge]->parBounds(0);
      tLoc = _orientation[iEdge] ?
        b.low()  + (t-tmin)/(tmax-tmin) * (b.high()-b.low()) :
        b.high() - (t-tmin)/(tmax-tmin) * (b.high()-b.low()) ;
      return;
    }
  }
}

void GEdgeCompound::getCompoundParameter(GEdge *ge,
                                         const double &tLoc,
                                         double &t) const
{
  for (int iEdge = 0; iEdge < (int)_compound.size(); iEdge++){
    if (ge == _compound[iEdge]){
      double tmin = _pars[iEdge];
      double tmax = _pars[iEdge+1];
      Range<double> b = _compound[iEdge]->parBounds(0);
      t = _orientation[iEdge] ? 
        tmin + (tLoc - b.low())/(b.high()-b.low()) * (tmax-tmin):
        tmax - (tLoc - b.low())/(b.high()-b.low()) * (tmax-tmin);
      return;
    }
  }
}

void GEdgeCompound::parametrize() 
{
  _pars.push_back(0.0);
  for (unsigned int i = 0; i < _compound.size(); i++){
    Range<double> b = _compound[i]->parBounds(0);
    _pars.push_back(_pars[_pars.size()-1]+(b.high() - b.low()));
  }   
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
  return _compound[iEdge]->point(tLoc);
}

SVector3 GEdgeCompound::firstDer(double par) const
{
  double tLoc;
  int iEdge;
  getLocalParameter(par,iEdge,tLoc);
  return _compound[iEdge]->firstDer(tLoc);
} 

void replaceMeshCompound(GFace *gf, std::list<GEdge*> &edges)
{
  std::list<GEdge*> e = gf->edges();
  // replace edges by their compounds
  std::set<GEdge*> mySet;
  std::list<GEdge*>::iterator it = e.begin();
  while(it != e.end()){
    if((*it)->getCompound()){
      mySet.insert((*it)->getCompound());
    }
    else{ 
      mySet.insert(*it);
    }
    ++it;
  }
  edges.clear();
  edges.insert(edges.begin(), mySet.begin(), mySet.end());
}
