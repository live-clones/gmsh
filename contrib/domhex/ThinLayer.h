// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Nicolas Kowalski

#ifndef THINLAYER_H_
#define THINLAYER_H_

#include "MVertex.h"
#include "MTriangle.h"
#include "meshGRegionDelaunayInsertion.h"

static int faces[4][3] = {{0, 1, 2}, {0, 2, 3}, {0, 3, 1}, {1, 3, 2}};

struct faceXtet {
  MVertex *v[3], *unsorted[3];
  MTet4 *t1;
  int i1;
  faceXtet(MTet4 *_t = 0, int iFac = 0) : t1(_t), i1(iFac)
  {
    MVertex *v0 = t1->tet()->getVertex(faces[iFac][0]);
    MVertex *v1 = t1->tet()->getVertex(faces[iFac][1]);
    MVertex *v2 = t1->tet()->getVertex(faces[iFac][2]);

    unsorted[0] = v0;
    unsorted[1] = v1;
    unsorted[2] = v2;

    v[0] = std::min(std::min(v0, v1), v2);
    v[2] = std::max(std::max(v0, v1), v2);
    v[1] =
      (v0 != v[0] && v0 != v[2]) ? v0 : (v1 != v[0] && v1 != v[2]) ? v1 : v2;
    //
    //    std::sort(v, v + 3);
  }

  inline MVertex *getVertex(int i) const { return unsorted[i]; }

  inline bool operator<(const faceXtet &other) const
  {
    if(v[0] < other.v[0]) return true;
    if(v[0] > other.v[0]) return false;
    if(v[1] < other.v[1]) return true;
    if(v[1] > other.v[1]) return false;
    if(v[2] < other.v[2]) return true;
    return false;
  }
  inline bool operator==(const faceXtet &other) const
  {
    return (v[0] == other.v[0] && v[1] == other.v[1] && v[2] == other.v[2]);
  }
  bool visible(MVertex *v)
  {
    MVertex *v0 = t1->tet()->getVertex(faces[i1][0]);
    MVertex *v1 = t1->tet()->getVertex(faces[i1][1]);
    MVertex *v2 = t1->tet()->getVertex(faces[i1][2]);
    double a[3] = {v0->x(), v0->y(), v0->z()};
    double b[3] = {v1->x(), v1->y(), v1->z()};
    double c[3] = {v2->x(), v2->y(), v2->z()};
    double d[3] = {v->x(), v->y(), v->z()};
    double o = robustPredicates ::orient3d(a, b, c, d);
    return o < 0;
  }
};

class CorrespVertices {
private:
  MVertex *StartPoint;
  SPoint3 EndPoint;
  SVector3 StartNormal;
  SVector3 EndNormal;
  faceXtet EndTriangle;
  double distP2P;
  double angleProd;
  bool Active;
  bool EndTriangleActive;
  bool IsMaster;
  int tagMaster;

public:
  CorrespVertices();
  ~CorrespVertices();
  void setStartPoint(MVertex *v);
  void setEndPoint(const SPoint3 &p);
  void setStartNormal(const SVector3 &v);
  void setEndNormal(const SVector3 &v);
  void setEndTriangle(faceXtet f);
  void setdistP2P(double d);
  void setangleProd(double a);
  void setActive(bool b);
  void setEndTriangleActive(bool b);
  void setIsMaster(bool b);
  void setTagMaster(int i);
  MVertex *getStartPoint();
  SPoint3 getEndPoint();
  SVector3 getStartNormal();
  SVector3 getEndNormal();
  faceXtet getEndTriangle();
  double getdistP2P();
  double getangleProd();
  bool getActive();
  bool getEndTriangleActive();
  bool getIsMaster();
  int getTagMaster();
};

class ThinLayer {
private:
public:
  ThinLayer();
  ~ThinLayer();
  static void perform();
  static void checkOppositeTriangles();
  static void fillvecOfThinSheets();
  static std::map<MVertex *, double> computeAllDistToOppSide();
  static double computeDistToOppSide(MVertex *v);
  static SVector3 computeInteriorNormal(MVertex *v);
  static MTet4 *getTetFromPoint(MVertex *v, const SVector3 &InteriorNormal);
  static bool IsPositivOrientation(const SVector3 &a, const SVector3 &b,
                                   const SVector3 &c);
  static void FindNewPoint(SPoint3 *CurrentPoint, int *CurrentTri,
                           MTet4 *CurrentTet, const SVector3 &InteriorNormal);
  static std::map<MVertex *, std::vector<MTetrahedron *> > VertexToTets;
  static std::map<MTetrahedron *, MTet4 *> TetToTet4;
  static std::map<MVertex *, std::vector<CorrespVertices *> > VertexToCorresp;
  static std::vector<std::vector<CorrespVertices *> > vecOfThinSheets;
  static const double epsilon;
  static const double angleMax;
  static const double distP2PMax;
  static void fillVertexToTets();
  static void fillTetToTet4();
};

#endif
