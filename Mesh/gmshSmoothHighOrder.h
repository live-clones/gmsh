// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_SMOOTH_HIGHORDER_H_
#define _GMSH_SMOOTH_HIGHORDER_H_

#include <map>
#include <vector>
#include "SVector3.h"
#include "GmshMatrix.h"
#include "dofManager.h"
#include "elasticityTerm.h"

class MVertex;
class MElement;
class GFace;
class GRegion;

class gmshHighOrderSmoother 
{
  const int _tag;
  std::map<MVertex*,SVector3> _straightSidedLocation;
  std::map<MVertex*,SVector3> _targetLocation;
  int _dim;
  void _clean () {
    _straightSidedLocation.clear();
    _targetLocation.clear();
  }
  double _MIDDLE;
  void moveTo (MVertex *v,  const std::map<MVertex*,SVector3> &) const;
public:  
  gmshHighOrderSmoother (int dim) : _tag(111), _dim(dim) {_clean();}
  void add ( MVertex * v, const SVector3 &d ) {
    _straightSidedLocation[v] = d;
    _targetLocation[v]        = SPoint3(v->x(),v->y(),v->z());
  }  
  void smooth ( std::vector<MElement*> & );
  double smooth_metric_ ( std::vector<MElement*> &, GFace *gf,
                          gsolver::dofManager<double,double> &myAssembler,
                          std::set<MVertex*> &verticesToMove,
                          gsolver::elasticityTerm &El);
  void smooth_metric ( std::vector<MElement*> &, GFace *gf );
  void smooth ( GFace* , bool metric = false);
  void smooth_p2point ( GFace* );
  void smooth_pNpoint ( GFace* );
  void smooth ( GRegion* );
  int getTag() const {return _tag;}
  void swap(GFace *, 
            edgeContainer &edgeVertices,
            faceContainer &faceVertices);
  void optimize(GFace *, 
                edgeContainer &edgeVertices,
                faceContainer &faceVertices);
  void computeMetricVector (GFace *gf, 
                            MElement *e, 
                            gmshMatrix<double> &J,
                            gmshMatrix<double> &JT,
                            gmshVector<double> &D);
  void moveToStraightSidedLocation  (MVertex *) const;
  void moveToTargetLocation  (MVertex *) const;
  void moveToStraightSidedLocation  (MElement *) const;
  void moveToTargetLocation (MElement *) const;  
  void updateTargetLocation (MVertex*, const SPoint3 &, const SPoint2 &) ;
  inline SVector3 getSSL(MVertex *v) const{
     std::map<MVertex*,SVector3>::const_iterator it =  _straightSidedLocation.find(v);
     if (it != _straightSidedLocation.end())return it->second;
     else return SVector3(v->x(),v->y(),v->z());
  }
  inline SVector3 getDisplacement(MVertex *v) const{
     std::map<MVertex*,SVector3>::const_iterator it  =  _straightSidedLocation.find(v);
     std::map<MVertex*,SVector3>::const_iterator itt =  _targetLocation.find(v);
     if (it == _straightSidedLocation.end())
       return SVector3(0.0,0.0,0.0);
     else{
       return SVector3(itt->second.x() - it->second.x(),
                       itt->second.y() - it->second.y(),
                       itt->second.z() - it->second.z());
     }
  }
};

#endif
