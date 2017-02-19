// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMODELIO_GEO_H_
#define _GMODELIO_GEO_H_

#include "Geo.h"

class GEO_Internals{
 private:
  void _allocateAll();
  void _freeAll();
 public:
  // FIXME: all this must (will) become private ; and all the direct calls in
  // Gmsh.y should (will) go through an integer-based API similar to the one in
  // OCC_Internals
  Tree_T *Points;
  Tree_T *Curves;
  Tree_T *Surfaces;
  Tree_T *Volumes;
  Tree_T *SurfaceLoops;
  Tree_T *EdgeLoops;
  Tree_T *LevelSets;
  List_T *PhysicalGroups;
  int MaxPointNum, MaxLineNum, MaxLineLoopNum, MaxSurfaceNum;
  int MaxSurfaceLoopNum, MaxVolumeNum, MaxPhysicalNum;
  std::multimap<int, std::vector<int> > meshCompounds;

  struct MasterEdge {
    int tag; // signed
    std::vector<double> affineTransform;
  };
  std::map<int, MasterEdge> periodicEdges;

  struct MasterFace {
    int tag;
    // map from slave to master edges
    std::map<int, int> edgeCounterparts;
    std::vector<double> affineTransform;
  };
  std::map<int, MasterFace> periodicFaces;

  gmshSurface *newGeometrySphere(int num, int centerTag, int pointTag);
  gmshSurface *newGeometryPolarSphere(int num, int centerTag, int pointTag);

 public:
  GEO_Internals(){ _allocateAll(); }
  ~GEO_Internals(){ _freeAll(); }
  void destroy(){ _freeAll(); _allocateAll(); }
  void resetPhysicalGroups();

  // get maximum tag number for each dimension
  int getMaxTag(int dim) const
  {
    switch(dim){
    case 0: return MaxPointNum;
    case 1: return MaxLineNum;
    case -1: return MaxLineLoopNum;
    case 2: return MaxSurfaceNum;
    case -2: return MaxSurfaceLoopNum;
    case 3: return MaxVolumeNum;
    default: return 0;
    }
  }

  // add shapes
  void addVertex(int num, double x, double y, double z, double lc);
  void addVertex(int num, double x, double y, gmshSurface *s, double lc);
  void addLine(int num, int startTag, int endTag);
  void addLine(int num, std::vector<int> vertexTags);
  void addCircleArc(int num, int startTag, int centerTag, int EndTag,
                    double nx=0., double ny=0., double nz=0.);
  void addEllipseArc(int num, int startTag, int centerTag, int majorTag,
                     int endTag, double nx=0., double ny=0., double nz=0.);
  void addSpline(int num, std::vector<int> vertexTags);
  void addBSpline(int num, std::vector<int> vertexTags);
  void addBezier(int num, std::vector<int> vertexTags);
  void addNurbs(int num, std::vector<int> vertexTags, std::vector<double> knots);
  void addCompoundLine(int num, std::vector<int> edgeTags);
  void addLineLoop(int num, std::vector<int> edgeTags);
  void addPlaneSurface(int num, std::vector<int> wireTags);
  void addSurfaceFilling(int num, std::vector<int> wireTags, int sphereCenterTag=-1);
  void addSurfaceLoop(int num, std::vector<int> faceTags);
  void addCompoundSurface(int num, std::vector<int> faceTags,
                          std::vector<int> edgeTags[4]=0);
  void addVolume(int num, std::vector<int> shellTags);
  void addCompoundVolume(int num, std::vector<int> regionTags);

  // add physical groups

  // set meshing constraints
  void setCompoundMesh(int dim, std::vector<int> tags);

  // synchronize internal CAD data with the given GModel
  void synchronize(GModel *model);
};

#endif
