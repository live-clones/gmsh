#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include "GRegion.h"
#include "MTetrahedron.h"
#include "MFace.h"

struct neighborContainer
{
  MTetrahedron *neigh[4];
  neighborContainer (){
    neigh[0] = neigh[1] = neigh[2] = neigh[3] = nullptr;
  }
};

double alphaShape (MTetrahedron *t){
  return t->gammaShapeMeasure();
}

int alphaShapes (GRegion *gr, double threshold,
		 std::vector<std::vector<MTetrahedron*> > &domains,
		 std::vector<std::vector<MFace> > &boundaries) {

  std::unordered_map<MTetrahedron*, neighborContainer> t2a;
  for (auto t : gr->tetrahedra)t2a[t] = neighborContainer();

  std::map< MFace, MTetrahedron *, MFaceLessThan> f2t;
  for (auto t : gr->tetrahedra){
    std::unordered_map<MTetrahedron*, neighborContainer>::iterator it1 = t2a.find(t);
    for (int i=0;i<4;i++){
      MFace f = t->getFace(i);
      std::map< MFace, MTetrahedron *, MFaceLessThan>::iterator it = f2t.find(f);
      if (it == f2t.end()){
	f2t[f] = t;
      }
      else {
	std::unordered_map<MTetrahedron*, neighborContainer>::iterator it2 = t2a.find(it->second);
	it1->second.neigh[i] = it2->first;
	for (int k=0;k<4;k++){
	  if (f == it2->first->getFace(k))
	    it2->second.neigh[k] = it1->first;
	}
	f2t.erase(it);
      }
    }    
  }

  std::unordered_set<MTetrahedron*> _touched;
  
  for (std::unordered_map<MTetrahedron*, neighborContainer>::iterator it = t2a.begin() ; it != t2a.end() ; ++it){
    if (alphaShape(it->first) > threshold && _touched.find(it->first) == _touched.end()){
      std::stack<MTetrahedron*> _s;
      std::vector<MTetrahedron*> _domain;
      std::vector<MFace> _boundary;
      _s.push(it->first);
      _touched.insert(it->first);
      _domain.push_back(it->first);
      while(!_s.empty()){
	MTetrahedron *t = _s.top();
	std::unordered_map<MTetrahedron*, neighborContainer>::iterator itx = t2a.find(t);
	_s.pop();
	for (int i=0;i<4;i++){
	  if (!itx->second.neigh[i])_boundary.push_back(itx->first->getFace(i));
	  else if (_touched.find(itx->second.neigh[i]) == _touched.end()){
	    if (alphaShape(itx->second.neigh[i]) > threshold){
	      _s.push(itx->second.neigh[i]);
	      _touched.insert(itx->second.neigh[i]);
	      _domain.push_back(itx->second.neigh[i]);	    
	    }	    
	    else {
	      _boundary.push_back(itx->first->getFace(i));
	    }
	  }
	}	  
      }
      boundaries.push_back(_boundary);
      domains.push_back(_domain);
    }
  }
  return 0;
}
