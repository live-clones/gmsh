// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DISCRETE_FACE_H_
#define _DISCRETE_FACE_H_

#include "GModel.h"
#include "GFace.h"
#include "discreteEdge.h"
#include "MEdge.h"
#include "meshPartitionObjects.h"
#include "meshPartitionOptions.h"
#include "meshPartition.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "MLine.h"
#include <stdlib.h>

class discreteDiskFace;
class triangulation;


class discreteFace : public GFace {
  // FIXME we should at the end use a
  // mesh() function that is specific to
  // discreteFace
  // we should also SAVE those data's
 public:
  discreteFace(GModel *model, int num);
  virtual ~discreteFace() {}
  void checkAndFixOrientation();
  void setupDiscreteVertex(GVertex*,MVertex*,std::set<MVertex*>*);
  void setupDiscreteEdge(discreteEdge*,std::vector<MLine*>,std::set<MVertex*>*);
  void splitDiscreteEdge(GEdge*,GVertex*,discreteEdge*[2]);
  void updateTopology(std::vector<triangulation*>&);
  void split(triangulation*,std::vector<triangulation*>&,int);
  void fillHoles(triangulation*);
  void addTriangle(triangulation*,MTriangle*);
  void complex_crossField();
  void crossField();
  GPoint point(double par1, double par2) const;
  SPoint2 parFromPoint(const SPoint3 &p, bool onSurface=true) const;
  SVector3 normal(const SPoint2 &param) const;
  double curvatureMax(const SPoint2 &param) const;
  double curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                                  double *curvMax, double *curvMin) const;
  virtual bool haveParametrization() { return getCompound(); }
  GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &param,
                         SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const;
  void setBoundEdges(GModel *gm, std::vector<int> tagEdges);
  void findEdges(std::map<MEdge, std::vector<int>, Less_Edge > &map_edges);
  void writeGEO(FILE *fp);
  void createGeometry();
  void gatherMeshes();
  virtual void mesh (bool verbose);
  std::vector<discreteDiskFace*> _atlas;
  std::vector<GFace*> _CAD;
  std::map<MEdge,std::vector<int>,Less_Edge> allEdg2Tri;
};

#endif
