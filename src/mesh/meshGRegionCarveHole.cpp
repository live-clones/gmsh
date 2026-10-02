// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
#include "SPoint3KDTree.h"

template <class T>
void carveHole(std::vector<T *> &elements, double distance,
               const SPoint3Search &search)
{
  // delete all elements that have at least one vertex closer than
  // 'distance' from the carving surface vertices
  std::vector<T *> temp;
  for(std::size_t i = 0; i < elements.size(); i++) {
    for(std::size_t j = 0; j < elements[i]->getNumVertices(); j++) {
      double d2;
      search.nearest(elements[i]->getVertex(j)->point(), &d2);
      if(std::sqrt(d2) < distance) {
        delete elements[i];
        break;
      }
      else if(j == elements[i]->getNumVertices() - 1) {
        temp.push_back(elements[i]);
      }
    }
  }
  elements = temp;
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
  SPoint3Search search;
  for(std::size_t i = 0; i < surfaces.size(); i++) {
    GFace *gf = m->getFaceByTag(surfaces[i]);
    if(!gf) {
      Msg::Error("Unknown carving surface %d", surfaces[i]);
      return;
    }
    for(auto v : gf->mesh_vertices) search.points().push_back(v->point());
  }
  if(!search.size()) {
    Msg::Error("No nodes on carving surfaces");
    return;
  }
  search.build();

  // remove the volume elements that are within 'distance' of the
  // carved surface
  carveHole(gr->tetrahedra, distance, search);
  carveHole(gr->hexahedra, distance, search);
  carveHole(gr->prisms, distance, search);
  carveHole(gr->pyramids, distance, search);

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
