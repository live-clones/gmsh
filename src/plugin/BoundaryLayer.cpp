// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include "GModel.h"
#include "BoundaryLayer.h"

StringXNumber BoundaryLayerOptions_Number[] = {
  {GMSH_FULLRC, "Test", nullptr, 1.}
};

extern "C" {
  GMSH_Plugin *GMSH_RegisterBoundaryLayerPlugin() {
    return new GMSH_BoundaryLayerPlugin();
  }
}

std::string GMSH_BoundaryLayerPlugin::getHelp() const
{
  return "Plugin(BoundaryLayer) performs magic.";
}

int GMSH_BoundaryLayerPlugin::getNbOptions() const
{
  return sizeof(BoundaryLayerOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_BoundaryLayerPlugin::getOption(int iopt)
{
  return &BoundaryLayerOptions_Number[iopt];
}

bool bl2d(GModel *m,
          std::vector<GEdge*> &input,
          std::vector<GFace*> &faces)
{
  // get all GVertex in input edges
  // for each GVertex:
  //   - if all adjacent edges to the vertex are in input, spawn 1 node
  //        in each face in all the faces connected to the vertex
  //   - if some edges are not in input, spawn 1 node on each connected
  //     edge
  // for each MVertex on input that is not on a GVErtex
  //   - spawn 1 node in the face

  std::map<MVertex*, std::vector<MVertex*>> spawned;
  std::set<GEdge*> ges;
  ges.insert(input.begin(), input.end());
  std::set<GFace*> gfs;
  gfs.insert(faces.begin(), faces.end());
  std::set<GVertex*> gvs;
  for(auto ge : input) {
    auto vs = ge->vertices();
    gvs.insert(vs.begin(), vs.end());
  }

  printf("input %lu %lu\n", ges.size(), gvs.size());

  for(auto gv : gvs) {
    if(gv->mesh_vertices.empty()) {
      Msg::Error("No mesh node on model point %d - abort!", gv->tag());
      return false;
    }

    std::vector<GEdge*> connectedEdges = gv->edges();
    std::vector<GFace*> connectedFaces = gv->faces();
    std::vector<GEdge*> toinsert;
    std::size_t found = 0;
    for(auto ge : connectedEdges) {
      if(ges.find(ge) != ges.end()) {
        found++;
      }
      else {
        toinsert.push_back(ge);
      }
    }
    if(found == connectedEdges.size()) {
      for(auto gf : connectedFaces) {
        if(gfs.find(gf) != gfs.end()) {
          printf("insert vertex %d in face %d\n", gv->tag(), gf->tag());
          MVertex *v = gv->mesh_vertices[0];
          MVertex *newv = new MFaceVertex(v->x(), v->y(), v->z(), gf, 0., 0.);
          spawned[v].push_back(newv);
        }
      }
    }
    else {
      for(auto ge : toinsert) {
        printf("insert vertex %d in edge %d\n", gv->tag(), ge->tag());
        MVertex *v = gv->mesh_vertices[0];
        MVertex *newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, 0.);
        spawned[v].push_back(newv);
      }
    }
  }

  // TOOD: fans
}

PView *GMSH_BoundaryLayerPlugin::execute(PView *v)
{
  int test = (int)BoundaryLayerOptions_Number[0].def;

  GModel *m = GModel::current();
  GEdge *ge1 = m->getEdgeByTag(1);
  GEdge *ge2 = m->getEdgeByTag(2);
  GFace *gf = m->getFaceByTag(1);

  if(ge1 && ge2 && gf) {
    std::vector<GEdge*> e = {ge1, ge2};
    std::vector<GFace*> f = {gf};
    bl2d(m, e, f);
  }

  return v;
}
