// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _BNDRYLRDATA_
#define _BNDRYLRDATA_

#include "SVector3.h"
#include "STensor3.h"
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
  std::vector<SMetric3> _metrics;
  std::vector<GFace*> _joint;
  BoundaryLayerData(){}
  BoundaryLayerData(const SVector3 & dir,
                    std::vector<MVertex*> column,
                    std::vector<SMetric3> metrics)
    : _n(dir), _column(column), _metrics(metrics){}
  BoundaryLayerData(const SVector3 & dir,
                    std::vector<MVertex*> column,
                    std::vector<SMetric3> metrics,
                    std::vector<GFace*> joint)
  : _n(dir), _column(column), _metrics(metrics),_joint(joint){}
};

struct BoundaryLayerFan
{
  MEdge _e1, _e2;
  bool sense;
  BoundaryLayerFan(MEdge e1, MEdge e2 , bool s = true)
    : _e1(e1),_e2(e2) , sense (s){}
};

// wedge between 2 sets of continuous faces
struct BoundaryLayerFanWedge3d
{
  std::vector<GFace*> _gf1, _gf2;
  BoundaryLayerFanWedge3d(GFace *gf1=0, GFace *gf2=0)
  {
    if(gf1)_gf1.push_back(gf1);
    if(gf2)_gf2.push_back(gf2);
  }
  BoundaryLayerFanWedge3d(std::vector<GFace*> &gf1,
			  std::vector<GFace*> &gf2):_gf1(gf1),_gf2(gf2)
  {
  }
  bool isLeft (const GFace *gf) const {
    for (unsigned int i=0;i<_gf1.size();i++)if (_gf1[i] == gf)return true;
    return false;
  }
  bool isRight (const GFace *gf) const{
    for (unsigned int i=0;i<_gf2.size();i++)if (_gf2[i] == gf)return true;
    return false;
  }
  bool isLeft (const std::vector<GFace *> &gf) const {
    for (unsigned int i=0;i<gf.size();i++)if (isLeft(gf[i]))return true;
    return false;
  }
  bool isRight (const std::vector<GFace *> &gf) const {
    for (unsigned int i=0;i<gf.size();i++)if (isRight(gf[i]))return true;
    return false;
  }

};

struct BoundaryLayerFanCorner3d
{
  int _fanSize;
  std::vector<GFace *> _gf;
  BoundaryLayerFanCorner3d() : _fanSize(0){}
  BoundaryLayerFanCorner3d(int fanSize ,std::vector<GFace *> &gf)
  : _fanSize(fanSize), _gf(gf){}
};


struct edgeColumn {
  const BoundaryLayerData &_c1, &_c2;
  edgeColumn(const BoundaryLayerData &c1, const BoundaryLayerData &c2)
    : _c1(c1), _c2(c2){}
};

struct faceColumn {
  const BoundaryLayerData &_c1, &_c2, &_c3, &_c4;
  faceColumn(const BoundaryLayerData &c1,
	     const BoundaryLayerData &c2,
	     const BoundaryLayerData &c3)
  : _c1(c1), _c2(c2), _c3(c3), _c4(c3){}
  faceColumn(const BoundaryLayerData &c1,
	     const BoundaryLayerData &c2,
	     const BoundaryLayerData &c4,
	     const BoundaryLayerData &c3)
  : _c1(c1), _c2(c2), _c3(c3), _c4(c4){}
};


class BoundaryLayerColumns
{
  std::map<MVertex*, BoundaryLayerFan> _fans;
  std::map<MVertex*, BoundaryLayerFanWedge3d> _wedges;
  std::map<MVertex*, BoundaryLayerFanCorner3d> _corners;
public:
  std::map<MFace, GFace*, Less_Face> _inverse_classification;
  std::multimap<MVertex*, BoundaryLayerData>  _data;
  size_t size () const {return _data.size();}
  typedef std::multimap<MVertex*,BoundaryLayerData>::iterator iter;
  typedef std::map<MVertex*, BoundaryLayerFan>::iterator iterf;
  std::multimap<MVertex*, MVertex*> _non_manifold_edges;
  std::multimap<MVertex*,MTriangle*> _non_manifold_faces;
  std::multimap<MEdge, SVector3, Less_Edge> _normals;
  std::multimap<MFace, SVector3, Less_Face> _normals3D;
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
  inline void addColumn(const SVector3 &dir, MVertex* v,
                        std::vector<MVertex*> _column,
                        std::vector<SMetric3> _metrics,
                        std::vector<GFace*> _joint)
  {
    _data.insert (std::make_pair(v,BoundaryLayerData(dir, _column,_metrics,_joint)));
  }
  inline void addFan(MVertex *v, MEdge e1, MEdge e2, bool s)
  {
    _fans.insert(std::make_pair(v,BoundaryLayerFan(e1,e2,s)));
  }
  inline void addWedge(MVertex *v, GFace *gf1, GFace *gf2)
  {
    _wedges.insert(std::make_pair(v,BoundaryLayerFanWedge3d(gf1,gf2)));
  }
  inline void addWedge(MVertex *v, std::vector<GFace *>&gf1, std::vector<GFace *> &gf2)
  {
    _wedges.insert(std::make_pair(v,BoundaryLayerFanWedge3d(gf1,gf2)));
  }
  inline void addCorner(MVertex *v, int fanSize, std::vector<GFace *> &gfs)
  {
    _corners.insert(std::make_pair(v,BoundaryLayerFanCorner3d(fanSize, gfs)));
  }
  inline bool isCorner (MVertex* v) const{
    return _corners.find(v) != _corners.end();
  }
  inline bool isOnWedge (MVertex* v) const{
    return _wedges.find(v) != _wedges.end();
  }

  inline BoundaryLayerFanWedge3d getWedge (MVertex* v) {
    std::map<MVertex*, BoundaryLayerFanWedge3d>::iterator it = _wedges.find(v);
    return it->second;
  }
  inline BoundaryLayerFanCorner3d getCorner (MVertex* v) {
    std::map<MVertex*, BoundaryLayerFanCorner3d>::iterator it = _corners.find(v);
    return it->second;
  }


  const BoundaryLayerData &getColumn(MVertex *v, MFace f);

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
  faceColumn getColumns(GFace *gf, MVertex *v1, MVertex *v2 , MVertex* v3, int side);
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

BoundaryLayerField* getBLField(GModel *gm);
bool buildAdditionalPoints2D (GFace *gf ) ;
BoundaryLayerColumns * buildAdditionalPoints3D (GRegion *gr) ;
void buildMeshMetric(GFace *gf, double *uv, SMetric3 &m, double metric[3]);


#endif
