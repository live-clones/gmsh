// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _BNDRYLRDATA_
#define _BNDRYLRDATA_

#include "SVector3.h"
#include "STensor3.h"
#include "MElement.h"
#include "MEdge.h"
#include "MFace.h"
#include <map>
#include <set>

class GFace;
class GRegion;
class MTriangle;
class BoundaryLayerField;

const int USEFANS__ = 1;

struct BoundaryLayerData
{
  SVector3 _n;
  std::vector<MVertex*> _column;
  //  std::vector<SMetric3> _metrics;
  //  std::vector<GFace*> _joint;
  BoundaryLayerData(){}
  BoundaryLayerData(const SVector3 & dir,
                    std::vector<MVertex*> column/*,
						  std::vector<SMetric3> metrics*/)
  : _n(dir), _column(column) /*,_metrics(metrics)*/{}
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
  std::map<MVertex*, BoundaryLayerFan> _fans;
public:
  // Element columns
  std::map<MElement*,MElement*> _toFirst;
  std::map<MElement*,std::vector<MElement*> > _elemColumns;  

  std::map<MFace, GFace*, Less_Face> _inverse_classification;
  std::multimap<MVertex*, BoundaryLayerData>  _data;
  size_t size () const {return _data.size();}
  typedef std::multimap<MVertex*,BoundaryLayerData>::iterator iter;
  typedef std::map<MVertex*, BoundaryLayerFan>::iterator iterf;
  std::multimap<MVertex*, MVertex*> _non_manifold_edges;
  std::multimap<MEdge, SVector3, Less_Edge> _normals;
  void clearData () {
    _toFirst.clear();
    _elemColumns.clear();
    _inverse_classification.clear();
    _data.clear();
    _normals.clear();
    _non_manifold_edges.clear();
    _elemColumns.clear();
    _fans.clear();
  }

  iter begin() { return _data.begin(); }
  iter end() { return _data.end(); }
  iterf beginf() { return _fans.begin(); }
  iterf endf() { return _fans.end(); }
  BoundaryLayerColumns (){}
  inline void addColumn(const SVector3 &dir, MVertex* v,
                        std::vector<MVertex*> _column//,
			//                        std::vector<SMetric3> _metrics,
			//                        std::vector<GFace*> _joint
			)
  {
    _data.insert (std::make_pair(v,BoundaryLayerData(dir, _column/*,_metrics,_joint*/)));
  }
  inline void addFan(MVertex *v, MEdge e1, MEdge e2, bool s)
  {
    _fans.insert(std::make_pair(v,BoundaryLayerFan(e1,e2,s)));
  }

  inline const BoundaryLayerFan *getFan(MVertex *v) const{
    std::map<MVertex*,BoundaryLayerFan>::const_iterator it = _fans.find(v);
     if (it != _fans.end()){
       return &it->second;
     }
     return 0;
  }

  //  const BoundaryLayerData &getColumn(MVertex *v, MFace f) const;

  inline const BoundaryLayerData &getColumn(MVertex *v, MEdge e) const
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
  //  faceColumn getColumns(GFace *gf, MVertex *v1, MVertex *v2 , MVertex* v3, int side);
  inline int getNbColumns(MVertex *v) const { return _data.count(v); }
  inline const BoundaryLayerData &getColumn(MVertex *v, int iColumn) const
  {
    int count = 0;
    for(std::multimap<MVertex*,BoundaryLayerData>::const_iterator itm  = _data.lower_bound(v);
        itm != _data.upper_bound(v); ++itm){
      if (count++ == iColumn) return itm->second;
    }
    static BoundaryLayerData error;
    return error;
  }
};

BoundaryLayerField* getBLField(GModel *gm);
bool buildAdditionalPoints2D (GFace *gf ) ;
bool buildAdditionalPoints3D (GRegion *gr) ;
void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3]);

#endif
