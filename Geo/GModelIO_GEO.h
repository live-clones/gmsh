// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GMODELIO_GEO_H_
#define _GMODELIO_GEO_H_

#include "Geo.h"

class GEO_Internals{
 private:
  void alloc_all();
  void free_all();
 public:
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

 public:
  GEO_Internals(){ alloc_all(); }
  ~GEO_Internals(){ free_all(); }
  void destroy(){ free_all(); alloc_all(); }
  void reset_physicals();
  void addCompoundMesh(int dim, List_T *_list)
  {
    std::vector<int> compound;
    for(int i = 0; i < List_Nbr(_list); i++)
      compound.push_back((int)*(double*)List_Pointer(_list, i));
    meshCompounds.insert(std::make_pair(dim,compound));
  }

};

#endif
