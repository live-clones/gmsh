// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GEdgeCompound.h"
#include "Numeric.h"

GEdgeCompound::GEdgeCompound(GModel *m, int tag, std::vector<GEdge*> &compound)
  : GEdge(m, tag, 0 , 0), _compound(compound)
{
  orderEdges ();
  int N = _compound.size();
  v0 = _orientation[0] ?     _compound[0]->getBeginVertex() : _compound[0]->getEndVertex();
  v1 = _orientation[N-1] ? _compound[N-1]->getEndVertex() :   _compound[N-1]->getBeginVertex();
  v0->addEdge(this);
  v1->addEdge(this);
  parametrize();
}

void GEdgeCompound::orderEdges()
{
  std::list<GEdge*> edges ;  
  std::vector<GEdge*> _c ;  
  for (int i=0;i<_compound.size();i++){
    _compound[i]->setCompound(this);
    edges.push_back(_compound[i]);
  }
  _c.push_back(*(edges.begin())); 
  edges.erase(edges.begin());
  _orientation.push_back(true);
  GVertex *first = _c[0]->getBeginVertex();
  GVertex *last = _c[0]->getEndVertex();  

  while (first != last){
    if (edges.empty())break;
    for (std::list<GEdge*>::iterator it = edges.begin() ; it != edges.end() ; ++it){
      GEdge *e = *it;
      //      printf("last %d edge %d %d\n",last->tag(),e->getBeginVertex()->tag(),
      //	     e->getEndVertex()->tag());
      if (e->getBeginVertex() == last){
	_c.push_back(e); 
	edges.erase(it);
	_orientation.push_back(true);
	last = e->getEndVertex();
	break;
      }
      else if (e->getEndVertex() == last){
	_c.push_back(e); 
	edges.erase(it);
	_orientation.push_back(false);
	last = e->getBeginVertex();
	break;
      }
    }
  }  
  _compound = _c;
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
  return Range<double>(0, _pars[_compound.size()-1]); 
}

/*
  +--------+-----------+----------- ... ----+
  0      _par[1]     _par[2]              _par[N-1]

*/

void GEdgeCompound::getLocalParameter ( const double &t,
					int &iEdge,
					double & tLoc) const
{
  for (iEdge=0 ; iEdge<_compound.size() ;iEdge++){
    //    printf("iEdge %d par %g\n",iEdge,_pars[iEdge]);
    if (t <= _pars[iEdge]){
      tLoc = _orientation[iEdge] ? t - _pars[iEdge] : _pars[iEdge+1] - t;
      return;
    }
  }
}

void GEdgeCompound::parametrize() 
{
  for (int i=0;i<_compound.size();i++){
    Range<double> b = _compound[i]->parBounds(0);
    if (!i)_pars.push_back(b.high() - b.low());
    else _pars.push_back(_pars[i-1]+(b.high() - b.low()));
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
  //  printf("compound %d par %g edge %d loc %g\n",tag(),par,iEdge,tLoc);
  return _compound[iEdge]->point(tLoc);
}

SVector3 GEdgeCompound::firstDer(double par) const
{
  double tLoc;
  int iEdge;
  getLocalParameter(par,iEdge,tLoc);
  return _compound[iEdge]->firstDer(tLoc);
} 

