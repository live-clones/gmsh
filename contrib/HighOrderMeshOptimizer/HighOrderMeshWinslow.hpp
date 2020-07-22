// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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

#ifndef HIGH_ORDER_MESH_WINSLOW_H
#define HIGH_ORDER_MESH_WINSLOW_H

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
#include "laplaceTerm.h"

class MVertex;
class MElement;
class GFace;
class GRegion;

class highOrderWinslow {
  typedef std::map<MFace, std::vector<MElement *>, MFaceLessThan> MFaceVecMEltMap;
private:
  GModel *_gm;
  const int _tag;
  // contains the position of vertices in a straight sided mesh
  std::map<MVertex *, SVector3, MVertexPtrLessThan> _straightSidedLocation;
  // contains the position of vertices in the best curvilinear mesh available
  std::map<MVertex *, SVector3, MVertexPtrLessThan> _targetLocation;
  int _dim;
  void _clean()
  {
    _straightSidedLocation.clear();
    _targetLocation.clear();
  }
  void _moveToStraightSidedLocation(MElement *) const;
  void _computeStraightSidedPositions();
  void _printJacobians(GModel *m, const char *nm);
  void _picardPart1(std::vector<MElement *> &allElem, std::vector<MElement *> &boundaryElem, MFaceVecMEltMap &face2el, std::set<MVertex *, MVertexPtrLessThan> &vertices, std::map<MVertex *, SVector3> *currentSolution, std::map<MVertex *, SVector3> *alpha, int idAlphaComp);
  void _picardPart2(std::vector<MElement *> &allElem, std::set<MVertex *, MVertexPtrLessThan> &vertices, std::map<MVertex *, SVector3> *alpha, std::map<MVertex *, SVector3> *currentSolution, std::map<MVertex *, SVector3> *newSolution, int idComponent);
  void _picardIteration(std::vector<MElement *> &all, std::vector<MElement *> &boundaryElem, MFaceVecMEltMap &face2el, std::set<MVertex *, MVertexPtrLessThan> &vertices, std::map<MVertex *, SVector3> *currentSolution, std::map<MVertex *, SVector3> *newSolution);
  double _computeErrorPicard(std::map<MVertex *, SVector3> *currentSolution, std::map<MVertex *, SVector3> *newSolution);
public:
  highOrderWinslow(GModel *gm);
  highOrderWinslow(GModel *gm, GModel *mesh, int order);
  void smoothMesh(GModel *m, bool onlyVisible);
  
  inline SVector3 getSSL(MVertex *v) const
  {
    std::map<MVertex *, SVector3>::const_iterator it =
      _straightSidedLocation.find(v);
    if(it != _straightSidedLocation.end())
      return it->second;
    else
      return SVector3(v->x(), v->y(), v->z());
  }
  inline SVector3 getTL(MVertex *v) const
  {
    std::map<MVertex *, SVector3>::const_iterator it = _targetLocation.find(v);
    if(it != _targetLocation.end())
      return it->second;
    else
      return SVector3(v->x(), v->y(), v->z());
  }
  void makePosViewWithJacobians(const char *nm);
  void calcFace2Elements(GEntity *entity, MFaceVecMEltMap &face2el);
  void applyWinslowTo(GModel *gm, std::vector<MElement *> &all,std::vector<MElement *> &boundaryElements, MFaceVecMEltMap &face2el, double precision);
  void getBoundaryElementsRegionN(std::vector<MElement *> &boundaryElements, MFaceVecMEltMap &face2el, std::vector<MElement *> &eltsRegionN, std::vector<MElement *> &boundaryElementsRegionN);
};

#endif

void HighOrderMeshWinslow(GModel *m, bool onlyVisible);

#endif
