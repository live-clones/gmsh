// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "NearestNeighbor.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif

GMSH_NearestNeighborPlugin::GMSH_NearestNeighborPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

std::string GMSH_NearestNeighborPlugin::getHelp() const
{
  return "Plugin(NearestNeighbor) computes the distance from each "
         "point in `View' to its nearest neighbor.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(NearestNeighbor) is executed in-place.";
}

PView *GMSH_NearestNeighborPlugin::execute(PView *v)
{
  int iView = (int)option(0);

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  int totpoints = data1->getNumPoints();
  if(!totpoints) {
    Msg::Error("View[%d] contains no points", v1->getIndex());
    return v;
  }

#if defined(HAVE_ANN)
  ANNpointArray zeronodes = annAllocPts(totpoints, 3);
  int k = 0, step = 0;
  for(int ent = 0; ent < data1->getNumEntities(step); ent++) {
    for(int ele = 0; ele < data1->getNumElements(step, ent); ele++) {
      if(data1->skipElement(step, ent, ele)) continue;
      int numNodes = data1->getNumNodes(step, ent, ele);
      if(numNodes != 1) continue;
      data1->getNode(step, ent, ele, 0, zeronodes[k][0], zeronodes[k][1],
                     zeronodes[k][2]);
      k++;
    }
  }
  // getNumPoints() also counts the points skipped above
  if(k < 2) {
    Msg::Error("View[%d] contains less than 2 points", v1->getIndex());
    annDeallocPts(zeronodes);
    return v;
  }
  ANNkd_tree *kdtree = new ANNkd_tree(zeronodes, k, 3);
  ANNidxArray index = new ANNidx[2];
  ANNdistArray dist = new ANNdist[2];

  v1->setChanged(true);
  for(int ent = 0; ent < data1->getNumEntities(step); ent++) {
    for(int ele = 0; ele < data1->getNumElements(step, ent); ele++) {
      if(data1->skipElement(step, ent, ele)) continue;
      int numNodes = data1->getNumNodes(step, ent, ele);
      if(numNodes != 1) continue;
      double xyz[3];
      data1->getNode(step, ent, ele, 0, xyz[0], xyz[1], xyz[2]);
      kdtree->annkSearch(xyz, 2, index, dist);
      data1->setValue(step, ent, ele, 0, 0, sqrt(dist[1]));
    }
  }

  delete kdtree;
  annDeallocPts(zeronodes);
  delete[] index;
  delete[] dist;
#else
  Msg::Error("Nearest neighbor computation requires ANN");
#endif

  data1->setName(v1->getData()->getName() + "_NearestNeighbor");
  data1->finalize();

  return v1;
}
