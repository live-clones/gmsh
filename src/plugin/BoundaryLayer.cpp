// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
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

  // spawn nodes for model points
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
          SPoint2 param;
          if(reparamMeshVertexOnFace(v, gf, param)) {
            MVertex *newv = new MFaceVertex(v->x(), v->y(), v->z(), gf,
                                            param.x(), param.y());
            gf->mesh_vertices.push_back(newv);
            spawned[v].push_back(newv);
          }
          else {
            Msg::Warning("Could not compute parametric coordinates of node on "
                         "surface %d - maybe on seam?", gf->tag());
          }
        }
      }
    }
    else {
      for(auto ge : toinsert) {
        printf("insert vertex %d in edge %d\n", gv->tag(), ge->tag());
        MVertex *v = gv->mesh_vertices[0];
        double param;
        if(reparamMeshVertexOnEdge(v, ge, param)){
          MVertex *newv = new MEdgeVertex(v->x(), v->y()+0.075, v->z(), ge, param);
          ge->mesh_vertices.push_back(newv);
          spawned[v].push_back(newv);
        }
        else{
          Msg::Warning("Could not compute parametric coordinates of node on "
                       "curve %d", ge->tag());
        }
      }
    }
  }

  // spawn nodes for curves
  for(auto ge : input) {
    std::vector<GFace*> connectedFaces = ge->faces();
    for(auto gf : connectedFaces) {
      if(gfs.find(gf) == gfs.end()) continue;
      for(auto v : ge->mesh_vertices) {
        SPoint2 param;
        if(reparamMeshVertexOnFace(v, gf, param)) {
          MVertex *newv = new MFaceVertex(v->x(), v->y(), v->z(), gf,
                                          param.x(), param.y());
          gf->mesh_vertices.push_back(newv);
          spawned[v].push_back(newv);
        }
      }
    }
  }

  // connect old elements to new spawned vertices
  for(auto gf : faces) {
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        auto sp = spawned[e->getVertex(j)];
        for(auto v : sp) {
          if(v->onWhat() == gf) {
            e->setVertex(j, v);
            break;
          }
          // find better solution
          auto bnd = gf->edges();
          for(auto ge : bnd) {
            if(v->onWhat() == ge) {
              e->setVertex(j, v);
              break;
            }
          }
        }
      }
    }
  }

  // create zero-sized elements:
  for(auto ge : input) {
    std::vector<GFace*> connectedFaces = ge->faces();
    for(auto gf : connectedFaces) {
      if(gfs.find(gf) == gfs.end()) continue;
      for(std::size_t i = 0; i < ge->lines.size(); i++) {
        MLine *l = ge->lines[i];
        auto sp0 = spawned[l->getVertex(0)];
        auto sp1 = spawned[l->getVertex(1)];
        if(sp0.empty() || sp1.empty()) {
          Msg::Warning("Could not find spawned boundary layer node for node(s) "
                       "%lu and/or %lu", l->getVertex(0)->getNum(),
                       l->getVertex(1)->getNum());
        }
        else {
          gf->quadrangles.push_back(new MQuadrangle(l->getVertex(0), l->getVertex(1),
                                                    sp1.front(), sp0.front()));
          for(std::size_t j = 1; j < sp0.size(); j++)
            gf->triangles.push_back(new MTriangle(l->getVertex(0),
                                                  sp0[j - 1], sp0[j]));
          for(std::size_t j = 1; j < sp1.size(); j++)
            gf->triangles.push_back(new MTriangle(l->getVertex(1),
                                                  sp1[j - 1], sp1[j]));
        }
      }
    }
    // TODO create missing line elements
  }


  // TOOD: fans
}

PView *GMSH_BoundaryLayerPlugin::execute(PView *v)
{
  int test = (int)BoundaryLayerOptions_Number[0].def;

  GModel *m = GModel::current();
  GEdge *ge1 = m->getEdgeByTag(1);
  GEdge *ge2 = m->getEdgeByTag(2);
  GEdge *ge3 = m->getEdgeByTag(3);
  GEdge *ge4 = m->getEdgeByTag(4);
  GFace *gf = m->getFaceByTag(1);

  if(ge1 && ge2 && ge3 && ge4 && gf) {
    std::vector<GEdge*> e = {ge1, ge2};
    std::vector<GFace*> f = {gf};
    bl2d(m, e, f);
  }

  return v;
}
