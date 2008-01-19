// $Id: meshGRegionCarveHole.cpp,v 1.2 2008-01-19 09:55:33 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <set>
#include "GModel.h"
#include "Message.h"

#if !defined(HAVE_ANN)

void carveHole(GRegion *gr, int num, double distance, std::vector<int> &surfaces)
{
  Msg(GERROR, "Gmsh must be compiled with ANN support to carve holes in meshes");
}

#else

#include "ANN/ANN.h"

template <class T>
void carveHole(std::vector<T*> &elements, double distance, ANNkd_tree *kdtree)
{
  // delete all elements that have at least one vertex closer than
  // 'distance' from the carving surface vertices
  ANNidxArray index = new ANNidx[1];
  ANNdistArray dist = new ANNdist[1];
  std::vector<T*> temp;
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumVertices(); j++){
      MVertex *v = elements[i]->getVertex(j);
      double xyz[3] = {v->x(), v->y(), v->z()};
      kdtree->annkSearch(xyz, 1, index, dist);
      double d = sqrt(dist[0]);
      if(d < distance){
	delete elements[i];
	break;
      }
      else if(j == elements[i]->getNumVertices() - 1){
        temp.push_back(elements[i]);
      }
    }
  }
  elements = temp;
  delete [] index;
  delete [] dist;
}

template <class T>
void addFaces(std::vector<T*> &elements, std::set<MFace, Less_Face> &faces)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumFaces(); j++){
      MFace f = elements[i]->getFace(j);
      std::set<MFace, Less_Face>::iterator it = faces.find(f);
      if(it == faces.end())
	faces.insert(f);
      else
	faces.erase(it);
    }
  }
}

void carveHole(GRegion *gr, int num, double distance, std::vector<int> &surfaces)
{
  Msg(INFO, "Carving hole %d from surface %d at distance %g", num, surfaces[0], distance);
  GModel *m = gr->model();

  // add all points from carving surfaces into kdtree
  int numnodes = 0;
  for(unsigned int i = 0; i < surfaces.size(); i++){
    GFace *gf = m->faceByTag(surfaces[i]);
    if(!gf){
      Msg(GERROR, "Unknown carving surface %d", surfaces[i]);
      return;
    }
    numnodes += gf->mesh_vertices.size();
  }

  ANNpointArray kdnodes = annAllocPts(numnodes, 4);
  int k = 0;
  for(unsigned int i = 0; i < surfaces.size(); i++){
    GFace *gf = m->faceByTag(surfaces[i]);
    for(unsigned int j = 0; j < gf->mesh_vertices.size(); j++){
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
  GFace *gf = m->faceByTag(num);
  if(!gf) return;
  std::set<MFace, Less_Face> faces;
  std::list<GFace*> f = gr->faces();
  for(std::list<GFace*>::iterator it = f.begin(); it != f.end(); it++){
    addFaces((*it)->triangles, faces);
    addFaces((*it)->quadrangles, faces);
  }
  addFaces(gr->tetrahedra, faces);
  addFaces(gr->hexahedra, faces);
  addFaces(gr->prisms, faces);
  addFaces(gr->pyramids, faces);

  std::set<MVertex*> verts;
  for(std::set<MFace, Less_Face>::iterator it = faces.begin(); it != faces.end(); it++){
    for(int i = 0; i < it->getNumVertices(); i++){
      it->getVertex(i)->setEntity(gf);
      verts.insert(it->getVertex(i));
    }
    if(it->getNumVertices() == 3)
      gf->triangles.push_back(new MTriangle(it->getVertex(0), it->getVertex(1),
					    it->getVertex(2)));
    else if(it->getNumVertices() == 4)
      gf->quadrangles.push_back(new MQuadrangle(it->getVertex(0), it->getVertex(1),
						it->getVertex(2), it->getVertex(3)));
  }
}

#endif
