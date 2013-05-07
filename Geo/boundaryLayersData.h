// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _BNDRYLRDATA_
#define _BNDRYLRDATA_

#include "SVector3.h"
#include "STensor3.h"
#include "MEdge.h"
#include <map>
#include <set>

class Field;
class GFace;
class GRegion;
class MTriangle;

struct BoundaryLayerData
{
  SVector3 _n;
  std::vector<MVertex*> _column;
  std::vector<SMetric3> _metrics;
  BoundaryLayerData(){}
  BoundaryLayerData(const SVector3 & dir,
                    std::vector<MVertex*> column,
                    std::vector<SMetric3> metrics)
    : _n(dir), _column(column), _metrics(metrics){}
};

struct BoundaryLayerFan
{
  MEdge _e1, _e2;
  bool sense;
  BoundaryLayerFan(MEdge e1, MEdge e2 , bool s = true)
    : _e1(e1),_e2(e2) , sense (s){}
};

struct edgeColumn {
  const BoundaryLayerData &_c1, &_c2;
  edgeColumn(const BoundaryLayerData &c1, const BoundaryLayerData &c2)
    : _c1(c1), _c2(c2){}
};

class BoundaryLayerColumns
{
  std::multimap<MVertex*, BoundaryLayerData>  _data;
  std::map<MVertex*, BoundaryLayerFan> _fans;
public:
  size_t size () const {return _data.size();}
  typedef std::multimap<MVertex*,BoundaryLayerData>::iterator iter;
  typedef std::map<MVertex*, BoundaryLayerFan>::iterator iterf;
  std::multimap<MVertex*, MVertex*> _non_manifold_edges;
  std::multimap<MVertex*,MTriangle*> _non_manifold_faces;
  std::multimap<MEdge, SVector3, Less_Edge> _normals;
  iter begin() { return _data.begin(); }
  iter end() { return _data.end(); }
  iterf beginf() { return _fans.begin(); }
  iterf endf() { return _fans.end(); }
  BoundaryLayerColumns (){}
  inline void addColumn(const SVector3 &dir, MVertex* v,
                        std::vector<MVertex*> _column,
                        std::vector<SMetric3> _metrics)
  {
    _data.insert (std::make_pair(v,BoundaryLayerData(dir, _column,_metrics)));
  }
  inline void addFan(MVertex *v, MEdge e1, MEdge e2, bool s)
  {
    _fans.insert(std::make_pair(v,BoundaryLayerFan(e1,e2,s)));
  }
  inline const BoundaryLayerData &getColumn(MVertex *v, MEdge e)
  {
    std::map<MVertex*,BoundaryLayerFan>::const_iterator it = _fans.find(v);
    int N = getNbColumns(v) ;
    if (N == 1) return getColumn(v, 0);
    Equal_Edge aaa;
    if (it != _fans.end()){
      if (aaa(it->second._e1, e))
	return getColumn(v, 0);
      else
	return getColumn(v, N-1);
    }
    Msg::Error("Cannot handle embedded lines in boundary layers");
    static BoundaryLayerData error;
    return error;
  }
  edgeColumn getColumns(MVertex *v1, MVertex *v2 , int side);
  inline int getNbColumns(MVertex *v) { return _data.count(v); }
  inline const BoundaryLayerData &getColumn(MVertex *v, int iColumn)
  {
    int count = 0;
    for(std::multimap<MVertex*,BoundaryLayerData>::iterator itm  = _data.lower_bound(v);
        itm != _data.upper_bound(v); ++itm){
      if (count++ == iColumn) return itm->second;
    }
    static BoundaryLayerData error;
    return error;
  }
  void filterPoints();
};

bool buildAdditionalPoints2D (GFace *gf, BoundaryLayerColumns * ) ;
bool buildAdditionalPoints3D (GRegion *gr, BoundaryLayerColumns * ) ;
void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3]);

#endif
