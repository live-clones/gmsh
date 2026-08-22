// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <vector>
#include "GmshMessage.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "meshGFaceCopy.h"

void copyMesh(GFace *source, GFace *target)
{
  std::map<MVertex *, MVertex *> vs2vt;

  // add principal GVertex pairs

  std::vector<GVertex *> s_vtcs = source->vertices();
  s_vtcs.insert(s_vtcs.end(), source->embeddedVertices().begin(),
                source->embeddedVertices().end());
  for(auto it = source->embeddedEdges().begin();
      it != source->embeddedEdges().end(); it++) {
    if((*it)->getBeginVertex()) s_vtcs.push_back((*it)->getBeginVertex());
    if((*it)->getEndVertex()) s_vtcs.push_back((*it)->getEndVertex());
  }
  std::vector<GVertex *> t_vtcs = target->vertices();
  t_vtcs.insert(t_vtcs.end(), target->embeddedVertices().begin(),
                target->embeddedVertices().end());
  for(auto it = target->embeddedEdges().begin();
      it != target->embeddedEdges().end(); it++) {
    if((*it)->getBeginVertex()) t_vtcs.push_back((*it)->getBeginVertex());
    if((*it)->getEndVertex()) t_vtcs.push_back((*it)->getEndVertex());
  }

  if(s_vtcs.size() != t_vtcs.size()) {
    Msg::Info("Periodicity imposed on topologically incompatible surfaces"
              "(%d vs %d points)",
              s_vtcs.size(), t_vtcs.size());
  }

  std::set<GVertex *> checkVtcs(s_vtcs.begin(), s_vtcs.end());

  for(auto tvIter = t_vtcs.begin(); tvIter != t_vtcs.end(); ++tvIter) {
    GVertex *gvt = *tvIter;
    auto gvsIter = target->vertexCounterparts.find(gvt);

    if(gvsIter == target->vertexCounterparts.end()) {
      Msg::Error("Periodic meshing of surface %d with surface %d: "
                 "point %d has no periodic counterpart",
                 target->tag(), source->tag(), gvt->tag());
    }
    else {
      GVertex *gvs = gvsIter->second;
      if(checkVtcs.find(gvs) == checkVtcs.end()) {
        if(gvs)
          Msg::Error(
            "Periodic meshing of surface %d with surface %d: "
            "point %d has periodic counterpart %d outside of source surface",
            target->tag(), source->tag(), gvt->tag(), gvs->tag());

        else
          Msg::Error("Periodic meshing of surface %d with surface %d: "
                     "point %d has no periodic counterpart",
                     target->tag(), source->tag(), gvt->tag());
      }
      if(gvs) {
        MVertex *vs = gvs->mesh_vertices[0];
        MVertex *vt = gvt->mesh_vertices[0];
        vs2vt[vs] = vt;
        target->correspondingVertices[vt] = vs;
      }
    }
  }

  // add corresponding curve nodes assuming curves were correctly meshed already

  std::vector<GEdge *> s_edges = source->edges();
  s_edges.insert(s_edges.end(), source->embeddedEdges().begin(),
                 source->embeddedEdges().end());
  std::vector<GEdge *> t_edges = target->edges();
  t_edges.insert(t_edges.end(), target->embeddedEdges().begin(),
                 target->embeddedEdges().end());

  std::set<GEdge *> checkEdges;
  checkEdges.insert(s_edges.begin(), s_edges.end());

  for(auto te_iter = t_edges.begin(); te_iter != t_edges.end(); ++te_iter) {
    GEdge *get = *te_iter;

    auto gesIter = target->edgeCounterparts.find(get);
    if(gesIter == target->edgeCounterparts.end()) {
      Msg::Error("Periodic meshing of surface %d with surface %d: "
                 "curve %d has no periodic counterpart",
                 target->tag(), source->tag(), get->tag());
    }
    else {
      GEdge *ges = gesIter->second.first;
      if(checkEdges.find(ges) == checkEdges.end()) {
        Msg::Error("Periodic meshing of surface %d with surface %d: "
                   "curve %d has periodic counterpart %d",
                   target->tag(), source->tag(), get->tag(), ges->tag());
      }
      if(get->mesh_vertices.size() != ges->mesh_vertices.size()) {
        Msg::Error("Periodic meshing of surface %d with surface %d: "
                   "curve %d has %d vertices, whereas correspondant %d has %d",
                   target->tag(), source->tag(), get->tag(),
                   get->mesh_vertices.size(), ges->tag(),
                   ges->mesh_vertices.size());
      }
      int orientation = gesIter->second.second;
      int is = orientation == 1 ? 0 : get->mesh_vertices.size() - 1;
      for(unsigned it = 0; it < get->mesh_vertices.size();
          it++, is += orientation) {
        MVertex *vs = ges->mesh_vertices[is];
        MVertex *vt = get->mesh_vertices[it];
        vs2vt[vs] = vt;
        target->correspondingVertices[vt] = vs;
      }
    }
  }

  // transform interior nodes
  std::vector<double> &tfo = target->affineTransform;

  for(std::size_t i = 0; i < source->mesh_vertices.size(); i++) {
    MVertex *vs = source->mesh_vertices[i];
    SPoint2 XXX;

    double ps[4] = {vs->x(), vs->y(), vs->z(), 1.};
    double res[4] = {0., 0., 0., 0.};
    int idx = 0;
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) res[i] += tfo[idx++] * ps[j];

    SPoint3 tp(res[0], res[1], res[2]);
    XXX = target->parFromPoint(tp);

    GPoint gp = target->point(XXX);
    MVertex *vt =
      new MFaceVertex(gp.x(), gp.y(), gp.z(), target, gp.u(), gp.v());
    target->mesh_vertices.push_back(vt);
    target->correspondingVertices[vt] = vs;
    vs2vt[vs] = vt;
  }

  // create new elements
  for(unsigned i = 0; i < source->triangles.size(); i++) {
    MVertex *v1 = vs2vt[source->triangles[i]->getVertex(0)];
    MVertex *v2 = vs2vt[source->triangles[i]->getVertex(1)];
    MVertex *v3 = vs2vt[source->triangles[i]->getVertex(2)];
    if(v1 && v2 && v3) {
      target->triangles.push_back(new MTriangle(v1, v2, v3));
    }
    else {
      Msg::Error("Could not find periodic counterpart of triangle nodes "
                 "%zu %zu %zu",
                 source->triangles[i]->getVertex(0)->getNum(),
                 source->triangles[i]->getVertex(1)->getNum(),
                 source->triangles[i]->getVertex(2)->getNum());
    }
  }

  for(unsigned i = 0; i < source->quadrangles.size(); i++) {
    MVertex *v1 = vs2vt[source->quadrangles[i]->getVertex(0)];
    MVertex *v2 = vs2vt[source->quadrangles[i]->getVertex(1)];
    MVertex *v3 = vs2vt[source->quadrangles[i]->getVertex(2)];
    MVertex *v4 = vs2vt[source->quadrangles[i]->getVertex(3)];
    if(v1 && v2 && v3 && v4) {
      target->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
    }
    else {
      Msg::Error("Could not find periodic counterpart of quadrangle nodes "
                 "%zu %zu %zu %zu",
                 source->quadrangles[i]->getVertex(0)->getNum(),
                 source->quadrangles[i]->getVertex(1)->getNum(),
                 source->quadrangles[i]->getVertex(2)->getNum(),
                 source->quadrangles[i]->getVertex(3)->getNum());
    }
  }
}