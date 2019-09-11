// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "BoundaryAngles.h"
#include "GModel.h"
#include "discreteEdge.h"
#include "MLine.h"

StringXNumber BoundaryAnglesOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.},
};

extern "C" {
GMSH_Plugin *GMSH_RegisterBoundaryAnglesPlugin() { return new GMSH_BoundaryAnglesPlugin(); }
}


std::string GMSH_BoundaryAnglesPlugin::getHelp() const
{
  return "Plugin(BoundaryAngles) computes FIXME.";
}

int GMSH_BoundaryAnglesPlugin::getNbOptions() const
{
  return sizeof(BoundaryAnglesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_BoundaryAnglesPlugin::getOption(int iopt)
{
  return &BoundaryAnglesOptions_Number[iopt];
}

struct Less_EdgeEle {
  bool operator()(const std::pair<MEdge, MElement*> &e1,
                  const std::pair<MEdge, MElement*> &e2) const
  {
    Less_Edge le;
    return le(e1.first, e2.first);
  }
};

PView *GMSH_BoundaryAnglesPlugin::execute(PView *v)
{
  // get the mesh of the current model, and iterate on the surfaces

  GModel *m = GModel::current();
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {

    GFace *gf = *it;
    std::set<std::pair<MEdge, MElement*>, Less_EdgeEle> boundaryEdges;
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for(int j = 0; j < e->getNumEdges(); j++) {
        std::pair<MEdge, MElement *> ed(e->getEdge(j), e);
        std::set<std::pair<MEdge, MElement*>, Less_EdgeEle>::iterator it =
          boundaryEdges.find(ed);
        if(it == boundaryEdges.end()) {
          boundaryEdges.insert(ed);
        }
        else{
          boundaryEdges.erase(it);
        }
      }
    }
    printf("%d boundary edges on face %d\n", boundaryEdges.size(), gf->tag());
    if(boundaryEdges.empty()) continue;

    PView *view = new PView();
    PViewDataList *data = getDataList(view);

    // fix orientation?
    /*
    bool reverse;
    std::set<std::pair<MEdge, MElement*>, Less_EdgeEle>::iterator it2 = boundaryEdges.begin();
    for(int j = 0; j < it2->second->getNumEdges(); j++){
      MEdge ed = it2->second->getEdge(j);
      if(it2->first == ed){
        if(it2->first.getVertex(0) != ed.getVertex(0)) {
          printf("REVERSE!\n");
          reverse = true;
        }
      }
    }
    */

    std::vector<MEdge> edges;
    SVector3 normal(0, 0, 1.);
    for(std::set<std::pair<MEdge, MElement*>, Less_EdgeEle>::iterator it =
          boundaryEdges.begin(); it != boundaryEdges.end(); ++it) {
      edges.push_back(it->first);
      if(it == boundaryEdges.begin())
        normal = it->second->getFace(0).normal();
    }
    std::vector<std::vector<MVertex *> > nodes;
    if(SortEdgeConsecutive(edges, nodes)) {
      if(nodes.size() != 1) {
        Msg::Warning("Non connected boundary!");
      }
      else{
        printf("sorted nodes:\n");
        // FIXME handle last elements
        for(std::size_t i = 0; i < nodes[0].size() - 2; i++) {
          SPoint3 p1 = nodes[0][i]->point();
          SPoint3 p2 = nodes[0][i + 1]->point();
          SPoint3 p3 = nodes[0][i + 2]->point();
          SVector3 v1(p2, p1);
          SVector3 v2(p2, p3);
          double a = signedAngle(v1, v2, normal);
          printf("angle = %g\n", a);

          data->SP.push_back(p2.x());
          data->SP.push_back(p2.y());
          data->SP.push_back(p2.z());
          data->SP.push_back(a);
          data->NbSP++;
        }
      }
    }

    char tmp[500];
    sprintf(tmp, "Surface%d_Angles", gf->tag());
    data->Time.push_back(0.);
    data->setName(tmp);
    strcat(tmp, ".pos");
    data->setFileName(tmp);
    data->finalize();
  }

  return 0;
}
