// $Id: meshGFaceExtruded.cpp,v 1.7 2006-11-27 03:06:46 geuzaine Exp $
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

#include <set>
#include "ExtrudeParams.h"
#include "GModel.h"
#include "Context.h"
#include "Message.h"

extern Context_T CTX;

void extrudeMesh(GEdge *from, GFace *to,
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

  // create elements
  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;
  for(unsigned int i = 0; i < from->lines.size(); i++){
    MVertex *v0 = from->lines[i]->getVertex(0);
    MVertex *v1 = from->lines[i]->getVertex(1);
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	std::vector<MVertex*> verts;
	double x[4] = {v0->x(), v1->x(), v0->x(), v1->x()};
	double y[4] = {v0->y(), v1->y(), v0->y(), v1->y()};
	double z[4] = {v0->z(), v1->z(), v0->z(), v1->z()};
	ep->Extrude(j, k, x[0], y[0], z[0]);
	ep->Extrude(j, k, x[1], y[1], z[1]);
	ep->Extrude(j, k + 1, x[2], y[2], z[2]);
	ep->Extrude(j, k + 1, x[3], y[3], z[3]);
	for(int p = 0; p < 4; p++){
	  MVertex tmp(x[p], y[p], z[p], 0, -1);
	  itp = pos.find(&tmp);
	  if(itp == pos.end()) {
	    Msg(GERROR, "Could not find extruded vertex in surface %d", to->tag());
	    return;
	  }
	  verts.push_back(*itp);
	}
	if(verts[0] == verts[1] || verts[1] == verts[3]){
	  to->triangles.push_back(new MTriangle(verts[0], verts[3], verts[2]));
	}
	else if(verts[0] == verts[2] || verts[2] == verts[3]){
	  to->triangles.push_back(new MTriangle(verts[0], verts[1], verts[3]));
	}
	else if(verts[0] == verts[3] || verts[1] == verts[2]){
          Msg(GERROR, "Uncoherent extruded quadrangle in surface %d", to->tag());
          return;
        }
        else{
	  to->quadrangles.push_back(new MQuadrangle(verts[0], verts[1], 
						    verts[3], verts[2]));
	}
      }
    }
  }
}

void copyMesh(GFace *from, GFace *to,
	      std::set<MVertex*, MVertexLessThanLexicographic> &pos)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  // create vertices
  for(unsigned int i = 0; i < from->mesh_vertices.size(); i++){
    MVertex *v = from->mesh_vertices[i];
    double x = v->x(), y = v->y(), z = v->z();
    ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1], 
		x, y, z);
    MVertex *newv = new MVertex(x, y, z, to);
    to->mesh_vertices.push_back(newv);
    pos.insert(newv);
  }

  // create elements
  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;
  for(unsigned int i = 0; i < from->triangles.size(); i++){
    std::vector<MVertex*> verts;
    for(int j = 0; j < 3; j++){
      MVertex *v = from->triangles[i]->getVertex(j);
      MVertex tmp(v->x(), v->y(), v->z(), 0, -1);
      ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
		  tmp.x(), tmp.y(), tmp.z());
      itp = pos.find(&tmp);
      if(itp == pos.end()) {
	Msg(GERROR, "Could not find extruded vertex in surface %d", to->tag());
	return;
      }
      verts.push_back(*itp);
    }
    to->triangles.push_back(new MTriangle(verts));
  }
  for(unsigned int i = 0; i < from->quadrangles.size(); i++){
    std::vector<MVertex*> verts;
    for(int j = 0; j < 4; j++){
      MVertex *v = from->quadrangles[i]->getVertex(j);
      MVertex tmp(v->x(), v->y(), v->z(), 0, -1);
      ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1],
		  tmp.x(), tmp.y(), tmp.z());
      itp = pos.find(&tmp);
      if(itp == pos.end()) {
	Msg(GERROR, "Could not find extruded vertex in surface %d", to->tag());
	return;
      }
      verts.push_back(*itp);
    }
    to->quadrangles.push_back(new MQuadrangle(verts));
  }
}

int MeshExtrudedSurface(GFace *gf)
{
  ExtrudeParams *ep = gf->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh)
    return 0;

  // build a set with all the vertices on the boundary of gf
  double old_tol = MVertexLessThanLexicographic::tolerance; 
  MVertexLessThanLexicographic::tolerance = 1.e-6 * CTX.lc;
  std::set<MVertex*, MVertexLessThanLexicographic> pos;
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*>::iterator it = edges.begin();
  while(it != edges.end()){
    pos.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
    pos.insert((*it)->getBeginVertex()->mesh_vertices.begin(),
	       (*it)->getBeginVertex()->mesh_vertices.end());
    pos.insert((*it)->getEndVertex()->mesh_vertices.begin(),
	       (*it)->getEndVertex()->mesh_vertices.end());
    ++it;
  }

  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    // surface is extruded from a curve
    GEdge *from = gf->model()->edgeByTag(std::abs(ep->geo.Source));
    if(!from) return 0;
    extrudeMesh(from, gf, pos);
  }
  else {
    // surface is a copy of another surface ("chapeau")
    GFace *from = gf->model()->faceByTag(std::abs(ep->geo.Source));
    if(!from) return 0;
    copyMesh(from, gf, pos);
  }

  MVertexLessThanLexicographic::tolerance = old_tol; 

  return 1;
}
