// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _HIGH_ORDER_TOOLS_H_
#define _HIGH_ORDER_TOOLS_H_

#include <map>
#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"

#if defined(HAVE_SOLVER)

#include "SVector3.h"
#include "fullMatrix.h"
#include "dofManager.h"
#include "elasticityTerm.h"

class MVertex;
class MElement;
class GFace;
class GRegion;

class highOrderTools
{
  GModel *_gm;
  const int _tag;
  // contains the position of vertices in a straight sided mesh
  std::map<MVertex*,SVector3> _straightSidedLocation;
  // contains the position of vertices in the best curvilinear mesh
  // available 
  std::map<MVertex*,SVector3> _targetLocation;
  int _dim;
  void _clean()
  {
    _straightSidedLocation.clear();
    _targetLocation.clear();
  }
  double smooth_metric_(std::vector<MElement*>  & v, 
			GFace *gf, 
			dofManager<double> &myAssembler,
			std::set<MVertex*> &verticesToMove,
			elasticityTerm &El);
  void computeMetricInfo(GFace *gf, 
			 MElement *e, 
			 fullMatrix<double> &J,
			 fullMatrix<double> &JT,
			 fullVector<double> &D);
  double apply_incremental_displacement (double max_incr,
					 std::vector<MElement*> & v,
					 bool mixed,
					 double thres,
					 char *meshName,
					 std::vector<MElement*> & disto);
  void moveToStraightSidedLocation(MElement *) const;
  void computeStraightSidedPositions ();
 public:  
  highOrderTools(GModel *gm);
  highOrderTools(GModel *gm, GModel *mesh, int order);
  //  void applyGlobalSmoothing ();
  void ensureMinimumDistorsion(MElement *e, double threshold);
  void ensureMinimumDistorsion (std::vector<MElement*> &all, double threshold);
  void ensureMinimumDistorsion (double threshold);
  double applySmoothingTo (GFace *gf, double tres = 0.1, bool mixed = false);
  void applySmoothingTo(std::vector<MElement*> & all, GFace *gf);
  double applySmoothingTo (std::vector<MElement*> &all,  double threshold, bool mixed);
  inline SVector3 getSSL(MVertex *v) const
  {
    std::map<MVertex*,SVector3>::const_iterator it =  _straightSidedLocation.find(v);
    if (it != _straightSidedLocation.end())return it->second;
    else return SVector3(v->x(),v->y(),v->z());
  }
  void makePosViewWithJacobians(const char *nm);
};

#else

class highOrderTools
{
 public:
  highOrderTools(GModel *gm)
  {
    Msg::Error("Gmsh has to be compiled with solver support to use highOrderSmoother");
  }
  void applyGlobalSmoothing (){}
  void ensureMinimumDistorsion (double threshold){}
};

#endif

#endif
