// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "meshGEdge.h"
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

/*  
    nodes at start (s) and end (e) of GEdge ge
    that does NOT belong tho the list of BL edges
    but is connected to a BL edge (vertical)

    Vertex a is inserted after s
    Vertex b is (possibly) inserted before e

    |
    |
    s--a---x(t(0))---x(t(1))--...--x(t(n-2))-----x(t(n-1))---e    
*/


bool bl2d(GModel *m,
          std::vector<GEdge*> &onCurves,
          std::vector<GFace*> &inSurfaces,
	  double width)
{
  // for each GVertex connected to the GEdges in onCurves:
  //   - if all adjacent GEdges to the GVertex are in onCurves, spawn 1 MVertex
  //     in each GFace connected to the GVertex that are in inSurfaces
  //   - if some adjacent GEdges are not in onCurves, spawn 1 MVertex on each
  //     connected GEdge
  // for each MVertex classified the GEdges in onCurves:
  //   - spawn 1 MVertex in the connected GFaces that are in inSurfaces

  std::set<GEdge*> onCurvesSet;
  onCurvesSet.insert(onCurves.begin(), onCurves.end());

  std::set<GFace*> inSurfacesSet;
  inSurfacesSet.insert(inSurfaces.begin(), inSurfaces.end());

  std::map<MVertex*, std::vector<MVertex*>> spawned;

  std::set<GVertex*> connectedPoints;
  for(auto ge : onCurves) {
    auto vs = ge->vertices();
    connectedPoints.insert(vs.begin(), vs.end());
  }


  // spawn nodes for model points
  for(auto gv : connectedPoints) {
    if(gv->mesh_vertices.empty()) {
      Msg::Error("No mesh node on model point %d - abort!", gv->tag());
      return false;
    }

    std::vector<GEdge*> connectedCurves = gv->edges();
    std::vector<GFace*> connectedSurfaces = gv->faces();
    std::vector<GEdge*> toinsert;
    std::size_t found = 0;
    for(auto ge : connectedCurves) {
      if(onCurvesSet.find(ge) != onCurvesSet.end()) {
        found++;
      }
      else {
        toinsert.push_back(ge);
      }
    }
    // All edges adjacent to this model edge are in the boundart layer
    // thus we only add one point on the face -- the strategy here is
    // to possibly add "fans" in a second stage as another "plugin" 
    if(found == connectedCurves.size()) {
      for(auto gf : connectedSurfaces) {
        if(inSurfacesSet.find(gf) != inSurfacesSet.end()) {
          MVertex *v = gv->mesh_vertices[0];
          SPoint2 param;
          if(reparamMeshVertexOnFace(v, gf, param)) {
            MVertex *newv = new MFaceVertex(v->x(), v->y(), v->z(), gf,
                                            param.x(), param.y());
            gf->mesh_vertices.push_back(newv);
            spawned[v].push_back(newv);
            printf("inserted node %lu from point %d in surface %d\n",
                   newv->getNum(), gv->tag(), gf->tag());
          }
          else {
            Msg::Warning("Could not compute parametric coordinates of node on "
                         "surface %d - maybe on seam?", gf->tag());
          }
        }
      }
    }
    // insert a boundary layer node in every connected edge that is NOT
    // on the boundary layer -- this includes "slip" walls and embedded edges
    else {
      for(auto ge : toinsert) {
        MVertex *v = gv->mesh_vertices[0];
        double param;
        if(reparamMeshVertexOnEdge(v, ge, param)){
	  bool end = ge->getEndVertex() == gv;
	  MVertex *newv;
	  if (end){
	    MEdgeVertex *vend = static_cast<MEdgeVertex*> (ge->mesh_vertices.back());
	    newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param,vend->getLc());
	    ge->mesh_vertices.push_back(newv);
	  }
	  else {
	    MEdgeVertex *vbeg = static_cast<MEdgeVertex*> (ge->mesh_vertices.front());
	    newv = new MEdgeVertex(v->x(), v->y(), v->z(), ge, param,vbeg->getLc());
	    ge->mesh_vertices.insert(ge->mesh_vertices.begin(),newv);
	  }
	  
          spawned[v].push_back(newv);
          printf("inserted node %lu from point %d in curve %d -- %lu internal nodes\n",
                 newv->getNum(), gv->tag(), ge->tag(),ge->mesh_vertices.size());
	  if (end)ge->lines.push_back(new MLine(v, newv));
	  else ge->lines.insert(ge->lines.begin(),new MLine(newv, v));
        }
        else{
          Msg::Warning("Could not compute parametric coordinates of node on "
                       "curve %d", ge->tag());
        }
      }
    }
  }

  // spawn nodes for model curves
  for(auto ge : onCurves) {
    std::vector<GFace*> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(auto v : ge->mesh_vertices) {
        SPoint2 param;
        if(reparamMeshVertexOnFace(v, gf, param)) {
          MVertex *newv = new MFaceVertex(v->x(), v->y()+0.01, v->z(), gf,
                                          param.x(), param.y()+0.01);
          gf->mesh_vertices.push_back(newv);
          spawned[v].push_back(newv);
        }
      }
    }
  }

  
  std::set<GEntity*> modified;
  for(auto vv : spawned)
    for(auto v : vv.second)
      modified.insert(v->onWhat());

  // connect old elements to new spawned vertices

  //  for(auto ge : modified) {
  //    for(std::size_t i = 0; i < ge->getNumMeshElements(); i++) {
  //      MElement *e = ge->getMeshElement(i);
  //      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
  //	auto sp = spawned[e->getVertex(j)];
  //	for(auto v : sp) {
  //	  if(v->onWhat() == ge) {
  //	    e->setVertex(j, v);
  //	    break;
  //	  }
  //	}
  //      }
  //    }
  //  }

  for (auto gf : inSurfaces) {
    for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
      MElement *e = gf->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
	auto sp = spawned[e->getVertex(j)];
	for(auto v : sp) {
	  if(v->onWhat() == gf || v->onWhat()->dim() == 1) {
	      e->setVertex(j, v);
	  }
	}
      }
    }
  }
	
  /*  for(auto ge : modified) {
    std::vector<GFace*> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
	MElement *e = gf->getMeshElement(i);
	for(std::size_t j = 0; j < e->getNumVertices(); j++) {
	  auto sp = spawned[e->getVertex(j)];
	  for(auto v : sp) {
	    if(v->onWhat() == ge) {
	      e->setVertex(j, v);
	      break;
	    }
	  }
        }
      }
    }
    }*/

  // create zero-sized elements in connected surfaces
  for(auto ge : onCurves) {
    std::vector<GFace*> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
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
  }

  for (GModel::eiter eit = m->firstEdge() ; eit != m->lastEdge() ; ++eit) meshGEdgeInsertBoundaryLayer(*eit, width);

  // TODO: fans
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

  double width = 3.e-1;
  if(ge1 && ge2 && ge3 && ge4 && gf) {
    std::vector<GEdge*> e = {ge1,ge2,ge4};
    std::vector<GFace*> f = {gf};
    bl2d(m, e, f, width);
  }

  return v;
}
