// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "PViewOptions.h"
#include "BoundaryAngles.h"
#include "GModel.h"
#include "discreteEdge.h"
#include "MLine.h"
#include <cstring>
#include <algorithm>
#include <string>

StringXNumber BoundaryAnglesOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.},
  {GMSH_FULLRC, "Save", NULL, 0.},
  {GMSH_FULLRC, "Visible", NULL, 0.},
  {GMSH_FULLRC, "Remove", NULL, 0.},
};

StringXString BoundaryAnglesOptions_String[] = {
  {GMSH_FULLRC, "Filename", NULL, "Angles_Surface"},
};

extern "C" {
GMSH_Plugin *GMSH_RegisterBoundaryAnglesPlugin()
{
  return new GMSH_BoundaryAnglesPlugin();
}
}

std::string GMSH_BoundaryAnglesPlugin::getHelp() const
{
  return "Plugin(BoundaryAngles) computes the (interior) angles between the "
         "line elements on the boundary of all surfaces. The angles, computed "
         "modulo 2*Pi, are stored in a new post-processing view, one for each "
         "surface. The plugin currently only works for planar surfaces.";
}

int GMSH_BoundaryAnglesPlugin::getNbOptions() const
{
  return sizeof(BoundaryAnglesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_BoundaryAnglesPlugin::getOption(int iopt)
{
  return &BoundaryAnglesOptions_Number[iopt];
}

int GMSH_BoundaryAnglesPlugin::getNbOptionsStr() const
{
  return sizeof(BoundaryAnglesOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_BoundaryAnglesPlugin::getOptionStr(int iopt)
{
  return &BoundaryAnglesOptions_String[iopt];
}

struct Less_EdgeEle {
  bool operator()(const std::pair<MEdge, MElement *> &e1,
                  const std::pair<MEdge, MElement *> &e2) const
  {
    MEdgeLessThan le;
    return le(e1.first, e2.first);
  }
};

PView *GMSH_BoundaryAnglesPlugin::execute(PView *v)
{
  int saveOnDisk = (int)BoundaryAnglesOptions_Number[1].def;
  int viewVisible = (int)BoundaryAnglesOptions_Number[2].def;
  int removeView = (int)BoundaryAnglesOptions_Number[3].def;
  std::string filename_prefix = BoundaryAnglesOptions_String[0].def;
  // get the mesh of the current model, and iterate on the surfaces
  GModel *m = GModel::current();
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    GFace *gf = *it;
    std::set<std::pair<MEdge, MElement *>, Less_EdgeEle> boundaryEdges;
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for(int j = 0; j < e->getNumEdges(); j++) {
        std::pair<MEdge, MElement *> ed(e->getEdge(j), e);
        std::set<std::pair<MEdge, MElement *>, Less_EdgeEle>::iterator it =
          boundaryEdges.find(ed);
        if(it == boundaryEdges.end()) { boundaryEdges.insert(ed); }
        else {
          boundaryEdges.erase(it);
        }
      }
    }
    if(boundaryEdges.empty()) continue;

    PView *view = new PView();
    PViewDataList *data = getDataList(view);
    std::vector<MEdge> edges;
    SVector3 normal(0, 0, 1.);
    for(std::set<std::pair<MEdge, MElement *>, Less_EdgeEle>::iterator it =
          boundaryEdges.begin();
        it != boundaryEdges.end(); ++it) {
      edges.push_back(it->first);
      if(it == boundaryEdges.begin()) normal = it->second->getFace(0).normal();
    }
    std::vector<std::vector<MVertex *> > nodes;
    if(SortEdgeConsecutive(edges, nodes)) {
      if(nodes.size() != 1) { Msg::Warning("Non connected boundary!"); }
      else {
        // Preserve orientation of the mesh
        // Algo: Take first edge ; find "it" in the sorted vertices and check
        // order; reverse if necessary
        {
          // First edge (and element) of the boundary
          std::set<std::pair<MEdge, MElement *>, Less_EdgeEle>::iterator it2 =
            boundaryEdges.begin();
          // Loop on every sorted and consecutive nodes
          for(int j = 0; j < static_cast<int>(nodes[0].size()) - 1; j++) {
            // Find the vertex that is the starting point of the edge it2->first
            if(nodes[0][j]->getNum() == it2->first.getVertex(0)->getNum()) {
              // Check that next vertex is also the end-point of the edge
              if(nodes[0][j + 1]->getNum() !=
                 it2->first.getVertex(1)->getNum()) {
                std::reverse(nodes[0].begin(), nodes[0].end());
              }
              break;
            }
          }
        }
        // Handle last elements
        nodes[0].push_back(nodes[0][0]);
        nodes[0].push_back(nodes[0][1]);
        // Compute angle at each point (mod 2pi)
        for(std::size_t i = 0; i < nodes[0].size() - 2; i++) {
          SPoint3 p1 = nodes[0][i]->point();
          SPoint3 p2 = nodes[0][i + 1]->point();
          SPoint3 p3 = nodes[0][i + 2]->point();
          SVector3 v1(p2, p1);
          SVector3 v2(p2, p3);
          double a = signedAngle(v1, v2, normal);
          data->SP.push_back(p2.x());
          data->SP.push_back(p2.y());
          data->SP.push_back(p2.z());
          data->SP.push_back(a);
          data->NbSP++;
        }
      }
    }

    char viewname[500];
    sprintf(viewname, "%s_%d", filename_prefix.c_str(), gf->tag());
    data->Time.push_back(0.);
    data->setName(viewname);
    strcat(viewname, ".pos");
    data->setFileName(viewname);
    data->finalize();
    if(!viewVisible)
      view->getOptions()->visible = 0;
    if(saveOnDisk)
      view->write(viewname, 0, false);
    if(removeView)
      delete view;
    
  }

  return 0;
}
