#ifndef _MESHGFACE_BNDRYLR_
#define _MESHGFACE_BNDRYLR_

#include "STensor3.h"
#include "MEdge.h"
#include <map>
#include <set>
class Field;
class GFace;
struct BoundaryLayerData
{
  BoundaryLayerData (std::vector<MVertex*> column,
		     std::vector<SMetric3> metrics)
    : _column(column),_metrics(metrics)
  {
    
  }
  std::vector<MVertex*> _column;
  std::vector<SMetric3> _metrics;    
};

struct BoundaryLayerFan 
{
  MEdge _e1, _e2;
  bool sense;
  BoundaryLayerFan (MEdge e1, MEdge e2 , bool s = true) 
  : _e1(e1),_e2(e2) , sense (s)
  {}
};

class BoundaryLayerColumns  
{
  std::multimap<MVertex*,BoundaryLayerData>  _data;
  std::map<MVertex*,BoundaryLayerFan> _fans;
public:
  typedef  std::multimap<MVertex*,BoundaryLayerData>::iterator iter;
  typedef  std::map<MVertex*,BoundaryLayerFan>::iterator iterf;
  std::multimap<MVertex*,MVertex*> _non_manifold_edges;
  iter begin() {return _data.begin();}
  iter end() {return _data.end();}
  iterf beginf() {return _fans.begin();}
  iterf endf() {return _fans.end();}
  BoundaryLayerColumns () 
  {    
  }
  inline void addColumn (MVertex* v,
		  std::vector<MVertex*> _column,
		  std::vector<SMetric3> _metrics){
    _data.insert (std::make_pair(v,BoundaryLayerData(_column,_metrics)));
  }
  inline void addFan (MVertex *v, MEdge e1, MEdge e2, bool s){
    _fans.insert(std::make_pair(v,BoundaryLayerFan(e1,e2,s)));
  }
  
  inline const BoundaryLayerData & getColumn ( MVertex *v, MEdge e ){
    std::map<MVertex*,BoundaryLayerFan>::const_iterator it = _fans.find(v);
    int N =  getNbColumns (v) ;
    if (N == 1) return getColumn(v,0);
    Equal_Edge aaa;
    if (it != _fans.end()){
      if (aaa(it->second._e1,e))
	return getColumn ( v, 0 );
      else
	return  getColumn ( v, N-1 );
    }
    else printf("ooops\n");
  }


  inline int getNbColumns (MVertex *v) {
    return _data.count (v);
  }
  inline const BoundaryLayerData & getColumn ( MVertex *v, int iColumn ){
    int count = 0;
    for ( std::multimap<MVertex*,BoundaryLayerData> :: iterator itm  = _data.lower_bound(v);
	  itm != _data.upper_bound(v); ++itm)
      {
	if (count++ == iColumn) return itm->second;
      }    
  }
  void filterPoints();
};


BoundaryLayerColumns * buidAdditionalPoints2D (GFace *gf,  double _angle) ;
void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3]);


#endif
