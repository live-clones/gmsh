// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
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

void GRegion::set(const std::list<GFace*> f) { 
  for (std::list<GFace*>::iterator it =  l_faces.begin(); it !=  l_faces.end() ; ++it){
    (*it)->delRegion(this);
  }
  l_faces = f; 
  for (std::list<GFace*>::iterator it =  l_faces.begin(); it !=  l_faces.end() ; ++it){
    (*it)->addRegion(this);
  }
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
  deleteVertexArrays();
  model()->destroyMeshCaches();
}

unsigned int GRegion::getNumMeshElements()
{ 
  return tetrahedra.size() + hexahedra.size() + prisms.size() + pyramids.size() +
    polyhedra.size();
}

unsigned int GRegion::getNumMeshParentElements()
{
  unsigned int n = 0;
  for(unsigned int i = 0; i < polyhedra.size(); i++)
    if(polyhedra[i]->ownsParent())
      n++;
  return n;
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
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size() + 
          pyramids.size())
    return pyramids[index - tetrahedra.size() - hexahedra.size() - prisms.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size() + 
          pyramids.size() + polyhedra.size())
    return polyhedra[index - tetrahedra.size() - hexahedra.size() - prisms.size() - 
                     pyramids.size()];
  return 0;
}

void GRegion::resetMeshAttributes()
{
  meshAttributes.Method = MESH_UNSTRUCTURED;
  meshAttributes.extrude = 0;
  meshAttributes.QuadTri = NO_QUADTRI;
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

SOrientedBoundingBox GRegion::getOBB()
{
  if (!_obb) {
    std::vector<SPoint3> vertices;
    std::list<GFace*> b_faces = faces();
    for (std::list<GFace*>::iterator b_face = b_faces.begin(); 
         b_face != b_faces.end(); b_face++) {
      if((*b_face)->getNumMeshVertices() > 0) {
        int N = (*b_face)->getNumMeshVertices();
        for (int i = 0; i < N; i++) {
          MVertex* mv = (*b_face)->getMeshVertex(i);
          vertices.push_back(mv->point());
        }
        std::list<GEdge*> eds = (*b_face)->edges();
        for(std::list<GEdge*>::iterator ed = eds.begin(); ed != eds.end(); ed++) {
          int N2 = (*ed)->getNumMeshVertices();
          for (int i = 0; i < N2; i++) {
            MVertex* mv = (*ed)->getMeshVertex(i);
            vertices.push_back(mv->point());
          }
          // Don't forget to add the first and last vertices...
          SPoint3 pt1((*ed)->getBeginVertex()->x(),
                      (*ed)->getBeginVertex()->y(),
                      (*ed)->getBeginVertex()->z());
          SPoint3 pt2((*ed)->getEndVertex()->x(),
                      (*ed)->getEndVertex()->y(),
                      (*ed)->getEndVertex()->z());
          vertices.push_back(pt1);
          vertices.push_back(pt2);
        }
      } 
      else if ((*b_face)->buildSTLTriangulation()) {
        for (unsigned int i = 0; i < (*b_face)->stl_vertices.size(); i++){
          GPoint p = (*b_face)->point((*b_face)->stl_vertices[i]);
          vertices.push_back(SPoint3(p.x(), p.y(), p.z()));
        } 
      }
      else {
        int N = 10;
        std::list<GEdge*> b_edges = (*b_face)->edges();
        for (std::list<GEdge*>::iterator b_edge = b_edges.begin(); 
             b_edge != b_edges.end(); b_edge++) {
          Range<double> tr = (*b_edge)->parBounds(0);
          for (int j = 0; j < N; j++) {
            double t = tr.low() + (double)j / (double)(N - 1) * (tr.high() - tr.low());
            GPoint p = (*b_edge)->point(t);
            SPoint3 pt(p.x(), p.y(), p.z());
            vertices.push_back(pt);
          }
        }       
      }
    }
    _obb = SOrientedBoundingBox::buildOBB(vertices);
  }
  return SOrientedBoundingBox(_obb);
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

  if(meshAttributes.Method == MESH_TRANSFINITE){
    fprintf(fp, "Transfinite Volume {%d}", tag());
    if(meshAttributes.corners.size()){
      fprintf(fp, " = {");
      for(unsigned int i = 0; i < meshAttributes.corners.size(); i++){
        if(i) fprintf(fp, ",");
        fprintf(fp, "%d", meshAttributes.corners[i]->tag());
      }
      fprintf(fp, "}");
    }
    fprintf(fp, ";\n");

    if(meshAttributes.QuadTri != NO_QUADTRI )
      fprintf(fp, "TransfQuadTri {%d};\n", tag());
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

void GRegion::replaceFaces (std::list<GFace*> &new_faces)
{
  replaceFacesInternal (new_faces);
  if (l_faces.size() != new_faces.size()){
    Msg::Fatal("impossible to replace faces in region %d (%d vs %d)",tag(),
	       l_faces.size(),new_faces.size());
  }

  std::list<GFace*>::iterator it  = l_faces.begin();
  std::list<GFace*>::iterator it2 = new_faces.begin();
  std::list<int>::iterator it3 = l_dirs.begin();
  std::list<int> newdirs;
  for ( ; it != l_faces.end(); ++it, ++it2, ++it3){
    (*it)->delRegion(this);
    (*it2)->addRegion(this);        
    // if ((*it2)->getBeginVertex() == (*it)->getBeginVertex())
      newdirs.push_back(*it3);
    // else
    //   newdirs.push_back(-(*it3));
  }
  l_faces = new_faces;
  l_dirs = newdirs;
}

double GRegion::computeSolidProperties (std::vector<double> cg,
					std::vector<double> inertia)
{
  std::list<GFace*>::iterator it = l_faces.begin();
  std::list<int>::iterator itdir =  l_dirs.begin();
  double volumex = 0;
  double volumey = 0;
  double volumez = 0;
  double surface = 0;
  cg[0] = cg[1] = cg[2] = 0.0;
  for ( ; it != l_faces.end(); ++it,++itdir){    
    //printf("face %d dir %d %d elements\n",(*it)->tag(),*itdir,(int)(*it)->triangles.size());
    for (unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *e = (*it)->triangles[i];
      int npt;
      IntPt *pts;
      e->getIntegrationPoints (2*(e->getPolynomialOrder()-1)+3, &npt, &pts);      
      for (int j=0;j<npt;j++){
	SPoint3 pt;
	// compute x,y,z of the integration point
	e->pnt(pts[j].pt[0],pts[j].pt[1],pts[j].pt[2],pt);
	double jac[3][3];
	// compute normal
	double detJ = e->getJacobian(pts[j].pt[0],pts[j].pt[1],pts[j].pt[2],jac);
	SVector3 n (jac[2][0],jac[2][1],jac[2][2]);
	n.normalize();
	n *= (double)*itdir;
	surface += detJ*pts[j].weight;
	volumex += detJ*n.x()*pt.x()*pts[j].weight;
	volumey += detJ*n.y()*pt.y()*pts[j].weight;
	volumez += detJ*n.z()*pt.z()*pts[j].weight;
	cg[0]  += detJ*n.x()*(pt.x()*pt.x())*pts[j].weight*0.5;
	cg[1]  += detJ*n.y()*(pt.y()*pt.y())*pts[j].weight*0.5;
	cg[2]  += detJ*n.z()*(pt.z()*pt.z())*pts[j].weight*0.5;
      }
    }
  }

  printf("%g -- %g %g %g\n",surface,volumex,volumey,volumez);

  double volume = volumex;

  cg[0]/=volume;
  cg[1]/=volume;
  cg[2]/=volume;

  it = l_faces.begin();
  itdir =  l_dirs.begin();
  inertia[0] =   
    inertia[1] = 
    inertia[2] = 
    inertia[3] = 
    inertia[4] = 
    inertia[5] = 0.0;

  for ( ; it != l_faces.end(); ++it,++itdir){    
    for (unsigned int i = 0; i < (*it)->getNumMeshElements(); ++i){
      MElement *e = (*it)->getMeshElement(i);
      int npt;
      IntPt *pts;
      e->getIntegrationPoints (2*(e->getPolynomialOrder()-1)+3, &npt, &pts);      
      for (int j = 0; j < npt; j++){
	SPoint3 pt;
	// compute x,y,z of the integration point
	e->pnt(pts[j].pt[0],pts[j].pt[1],pts[j].pt[2],pt);
	double jac[3][3];
	// compute normal
	double detJ = e->getJacobian(pts[j].pt[0],pts[j].pt[1],pts[j].pt[2],jac);
	SVector3 n (jac[2][0],jac[2][1],jac[2][2]);
	n *= (double)*itdir;
	inertia[0]  += pts[j].weight*detJ*n.x()*(pt.x()-cg[0])*(pt.x()-cg[0])*(pt.x()-cg[0])/3.0;
	inertia[1]  += pts[j].weight*detJ*n.y()*(pt.y()-cg[1])*(pt.y()-cg[1])*(pt.y()-cg[1])/3.0;
	inertia[2]  += pts[j].weight*detJ*n.z()*(pt.z()-cg[2])*(pt.z()-cg[2])*(pt.z()-cg[2])/3.0;
	inertia[3]  += pts[j].weight*detJ*n.x()*(pt.y()-cg[1])*(pt.x()-cg[0])*(pt.x()-cg[0])/3.0;
	inertia[4]  += pts[j].weight*detJ*n.x()*(pt.z()-cg[2])*(pt.x()-cg[0])*(pt.x()-cg[0])/3.0;
	inertia[5]  += pts[j].weight*detJ*n.y()*(pt.z()-cg[2])*(pt.y()-cg[1])*(pt.y()-cg[1])/3.0;
      }
    }
  }
  return volume;
}

