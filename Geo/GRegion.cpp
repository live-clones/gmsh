// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "GmshMessage.h"
#include "VertexArray.h"

GRegion::GRegion(GModel *model, int tag) : GEntity (model, tag)
{
  resetMeshAttributes();
}

GRegion::~GRegion()
{
  std::list<GFace*>::iterator it = l_faces.begin();
  while(it != l_faces.end()){
    (*it)->delRegion(this);
    ++it;
  }

  deleteMesh();
}

void GRegion::deleteMesh()
{
  for(unsigned int i = 0; i < mesh_vertices.size(); i++) delete mesh_vertices[i];
  mesh_vertices.clear();
  transfinite_vertices.clear();
  for(unsigned int i = 0; i < tetrahedra.size(); i++) delete tetrahedra[i];
  tetrahedra.clear();
  for(unsigned int i = 0; i < hexahedra.size(); i++) delete hexahedra[i];
  hexahedra.clear();
  for(unsigned int i = 0; i < prisms.size(); i++) delete prisms[i];
  prisms.clear();
  for(unsigned int i = 0; i < pyramids.size(); i++) delete pyramids[i];
  pyramids.clear();
  for(unsigned int i = 0; i < polyhedra.size(); i++) delete polyhedra[i];
  polyhedra.clear();
}

unsigned int GRegion::getNumMeshElements()
{ 
  return tetrahedra.size() + hexahedra.size() + prisms.size() + pyramids.size() + polyhedra.size();
}

void GRegion::getNumMeshElements(unsigned *const c) const
{
  c[0] += tetrahedra.size();
  c[1] += hexahedra.size();
  c[2] += prisms.size();
  c[3] += pyramids.size();
  c[4] += polyhedra.size();
}

MElement *const *GRegion::getStartElementType(int type) const
{
  switch(type) {
  case 0:
    if(tetrahedra.empty()) return 0; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&tetrahedra[0]);
  case 1:
    if(hexahedra.empty()) return 0; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&hexahedra[0]);
  case 2:
    if(prisms.empty()) return 0; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&prisms[0]);
  case 3:
    if(pyramids.empty()) return 0; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&pyramids[0]);
  case 4:
    if(polyhedra.empty()) return 0;
    return reinterpret_cast<MElement *const *>(&polyhedra[0]);
  }
  return 0;
}

MElement *GRegion::getMeshElement(unsigned int index)
{ 
  if(index < tetrahedra.size())
    return tetrahedra[index];
  else if(index < tetrahedra.size() + hexahedra.size())
    return hexahedra[index - tetrahedra.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size())
    return prisms[index - tetrahedra.size() - hexahedra.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size() + pyramids.size())
    return pyramids[index - tetrahedra.size() - hexahedra.size() - prisms.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size() + pyramids.size() + polyhedra.size())
    return polyhedra[index - tetrahedra.size() - hexahedra.size() - prisms.size() - pyramids.size()];
  return 0;
}

void GRegion::resetMeshAttributes()
{
  meshAttributes.Method = MESH_UNSTRUCTURED;
  meshAttributes.extrude = 0;
}

SBoundingBox3d GRegion::bounds() const
{
  SBoundingBox3d res;
  if(geomType() != DiscreteVolume){
    std::list<GFace*>::const_iterator it = l_faces.begin();
    for(; it != l_faces.end(); it++)
      res += (*it)->bounds();
  }
  else{
    for(unsigned int i = 0; i < mesh_vertices.size(); i++)
      res += mesh_vertices[i]->point();
  }
  return res;
}

SOrientedBoundingBox GRegion::getOBB() {
  if (!(this->_obb)) {
    vector<SPoint3> vertices;
    list<GFace*> b_faces = this->faces();
    for (list<GFace*>::iterator b_face = b_faces.begin(); b_face != b_faces.end(); b_face++) {
      if((*b_face)->getNumMeshVertices() > 0) {
	int N = (*b_face)->getNumMeshVertices();
	for (int i = 0; i < N; i++) {
	  MVertex* mv = (*b_face)->getMeshVertex(i);
	  vertices.push_back(mv->point());
	}
	list<GEdge*> eds = (*b_face)->edges();
	for(list<GEdge*>::iterator ed = eds.begin(); ed != eds.end(); ed++) {
	  int N2 = (*ed)->getNumMeshVertices();
	  for (int i = 0; i < N2; i++) {
	    MVertex* mv = (*ed)->getMeshVertex(i);
	    vertices.push_back(mv->point());
	  }
	  // Don't forget to add the first and last vertices...
	  SPoint3 pt1((*ed)->getBeginVertex()->x(),(*ed)->getBeginVertex()->y(),(*ed)->getBeginVertex()->z());
	  SPoint3 pt2((*ed)->getEndVertex()->x(),(*ed)->getEndVertex()->y(),(*ed)->getEndVertex()->z());
	  vertices.push_back(pt1);
	  vertices.push_back(pt2);
	}
      } else if ((*b_face)->buildSTLTriangulation()) {
	int N = (*b_face)->va_geom_triangles->getNumVertices();
        for(int i = 0; i < N; i++) {
	  SPoint3 p(((*b_face)->va_geom_triangles->getVertexArray(3*i))[0],
		    ((*b_face)->va_geom_triangles->getVertexArray(3*i))[1],
		    ((*b_face)->va_geom_triangles->getVertexArray(3*i))[2]);
	  vertices.push_back(p);	  
	}
      } else {
	int N = 10;
        list<GEdge*> b_edges = (*b_face)->edges();
        for (list<GEdge*>::iterator b_edge = b_edges.begin(); b_edge != b_edges.end(); b_edge++) {
	  Range<double> tr = (*b_edge)->parBounds(0);
	  for (int j = 0; j < N; j++) {
	    double t = tr.low() + (double)j / (double)(N-1)*(tr.high() - tr.low());
	    GPoint p = (*b_edge)->point(t);
	    SPoint3 pt(p.x(),p.y(),p.z());
	    vertices.push_back(pt);
	  }
	}       
      }
    }
    this->_obb = SOrientedBoundingBox::buildOBB(vertices);
  }
  return (SOrientedBoundingBox(this->_obb));
}

void GRegion::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive){
    std::list<GFace*>::iterator it = l_faces.begin();
    while(it != l_faces.end()){
      (*it)->setVisibility(val, recursive);
      ++it;
    }
  }
}

std::string GRegion::getAdditionalInfoString()
{
  std::ostringstream sstream;
  if(l_faces.size() > 20){
    sstream << "{" << l_faces.front()->tag() << ",...," << l_faces.back()->tag() << "}";
  }
  else if(l_faces.size()){
    sstream << "{";
    for(std::list<GFace*>::iterator it = l_faces.begin(); it != l_faces.end(); ++it){
      if(it != l_faces.begin()) sstream << ",";
      sstream << (*it)->tag();
    }
    sstream << "}";
  }
  return sstream.str();
}

void GRegion::writeGEO(FILE *fp)
{
  if(geomType() == DiscreteVolume) return;

  if(l_faces.size()){
    fprintf(fp, "Surface Loop(%d) = ", tag());
    for(std::list<GFace*>::iterator it = l_faces.begin(); it != l_faces.end(); it++) {
      if(it != l_faces.begin())
        fprintf(fp, ", %d", (*it)->tag());
      else
        fprintf(fp, "{%d", (*it)->tag());
    }
    fprintf(fp, "};\n");
    fprintf(fp, "Volume(%d) = {%d};\n", tag(), tag());
  }
}

std::list<GEdge*> GRegion::edges() const
{
  std::list<GEdge*> e;
  std::list<GFace*>::const_iterator it = l_faces.begin();
  while(it != l_faces.end()){
    std::list<GEdge*> e2;
    e2 = (*it)->edges();
    std::list<GEdge*>::const_iterator it2 = e2.begin();
    while (it2 != e2.end()){
      if(std::find(e.begin(), e.end(), *it2) == e.end())
        e.push_back(*it2);
      ++it2;
    }
    ++it;
  }
  return e;
}

bool GRegion::edgeConnected(GRegion *r) const
{
  std::list<GEdge*> e = edges();
  std::list<GEdge*> e2 = r->edges();

  std::list<GEdge*>::const_iterator it = e.begin();
  while(it != e.end()){
    if(std::find(e2.begin(), e2.end(), *it) != e2.end())
      return true;
    ++it;
  }
  return false;
}
