// $Id: meshGRegionExtruded.cpp,v 1.21 2008-02-17 08:48:01 geuzaine Exp $
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
#include "meshGFace.h"
#include "meshGRegion.h"
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

void createTet(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, GRegion *to)
{
  if(v1 != v2 && v1 != v3 && v1 != v4 && v2 != v3 && v2 != v4 && v3 != v4)
    to->tetrahedra.push_back(new MTetrahedron(v1, v2, v3, v4));
}

int getExtrudedVertices(MElement *ele, ExtrudeParams *ep, int j, int k, 
			std::set<MVertex*, MVertexLessThanLexicographic> &pos,
			std::vector<MVertex*> &verts)
{
  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp;
  double x[8], y[8], z[8];
  int n = ele->getNumVertices();
  for(int p = 0; p < n; p++){
    MVertex *v = ele->getVertex(p);
    x[p] = x[p + n] = v->x();
    y[p] = y[p + n] = v->y();
    z[p] = z[p + n] = v->z();
  }
  for(int p = 0; p < n; p++){
    ep->Extrude(j, k, x[p], y[p], z[p]);
    ep->Extrude(j, k + 1, x[p + n], y[p + n], z[p + n]);
  }
  for(int p = 0; p < 2 * n; p++){
    MVertex tmp(x[p], y[p], z[p], 0, -1);
    itp = pos.find(&tmp);
    if(itp == pos.end()){ // FIXME: workaround
      Msg(INFO, "Linear search for (%.16g, %.16g, %.16g)", tmp.x(), tmp.y(), tmp.z());
      itp = tmp.linearSearch(pos);
    }
    if(itp == pos.end())
      Msg(GERROR, "Could not find extruded vertex (%.16g, %.16g, %.16g)",
	  tmp.x(), tmp.y(), tmp.z());
    else
      verts.push_back(*itp);
  }
  return verts.size();
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
  for(unsigned int i = 0; i < from->triangles.size(); i++){
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	std::vector<MVertex*> verts;
	if(getExtrudedVertices(from->triangles[i], ep, j, k, pos, verts) == 6)
	  createPriPyrTet(verts, to);
      }
    }
  }
  for(unsigned int i = 0; i < from->quadrangles.size(); i++){
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	std::vector<MVertex*> verts;
	if(getExtrudedVertices(from->quadrangles[i], ep, j, k, pos, verts) == 8)
	  createHexPri(verts, to);
      }
    }
  }
}

void insertAllVertices(GRegion *gr, 
		       std::set<MVertex*, MVertexLessThanLexicographic> &pos)
{
  pos.insert(gr->mesh_vertices.begin(), gr->mesh_vertices.end());
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator itf = faces.begin();
  while(itf != faces.end()){
    pos.insert((*itf)->mesh_vertices.begin(), (*itf)->mesh_vertices.end());
    std::list<GEdge*> edges = (*itf)->edges();
    std::list<GEdge*>::iterator ite = edges.begin();
    while(ite != edges.end()){
      pos.insert((*ite)->mesh_vertices.begin(), (*ite)->mesh_vertices.end());
      pos.insert((*ite)->getBeginVertex()->mesh_vertices.begin(),
		 (*ite)->getBeginVertex()->mesh_vertices.end());
      pos.insert((*ite)->getEndVertex()->mesh_vertices.begin(),
		 (*ite)->getEndVertex()->mesh_vertices.end());
      ++ite;
    }
    ++itf;
  }
}

void meshGRegionExtruded::operator() (GRegion *gr) 
{  
  if(gr->geomType() == GEntity::DiscreteVolume) return;

  ExtrudeParams *ep = gr->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh || ep->geo.Mode != EXTRUDED_ENTITY) return;

  Msg(STATUS2, "Meshing volume %d (extruded)", gr->tag());

  // destroy the mesh if it exists
  deMeshGRegion dem;
  dem(gr);

  // build a set with all the vertices on the boundary of gr
  double old_tol = MVertexLessThanLexicographic::tolerance; 
  MVertexLessThanLexicographic::tolerance = 1.e-12 * CTX.lc;
  std::set<MVertex*, MVertexLessThanLexicographic> pos;
  insertAllVertices(gr, pos);

  // volume is extruded from a surface
  GFace *from = gr->model()->faceByTag(std::abs(ep->geo.Source));
  if(!from){
    Msg(GERROR, "Unknown source surface %d for extrusion", ep->geo.Source);
    return;
  }

  extrudeMesh(from, gr, pos);

  // carve holes if any (only do it now if the mesh is final, i.e., if
  // the mesh is recombined)
  if(ep->mesh.Holes.size() && ep->mesh.Recombine){
    std::map<int, std::pair<double, std::vector<int> > >::iterator it;
    for(it = ep->mesh.Holes.begin(); it != ep->mesh.Holes.end(); it++)
      carveHole(gr, it->first, it->second.first, it->second.second);
  }
  
  MVertexLessThanLexicographic::tolerance = old_tol; 
}

int edgeExists(MVertex *v1, MVertex *v2, 
	      std::set<std::pair<MVertex*, MVertex*> > &edges)
{
  std::pair<MVertex*, MVertex*> p(std::min(v1, v2), std::max(v1, v2));
  return edges.count(p);
}

void createEdge(MVertex *v1, MVertex *v2, 
	      std::set<std::pair<MVertex*, MVertex*> > &edges)
{
  std::pair<MVertex*, MVertex*> p(std::min(v1, v2), std::max(v1, v2));
  edges.insert(p);
}

void deleteEdge(MVertex *v1, MVertex *v2, 
	      std::set<std::pair<MVertex*, MVertex*> > &edges)
{
  std::pair<MVertex*, MVertex*> p(std::min(v1, v2), std::max(v1, v2));
  edges.erase(p);
}

// subdivide the 3 lateral faces of each prism
void phase1(GRegion *gr,
	    std::set<MVertex*, MVertexLessThanLexicographic> &pos,
	    std::set<std::pair<MVertex*, MVertex*> > &edges)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  GFace *from = gr->model()->faceByTag(std::abs(ep->geo.Source));
  if(!from) return;

  for(unsigned int i = 0; i < from->triangles.size(); i++){
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	std::vector<MVertex*> v;
        if(getExtrudedVertices(from->triangles[i], ep, j, k, pos, v) == 6){
#if 0 // old
          if(!edgeExists(v[0], v[4], edges))
            createEdge(v[1], v[3], edges);
          if(!edgeExists(v[4], v[2], edges))
            createEdge(v[1], v[5], edges);
          if(!edgeExists(v[3], v[2], edges))
            createEdge(v[0], v[5], edges);
#else // new from Michel Benhamou
	  if(v[1] < v[0]) createEdge(v[1], v[3], edges);
	  else createEdge(v[0], v[4], edges);
	  if(v[1] < v[2]) createEdge(v[1], v[5], edges);
	  else createEdge(v[4], v[2], edges);
	  if(v[0] < v[2]) createEdge(v[0], v[5], edges);
	  else createEdge(v[3], v[2], edges);
#endif
	}
      }
    }
  }
}

// modify lateral edges to make them "tet-compatible"
void phase2(GRegion *gr,
	    std::set<MVertex*, MVertexLessThanLexicographic> &pos,
	    std::set<std::pair<MVertex*, MVertex*> > &edges,
	    std::set<std::pair<MVertex*, MVertex*> > &edges_swap,
	    int &swap)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  GFace *from = gr->model()->faceByTag(std::abs(ep->geo.Source));
  if(!from) return;

  for(unsigned int i = 0; i < from->triangles.size(); i++){
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	std::vector<MVertex*> v;
	if(getExtrudedVertices(from->triangles[i], ep, j, k, pos, v) == 6){
	  if(edgeExists(v[3], v[1], edges) &&
	     edgeExists(v[4], v[2], edges) && 
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
void phase3(GRegion *gr,
	    std::set<MVertex*, MVertexLessThanLexicographic> &pos,
	    std::set<std::pair<MVertex*, MVertex*> > &edges)
{
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  GFace *from = gr->model()->faceByTag(std::abs(ep->geo.Source));
  if(!from) return;

  for(unsigned int i = 0; i < from->triangles.size(); i++){
    for(int j = 0; j < ep->mesh.NbLayer; j++) {
      for(int k = 0; k < ep->mesh.NbElmLayer[j]; k++) {
	std::vector<MVertex*> v;
	if(getExtrudedVertices(from->triangles[i], ep, j, k, pos, v) == 6){
	  if(edgeExists(v[3], v[1], edges) &&
	     edgeExists(v[4], v[2], edges) &&
	     edgeExists(v[3], v[2], edges)) {
	    createTet(v[0], v[1], v[2], v[3], gr);
	    createTet(v[3], v[4], v[5], v[2], gr);
	    createTet(v[1], v[3], v[4], v[2], gr);
	  }
	  else if(edgeExists(v[3], v[1], edges) &&
		  edgeExists(v[1], v[5], edges) &&
		  edgeExists(v[3], v[2], edges)) {
	    createTet(v[0], v[1], v[2], v[3], gr);
	    createTet(v[3], v[4], v[5], v[1], gr);
	    createTet(v[3], v[1], v[5], v[2], gr);
	  }
	  else if(edgeExists(v[3], v[1], edges) &&
		  edgeExists(v[1], v[5], edges) &&
		  edgeExists(v[5], v[0], edges)) {
	    createTet(v[0], v[1], v[2], v[5], gr);
	    createTet(v[3], v[4], v[5], v[1], gr);
	    createTet(v[1], v[3], v[5], v[0], gr);
	  }
	  else if(edgeExists(v[4], v[0], edges) &&
		  edgeExists(v[4], v[2], edges) &&
		  edgeExists(v[3], v[2], edges)) {
	    createTet(v[0], v[1], v[2], v[4], gr);
	    createTet(v[3], v[4], v[5], v[2], gr);
	    createTet(v[0], v[3], v[4], v[2], gr);
	  }
	  else if(edgeExists(v[4], v[0], edges) &&
		  edgeExists(v[4], v[2], edges) &&
		  edgeExists(v[5], v[0], edges)) {
	    createTet(v[0], v[1], v[2], v[4], gr);
	    createTet(v[3], v[4], v[5], v[0], gr);
	    createTet(v[0], v[2], v[4], v[5], gr);
	  }
	  else if(edgeExists(v[4], v[0], edges) &&
		  edgeExists(v[1], v[5], edges) &&
		  edgeExists(v[5], v[0], edges)) {
	    createTet(v[0], v[1], v[2], v[5], gr);
	    createTet(v[3], v[4], v[5], v[0], gr);
	    createTet(v[0], v[1], v[4], v[5], gr);
	  }
	}
      }
    }
  }
}

int SubdivideExtrudedMesh(GModel *m)
{
  // get all non-recombined extruded regions and vertices
  std::vector<GRegion*> regions;
  double old_tol = MVertexLessThanLexicographic::tolerance; 
  MVertexLessThanLexicographic::tolerance = 1.e-12 * CTX.lc;
  std::set<MVertex*, MVertexLessThanLexicographic> pos;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++){
    ExtrudeParams *ep = (*it)->meshAttributes.extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY && 
       !ep->mesh.Recombine){
      regions.push_back(*it);
      insertAllVertices(*it, pos);
    }
  }

  if(regions.empty()) return 0;

  Msg(INFO, "Subdividing extruded mesh");

  // create edges on lateral sides of "prisms"
  std::set<std::pair<MVertex*, MVertex*> > edges;
  for(unsigned int i = 0; i < regions.size(); i++)
    phase1(regions[i], pos, edges);

  // swap lateral edges to make them "tet-compatible"
  int j = 0, swap;
  std::set<std::pair<MVertex*, MVertex*> > edges_swap;
  do {
    swap = 0;
    for(unsigned int i = 0; i < regions.size(); i++)
      phase2(regions[i], pos, edges, edges_swap, swap);
    Msg(INFO, "Swapping %d", swap);
    if(j && j == swap) {
      Msg(GERROR, "Unable to subdivide extruded mesh: change surface mesh or");
      Msg(GERROR, "recombine extrusion instead");
      return -1;
    }
    j = swap;
  } while(swap);

  // delete "recombined" volume elements and create tetrahedra instead
  for(unsigned int i = 0; i < regions.size(); i++){
    GRegion *gr = regions[i];
    for(unsigned int i = 0; i < gr->hexahedra.size(); i++) 
      delete gr->hexahedra[i];
    gr->hexahedra.clear();
    for(unsigned int i = 0; i < gr->prisms.size(); i++) 
      delete gr->prisms[i];
    gr->prisms.clear();
    for(unsigned int i = 0; i < gr->pyramids.size(); i++)
      delete gr->pyramids[i];
    gr->pyramids.clear();
    phase3(gr, pos, edges);
  }

  // re-Extrude bounding surfaces using edges as constraint
  std::set<GFace*> faces;
  for(unsigned int i = 0; i < regions.size(); i++){
    std::list<GFace*> f = regions[i]->faces();
    faces.insert(f.begin(), f.end());
  }
  for(std::set<GFace*>::iterator it = faces.begin(); it != faces.end(); it++){
    ExtrudeParams *ep = (*it)->meshAttributes.extrude;
    if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY && 
       !ep->mesh.Recombine){
      GFace *gf = *it;
      Msg(INFO, "Remeshing surface %d", gf->tag());
      for(unsigned int i = 0; i < gf->triangles.size(); i++) 
	delete gf->triangles[i];
      gf->triangles.clear();
      for(unsigned int i = 0; i < gf->quadrangles.size(); i++) 
	delete gf->quadrangles[i];
      gf->quadrangles.clear();
      MeshExtrudedSurface(gf, &edges);
    }
  }

  // carve holes if any
  for(unsigned int i = 0; i < regions.size(); i++){
    GRegion *gr = regions[i];
    ExtrudeParams *ep = gr->meshAttributes.extrude;
    if(ep->mesh.Holes.size()){
      std::map<int, std::pair<double, std::vector<int> > >::iterator it;
      for(it = ep->mesh.Holes.begin(); it != ep->mesh.Holes.end(); it++)
	carveHole(gr, it->first, it->second.first, it->second.second);
    }
  }

  MVertexLessThanLexicographic::tolerance = old_tol;   
  return 1;
}
