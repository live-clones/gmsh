// $Id: meshGRegionExtruded.cpp,v 1.4 2006-11-27 22:32:01 geuzaine Exp $
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
#include "ExtrudeParams.h"
#include "GModel.h"
#include "Context.h"
#include "Message.h"

extern Context_T CTX;

void createPriPyrTet(std::vector<MVertex*> &v, GRegion *to)
{
  int dup[3];
  int j = 0;
  for(int i = 0; i < 3; i++)
    if(v[i] == v[i + 3])
      dup[j++] = i;

  if(j == 2) {
    if(dup[0] == 0 && dup[1] == 1)
      to->tetrahedra.push_back(new MTetrahedron(v[0], v[1], v[2], v[5]));
    else if(dup[0] == 1 && dup[1] == 2)
      to->tetrahedra.push_back(new MTetrahedron(v[0], v[1], v[2], v[3]));
    else
      to->tetrahedra.push_back(new MTetrahedron(v[0], v[1], v[2], v[4]));
  }
  else if(j == 1) {
    if(dup[0] == 0)
      to->pyramids.push_back(new MPyramid(v[1], v[4], v[5], v[2], v[0]));
    else if(dup[0] == 1)
      to->pyramids.push_back(new MPyramid(v[0], v[2], v[5], v[3], v[1]));
    else
      to->pyramids.push_back(new MPyramid(v[0], v[1], v[4], v[3], v[2]));
  }
  else {
    to->prisms.push_back(new MPrism(v));
    if(j) Msg(GERROR, "Degenerated prism in extrusion of volume %d", to->tag());
  }
}

void createHexPri(std::vector<MVertex*> &v, GRegion *to)
{
  int dup[4];
  int j = 0;
  for(int i = 0; i < 4; i++)
    if(v[i] == v[i + 4])
      dup[j++] = i;
  
  if(j == 2) {
    if(dup[0] == 0 && dup[1] == 1)
      to->prisms.push_back(new MPrism(v[0], v[3], v[7], v[1], v[2], v[6]));
    else if(dup[0] == 1 && dup[1] == 2)
      to->prisms.push_back(new MPrism(v[0], v[1], v[4], v[3], v[2], v[7]));
    else if(dup[0] == 2 && dup[1] == 3)
      to->prisms.push_back(new MPrism(v[0], v[3], v[4], v[1], v[2], v[5]));
    else if(dup[0] == 0 && dup[1] == 3)
      to->prisms.push_back(new MPrism(v[0], v[1], v[5], v[3], v[2], v[6]));
    else
      Msg(GERROR, "Uncoherent hexahedron in extrusion of volume %d", to->tag());
  }
  else {
    to->hexahedra.push_back(new MHexahedron(v));
    if(j) Msg(GERROR, "Degenerated hexahedron in extrusion of volume %d", to->tag());
  }
}

void extrudeMesh(GFace *from, GRegion *to,
		 std::set<MVertex*, MVertexLessThanLexicographic> &pos)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  // create vertices
  for(unsigned int i = 0; i < from->mesh_vertices.size(); i++){
    MVertex *v = from->mesh_vertices[i];
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	double x = v->x(), y = v->y(), z = v->z();
	ep->Extrude(j, k + 1, x, y, z);
	if(j != ep->mesh.NbLayer - 1 || k != ep->mesh.NbElmLayer[j] - 1){
	  MVertex *newv = new MVertex(x, y, z, to);
	  to->mesh_vertices.push_back(newv);
	  pos.insert(newv);
	}
      }
    }
  }

  // create elements (note that it would be faster to access the
  // *interior* nodes by direct indexing, but it's just simpler to
  // query everything by position)
  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;
  for(unsigned int i = 0; i < from->triangles.size(); i++){
    MVertex *v0 = from->triangles[i]->getVertex(0);
    MVertex *v1 = from->triangles[i]->getVertex(1);
    MVertex *v2 = from->triangles[i]->getVertex(2);
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	std::vector<MVertex*> verts;
	double x[6] = {v0->x(), v1->x(), v2->x(), v0->x(), v1->x(), v2->x()};
	double y[6] = {v0->y(), v1->y(), v2->y(), v0->y(), v1->y(), v2->y()};
	double z[6] = {v0->z(), v1->z(), v2->z(), v0->z(), v1->z(), v2->z()};
	for(int p = 0; p < 3; p++){
	  ep->Extrude(j, k, x[p], y[p], z[p]);
	  ep->Extrude(j, k + 1, x[p + 3], y[p + 3], z[p + 3]);
	}
	for(int p = 0; p < 6; p++){
	  MVertex tmp(x[p], y[p], z[p], 0, -1);
	  itp = pos.find(&tmp);
	  if(itp == pos.end()) {
	    Msg(GERROR, "Could not find extruded vertex in volume %d", to->tag());
	    return;
	  }
	  verts.push_back(*itp);
	}
	createPriPyrTet(verts, to);
      }
    }
  }
  for(unsigned int i = 0; i < from->quadrangles.size(); i++){
    MVertex *v0 = from->quadrangles[i]->getVertex(0);
    MVertex *v1 = from->quadrangles[i]->getVertex(1);
    MVertex *v2 = from->quadrangles[i]->getVertex(2);
    MVertex *v3 = from->quadrangles[i]->getVertex(3);
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	std::vector<MVertex*> verts;
	double x[8] = {v0->x(), v1->x(), v2->x(), v3->x(), 
		       v0->x(), v1->x(), v2->x(), v3->x()};
	double y[8] = {v0->y(), v1->y(), v2->y(), v3->y(), 
		       v0->y(), v1->y(), v2->y(), v3->y()};
	double z[8] = {v0->z(), v1->z(), v2->z(), v3->z(), 
		       v0->z(), v1->z(), v2->z(), v3->z()};
	for(int p = 0; p < 4; p++){
	  ep->Extrude(j, k, x[p], y[p], z[p]);
	  ep->Extrude(j, k + 1, x[p + 4], y[p + 4], z[p + 4]);
	}
	for(int p = 0; p < 8; p++){
	  MVertex tmp(x[p], y[p], z[p], 0, -1);
	  itp = pos.find(&tmp);
	  if(itp == pos.end()) {
	    Msg(GERROR, "Could not find extruded vertex in volume %d", to->tag());
	    return;
	  }
	  verts.push_back(*itp);
	}
	createHexPri(verts, to);
      }
    }
  }
}

int MeshExtrudedVolume(GRegion *gr)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh || ep->geo.Mode != EXTRUDED_ENTITY)
    return 0;

  // build a set with all the vertices on the boundary of gr
  double old_tol = MVertexLessThanLexicographic::tolerance; 
  MVertexLessThanLexicographic::tolerance = 1.e-12;
  std::set<MVertex*, MVertexLessThanLexicographic> pos;
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while(it != faces.end()){
    pos.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
    std::list<GEdge*> edges = (*it)->edges();
    std::list<GEdge*>::iterator ite = edges.begin();
    while(ite != edges.end()){
      pos.insert((*ite)->mesh_vertices.begin(), (*ite)->mesh_vertices.end());
      pos.insert((*ite)->getBeginVertex()->mesh_vertices.begin(),
		 (*ite)->getBeginVertex()->mesh_vertices.end());
      pos.insert((*ite)->getEndVertex()->mesh_vertices.begin(),
		 (*ite)->getEndVertex()->mesh_vertices.end());
      ++ite;
    }
    ++it;
  }

  // volume is extruded from a surface
  GFace *from = gr->model()->faceByTag(std::abs(ep->geo.Source));
  if(!from) return 0;

  extrudeMesh(from, gr, pos);

  MVertexLessThanLexicographic::tolerance = old_tol; 

  return 1;
}
