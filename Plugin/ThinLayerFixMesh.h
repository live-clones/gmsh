// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Author: Nicolas Kowalski

#ifndef THINLAYERFIXMESH_H_
#define THINLAYERFIXMESH_H_

#include "Plugin.h"
#include "MVertex.h"
#include "MTriangle.h"
#if defined(HAVE_MESH)
#include "meshGRegionDelaunayInsertion.h"
#endif

extern "C"
{
  GMSH_Plugin *GMSH_RegisterThinLayerFixMeshPlugin();
}

#if defined(HAVE_MESH)
static int faces[4][3] = {{0,1,2}, {0,2,3}, {0,3,1}, {1,3,2}};

struct faceXtetFM{
  MVertex *v[3],*unsorted[3];
  MTet4 *t1;
  int i1;
  faceXtetFM(MTet4 *_t=0, int iFac=0) : t1(_t), i1(iFac)
  {
    //	  std::cout<<"entering faceXTet"<<std::endl;
    //	  std::cout<<"tag of tet is "<<t1->tet()->getNum()<<std::endl;
    //	  std::cout<<"first vec of tet is "<<t1->tet()->getVertex(0)->getNum()<<std::endl;
    //	  std::cout<<"second vec of tet is "<<t1->tet()->getVertex(1)->getNum()<<std::endl;
    //	  std::cout<<"third vec of tet is "<<t1->tet()->getVertex(2)->getNum()<<std::endl;
    //	  std::cout<<"fourth vec of tet is "<<t1->tet()->getVertex(3)->getNum()<<std::endl;
    MVertex *v0 = t1->tet()->getVertex(faces[iFac][0]);
    //    std::cout<<"after first vert"<<std::endl;
    MVertex *v1 = t1->tet()->getVertex(faces[iFac][1]);
    //    std::cout<<"after second vert"<<std::endl;
    MVertex *v2 = t1->tet()->getVertex(faces[iFac][2]);
    //    std::cout<<"after third vert"<<std::endl;

    unsorted[0] = v0;
    //    std::cout<<"after first unsorted"<<std::endl;
    unsorted[1] = v1;
    //    std::cout<<"after second unsorted"<<std::endl;
    unsorted[2] = v2;
    //    std::cout<<"after third unsorted"<<std::endl;

    v[0] = std::min(std::min(v0,v1),v2);
    //    std::cout<<"after min"<<std::endl;
    v[2] = std::max(std::max(v0,v1),v2);
    //    std::cout<<"after max"<<std::endl;
    v[1] = (v0 != v[0] && v0 != v[2]) ? v0 : (v1 != v[0] && v1 != v[2]) ? v1 : v2;
    //    std::cout<<"after minimax"<<std::endl;
    //
    //    std::sort(v, v + 3);
  }

  inline MVertex * getVertex (int i) const { return unsorted[i];}

  inline bool operator < (const faceXtetFM & other) const
  {
    if (v[0] < other.v[0]) return true;
    if (v[0] > other.v[0]) return false;
    if (v[1] < other.v[1]) return true;
    if (v[1] > other.v[1]) return false;
    if (v[2] < other.v[2]) return true;
    return false;
  }
  inline bool operator == (const faceXtetFM & other) const
  {
    return (v[0] == other.v[0] &&
	    v[1] == other.v[1] &&
	    v[2] == other.v[2] );
  }
  bool visible (MVertex *v){
    MVertex* v0 = t1->tet()->getVertex(faces[i1][0]);
    MVertex* v1 = t1->tet()->getVertex(faces[i1][1]);
    MVertex* v2 = t1->tet()->getVertex(faces[i1][2]);
    double a[3] = {v0->x(),v0->y(),v0->z()};
    double b[3] = {v1->x(),v1->y(),v1->z()};
    double c[3] = {v2->x(),v2->y(),v2->z()};
    double d[3] = {v->x(),v->y(),v->z()};
    double o = robustPredicates :: orient3d(a,b,c,d);
    return o < 0;
  }
};

class CorrespVerticesFixMesh{
private:
  MVertex* StartPoint;
  SPoint3 EndPoint;
  SVector3 StartNormal;
  SVector3 EndNormal;
  MVertex* EndTrianglePoint1;
  MVertex* EndTrianglePoint2;
  MVertex* EndTrianglePoint3;
  //	faceXtetFM EndTriangle;
  double distP2P;
  double angleProd;
  bool Active;
  bool EndTriangleActive;
  bool IsMaster;
  int tagMaster;
public:
  CorrespVerticesFixMesh();
  ~CorrespVerticesFixMesh();
  void setStartPoint(MVertex* v);
  void setEndPoint(SPoint3 p);
  void setStartNormal(SVector3 v);
  void setEndNormal(SVector3 v);
  //	void setEndTriangle(faceXtetFM f);
  void setEndTrianglePoint1(MVertex* v);
  void setEndTrianglePoint2(MVertex* v);
  void setEndTrianglePoint3(MVertex* v);
  void setdistP2P(double d);
  void setangleProd(double a);
  void setActive(bool b);
  void setEndTriangleActive(bool b);
  void setIsMaster(bool b);
  void setTagMaster(int i);
  MVertex* getStartPoint();
  SPoint3 getEndPoint();
  SVector3 getStartNormal();
  SVector3 getEndNormal();
  //	faceXtetFM getEndTriangle();
  MVertex* getEndTrianglePoint1();
  MVertex* getEndTrianglePoint2();
  MVertex* getEndTrianglePoint3();
  double getdistP2P();
  double getangleProd();
  bool getActive();
  bool getEndTriangleActive();
  bool getIsMaster();
  int getTagMaster();
};
#endif

class GMSH_ThinLayerFixMeshPlugin : public GMSH_PostPlugin
{
private:
public:
  GMSH_ThinLayerFixMeshPlugin(){}
  //~GMSH_ThinLayerFixMeshPlugin();
  std::string getName() const { return "ThinLayerFixMesh"; }
  std::string getShortHelp() const
  {
    return "Fix the mesh in thin parts";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  PView *execute(PView *);
#if defined(HAVE_MESH)
  static void perform();
  static void checkOppositeTriangles();
  static void fillvecOfThinSheets();
  static std::map<MVertex*,double> computeAllDistToOppSide();
  static double computeDistToOppSide(MVertex* v);
  static SVector3 computeInteriorNormal(MVertex* v);
  static MTet4* getTetFromPoint(MVertex* v, SVector3 InteriorNormal);
  static bool IsPositivOrientation(SVector3 a, SVector3 b, SVector3 c);
  static void FindNewPoint(SPoint3* CurrentPoint, int* CurrentTri,
                           MTet4** CurrentTet, SVector3 InteriorNormal);
  static std::map<MVertex*,std::vector<MTetrahedron*> > VertexToTets;
  static std::map<MTetrahedron*,MTet4*> TetToTet4;
  static std::map<MVertex*,std::vector<CorrespVerticesFixMesh*> > VertexToCorresp;
  static std::vector<std::vector<CorrespVerticesFixMesh*> > vecOfThinSheets;
  static const double epsilon;
  static const double angleMax;
  static const double distP2PMax;
  static void fillVertexToTets();
  static void fillTetToTet4();
#endif
};

#endif
