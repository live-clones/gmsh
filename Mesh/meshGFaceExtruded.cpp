// $Id: meshGFaceExtruded.cpp,v 1.28 2008-03-20 11:44:08 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
#include "MElement.h"
#include "ExtrudeParams.h"
#include "Context.h"
#include "Message.h"

extern Context_T CTX;

void createQuaTri(std::vector<MVertex*> &v, GFace *to,
                  std::set<std::pair<MVertex*, MVertex*> > *constrainedEdges)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  if(v[0] == v[1] || v[1] == v[3])
    to->triangles.push_back(new MTriangle(v[0], v[3], v[2]));
  else if(v[0] == v[2] || v[2] == v[3])
    to->triangles.push_back(new MTriangle(v[0], v[1], v[3]));
  else if(v[0] == v[3] || v[1] == v[2])
    Msg(GERROR, "Uncoherent extruded quadrangle in surface %d", to->tag());
  else{
    if(ep->mesh.Recombine){
      to->quadrangles.push_back(new MQuadrangle(v[0], v[1], v[3], v[2]));
    }
    else if(!constrainedEdges){
      to->triangles.push_back(new MTriangle(v[0], v[1], v[3]));
      to->triangles.push_back(new MTriangle(v[0], v[3], v[2]));
    }
    else{
      std::pair<MVertex*, MVertex*> p(std::min(v[1], v[2]), std::max(v[1], v[2]));
      if(constrainedEdges->count(p)){
        to->triangles.push_back(new MTriangle(v[2], v[1], v[0]));
        to->triangles.push_back(new MTriangle(v[2], v[3], v[1]));
      }
      else{
        to->triangles.push_back(new MTriangle(v[2], v[3], v[0]));
        to->triangles.push_back(new MTriangle(v[0], v[3], v[1]));
      }
    }
  }
}

void extrudeMesh(GEdge *from, GFace *to,
                 std::set<MVertex*, MVertexLessThanLexicographic> &pos,
                 std::set<std::pair<MVertex*, MVertex*> > *constrainedEdges)
{
  ExtrudeParams *ep = to->meshAttributes.extrude;

  // create vertices (if the edges are constrained, they already exist)
  if(!constrainedEdges){
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
  }

  // create elements (note that it would be faster to access the
  // *interior* nodes by direct indexing, but it's just simpler to
  // query everything by position)
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
        for(int p = 0; p < 2; p++){
          ep->Extrude(j, k, x[p], y[p], z[p]);
          ep->Extrude(j, k + 1, x[p + 2], y[p + 2], z[p + 2]);
        }
        for(int p = 0; p < 4; p++){
          MVertex tmp(x[p], y[p], z[p], 0, -1);
          itp = pos.find(&tmp);
          if(itp == pos.end()){ // FIXME: workaround
            Msg(INFO, "Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
            itp = tmp.linearSearch(pos);
          }
          if(itp == pos.end()){
            Msg(GERROR, "Could not find extruded vertex (%.16g, %.16g, %.16g) in surface %d",
                tmp.x(), tmp.y(), tmp.z(), to->tag());
            return;
          }
          verts.push_back(*itp);
        }
        createQuaTri(verts, to, constrainedEdges);
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
      if(itp == pos.end()){ // FIXME: workaround
        Msg(INFO, "Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
        itp = tmp.linearSearch(pos);
      }
      if(itp == pos.end()) {
        Msg(GERROR, "Could not find extruded vertex (%.16g, %.16g, %.16g) in surface %d",
            tmp.x(), tmp.y(), tmp.z(), to->tag());
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
      if(itp == pos.end()){ // FIXME: workaround
        Msg(INFO, "Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
        itp = tmp.linearSearch(pos);
      }
      if(itp == pos.end()) {
        Msg(GERROR, "Could not find extruded vertex (%.16g, %.16g, %.16g) in surface %d", 
            tmp.x(), tmp.y(), tmp.z(), to->tag());
        return;
      }
      verts.push_back(*itp);
    }
    to->quadrangles.push_back(new MQuadrangle(verts));
  }
}

int MeshExtrudedSurface(GFace *gf, 
                        std::set<std::pair<MVertex*, MVertex*> > *constrainedEdges)
{
  ExtrudeParams *ep = gf->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh)
    return 0;

  Msg(STATUS2, "Meshing surface %d (extruded)", gf->tag());

  // build a set with all the vertices on the boundary of the face gf
  double old_tol = MVertexLessThanLexicographic::tolerance; 
  MVertexLessThanLexicographic::tolerance = 1.e-12 * CTX.lc;

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

  // if the edges of the mesh are constrained, the vertices already
  // exist on the face--so we add them to the set
  if(constrainedEdges)
    pos.insert(gf->mesh_vertices.begin(), gf->mesh_vertices.end());
  
  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    // surface is extruded from a curve
    GEdge *from = gf->model()->getEdgeByTag(std::abs(ep->geo.Source));
    if(!from){
      Msg(GERROR, "Unknown source curve %d for extrusion", ep->geo.Source);
      return 0;
    }
    extrudeMesh(from, gf, pos, constrainedEdges);
  }
  else {
    // surface is a copy of another surface (the "top" of the extrusion)
    GFace *from = gf->model()->getFaceByTag(std::abs(ep->geo.Source));
    if(!from){ 
      Msg(GERROR, "Unknown source surface %d for extrusion", ep->geo.Source);
      return 0;
    }
    copyMesh(from, gf, pos);
  }

  MVertexLessThanLexicographic::tolerance = old_tol; 

  gf->meshStatistics.status = GFace::DONE;
  return 1;
}

