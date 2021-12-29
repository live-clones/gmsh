// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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

#if !defined(HAVE_ANN)

void carveHole(GRegion *gr, int num, double distance,
               std::vector<int> &surfaces)
{
  Msg::Error("Gmsh must be compiled with ANN support to carve holes in meshes");
}

#else

#include "ANN/ANN.h"

template <class T>
void carveHole(std::vector<T *> &elements, double distance, ANNkd_tree *kdtree)
{
  // delete all elements that have at least one vertex closer than
  // 'distance' from the carving surface vertices
  ANNidxArray index = new ANNidx[1];
  ANNdistArray dist = new ANNdist[1];
  std::vector<T *> temp;
  for(std::size_t i = 0; i < elements.size(); i++) {
    for(std::size_t j = 0; j < elements[i]->getNumVertices(); j++) {
      MVertex *v = elements[i]->getVertex(j);
      double xyz[3] = {v->x(), v->y(), v->z()};
      kdtree->annkSearch(xyz, 1, index, dist);
      double d = std::sqrt(dist[0]);
      if(d < distance) {
        delete elements[i];
        break;
      }
      else if(j == elements[i]->getNumVertices() - 1) {
        temp.push_back(elements[i]);
      }
    }
  }
  elements = temp;
  delete[] index;
  delete[] dist;
}

template <class T>
void addFaces(std::vector<T *> &elements, std::set<MFace, MFaceLessThan> &faces)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    for(int j = 0; j < elements[i]->getNumFaces(); j++) {
      MFace f = elements[i]->getFace(j);
      auto it = faces.find(f);
      if(it == faces.end())
        faces.insert(f);
      else
        faces.erase(it);
    }
  }
}

void carveHole(GRegion *gr, int num, double distance,
               std::vector<int> &surfaces)
{
  Msg::Info("Carving hole %d from surface %d at distance %g", num, surfaces[0],
            distance);
  GModel *m = gr->model();

  // add all points from carving surfaces into kdtree
  int numnodes = 0;
  for(std::size_t i = 0; i < surfaces.size(); i++) {
    GFace *gf = m->getFaceByTag(surfaces[i]);
    if(!gf) {
      Msg::Error("Unknown carving surface %d", surfaces[i]);
      return;
    }
    numnodes += gf->mesh_vertices.size();
  }

  ANNpointArray kdnodes = annAllocPts(numnodes, 3);
  int k = 0;
  for(std::size_t i = 0; i < surfaces.size(); i++) {
    GFace *gf = m->getFaceByTag(surfaces[i]);
    for(std::size_t j = 0; j < gf->mesh_vertices.size(); j++) {
      kdnodes[k][0] = gf->mesh_vertices[j]->x();
      kdnodes[k][1] = gf->mesh_vertices[j]->y();
      kdnodes[k][2] = gf->mesh_vertices[j]->z();
      k++;
    }
  }
  ANNkd_tree *kdtree = new ANNkd_tree(kdnodes, numnodes, 3);

  // remove the volume elements that are within 'distance' of the
  // carved surface
  carveHole(gr->tetrahedra, distance, kdtree);
  carveHole(gr->hexahedra, distance, kdtree);
  carveHole(gr->prisms, distance, kdtree);
  carveHole(gr->pyramids, distance, kdtree);

  delete kdtree;
  annDeallocPts(kdnodes);

  // TODO: remove any interior elements left inside the carved surface
  // (could shoot a line from each element's barycenter and count
  // intersections o see who's inside)

  // generate discrete boundary mesh of the carved hole
  GFace *gf = m->getFaceByTag(num);
  if(!gf) return;
  std::set<MFace, MFaceLessThan> faces;
  std::vector<GFace *> f = gr->faces();
  for(auto it = f.begin(); it != f.end(); it++) {
    addFaces((*it)->triangles, faces);
    addFaces((*it)->quadrangles, faces);
  }
  addFaces(gr->tetrahedra, faces);
  addFaces(gr->hexahedra, faces);
  addFaces(gr->prisms, faces);
  addFaces(gr->pyramids, faces);

  std::set<MVertex *> verts;
  for(auto it = faces.begin(); it != faces.end(); it++) {
    for(std::size_t i = 0; i < it->getNumVertices(); i++) {
      it->getVertex(i)->setEntity(gf);
      verts.insert(it->getVertex(i));
    }
    if(it->getNumVertices() == 3)
      gf->triangles.push_back(
        new MTriangle(it->getVertex(0), it->getVertex(1), it->getVertex(2)));
    else if(it->getNumVertices() == 4)
      gf->quadrangles.push_back(
        new MQuadrangle(it->getVertex(0), it->getVertex(1), it->getVertex(2),
                        it->getVertex(3)));
  }
}

#endif
