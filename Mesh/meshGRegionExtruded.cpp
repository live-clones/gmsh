// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "ExtrudeParams.h"
#include "meshGFace.h"
#include "meshGRegion.h"
#include "Context.h"
#include "MVertexRTree.h"

#if defined(HAVE_QUADTRI)
#include "QuadTriExtruded3D.h"
#endif

static void addTetrahedron(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                           GRegion *to)
{
  to->tetrahedra.push_back(new MTetrahedron(v1, v2, v3, v4));
}

static void addPyramid(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                       MVertex *v5, GRegion *to)
{
  to->pyramids.push_back(new MPyramid(v1, v2, v3, v4, v5));
}

static void addPrism(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                     MVertex *v5, MVertex *v6, GRegion *to)
{
  to->prisms.push_back(new MPrism(v1, v2, v3, v4, v5, v6));
}

static void addHexahedron(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                          MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8,
                          GRegion *to)
{
  to->hexahedra.push_back(new MHexahedron(v1, v2, v3, v4, v5, v6, v7, v8));
}

static void createPriPyrTet(std::vector<MVertex *> &v, GRegion *to,
                            MElement *source)
{
  static int warningReg = 0;

  int dup[3];
  int j = 0;
  for(int i = 0; i < 3; i++)
    if(v[i] == v[i + 3]) dup[j++] = i;

  if(j == 2) {
    if(dup[0] == 0 && dup[1] == 1)
      addTetrahedron(v[0], v[1], v[2], v[5], to);
    else if(dup[0] == 1 && dup[1] == 2)
      addTetrahedron(v[0], v[1], v[2], v[3], to);
    else
      addTetrahedron(v[0], v[1], v[2], v[4], to);
  }
  else if(j == 1) {
    if(dup[0] == 0)
      addPyramid(v[1], v[4], v[5], v[2], v[0], to);
    else if(dup[0] == 1)
      addPyramid(v[0], v[2], v[5], v[3], v[1], to);
    else
      addPyramid(v[0], v[1], v[4], v[3], v[2], to);
  }
  else {
    addPrism(v[0], v[1], v[2], v[3], v[4], v[5], to);
    if(j && warningReg != to->tag()) {
      warningReg = to->tag();
      Msg::Warning("Degenerated prism in extrusion of volume %d", to->tag());
    }
  }
}

static void createHexPri(std::vector<MVertex *> &v, GRegion *to,
                         MElement *source)
{
  static int errorReg = 0;
  static int warningReg = 0;

  int dup[4];
  int j = 0;
  for(int i = 0; i < 4; i++)
    if(v[i] == v[i + 4]) dup[j++] = i;

  if(j == 2) {
    if(dup[0] == 0 && dup[1] == 1)
      addPrism(v[0], v[3], v[7], v[1], v[2], v[6], to);
    else if(dup[0] == 1 && dup[1] == 2)
      addPrism(v[0], v[1], v[4], v[3], v[2], v[7], to);
    else if(dup[0] == 2 && dup[1] == 3)
      addPrism(v[0], v[3], v[4], v[1], v[2], v[5], to);
    else if(dup[0] == 0 && dup[1] == 3)
      addPrism(v[0], v[1], v[5], v[3], v[2], v[6], to);
    else if(to->tag() != errorReg) {
      errorReg = to->tag();
      Msg::Error("Wrong hexahedron in extrusion of volume %d", to->tag());
    }
  }
  else {
    addHexahedron(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], to);
    if(j && warningReg != to->tag()) {
      warningReg = to->tag();
      Msg::Warning("Degenerated hexahedron in extrusion of volume %d",
                   to->tag());
    }
  }
}

static void createTet(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                      GRegion *to, MElement *source)
{
  if(v1 != v2 && v1 != v3 && v1 != v4 && v2 != v3 && v2 != v4 && v3 != v4)
    addTetrahedron(v1, v2, v3, v4, to);
}

static int getExtrudedVertices(MElement *ele, ExtrudeParams *ep, int j, int k,
                               MVertexRTree &pos, std::vector<MVertex *> &verts)
{
  double x[8], y[8], z[8];
  int n = ele->getNumVertices();
  for(int p = 0; p < n; p++) {
    MVertex *v = ele->getVertex(p);
    x[p] = x[p + n] = v->x();
    y[p] = y[p + n] = v->y();
    z[p] = z[p + n] = v->z();
  }
  for(int p = 0; p < n; p++) {
    ep->Extrude(j, k, x[p], y[p], z[p]);
    ep->Extrude(j, k + 1, x[p + n], y[p + n], z[p + n]);
  }
  for(int p = 0; p < 2 * n; p++) {
    MVertex *tmp = pos.find(x[p], y[p], z[p]);
    if(!tmp)
      Msg::Error("Could not find extruded vertex (%.16g, %.16g, %.16g)", x[p],
                 y[p], z[p]);
    else
      verts.push_back(tmp);
  }
  return verts.size();
}

static void extrudeMesh(GFace *from, GRegion *to, MVertexRTree &pos)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  // interior vertices
  std::vector<MVertex *> mesh_vertices = from->mesh_vertices;

  // add all embedded vertices
  std::vector<MVertex *> embedded = from->getEmbeddedMeshVertices();
  mesh_vertices.insert(mesh_vertices.end(), embedded.begin(), embedded.end());

  // add all vertices on surface seams
  std::set<MVertex *> seam;
  std::vector<GEdge *> const &l_edges = from->edges();
  for(auto it = l_edges.begin(); it != l_edges.end(); ++it) {
    if((*it)->isSeam(from)) {
      seam.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
      if((*it)->getBeginVertex())
        seam.insert((*it)->getBeginVertex()->mesh_vertices.begin(),
                    (*it)->getBeginVertex()->mesh_vertices.end());
      if((*it)->getEndVertex())
        seam.insert((*it)->getEndVertex()->mesh_vertices.begin(),
                    (*it)->getEndVertex()->mesh_vertices.end());
    }
  }
  mesh_vertices.insert(mesh_vertices.end(), seam.begin(), seam.end());

  // create extruded vertices
  for(std::size_t i = 0; i < mesh_vertices.size(); i++) {
    MVertex *v = mesh_vertices[i];
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
        double x = v->x(), y = v->y(), z = v->z();
        ep->Extrude(j, k + 1, x, y, z);
        if(j != ep->mesh.NbLayer - 1 || k != ep->mesh.NbElmLayer[j] - 1) {
          if(!pos.find(x, y, z)) {
            MVertex *newv = new MVertex(x, y, z, to);
            to->mesh_vertices.push_back(newv);
            pos.insert(newv);
          }
        }
      }
    }
  }

#if defined(HAVE_QUADTRI)
  if(ep && ep->mesh.ExtrudeMesh && ep->mesh.QuadToTri && ep->mesh.Recombine) {
    meshQuadToTriRegion(to, pos);
    return;
  }
#endif

  // create elements (note that it would be faster to access the *interior*
  // nodes by direct indexing, but it's just simpler to query everything by
  // position)
  for(std::size_t i = 0; i < from->triangles.size(); i++) {
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
        std::vector<MVertex *> verts;
        if(getExtrudedVertices(from->triangles[i], ep, j, k, pos, verts) == 6) {
          createPriPyrTet(verts, to, from->triangles[i]);
        }
      }
    }
  }

  if(from->quadrangles.size() && !ep->mesh.Recombine) {
    Msg::Error("Cannot extrude quadrangles without Recombine");
  }
  else {
    for(std::size_t i = 0; i < from->quadrangles.size(); i++) {
      for(int j = 0; j < ep->mesh.NbLayer; j++) {
        for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
          std::vector<MVertex *> verts;
          if(getExtrudedVertices(from->quadrangles[i], ep, j, k, pos, verts) ==
             8)
            createHexPri(verts, to, from->quadrangles[i]);
        }
      }
    }
  }
}

static void insertAllVertices(GRegion *gr, MVertexRTree &pos)
{
  pos.insert(gr->mesh_vertices);
  std::vector<MVertex *> embedded = gr->getEmbeddedMeshVertices();
  pos.insert(embedded);
  std::vector<GFace *> faces = gr->faces();
  for(auto itf = faces.begin(); itf != faces.end(); itf++) {
    pos.insert((*itf)->mesh_vertices);
    std::vector<MVertex *> embedded = (*itf)->getEmbeddedMeshVertices();
    pos.insert(embedded);
    std::vector<GEdge *> const &edges = (*itf)->edges();
    for(auto ite = edges.begin(); ite != edges.end(); ite++) {
      pos.insert((*ite)->mesh_vertices);
      if((*ite)->getBeginVertex())
        pos.insert((*ite)->getBeginVertex()->mesh_vertices);
      if((*ite)->getEndVertex())
        pos.insert((*ite)->getEndVertex()->mesh_vertices);
    }
  }
}

void meshGRegionExtruded::operator()(GRegion *gr)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(gr->geomType() == GEntity::DiscreteVolume) return;

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh || ep->geo.Mode != EXTRUDED_ENTITY) return;

  Msg::Info("Meshing volume %d (Extruded)", gr->tag());

  // destroy the mesh if it exists
  deMeshGRegion dem;
  dem(gr);

  // build an rtree with all the vertices on the boundary of gr
  MVertexRTree pos(CTX::instance()->geom.tolerance * CTX::instance()->lc);
  insertAllVertices(gr, pos);

  // volume is extruded from a surface
  GFace *from = gr->model()->getFaceByTag(std::abs(ep->geo.Source));
  if(!from) {
    Msg::Error("Unknown source surface %d for extrusion", ep->geo.Source);
    return;
  }

  extrudeMesh(from, gr, pos);

  // carve holes if any (only do it now if the mesh is final, i.e., if
  // the mesh is recombined)
  if(ep->mesh.Holes.size() && ep->mesh.Recombine) {
    for(auto it = ep->mesh.Holes.begin(); it != ep->mesh.Holes.end(); it++)
      carveHole(gr, it->first, it->second.first, it->second.second);
  }
}

static int edgeExists(MVertex *v1, MVertex *v2,
                      std::set<std::pair<MVertex *, MVertex *> > &edges)
{
  std::pair<MVertex *, MVertex *> p(std::min(v1, v2), std::max(v1, v2));
  return edges.count(p);
}

static void createEdge(MVertex *v1, MVertex *v2,
                       std::set<std::pair<MVertex *, MVertex *> > &edges)
{
  std::pair<MVertex *, MVertex *> p(std::min(v1, v2), std::max(v1, v2));
  edges.insert(p);
}

static void deleteEdge(MVertex *v1, MVertex *v2,
                       std::set<std::pair<MVertex *, MVertex *> > &edges)
{
  std::pair<MVertex *, MVertex *> p(std::min(v1, v2), std::max(v1, v2));
  edges.erase(p);
}

// subdivide the 3 lateral faces of each prism
static void phase1(GRegion *gr, MVertexRTree &pos,
                   std::set<std::pair<MVertex *, MVertex *> > &edges, int ntry)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  GFace *from = gr->model()->getFaceByTag(std::abs(ep->geo.Source));
  if(!from) return;

  for(std::size_t i = 0; i < from->triangles.size(); i++) {
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
        std::vector<MVertex *> v;
        if(getExtrudedVertices(from->triangles[i], ep, j, k, pos, v) == 6) {
          if(ntry == 1) {
            if(!edgeExists(v[0], v[4], edges)) createEdge(v[1], v[3], edges);
            if(!edgeExists(v[4], v[2], edges)) createEdge(v[1], v[5], edges);
            if(!edgeExists(v[3], v[2], edges)) createEdge(v[0], v[5], edges);
          }
          else { // from Michel Benhamou
            if(v[1]->getNum() < v[0]->getNum())
              createEdge(v[1], v[3], edges);
            else
              createEdge(v[0], v[4], edges);
            if(v[1]->getNum() < v[2]->getNum())
              createEdge(v[1], v[5], edges);
            else
              createEdge(v[4], v[2], edges);
            if(v[0]->getNum() < v[2]->getNum())
              createEdge(v[0], v[5], edges);
            else
              createEdge(v[3], v[2], edges);
          }
        }
      }
    }
  }
}

// modify lateral edges to make them "tet-compatible"
static void phase2(GRegion *gr, MVertexRTree &pos,
                   std::set<std::pair<MVertex *, MVertex *> > &edges,
                   std::set<std::pair<MVertex *, MVertex *> > &edges_swap,
                   int &swap)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  GFace *from = gr->model()->getFaceByTag(std::abs(ep->geo.Source));
  if(!from) return;

  for(std::size_t i = 0; i < from->triangles.size(); i++) {
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
        std::vector<MVertex *> v;
        if(getExtrudedVertices(from->triangles[i], ep, j, k, pos, v) == 6) {
          if(edgeExists(v[3], v[1], edges) && edgeExists(v[4], v[2], edges) &&
             edgeExists(v[0], v[5], edges)) {
            swap++;
            if(!edgeExists(v[3], v[1], edges_swap)) {
              deleteEdge(v[3], v[1], edges);
              createEdge(v[0], v[4], edges);
              createEdge(v[3], v[1], edges_swap);
              createEdge(v[0], v[4], edges_swap);
            }
            else if(!edgeExists(v[4], v[2], edges_swap)) {
              deleteEdge(v[4], v[2], edges);
              createEdge(v[1], v[5], edges);
              createEdge(v[4], v[2], edges_swap);
              createEdge(v[1], v[5], edges_swap);
            }
            else if(!edgeExists(v[0], v[5], edges_swap)) {
              deleteEdge(v[0], v[5], edges);
              createEdge(v[3], v[2], edges);
              createEdge(v[0], v[5], edges_swap);
              createEdge(v[3], v[2], edges_swap);
            }
          }
          else if(edgeExists(v[0], v[4], edges) &&
                  edgeExists(v[1], v[5], edges) &&
                  edgeExists(v[3], v[2], edges)) {
            swap++;
            if(!edgeExists(v[0], v[4], edges_swap)) {
              deleteEdge(v[0], v[4], edges);
              createEdge(v[3], v[1], edges);
              createEdge(v[0], v[4], edges_swap);
              createEdge(v[3], v[1], edges_swap);
            }
            else if(!edgeExists(v[1], v[5], edges_swap)) {
              deleteEdge(v[1], v[5], edges);
              createEdge(v[4], v[2], edges);
              createEdge(v[1], v[5], edges_swap);
              createEdge(v[4], v[2], edges_swap);
            }
            else if(!edgeExists(v[3], v[2], edges_swap)) {
              deleteEdge(v[3], v[2], edges);
              createEdge(v[0], v[5], edges);
              createEdge(v[3], v[2], edges_swap);
              createEdge(v[0], v[5], edges_swap);
            }
          }
        }
      }
    }
  }
}

// create tets
static void phase3(GRegion *gr, MVertexRTree &pos,
                   std::set<std::pair<MVertex *, MVertex *> > &edges)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  GFace *from = gr->model()->getFaceByTag(std::abs(ep->geo.Source));
  if(!from) return;

  for(std::size_t i = 0; i < from->triangles.size(); i++) {
    MTriangle *tri = from->triangles[i];
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
        std::vector<MVertex *> v;
        if(getExtrudedVertices(tri, ep, j, k, pos, v) == 6) {
          if(edgeExists(v[3], v[1], edges) && edgeExists(v[4], v[2], edges) &&
             edgeExists(v[3], v[2], edges)) {
            createTet(v[0], v[1], v[2], v[3], gr, tri);
            createTet(v[3], v[4], v[5], v[2], gr, tri);
            createTet(v[1], v[3], v[4], v[2], gr, tri);
          }
          else if(edgeExists(v[3], v[1], edges) &&
                  edgeExists(v[1], v[5], edges) &&
                  edgeExists(v[3], v[2], edges)) {
            createTet(v[0], v[1], v[2], v[3], gr, tri);
            createTet(v[3], v[4], v[5], v[1], gr, tri);
            createTet(v[3], v[1], v[5], v[2], gr, tri);
          }
          else if(edgeExists(v[3], v[1], edges) &&
                  edgeExists(v[1], v[5], edges) &&
                  edgeExists(v[5], v[0], edges)) {
            createTet(v[0], v[1], v[2], v[5], gr, tri);
            createTet(v[3], v[4], v[5], v[1], gr, tri);
            createTet(v[1], v[3], v[5], v[0], gr, tri);
          }
          else if(edgeExists(v[4], v[0], edges) &&
                  edgeExists(v[4], v[2], edges) &&
                  edgeExists(v[3], v[2], edges)) {
            createTet(v[0], v[1], v[2], v[4], gr, tri);
            createTet(v[3], v[4], v[5], v[2], gr, tri);
            createTet(v[0], v[3], v[4], v[2], gr, tri);
          }
          else if(edgeExists(v[4], v[0], edges) &&
                  edgeExists(v[4], v[2], edges) &&
                  edgeExists(v[5], v[0], edges)) {
            createTet(v[0], v[1], v[2], v[4], gr, tri);
            createTet(v[3], v[4], v[5], v[0], gr, tri);
            createTet(v[0], v[2], v[4], v[5], gr, tri);
          }
          else if(edgeExists(v[4], v[0], edges) &&
                  edgeExists(v[1], v[5], edges) &&
                  edgeExists(v[5], v[0], edges)) {
            createTet(v[0], v[1], v[2], v[5], gr, tri);
            createTet(v[3], v[4], v[5], v[0], gr, tri);
            createTet(v[0], v[1], v[4], v[5], gr, tri);
          }
        }
      }
    }
  }
}

int SubdivideExtrudedMesh(GModel *m)
{
  // get all non-recombined extruded regions and vertices; also, create a vector
  // of quadToTri regions that have NOT been meshed yet
  std::vector<GRegion *> regions;
#if defined(HAVE_QUADTRI)
  std::vector<GRegion *> regions_quadToTri;
#endif

  MVertexRTree pos(CTX::instance()->geom.tolerance * CTX::instance()->lc);
  for(auto it = m->firstRegion(); it != m->lastRegion(); it++) {
    ExtrudeParams *ep = (*it)->meshAttributes.extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY &&
       !ep->mesh.Recombine) {
      regions.push_back(*it);
      insertAllVertices(*it, pos);
    }
#if defined(HAVE_QUADTRI)
    // create vector of valid quadToTri regions...not all will necessarily be
    // meshed here.
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY &&
       ep->mesh.Recombine && ep->mesh.QuadToTri) {
      regions_quadToTri.push_back(*it);
    }
#endif
  }

  if(regions.empty()) return 0;

  Msg::Info("Subdividing extruded mesh");

  std::set<std::pair<MVertex *, MVertex *> > edges;

  for(int ntry = 1; ntry <= 2; ntry++) {
    // create edges on lateral sides of "prisms"
    for(std::size_t i = 0; i < regions.size(); i++)
      phase1(regions[i], pos, edges, ntry);
    // swap lateral edges to make them "tet-compatible"
    int j = 0, swap;
    std::set<std::pair<MVertex *, MVertex *> > edges_swap;
    do {
      swap = 0;
      for(std::size_t i = 0; i < regions.size(); i++)
        phase2(regions[i], pos, edges, edges_swap, swap);
      Msg::Info("Swapping %d", swap);
      if(j && j == swap) {
        if(ntry == 1) {
          Msg::Info("Subdivision failed, trying alternative split");
          edges.clear();
          break;
        }
        else {
          Msg::Error(
            "Unable to subdivide extruded mesh: change surface mesh or "
            "recombine extrusion instead");
          return -1;
        }
      }
      j = swap;
    } while(swap);
    if(!swap) break;
  }

  // delete volume elements and create tetrahedra instead
  for(std::size_t i = 0; i < regions.size(); i++) {
    GRegion *gr = regions[i];
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++)
      delete gr->tetrahedra[i];
    gr->tetrahedra.clear();
    for(std::size_t i = 0; i < gr->hexahedra.size(); i++)
      delete gr->hexahedra[i];
    gr->hexahedra.clear();
    for(std::size_t i = 0; i < gr->prisms.size(); i++) delete gr->prisms[i];
    gr->prisms.clear();
    for(std::size_t i = 0; i < gr->pyramids.size(); i++) delete gr->pyramids[i];
    gr->pyramids.clear();
    phase3(gr, pos, edges);
  }

  // remesh bounding surfaces, to make them compatible with the volume mesh
  std::set<GFace *> faces;
  for(std::size_t i = 0; i < regions.size(); i++) {
    GRegion *gr = regions[i];
    std::vector<GFace *> f = gr->faces();
    for(std::size_t i = 0; i < f.size(); i++) {
      ExtrudeParams *ep = f[i]->meshAttributes.extrude;
      // TODO: this does not yet handle swapping of edges in COPIED_ENTITY
      // surfaces, whose mesh is copied during extrusion (the "top"
      // surface). PS: we will need to distinguish the old boundary layer case
      // if we include these "copied" meshes
      if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY &&
         !ep->mesh.Recombine) {
        f[i]->meshStatistics.status = GFace::PENDING;
        faces.insert(f[i]);
      }
    }
  }
  int nIter = 0;
  while(1) {
    int nPending = 0;
    for(auto it = faces.begin(); it != faces.end(); it++) {
      GFace *gf = *it;
      if(gf->meshStatistics.status == GFace::PENDING) {
        Msg::Info("Remeshing surface %d", gf->tag());
        for(std::size_t i = 0; i < gf->triangles.size(); i++)
          delete gf->triangles[i];
        gf->triangles.clear();
        for(std::size_t i = 0; i < gf->quadrangles.size(); i++)
          delete gf->quadrangles[i];
        gf->quadrangles.clear();
        MeshExtrudedSurface(gf, &edges);
        nPending++;
      }
    }
    if(!nPending) break;
    if(nIter++ > 10) {
      Msg::Warning("Could not remesh all subdivided surfaces");
      break;
    }
  }

#if defined(HAVE_QUADTRI)
  // now mesh the QuadToTri regions. Everything can be done locally for each
  // quadToTri region, but still use edge set from above just to make sure
  // laterals get remeshed properly ( QuadToTriEdgeGenerator detects if the
  // neighbor has been meshed or if a lateral surface should remain static for
  // any other reason).  If this function detects allNonGlobalSharedLaterals, it
  // won't mesh the region (should already be done in ExtrudeMesh).
  for(std::size_t i = 0; i < regions_quadToTri.size(); i++) {
    GRegion *gr = regions_quadToTri[i];
    MVertexRTree pos_local(CTX::instance()->geom.tolerance *
                           CTX::instance()->lc);
    insertAllVertices(gr, pos_local);
    meshQuadToTriRegionAfterGlobalSubdivide(gr, &edges, pos_local);
  }
#endif

  // carve holes if any (TODO: update extrusion information)
  for(std::size_t i = 0; i < regions.size(); i++) {
    GRegion *gr = regions[i];
    ExtrudeParams *ep = gr->meshAttributes.extrude;
    if(ep->mesh.Holes.size()) {
      for(auto it = ep->mesh.Holes.begin(); it != ep->mesh.Holes.end(); it++)
        carveHole(gr, it->first, it->second.first, it->second.second);
    }
  }

#if defined(HAVE_QUADTRI)
  for(std::size_t i = 0; i < regions_quadToTri.size(); i++) {
    GRegion *gr = regions_quadToTri[i];
    ExtrudeParams *ep = gr->meshAttributes.extrude;
    if(ep->mesh.Holes.size()) {
      for(auto it = ep->mesh.Holes.begin(); it != ep->mesh.Holes.end(); it++)
        carveHole(gr, it->first, it->second.first, it->second.second);
    }
  }
#endif

  return 1;
}
