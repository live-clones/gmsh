// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#ifndef HIGH_ORDER_MESH_ELASTIC_ANALOGY_H
#define HIGH_ORDER_MESH_ELASTIC_ANALOGY_H

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

class highOrderTools {
private:
  GModel *_gm;
  const int _tag;
  // contains the position of vertices in a straight sided mesh
  std::map<MVertex *, SVector3> _straightSidedLocation;
  // contains the position of vertices in the best curvilinear mesh available
  std::map<MVertex *, SVector3> _targetLocation;
  int _dim;
  void _clean()
  {
    _straightSidedLocation.clear();
    _targetLocation.clear();
  }
  double _smoothMetric(std::vector<MElement *> &v, GFace *gf,
                       dofManager<double> &myAssembler,
                       std::set<MVertex *, MVertexPtrLessThan> &verticesToMove,
                       elasticityTerm &El);
  void _computeMetricInfo(GFace *gf, MElement *e, fullMatrix<double> &J,
                          fullMatrix<double> &JT, fullVector<double> &D);
  double _applyIncrementalDisplacement(double max_incr,
                                       std::vector<MElement *> &v, bool mixed,
                                       double thres, char *meshName,
                                       std::vector<MElement *> &disto);
  void _moveToStraightSidedLocation(MElement *) const;
  void _computeStraightSidedPositions();

public:
  highOrderTools(GModel *gm);
  highOrderTools(GModel *gm, GModel *mesh, int order);
  //  void applyGlobalSmoothing ();
  void ensureMinimumDistorsion(MElement *e, double threshold);
  void ensureMinimumDistorsion(std::vector<MElement *> &all, double threshold);
  void ensureMinimumDistorsion(double threshold);
  double applySmoothingTo(GFace *gf, double tres = 0.1, bool mixed = false);
  void applySmoothingTo(std::vector<MElement *> &all, GFace *gf);
  double applySmoothingTo(std::vector<MElement *> &all, double threshold,
                          bool mixed);
  inline SVector3 getSSL(MVertex *v) const
  {
    auto it = _straightSidedLocation.find(v);
    if(it != _straightSidedLocation.end())
      return it->second;
    else
      return SVector3(v->x(), v->y(), v->z());
  }
  inline SVector3 getTL(MVertex *v) const
  {
    auto it = _targetLocation.find(v);
    if(it != _targetLocation.end())
      return it->second;
    else
      return SVector3(v->x(), v->y(), v->z());
  }
  void makePosViewWithJacobians(const char *nm);
};

#endif

void HighOrderMeshElasticAnalogy(GModel *m, bool onlyVisible);

#endif
