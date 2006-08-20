// $Id: SecondOrder.cpp,v 1.40 2006-08-20 03:44:15 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MElement.h"
#include "Message.h"
#include "OS.h"

extern GModel *GMODEL;

// Creation of middle-edge vertices

MVertex *addEdgeVertex(GEdge *e, std::pair<MVertex*, MVertex*> &p, bool linear)
{
  MVertex *v0(p.first), *v1(p.second), *v;
  MEdge edge(v0, v1);

  if(linear){
    SPoint3 pc = edge.barycenter();
    v = new MVertex(pc.x(), pc.y(), pc.z(), e);
  }
  else{
    double u0 = 1e6, u1 = 1e6;
    Range<double> bounds = e->parBounds(0);
    if(e->getBeginVertex()->mesh_vertices.size() &&
       e->getBeginVertex()->mesh_vertices[0] == v0) 
      u0 = bounds.low();
    else if(e->getEndVertex()->mesh_vertices.size() &&
	    e->getEndVertex()->mesh_vertices[0] == v0) 
      u0 = bounds.high();
    else 
      v0->getParameter(0, u0);
    if(e->getBeginVertex()->mesh_vertices.size() &&
       e->getBeginVertex()->mesh_vertices[0] == v1) 
      u1 = bounds.low();
    else if(e->getEndVertex()->mesh_vertices.size() &&
	    e->getEndVertex()->mesh_vertices[0] == v1) 
      u1 = bounds.high();
    else 
      v1->getParameter(0, u1);

    printf("u12 = %g  %g\n", u0, u1);
    if(u0 < 1e6 && u1 < 1e6){
      double uc = 0.5 * (u0 + u1);
      GPoint pc = e->point(uc);
      v = new MEdgeVertex(pc.x(), pc.y(), pc.z(), e, uc);
    }
    else{
      SPoint3 pc = edge.barycenter();
      v = new MVertex(pc.x(), pc.y(), pc.z(), e);
    }
  }
  e->mesh_vertices.push_back(v);
  return v;
}  

MVertex *addEdgeVertex(GFace *f, std::pair<MVertex* , MVertex*> &p, bool linear)
{
  MVertex *v0(p.first), *v1(p.second), *v;
  MEdge edge(v0, v1);

  if(linear){
    SPoint3 pc = edge.barycenter();
    v = new MVertex(pc.x(), pc.y(), pc.z(), f);
  }
  else{
    SPoint2 p1 = f->parFromPoint(SPoint3(v0->x(), v0->y(), v0->z()));
    SPoint2 p2 = f->parFromPoint(SPoint3(v1->x(), v1->y(), v1->z()));
    double uc = 0.5 * (p1[0] + p2[0]);
    double vc = 0.5 * (p1[1] + p2[1]);
    GPoint pc = f->point(uc, vc);
    v = new MFaceVertex(pc.x(), pc.y(), pc.z(), f, uc, vc);
  }

  f->mesh_vertices.push_back(v);
  return v;
}

MVertex *addEdgeVertex(GRegion *r, std::pair<MVertex* , MVertex*> &p, bool linear)
{
  MVertex *v0(p.first), *v1(p.second), *v;
  MEdge edge(v0, v1);
  SPoint3 pc = edge.barycenter();
  v = new MVertex(pc.x(), pc.y(), pc.z(), r);
  r->mesh_vertices.push_back(v);
  return v;
}

template<class T, class U>
void addEdgeVertices(U *ge, std::vector<T*> &elements, bool linear,
		     std::map<std::pair<MVertex*,MVertex*>, MVertex* > &edges)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumEdges(); j++){
      MEdge e = elements[i]->getEdge(j);
      std::pair<MVertex*, MVertex*> p(e.getMinVertex(), e.getMaxVertex());
      if(!edges.count(p)) edges[p] = addEdgeVertex(ge, p, linear);
    }
  }
}

// Creation of middle-face vertices

MVertex *addFaceVertex(GFace *f, std::vector<MVertex*> &p, bool linear)
{
  /*
  MVertex *v;
  if(linear || e->dim() == 3){
    // just interpolate linear between the 4
  }
  else if(e->dim() == 2){
    xyz2uv();
    xyz2uv();
    xyz2uv();
    xyz2uv();
    // interpolate
  }
  e->mesh_vertices.push_back(v);
  */
  return 0;
}

template<class T>
void addFaceVertices(GEntity *e, std::vector<T*> &elements)
{
}

// Creation of middle-volume vertices

MVertex *addVolumeVertex(GEntity *ge, MElement *elem)
{
  SPoint3 pc = elem->barycenter();
  MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), ge);
  ge->mesh_vertices.push_back(v);
  return v;
}

// Main routines

void Degre1()
{
  // loop on all elements 
  // - get their edge/face/volume vertices mark them with setVisibility(-1);
  // - generate a first order element for each element
  // - swap lists at the end
  // loop on all vertices and delete all vertices marked (-1)

}

void Degre2(int dim)
{
  Msg(STATUS1, "Mesh second order...");
  double t1 = Cpu();

  //bool linear = true;
  bool linear = false;
  std::map<std::pair<MVertex*,MVertex*>, MVertex* > edges;
  std::map<std::vector<MVertex*>, MVertex* > quadFaces;

  // loop over all elements and create unique edges and faces and
  // their associated new vertices
  for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); ++it){
    addEdgeVertices(*it, (*it)->lines, linear, edges);
  }
  for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); ++it){
    addEdgeVertices(*it, (*it)->triangles, linear, edges);
    addEdgeVertices(*it, (*it)->quadrangles, linear, edges);
    //addFaceVertices(*it, (*it)->quadrangles, linear);
  }
  for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); ++it){
    addEdgeVertices(*it, (*it)->tetrahedra, linear, edges);
    addEdgeVertices(*it, (*it)->hexahedra, linear, edges);
    addEdgeVertices(*it, (*it)->prisms, linear, edges);
    addEdgeVertices(*it, (*it)->pyramids, linear, edges);
//     addFaceVertices(*it, (*it)->hexahedra, linear);
//     addFaceVertices(*it, (*it)->prisms, linear);
//     addFaceVertices(*it, (*it)->pyramids, linear);
  }
  
  // loop on all elements again and create one new element from each
  // old one, querying the edge/face maps to get the extra vertices
  double t2 = Cpu();
  Msg(STATUS1, "Mesh second order complete (%g s)", t2 - t1);
}
