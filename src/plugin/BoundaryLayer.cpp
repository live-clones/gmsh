// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <set>
#include "GModel.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "meshGEdge.h"
#include "BoundaryLayer.h"
#include "winslowUntangler.h"
#include "Context.h"

StringXNumber BoundaryLayerOptions_Number[] = {
  {GMSH_FULLRC, "Thickness", nullptr, 1.e-2},
  {GMSH_FULLRC, "Size", nullptr, 1.e-3},
  {GMSH_FULLRC, "Ratio", nullptr, 1.2}};

StringXString BoundaryLayerOptions_String[] = {
  {GMSH_FULLRC, "Volumes", nullptr, ""},
  {GMSH_FULLRC, "Surfaces", nullptr, ""},
  {GMSH_FULLRC, "Curves", nullptr, ""},
  {GMSH_FULLRC, "Points", nullptr, ""},
};

extern "C" {
GMSH_Plugin *GMSH_RegisterBoundaryLayerPlugin()
{
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

int GMSH_BoundaryLayerPlugin::getNbOptionsStr() const
{
  return sizeof(BoundaryLayerOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_BoundaryLayerPlugin::getOptionStr(int iopt)
{
  return &BoundaryLayerOptions_String[iopt];
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

static double triangle_area_2d(std::array<double, 2> a, std::array<double, 2> b,
                               std::array<double, 2> c)
{
  return .5 * ((b[1] - a[1]) * (b[0] + a[0]) + (c[1] - b[1]) * (c[0] + b[0]) +
               (a[1] - c[1]) * (a[0] + c[0]));
}

static void fanitzie(std::vector<GFace *> &gfs, std::vector<GVertex *> &gvs,
                     std::vector<MElement *> &ecole_des_fans)
{
  for(auto gv : gvs) {
    MVertex *v = gv->mesh_vertices[0];
    MVertex *toDelete = nullptr;

    for(auto gf : gfs) {
      int count = 0;
      for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
        for(size_t j = 0; j < 4; j++) {
          MEdge ed = gf->quadrangles[i]->getEdge(j);
          if(ed.getVertex(0) == v && ed.getVertex(1)->onWhat() == gf) {
            toDelete = ed.getVertex(1);
            count++;
          }
          else if(ed.getVertex(1) == v && ed.getVertex(0)->onWhat() == gf) {
            toDelete = ed.getVertex(0);
            count++;
          }
        }
      }
      if(count != 2) {
        Msg::Warning("Impossible to make a fan at GVertex %d (count = %d)",
                     gv->tag(), count);
        continue;
      }

      std::vector<MTriangle *> corners, local_fans;
      for(std::size_t i = 0; i < gf->triangles.size(); i++) {
        for(std::size_t j = 0; j < 3; j++) {
          if(gf->triangles[i]->getVertex(j) == toDelete) {
            MVertex *vv[3] = {v, gf->triangles[i]->getVertex((j + 1) % 3),
                              gf->triangles[i]->getVertex((j + 2) % 3)};
            gf->triangles[i]->setVertex(0, vv[0]);
            gf->triangles[i]->setVertex(1, vv[1]);
            gf->triangles[i]->setVertex(2, vv[2]);
            ecole_des_fans.push_back(gf->triangles[i]);
            local_fans.push_back(gf->triangles[i]);
          }
        }
      }

      std::vector<MQuadrangle *> temp;
      for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
        bool found = false;

        int foundindex = -1;
        for(std::size_t j = 0; j < 4; j++)
          if(gf->quadrangles[i]->getVertex(j) == v) { foundindex = j; }

        for(std::size_t j = 0; j < 4; j++) {
          if(gf->quadrangles[i]->getVertex(j) == toDelete) {
            if(foundindex >= 0) {
              found = true;
              MVertex *qq[4] = {
                gf->quadrangles[i]->getVertex((foundindex + 0) % 4),
                gf->quadrangles[i]->getVertex((foundindex + 1) % 4),
                gf->quadrangles[i]->getVertex((foundindex + 2) % 4),
                gf->quadrangles[i]->getVertex((foundindex + 3) % 4)};
              auto newT =
                new MTriangle(gf->quadrangles[i]->getVertex((j + 1) % 4),
                              gf->quadrangles[i]->getVertex((j + 2) % 4),
                              gf->quadrangles[i]->getVertex((j + 3) % 4));
              int count = 0;
              //     printf("%lu %lu %lu %lu
              //     \n",qq[0]->getNum(),qq[1]->getNum(),qq[2]->getNum(),qq[3]->getNum());
              for(int k = 0; k < 4; k++) {
                if(qq[k] != toDelete) newT->setVertex(count++, qq[k]);
              }
              ecole_des_fans.push_back(newT);
              corners.push_back(newT);
              gf->triangles.push_back(newT);
            }
            else {
              gf->quadrangles[i]->setVertex(j, v);
            }
          }
        }
        if(found)
          delete gf->quadrangles[i];
        else
          temp.push_back(gf->quadrangles[i]);
      }
      gf->quadrangles = temp;

      auto toErase =
        std::find(gf->mesh_vertices.begin(), gf->mesh_vertices.end(), toDelete);
      if(toErase != gf->mesh_vertices.end()) gf->mesh_vertices.erase(toErase);

      if(corners.size() == 2) {
        for(auto t : corners) {
          for(auto tt : local_fans) {
            if(tt != t) {
              for(size_t j = 0; j < 3; j++) {
                MVertex *tj0 = t->getVertex(j);
                MVertex *tj1 = t->getVertex((j + 1) % 3);
                MVertex *tj2 = t->getVertex((j + 2) % 3);
                for(size_t k = 0; k < 3; k++) {
                  MVertex *ttj0 = tt->getVertex(k);
                  MVertex *ttj1 = tt->getVertex((k + 1) % 3);
                  MVertex *ttj2 = tt->getVertex((k + 2) % 3);
                  if(ttj0 == tj1 && ttj1 == tj0) {
                    gf->triangles.erase(
                      std::find(gf->triangles.begin(), gf->triangles.end(), t));
                    gf->triangles.erase(std::find(gf->triangles.begin(),
                                                  gf->triangles.end(), tt));
                    MVertex *vv[4] = {tj0, ttj2, tj1, tj2};
                    for(size_t l = 0; l < 4; l++) {
                      if(vv[l]->onWhat()->dim() != 2 &&
                         vv[(l + 1) % 4]->onWhat()->dim() != 2) {
                        gf->quadrangles.push_back(
                          new MQuadrangle(vv[(l + 0) % 4], vv[(l + 1) % 4],
                                          vv[(l + 2) % 4], vv[(l + 3) % 4]));
                        ecole_des_fans.push_back(gf->quadrangles.back());
                        break;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

bool bl(GModel *m, std::vector<GVertex *> &onPoints,
        std::vector<GEdge *> &onCurves, std::vector<GFace *> &inSurfaces,
        std::vector<GRegion *> &inVolumes, double thickness,
        std::map<MElement *, double> &layers)
{
  // 2D case:
  // for each GVertex connected to the GEdges in onCurves:
  //   - if all adjacent GEdges to the GVertex are in onCurves, spawn 1 MVertex
  //     in each GFace connected to the GVertex that are in inSurfaces
  //   - if some adjacent GEdges are not in onCurves, spawn 1 MVertex on each
  //     connected GEdge
  // for each MVertex classified on the GEdges in onCurves:
  //   - spawn 1 MVertex in the connected GFaces that are in inSurfaces

  // 3D case:
  // for each GVertex connected to the GFaces in inSurfaces:
  //   - if all adjacent GFaces to the GVertex are in inSurface, spawn 1 MVertex
  //     in each GRegion connected to the GVertex that are in inVolumes
  //   - if some adjacent GFaces are not in inSurfaces, spawn 1 MVertex in each
  //     connected GFace
  //   -
  // for each MVertex classified on a GEdge connected to the GFaces in
  // inSurfaces:
  //   -
  // for each MVertex classified on the GFaces in inSurfaces:
  //   -

  std::set<GEdge *> onCurvesSet;
  onCurvesSet.insert(onCurves.begin(), onCurves.end());

  std::set<GFace *> inSurfacesSet;
  inSurfacesSet.insert(inSurfaces.begin(), inSurfaces.end());

  std::map<MVertex *, std::vector<MVertex *>> spawned;

  std::set<GVertex *> connectedPoints;
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

    std::vector<GEdge *> connectedCurves = gv->edges();
    std::vector<GFace *> connectedSurfaces = gv->faces();
    std::vector<GEdge *> toinsert;
    std::size_t found = 0;
    for(auto ge : connectedCurves) {
      if(onCurvesSet.find(ge) != onCurvesSet.end()) { found++; }
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
            MVertex *newv =
              new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
            gf->mesh_vertices.push_back(newv);
            spawned[v].push_back(newv);
            Msg::Debug("inserted node %lu from point %d in surface %d",
                       newv->getNum(), gv->tag(), gf->tag());
          }
          else {
            Msg::Warning("Could not compute parametric coordinates of node on "
                         "surface %d - maybe on seam?",
                         gf->tag());
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
        if(reparamMeshVertexOnEdge(v, ge, param)) {
          bool end = ge->getEndVertex() == gv;
          MVertex *newv;
          if(end) {
            MEdgeVertex *vend =
              static_cast<MEdgeVertex *>(ge->mesh_vertices.back());
            newv =
              new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, vend->getLc());
            ge->mesh_vertices.push_back(newv);
          }
          else {
            MEdgeVertex *vbeg =
              static_cast<MEdgeVertex *>(ge->mesh_vertices.front());
            newv =
              new MEdgeVertex(v->x(), v->y(), v->z(), ge, param, vbeg->getLc());
            ge->mesh_vertices.insert(ge->mesh_vertices.begin(), newv);
          }

          spawned[v].push_back(newv);
          Msg::Debug("inserted node %lu from point %d in curve %d -- %lu internal nodes",
                     newv->getNum(), gv->tag(), ge->tag(),ge->mesh_vertices.size());
          if(end)
            ge->lines.push_back(new MLine(v, newv));
          else
            ge->lines.insert(ge->lines.begin(), new MLine(newv, v));
        }
        else {
          Msg::Warning("Could not compute parametric coordinates of node on "
                       "curve %d", ge->tag());
        }
      }
    }
  }

  // spawn nodes for model curves
  for(auto ge : onCurves) {
    std::vector<GFace *> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(auto v : ge->mesh_vertices) {
        SPoint2 param;
        if(reparamMeshVertexOnFace(v, gf, param)) {
          MVertex *newv =
            new MFaceVertex(v->x(), v->y(), v->z(), gf, param.x(), param.y());
          gf->mesh_vertices.push_back(newv);
          spawned[v].push_back(newv);
        }
      }
    }
  }

  std::set<GEntity *> modified;
  for(auto vv : spawned)
    for(auto v : vv.second) modified.insert(v->onWhat());

  for(auto gf : inSurfaces) {
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

  // create zero-sized elements in connected surfaces
  for(auto ge : onCurves) {
    std::vector<GFace *> connectedSurfaces = ge->faces();
    for(auto gf : connectedSurfaces) {
      std::set<MEdge, MEdgeLessThan> edges_of_elements;
      for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
        MElement *e = gf->getMeshElement(i);
        for(int j = 0; j < e->getNumEdges(); j++)
          edges_of_elements.insert(e->getEdge(j));
      }

      if(inSurfacesSet.find(gf) == inSurfacesSet.end()) continue;
      for(std::size_t i = 0; i < ge->lines.size(); i++) {
        MLine *l = ge->lines[i];
        auto sp0 = spawned[l->getVertex(0)];
        auto sp1 = spawned[l->getVertex(1)];
        if(sp0.empty() || sp1.empty()) {
          Msg::Warning("Could not find spawned boundary layer node for node(s) "
                       "%lu and/or %lu",
                       l->getVertex(0)->getNum(), l->getVertex(1)->getNum());
        }
        else {
          std::vector<MVertex *> V0, V1;
          for(auto V : sp0)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V0.push_back(V);
            }
          for(auto V : sp1)
            if(V->onWhat() == gf || V->onWhat()->dim() == 1) {
              V1.push_back(V);
            }
          // There can be several vertices for the same face -- in case of
          // embedded edges. Assume that points are spawned on one side and then
          // on the other in the same order.
          if(V0.size() != V1.size())
            Msg::Error("Error Boundary Layer %lu %lu", V0.size(), V1.size());
          for(size_t j = 0; j < V0.size(); j++) {
            std::set<MEdge, MEdgeLessThan>::iterator it =
              edges_of_elements.find(MEdge(V1[j], V0[j]));
            if(it == edges_of_elements.end()) {
              Msg::Error("Edge not found in boundary layer");
            }
            else {
              // orientation matters !!!
              if(it->getVertex(0) == V0[j])
                gf->quadrangles.push_back
                  (new MQuadrangle(l->getVertex(0), l->getVertex(1), V1[j], V0[j]));
              else
                gf->quadrangles.push_back
                  (new MQuadrangle(l->getVertex(1), l->getVertex(0), V0[j], V1[j]));
              layers[gf->quadrangles.back()] = thickness;
            }
          }
        }
      }
    }
  }

  std::vector<MElement *> ecole_des_fans;
  fanitzie(inSurfaces, onPoints, ecole_des_fans);
  for(auto e : ecole_des_fans) layers[e] = thickness;
  return true;
}

static void expandBL(
  GFace *gf,
  std::map<MElement *, std::array<std::array<double, 2>, 4>> &perfectShapes,
  std::map<MElement *, double> &layers, std::vector<GFace *> &inSurfaces)
{
  //  printf("layer size %lu\n",layers.size());
  //  std::vector<double> areas;
  std::vector<std::array<std::array<double, 2>, 3>> sh;
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    //    printf("%lu %lu\n",i,gf->getNumMeshElements());
    MElement *e = gf->getMeshElement(i);

    std::array<std::array<double, 2>, 4> vs;

    auto it = layers.find(e);

    if(e->getNumVertices() == 3) {
      if(it != layers.end()) {
        double T = M_PI / 6.;
        double thickness = it->second;
        //	double fact = it->second/sqrt(3.0);
        vs[0] = {0, 0.};
        vs[1] = {thickness, 0.};
        vs[2] = {thickness * cos(T), thickness * sin(T)};
        //	vs[0] = {fact, 0.};
        //	vs[1] = {fact*cos(2. * M_PI / 3.), fact*sin(2 * M_PI / 3.)};
        //	vs[2] = {fact*cos(4. * M_PI / 3.), fact*sin(4 * M_PI / 3.)};
      }
      else {
        auto it2 = perfectShapes.find(e);
        if(it2 != perfectShapes.end())
          vs = it2->second;
        else
          Msg::Error("Argh");
      }
      sh.push_back({vs[0], vs[1], vs[2]});
    }
    else {
      if(it != layers.end()) {
        double thickness = it->second;
        /*
        (0,thickness)  (dx,thickness)
        +-------------+
        |             |
        +-------------+
        (0,0)     (dx,0)
      */
        double dx = sqrt((vs[0][0] - vs[1][0]) * (vs[0][0] - vs[1][0]) +
                         (vs[0][1] - vs[1][1]) * (vs[0][1] - vs[1][1]));
        std::array<double, 2> p0 = {0, 0};
        std::array<double, 2> p1 = {dx, 0};
        std::array<double, 2> p2 = {dx, thickness};
        std::array<double, 2> p3 = {0, thickness};
        //	printf("thickness = %12.5E\n",thickness);
        sh.push_back({p0, p1, p2});
        sh.push_back({p2, p3, p0});
        sh.push_back({p0, p1, p3});
        sh.push_back({p1, p2, p3});
      }
      else {
        auto it2 = perfectShapes.find(e);
        if(it2 != perfectShapes.end())
          vs = it2->second;
        else
          Msg::Error("Argh");
        sh.push_back({vs[0], vs[1], vs[2]});
        sh.push_back({vs[2], vs[3], vs[0]});
        sh.push_back({vs[0], vs[1], vs[3]});
        sh.push_back({vs[1], vs[2], vs[3]});
      }
    }
  }

  std::vector<std::array<double, 2>> points;
  std::vector<std::array<uint32_t, 3>> triangles;
  std::vector<bool> locked;
  std::set<MVertex *> verts;

  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    for(size_t j = 0; j < e->getNumVertices(); j++)
      verts.insert(e->getVertex(j));
  }
  int index = 0;
  for(auto v : verts) {
    v->setIndex(index++);
    locked.push_back(v->onWhat()->dim() == 2 ? false : true);
    SPoint2 param;
    reparamMeshVertexOnFace(v, gf, param);
    points.push_back({param.x(), param.y()});
  }
  // int tricount = 0;
  for(std::size_t i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *e = gf->getMeshElement(i);
    if(e->getNumVertices() == 3) {
      //      if (areas[tricount] > 0)
      triangles.push_back({(uint32_t)e->getVertex(0)->getIndex(),
                           (uint32_t)e->getVertex(1)->getIndex(),
                           (uint32_t)e->getVertex(2)->getIndex()});
      //      else
      //	triangles.push_back({(uint32_t)e->getVertex(0)->getIndex(),
      //	      (uint32_t)e->getVertex(2)->getIndex(),
      //	      (uint32_t)e->getVertex(1)->getIndex()});
      //      tricount++;
    }
    else {
      triangles.push_back({(uint32_t)e->getVertex(0)->getIndex(),
                           (uint32_t)e->getVertex(1)->getIndex(),
                           (uint32_t)e->getVertex(2)->getIndex()});
      triangles.push_back({(uint32_t)e->getVertex(2)->getIndex(),
                           (uint32_t)e->getVertex(3)->getIndex(),
                           (uint32_t)e->getVertex(0)->getIndex()});
      triangles.push_back({(uint32_t)e->getVertex(0)->getIndex(),
                           (uint32_t)e->getVertex(1)->getIndex(),
                           (uint32_t)e->getVertex(3)->getIndex()});
      triangles.push_back({(uint32_t)e->getVertex(1)->getIndex(),
                           (uint32_t)e->getVertex(2)->getIndex(),
                           (uint32_t)e->getVertex(3)->getIndex()});
    }
  }
  untangle_triangles_2D(points, locked, triangles, sh, 1.e+0);

  for(auto v : verts) {
    int i = v->getIndex();
    if(!locked[i]) {
      GPoint gp = gf->point(points[i][0], points[i][1]);
      v->x() = gp.x();
      v->y() = gp.y();
      v->z() = gp.z();
      v->setParameter(0, gp.u());
      v->setParameter(1, gp.v());
    }
  }
}

static std::vector<MVertex *>
splitedge(MEdge me,
          std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> &split,
          std::vector<double> &t)
{
  auto it = split.find(me);
  if(it != split.end()) return it->second;

  std::vector<MVertex *> vs;
  vs.push_back(me.getVertex(0));
  if(me.getVertex(1)->onWhat()->dim() == 2) {
    SPoint2 p0, p1;
    GFace *gf = static_cast<GFace *>(me.getVertex(1)->onWhat());
    reparamMeshVertexOnFace(me.getVertex(0), gf, p0);
    reparamMeshVertexOnFace(me.getVertex(1), gf, p1);
    for(size_t i = 0; i < t.size() - 1; i++) {
      SPoint2 p = p0 + (p1 - p0) * t[i];
      GPoint gp = gf->point(p.x(), p.y());
      vs.push_back(new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, p.x(), p.y()));
      gf->mesh_vertices.push_back(vs.back());
    }
  }
  else if(me.getVertex(1)->onWhat()->dim() == 1) {
    double p0, p1;
    GEdge *ge = static_cast<GEdge *>(me.getVertex(1)->onWhat());
    reparamMeshVertexOnEdge(me.getVertex(0), ge, p0);
    reparamMeshVertexOnEdge(me.getVertex(1), ge, p1);
    for(size_t i = 0; i < t.size() - 1; i++) {
      double p = p0 + t[i] * (p1 - p0);
      GPoint gp = ge->point(p);
      vs.push_back(new MEdgeVertex(gp.x(), gp.y(), gp.z(), ge, p));
      ge->mesh_vertices.push_back(vs.back());
    }
  }
  vs.push_back(me.getVertex(1));
  split[me] = vs;
  return vs;
}

void splitounette(std::vector<GFace *> &f, std::map<MElement *, double> &layers,
                  std::vector<double> &widths)
{
  std::map<MEdge, std::vector<MVertex *>, MEdgeLessThan> split;
  std::vector<double> t;
  double tot = 0.0;
  for(auto w : widths) tot += w;

  double wloc = 0.0;
  for(auto w : widths) {
    wloc += w;
    t.push_back(wloc / tot);
  }

  //  for (auto w : widths) printf("%12.5E\n",w);
  //  for (auto x : t) printf("%12.5E\n",x);

  for(auto gf : f) {
    std::vector<MElement *> temp;
    for(size_t i = 0; i < gf->getNumMeshElements(); i++)
      temp.push_back(gf->getMeshElement(i));
    for(size_t i = 0; i < temp.size(); i++) {
      if(layers.find(temp[i]) != layers.end()) {
        if(temp[i]->getNumEdges() == 3) {
          //	  printf("FAN %d %d
          //%d\n",temp[i]->getVertex(0)->getNum(),temp[i]->getVertex(1)->getNum(),temp[i]->getVertex(2)->getNum());
          MEdge m01 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(1));
          MEdge m02 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(2));
          std::vector<MVertex *> p01 = splitedge(m01, split, t);
          std::vector<MVertex *> p02 = splitedge(m02, split, t);
          temp[i]->setVertex(1, p01[1]);
          temp[i]->setVertex(2, p02[1]);
          layers[temp[i]] = widths[0];
          for(size_t j = 1; j < p01.size() - 1; j++) {
            MVertex *v0 = p01[j];
            MVertex *v1 = p01[j + 1];
            MVertex *v2 = p02[j + 1];
            MVertex *v3 = p02[j];
            MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
            gf->quadrangles.push_back(q);
            layers[q] = widths[j];
          }
        }
        else if(temp[i]->getNumEdges() == 4) {
          MEdge m03 = MEdge(temp[i]->getVertex(0), temp[i]->getVertex(3));
          MEdge m12 = MEdge(temp[i]->getVertex(1), temp[i]->getVertex(2));
          std::vector<MVertex *> p03 = splitedge(m03, split, t);
          std::vector<MVertex *> p12 = splitedge(m12, split, t);
          for(size_t j = 0; j < p03.size() - 1; j++) {
            MVertex *v0 = p03[j];
            MVertex *v1 = p12[j];
            MVertex *v2 = p12[j + 1];
            MVertex *v3 = p03[j + 1];
            if(j == 0) {
              temp[i]->setVertex(0, v0);
              temp[i]->setVertex(1, v1);
              temp[i]->setVertex(2, v2);
              temp[i]->setVertex(3, v3);
              layers[temp[i]] = widths[j];
            }
            else {
              MQuadrangle *q = new MQuadrangle(v0, v1, v2, v3);
              gf->quadrangles.push_back(q);
              layers[q] = widths[j];
            }
          }
        }
      }
    }
    auto edges = gf->edges();
    for(auto ge : edges) {
      MLine *l0 = ge->lines.front();
      MLine *l1 = ge->lines.back();
      MEdge m0 = MEdge(l0->getVertex(0), l0->getVertex(1));
      MEdge m1 = MEdge(l1->getVertex(0), l1->getVertex(1));
      auto it0 = split.find(m0);
      auto it1 = split.find(m1);

      if(it0 != split.end()) {
        //	printf("coucou %d
        //%d\n",ge->tag(),l0->getVertex(0)->onWhat()->dim());
        std::vector<MLine *> old = ge->lines;
        ge->lines.clear();
        for(size_t j = 0; j < it0->second.size() - 1; j++)
          ge->lines.push_back(new MLine(it0->second[j], it0->second[j + 1]));
        for(size_t j = 1; j < old.size(); j++) ge->lines.push_back(old[j]);
        delete old.front();
      }
      if(it1 != split.end()) {
        //	printf("poucou %d
        //%d\n",ge->tag(),l1->getVertex(0)->onWhat()->dim());
        size_t s = it1->second.size();
        ge->lines.back()->setVertex(0, it1->second[s - 2]);
        for(size_t j = 2; j < s; j++)
          ge->lines.push_back(
            new MLine(it1->second[s - j], it1->second[s - j - 1]));
      }
    }
  }
}

std::string GMSH_BoundaryLayerPlugin::parse(std::string str,
                                            std::list<int> &physical)
{
  // Remove spaces
  str.erase(remove(str.begin(), str.end(), ' '), str.end());

  // Replace commas by spaces
  replace(str.begin(), str.end(), ',', ' ');

  // Init string stream
  std::stringstream stream;
  stream << str;

  // Parse stream for integers
  int tag;
  std::string tmp;
  while(!stream.eof()) {
    stream >> tmp; // Take next 'word'
    if(sscanf(tmp.c_str(), "%d", &tag) > 0) physical.push_back(tag);
  }

  // Return modified string
  return str;
}

PView *GMSH_BoundaryLayerPlugin::execute(PView *v)
{
  GModel *m = GModel::current();

  std::string volume = BoundaryLayerOptions_String[0].def;
  std::string surface = BoundaryLayerOptions_String[1].def;
  std::string curve = BoundaryLayerOptions_String[2].def;
  std::string point = BoundaryLayerOptions_String[3].def;

  std::vector<std::list<int>> entities(4);
  point = parse(point, entities[0]);
  curve = parse(curve, entities[1]);
  surface = parse(surface, entities[2]);
  volume = parse(volume, entities[3]);

  std::vector<GVertex *> vv;
  for(auto v : entities[0]) {
    GVertex *gv = m->getVertexByTag(v);
    if(gv) vv.push_back(gv);
  }
  std::vector<GEdge *> e;
  for(auto c : entities[1]) {
    GEdge *ge = m->getEdgeByTag(c);
    if(ge) e.push_back(ge);
  }
  std::vector<GFace *> f;
  for(auto s : entities[2]) {
    GFace *gf = m->getFaceByTag(s);
    if(gf) f.push_back(gf);
  }
  std::vector<GRegion *> r;
  for(auto e : entities[3]) {
    GRegion *gr = m->getRegionByTag(e);
    if(gr) r.push_back(gr);
  }

  double thickness = BoundaryLayerOptions_Number[0].def;
  double size = BoundaryLayerOptions_Number[1].def;
  double ratio = BoundaryLayerOptions_Number[2].def;

  std::map<MElement *, std::array<std::array<double, 2>, 4>> perfectShapes;

  {
    for(auto gf : f) {
      //      std::map<MVertex*,SPoint2> ivp;
      for(size_t i = 0; i < gf->getNumMeshElements(); i++) {
        std::vector<SPoint2> pts;
        for(size_t j = 0; j < gf->getMeshElement(i)->getNumVertices(); j++) {
          SPoint2 param;
          reparamMeshVertexOnFace(gf->getMeshElement(i)->getVertex(j), gf,
                                  param);
          pts.push_back(param);
        }
        if(pts.size() == 3) {
          std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
          std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
          std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
          double a = triangle_area_2d(vs0, vs1, vs2);
          if(a > 0)
            perfectShapes[gf->getMeshElement(i)] = {vs0, vs1, vs2, vs2};
          else
            perfectShapes[gf->getMeshElement(i)] = {vs0, vs2, vs1, vs1};
        }
        else {
          std::array<double, 2> vs0 = {pts[0].x(), pts[0].y()};
          std::array<double, 2> vs1 = {pts[1].x(), pts[1].y()};
          std::array<double, 2> vs2 = {pts[2].x(), pts[2].y()};
          std::array<double, 2> vs3 = {pts[3].x(), pts[3].y()};
          double a = triangle_area_2d(vs0, vs1, vs2);
          if(a > 0)
            perfectShapes[gf->getMeshElement(i)] = {vs0, vs1, vs2, vs3};
          else
            perfectShapes[gf->getMeshElement(i)] = {vs3, vs2, vs1, vs0};
        }
      }
    }
  }

  std::map<MElement *, double> layers;

  //  printf("perfectshapes = %lu\n",perfectShapes.size());


  double ww = 0.0;
  std::vector<double> ws;
  double hwall = size;
  while(1) {
    ws.push_back(hwall);
    ww += hwall;
    if(ww + hwall >= thickness) break;
    hwall *= ratio;
  }

  //  printf("ww = %12.5E\n",ww);
  //  double h = 0.;
  //  for (auto wid  : ws){
  //    h += wid;
  //    printf("h = %g y = %g\n",wid,h);
  //  }
  bl(m, vv, e, f, r, ww, layers);

  for(GModel::eiter eit = m->firstEdge(); eit != m->lastEdge(); ++eit)
    meshGEdgeInsertBoundaryLayer(*eit, ww);

  for(auto gf : f) expandBL(gf, perfectShapes, layers, f);

  if (ws.size() > 1)
    splitounette(f, layers, ws);

  //  for (auto gf : f)
  //    expandBL(gf, perfectShapes, layers, f);

  CTX::instance()->mesh.changed = ENT_ALL;

  return v;
}
