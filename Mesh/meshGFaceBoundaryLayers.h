#ifndef _MESHGFACE_BNDRYLR_
#define _MESHGFACE_BNDRYLR_

#include "SVector3.h"
#include "STensor3.h"
#include "MEdge.h"
#include <map>
#include <set>
class Field;
class GFace;
struct BoundaryLayerData
{
  BoundaryLayerData (const SVector3 & dir, 
		     std::vector<MVertex*> column,
		     std::vector<SMetric3> metrics)
  : _n(dir), _column(column),_metrics(metrics)
  {
    
  }  
  SVector3 _n;
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

struct edgeColumn {
  const BoundaryLayerData & _c1, &_c2;
  edgeColumn (const BoundaryLayerData & c1, const BoundaryLayerData & c2) : _c1(c1),_c2(c2){}
};

class BoundaryLayerColumns  
{
  std::multimap<MVertex*,BoundaryLayerData>  _data;
  std::map<MVertex*,BoundaryLayerFan> _fans;
public:
  typedef  std::multimap<MVertex*,BoundaryLayerData>::iterator iter;
  typedef  std::map<MVertex*,BoundaryLayerFan>::iterator iterf;
  std::multimap<MVertex*,MVertex*> _non_manifold_edges;
  std::multimap<MEdge,SVector3,Less_Edge> _normals;
  iter begin() {return _data.begin();}
  iter end() {return _data.end();}
  iterf beginf() {return _fans.begin();}
  iterf endf() {return _fans.end();}
  BoundaryLayerColumns () 
  {    
  }
  inline void addColumn (const SVector3 &dir, MVertex* v,
		  std::vector<MVertex*> _column,
		  std::vector<SMetric3> _metrics){
    _data.insert (std::make_pair(v,BoundaryLayerData(dir, _column,_metrics)));
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
    else Msg::Error("CANNOT HANDLE EMBEDDED LINES IN BLs");
  }
  
  inline edgeColumn getColumns ( MVertex *v1, MVertex *v2 , int side ){
    Equal_Edge aaa;
    MEdge e(v1,v2);
    std::map<MVertex*,BoundaryLayerFan>::const_iterator it1 = _fans.find(v1);
    std::map<MVertex*,BoundaryLayerFan>::const_iterator it2 = _fans.find(v2);
    int N1 =  getNbColumns (v1) ;
    int N2 =  getNbColumns (v2) ;

    int nbSides = _normals.count(e);

    //    if (nbSides != 1)printf("I'm here %d sides\n",nbSides);
    // Standard case, only two extruded columns from the two vertices
    if (N1 == 1 && N2 == 1) return edgeColumn(getColumn(v1,0),getColumn(v2,0));
    // one fan on 
    if (nbSides == 1){
      if (it1 != _fans.end() && it2 == _fans.end() ){
	if (aaa(it1->second._e1,e))
	  return edgeColumn(getColumn (v1,0),getColumn(v2,0));
	else
	  return edgeColumn(getColumn (v1,N1-1),getColumn(v2,0));
      }
      if (it2 != _fans.end() && it1 == _fans.end() ){
	if (aaa(it2->second._e1,e))
	  return edgeColumn(getColumn (v1,0),getColumn(v2,0));
	else
	  return edgeColumn(getColumn (v1,0),getColumn(v2,N2-1));
      }      
      
      if (N1 == 1 || N2 == 2){
	const BoundaryLayerData & c10 = getColumn(v1,0);
	const BoundaryLayerData & c20 = getColumn(v2,0);
	const BoundaryLayerData & c21 = getColumn(v2,1);
	if (dot(c10._n,c20._n) > dot(c10._n,c21._n) ) return edgeColumn(c10,c20);
	else return edgeColumn(c10,c21);
      }
      if (N1 == 2 || N2 == 1){
	const BoundaryLayerData & c10 = getColumn(v1,0);
	const BoundaryLayerData & c11 = getColumn(v1,1);
	const BoundaryLayerData & c20 = getColumn(v2,0);
	if (dot(c10._n,c20._n) > dot(c11._n,c20._n) ) return edgeColumn(c10,c20);
	else return edgeColumn(c11,c20);
      }

      Msg::Error ("Impossible Boundary Layer Configuration : one side and no fans");
      // FIXME WRONG
      return N1 ? edgeColumn (getColumn (v1,0),getColumn(v1,0)) : edgeColumn (getColumn (v2,0),getColumn(v2,0)); 
    }
    else if (nbSides == 2){
      if (it1 == _fans.end() && it2 == _fans.end() ){
	if (N1 != 2 || N2 != 2){
	  Msg::Error ("Impossible Boundary Layer Configuration");
	  // FIXME WRONG
	  return N1 ? edgeColumn (getColumn (v1,0),getColumn(v1,0)) : edgeColumn (getColumn (v2,0),getColumn(v2,0)); 
	}
	//	printf("coucou side %d %d %d\n",side,N1,N2);
	const BoundaryLayerData & c10 = getColumn(v1,0);
	const BoundaryLayerData & c11 = getColumn(v1,1);
	const BoundaryLayerData & c20 = getColumn(v2,0);
	const BoundaryLayerData & c21 = getColumn(v2,1);
	if (side == 0){
	  if (dot(c10._n,c20._n) > dot(c10._n,c21._n) ) return edgeColumn(c10,c20);
	  else return edgeColumn(c10,c21);
	}
	if (side == 1){
	  if (dot(c11._n,c20._n) > dot(c11._n,c21._n) ) return edgeColumn(c11,c20);
	  else return edgeColumn(c11,c21);
	}
      }
    }
    else {
      Msg::Error ("Not yet Done in BoundaryLayerData");
    }
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


BoundaryLayerColumns * buidAdditionalPoints2D (GFace *gf) ;
void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3]);


#endif
