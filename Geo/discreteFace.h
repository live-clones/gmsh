// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DISCRETE_FACE_H_
#define _DISCRETE_FACE_H_

#include "GModel.h"
#include "GFace.h"
#include "discreteEdge.h"
#include "MEdge.h"

class discreteFace : public GFace {
 public:
  discreteFace(GModel *model, int num);
  virtual ~discreteFace() {}
  GPoint point(double par1, double par2) const;
  SPoint2 parFromPoint(const SPoint3 &p, bool onSurface=true) const;
  SVector3 normal(const SPoint2 &param) const;
  double curvatureMax(const SPoint2 &param) const;
  double curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                                  double *curvMax, double *curvMin) const;
  GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &param, 
                         SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const;
  void setBoundEdges(std::vector<int> tagEdges);
  void findEdges(std::map<MEdge, std::vector<int>, Less_Edge > &map_edges);
  void writeGEO(FILE *fp);
};

#endif
