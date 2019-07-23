// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "MElementCut.h"
#include "GmshMessage.h"
#include "VertexArray.h"
#include "boundaryLayersData.h"
#include "ExtrudeParams.h"
#include "GmshDefines.h"

GRegion::GRegion(GModel *model, int tag) : GEntity(model, tag)
{
  GRegion::resetMeshAttributes();
}

GRegion::~GRegion()
{
  std::vector<GFace *>::iterator it = l_faces.begin();
  while(it != l_faces.end()) {
    (*it)->delRegion(this);
    ++it;
  }
  GRegion::deleteMesh();
}

void GRegion::deleteMesh()
{
  for(std::size_t i = 0; i < mesh_vertices.size(); i++)
    delete mesh_vertices[i];
  mesh_vertices.clear();
  transfinite_vertices.clear();
  for(std::size_t i = 0; i < tetrahedra.size(); i++) delete tetrahedra[i];
  tetrahedra.clear();
  for(std::size_t i = 0; i < hexahedra.size(); i++) delete hexahedra[i];
  hexahedra.clear();
  for(std::size_t i = 0; i < prisms.size(); i++) delete prisms[i];
  prisms.clear();
  for(std::size_t i = 0; i < pyramids.size(); i++) delete pyramids[i];
  pyramids.clear();
  for(std::size_t i = 0; i < trihedra.size(); i++) delete trihedra[i];
  trihedra.clear();
  for(std::size_t i = 0; i < polyhedra.size(); i++) delete polyhedra[i];
  polyhedra.clear();
  deleteVertexArrays();
  model()->destroyMeshCaches();
}

std::size_t GRegion::getNumMeshElements() const
{
  return tetrahedra.size() + hexahedra.size() + prisms.size() +
         pyramids.size() + trihedra.size() + polyhedra.size();
}

std::size_t GRegion::getNumMeshElementsByType(const int familyType) const
{
  if(familyType == TYPE_TET)
    return tetrahedra.size();
  else if(familyType == TYPE_HEX)
    return hexahedra.size();
  else if(familyType == TYPE_PRI)
    return prisms.size();
  else if(familyType == TYPE_PYR)
    return pyramids.size();
  else if(familyType == TYPE_TRIH)
    return trihedra.size();
  else if(familyType == TYPE_POLYH)
    return polyhedra.size();

  return 0;
}

std::size_t GRegion::getNumMeshParentElements()
{
  std::size_t n = 0;
  for(std::size_t i = 0; i < polyhedra.size(); i++)
    if(polyhedra[i]->ownsParent()) n++;
  return n;
}

void GRegion::getNumMeshElements(unsigned *const c) const
{
  c[0] += tetrahedra.size();
  c[1] += hexahedra.size();
  c[2] += prisms.size();
  c[3] += pyramids.size();
  c[4] += trihedra.size();
  c[5] += polyhedra.size();
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
    if(trihedra.empty()) return 0;
    return reinterpret_cast<MElement *const *>(&trihedra[0]);
  case 5:
    if(polyhedra.empty()) return 0;
    return reinterpret_cast<MElement *const *>(&polyhedra[0]);
  }
  return 0;
}

MElement *GRegion::getMeshElement(std::size_t index) const
{
  if(index < tetrahedra.size())
    return tetrahedra[index];
  else if(index < tetrahedra.size() + hexahedra.size())
    return hexahedra[index - tetrahedra.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size())
    return prisms[index - tetrahedra.size() - hexahedra.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size() +
                    pyramids.size())
    return pyramids[index - tetrahedra.size() - hexahedra.size() -
                    prisms.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size() +
                    pyramids.size() + trihedra.size())
    return trihedra[index - tetrahedra.size() - hexahedra.size() -
                    prisms.size() - pyramids.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size() +
                    pyramids.size() + trihedra.size() + polyhedra.size())
    return polyhedra[index - tetrahedra.size() - hexahedra.size() -
                     prisms.size() - pyramids.size() - trihedra.size()];

  return 0;
}

MElement *GRegion::getMeshElementByType(const int familyType,
                                        const std::size_t index) const
{
  if(familyType == TYPE_TET)
    return tetrahedra[index];
  else if(familyType == TYPE_HEX)
    return hexahedra[index];
  else if(familyType == TYPE_PRI)
    return prisms[index];
  else if(familyType == TYPE_PYR)
    return pyramids[index];
  else if(familyType == TYPE_TRIH)
    return trihedra[index];
  else if(familyType == TYPE_POLYH)
    return polyhedra[index];

  return 0;
}

void GRegion::resetMeshAttributes()
{
  meshAttributes.recombine3D = 0;
  meshAttributes.method = MESH_UNSTRUCTURED;
  meshAttributes.extrude = 0;
  meshAttributes.QuadTri = NO_QUADTRI;
}

SBoundingBox3d GRegion::bounds(bool fast) const
{
  SBoundingBox3d res;
  if(geomType() != DiscreteVolume && geomType() != PartitionVolume) {
    std::vector<GFace *>::const_iterator it = l_faces.begin();
    for(; it != l_faces.end(); it++) res += (*it)->bounds(fast);
  }
  else {
    int ipp = getNumMeshElements() / 20;
    if(ipp < 1) ipp = 1;
    for(std::size_t i = 0; i < getNumMeshElements(); i += ipp)
      for(std::size_t j = 0; j < getMeshElement(i)->getNumVertices(); j++)
        res += getMeshElement(i)->getVertex(j)->point();
  }
  return res;
}

SOrientedBoundingBox GRegion::getOBB()
{
  if(!_obb) {
    std::vector<SPoint3> vertices;
    std::vector<GFace *> b_faces = faces();
    for(std::vector<GFace *>::iterator b_face = b_faces.begin();
        b_face != b_faces.end(); b_face++) {
      if((*b_face)->getNumMeshVertices() > 0) {
        int N = (*b_face)->getNumMeshVertices();
        for(int i = 0; i < N; i++) {
          MVertex *mv = (*b_face)->getMeshVertex(i);
          vertices.push_back(mv->point());
        }
        std::vector<GEdge *> eds = (*b_face)->edges();
        for(std::vector<GEdge *>::iterator ed = eds.begin(); ed != eds.end();
            ed++) {
          int N2 = (*ed)->getNumMeshVertices();
          for(int i = 0; i < N2; i++) {
            MVertex *mv = (*ed)->getMeshVertex(i);
            vertices.push_back(mv->point());
          }
          // Don't forget to add the first and last vertices...
          if((*ed)->getBeginVertex()){
            SPoint3 pt1((*ed)->getBeginVertex()->x(),
                        (*ed)->getBeginVertex()->y(),
                        (*ed)->getBeginVertex()->z());
            vertices.push_back(pt1);
          }
          if((*ed)->getEndVertex()){
            SPoint3 pt2((*ed)->getEndVertex()->x(),
                        (*ed)->getEndVertex()->y(),
                        (*ed)->getEndVertex()->z());
            vertices.push_back(pt2);
          }
        }
      }
      else if((*b_face)->buildSTLTriangulation()) {
        vertices = (*b_face)->stl_vertices_xyz;
      }
      else {
        int N = 10;
        std::vector<GEdge *> b_edges = (*b_face)->edges();
        for(std::vector<GEdge *>::iterator b_edge = b_edges.begin();
            b_edge != b_edges.end(); b_edge++) {
          Range<double> tr = (*b_edge)->parBounds(0);
          for(int j = 0; j < N; j++) {
            double t =
              tr.low() + (double)j / (double)(N - 1) * (tr.high() - tr.low());
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
  if(recursive) {
    std::vector<GFace *>::iterator it = l_faces.begin();
    while(it != l_faces.end()) {
      (*it)->setVisibility(val, recursive);
      ++it;
    }
  }
}

void GRegion::setColor(unsigned int val, bool recursive)
{
  GEntity::setColor(val);
  if(recursive) {
    std::vector<GFace *>::iterator it = l_faces.begin();
    while(it != l_faces.end()) {
      (*it)->setColor(val, recursive);
      ++it;
    }
  }
}

int GRegion::delFace(GFace *face)
{
  // TODO C++11 fix the UB if deleting at it == .end()
  std::vector<GFace *>::iterator it;
  int pos = 0;
  for(it = l_faces.begin(); it != l_faces.end(); ++it) {
    if(*it == face) break;
    pos++;
  }
  l_faces.erase(it);

  std::vector<int>::iterator itOri;
  int posOri = 0, orientation = 0;
  for(itOri = l_dirs.begin(); itOri != l_dirs.end(); ++itOri) {
    if(posOri == pos) {
      orientation = *itOri;
      break;
    }
    posOri++;
  }
  l_dirs.erase(itOri);

  return orientation;
}

std::string GRegion::getAdditionalInfoString(bool multline)
{
  std::ostringstream sstream;
  if(l_faces.size()) {
    sstream << "Boundary surfaces: ";
    for(std::vector<GFace *>::iterator it = l_faces.begin();
        it != l_faces.end(); ++it) {
      if(it != l_faces.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }
  if(embedded_faces.size()) {
    sstream << "Embedded surfaces: ";
    for(std::vector<GFace *>::iterator it = embedded_faces.begin();
        it != embedded_faces.end(); ++it) {
      if(it != embedded_faces.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }
  if(embedded_edges.size()) {
    sstream << "Embedded curves: ";
    for(std::vector<GEdge *>::iterator it = embedded_edges.begin();
        it != embedded_edges.end(); ++it) {
      if(it != embedded_edges.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }
  if(embedded_vertices.size()) {
    sstream << "Embedded points: ";
    for(std::vector<GVertex *>::iterator it = embedded_vertices.begin();
        it != embedded_vertices.end(); ++it) {
      if(it != embedded_vertices.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }

  if(meshAttributes.method == MESH_TRANSFINITE ||
     (meshAttributes.extrude && meshAttributes.extrude->mesh.ExtrudeMesh)) {
    sstream << "Mesh attributes:";
    if(meshAttributes.method == MESH_TRANSFINITE) sstream << " transfinite";
    if(meshAttributes.extrude && meshAttributes.extrude->mesh.ExtrudeMesh)
      sstream << " extruded";
  }
  std::string str = sstream.str();
  if(str.size() && (str[str.size() - 1] == '\n' || str[str.size() - 1] == ' '))
    str.resize(str.size() - 1);
  return str;
}

void GRegion::writeGEO(FILE *fp)
{
  if(geomType() == DiscreteVolume) return;

  if(l_faces.size()) {
    fprintf(fp, "Surface Loop(%d) = ", tag());
    for(std::vector<GFace *>::iterator it = l_faces.begin();
        it != l_faces.end(); it++) {
      if(it != l_faces.begin())
        fprintf(fp, ", %d", (*it)->tag());
      else
        fprintf(fp, "{%d", (*it)->tag());
    }
    fprintf(fp, "};\n");
    fprintf(fp, "Volume(%d) = {%d};\n", tag(), tag());
  }

  for(std::vector<GFace *>::iterator it = embedded_faces.begin();
      it != embedded_faces.end(); it++)
    fprintf(fp, "Surface {%d} In Volume {%d};\n", (*it)->tag(), tag());

  for(std::vector<GEdge *>::iterator it = embedded_edges.begin();
      it != embedded_edges.end(); it++)
    fprintf(fp, "Line {%d} In Volume {%d};\n", (*it)->tag(), tag());

  for(std::vector<GVertex *>::iterator it = embedded_vertices.begin();
      it != embedded_vertices.end(); it++)
    fprintf(fp, "Point {%d} In Volume {%d};\n", (*it)->tag(), tag());

  if(meshAttributes.method == MESH_TRANSFINITE) {
    fprintf(fp, "Transfinite Volume {%d}", tag());
    if(meshAttributes.corners.size()) {
      fprintf(fp, " = {");
      for(std::size_t i = 0; i < meshAttributes.corners.size(); i++) {
        if(i) fprintf(fp, ",");
        fprintf(fp, "%d", meshAttributes.corners[i]->tag());
      }
      fprintf(fp, "}");
    }
    fprintf(fp, ";\n");

    if(meshAttributes.QuadTri != NO_QUADTRI)
      fprintf(fp, "TransfQuadTri {%d};\n", tag());
  }
}

std::vector<GEdge *> const &GRegion::edges() const
{
  // TODO C++11 clean this up
  static std::vector<GEdge *> e;
  e.clear();
  std::vector<GFace *>::const_iterator it = l_faces.begin();
  while(it != l_faces.end()) {
    std::vector<GEdge *> const &e2 = (*it)->edges();
    std::vector<GEdge *>::const_iterator it2 = e2.begin();
    while(it2 != e2.end()) {
      GEdge *const edge = *it2;
      if(std::find(e.begin(), e.end(), edge) == e.end()) e.push_back(edge);
      ++it2;
    }
    ++it;
  }
  return e;
}

bool GRegion::edgeConnected(GRegion *r) const
{
  std::vector<GEdge *> e = edges(), e2 = r->edges();

  std::vector<GEdge *>::const_iterator it = e.begin();
  while(it != e.end()) {
    if(std::find(e2.begin(), e2.end(), *it) != e2.end()) return true;
    ++it;
  }
  return false;
}

double GRegion::computeSolidProperties(std::vector<double> cg,
                                       std::vector<double> inertia)
{
  std::vector<GFace *>::iterator it = l_faces.begin();
  std::vector<int>::iterator itdir = l_dirs.begin();
  double volumex = 0;
  double volumey = 0;
  double volumez = 0;
  double surface = 0;
  cg[0] = cg[1] = cg[2] = 0.0;
  for(; it != l_faces.end(); ++it, ++itdir) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); ++i) {
      MTriangle *e = (*it)->triangles[i];
      int npt;
      IntPt *pts;
      e->getIntegrationPoints(2 * (e->getPolynomialOrder() - 1) + 3, &npt,
                              &pts);
      for(int j = 0; j < npt; j++) {
        SPoint3 pt;
        // compute x,y,z of the integration point
        e->pnt(pts[j].pt[0], pts[j].pt[1], pts[j].pt[2], pt);
        double jac[3][3];
        // compute normal
        double detJ =
          e->getJacobian(pts[j].pt[0], pts[j].pt[1], pts[j].pt[2], jac);
        SVector3 n(jac[2][0], jac[2][1], jac[2][2]);
        n.normalize();
        n *= (double)*itdir;
        surface += detJ * pts[j].weight;
        volumex += detJ * n.x() * pt.x() * pts[j].weight;
        volumey += detJ * n.y() * pt.y() * pts[j].weight;
        volumez += detJ * n.z() * pt.z() * pts[j].weight;
        cg[0] += detJ * n.x() * (pt.x() * pt.x()) * pts[j].weight * 0.5;
        cg[1] += detJ * n.y() * (pt.y() * pt.y()) * pts[j].weight * 0.5;
        cg[2] += detJ * n.z() * (pt.z() * pt.z()) * pts[j].weight * 0.5;
      }
    }
  }

  printf("%g -- %g %g %g\n", surface, volumex, volumey, volumez);

  double volume = volumex;

  cg[0] /= volume;
  cg[1] /= volume;
  cg[2] /= volume;

  it = l_faces.begin();
  itdir = l_dirs.begin();
  inertia[0] = inertia[1] = inertia[2] = inertia[3] = inertia[4] = inertia[5] =
    0.0;

  for(; it != l_faces.end(); ++it, ++itdir) {
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); ++i) {
      MElement *e = (*it)->getMeshElement(i);
      int npt;
      IntPt *pts;
      e->getIntegrationPoints(2 * (e->getPolynomialOrder() - 1) + 3, &npt,
                              &pts);
      for(int j = 0; j < npt; j++) {
        SPoint3 pt;
        // compute x,y,z of the integration point
        e->pnt(pts[j].pt[0], pts[j].pt[1], pts[j].pt[2], pt);
        double jac[3][3];
        // compute normal
        double detJ =
          e->getJacobian(pts[j].pt[0], pts[j].pt[1], pts[j].pt[2], jac);
        SVector3 n(jac[2][0], jac[2][1], jac[2][2]);
        n *= (double)*itdir;
        inertia[0] += pts[j].weight * detJ * n.x() * (pt.x() - cg[0]) *
                      (pt.x() - cg[0]) * (pt.x() - cg[0]) / 3.0;
        inertia[1] += pts[j].weight * detJ * n.y() * (pt.y() - cg[1]) *
                      (pt.y() - cg[1]) * (pt.y() - cg[1]) / 3.0;
        inertia[2] += pts[j].weight * detJ * n.z() * (pt.z() - cg[2]) *
                      (pt.z() - cg[2]) * (pt.z() - cg[2]) / 3.0;
        inertia[3] += pts[j].weight * detJ * n.x() * (pt.y() - cg[1]) *
                      (pt.x() - cg[0]) * (pt.x() - cg[0]) / 3.0;
        inertia[4] += pts[j].weight * detJ * n.x() * (pt.z() - cg[2]) *
                      (pt.x() - cg[0]) * (pt.x() - cg[0]) / 3.0;
        inertia[5] += pts[j].weight * detJ * n.y() * (pt.z() - cg[2]) *
                      (pt.y() - cg[1]) * (pt.y() - cg[1]) / 3.0;
      }
    }
  }
  return volume;
}

std::vector<GVertex *> GRegion::vertices() const
{
  std::set<GVertex *> v;
  for(std::vector<GFace *>::const_iterator it = l_faces.begin();
      it != l_faces.end(); ++it) {
    GFace const *const gf = *it;
    std::vector<GVertex *> const &vs = gf->vertices();
    v.insert(vs.begin(), vs.end());
  }
  return std::vector<GVertex *>(v.begin(), v.end());
}

void GRegion::addElement(int type, MElement *e)
{
  switch(type) {
  case TYPE_TET: addTetrahedron(reinterpret_cast<MTetrahedron *>(e)); break;
  case TYPE_HEX: addHexahedron(reinterpret_cast<MHexahedron *>(e)); break;
  case TYPE_PRI: addPrism(reinterpret_cast<MPrism *>(e)); break;
  case TYPE_PYR: addPyramid(reinterpret_cast<MPyramid *>(e)); break;
  case TYPE_TRIH: addTrihedron(reinterpret_cast<MTrihedron *>(e)); break;
  case TYPE_POLYH: addPolyhedron(reinterpret_cast<MPolyhedron *>(e)); break;
  default: Msg::Error("Trying to add unsupported element in region");
  }
}

void GRegion::removeElement(int type, MElement *e)
{
  switch(type) {
  case TYPE_TET: {
    std::vector<MTetrahedron *>::iterator it =
      std::find(tetrahedra.begin(), tetrahedra.end(),
                reinterpret_cast<MTetrahedron *>(e));
    if(it != tetrahedra.end()) tetrahedra.erase(it);
  } break;
  case TYPE_HEX: {
    std::vector<MHexahedron *>::iterator it = std::find(
      hexahedra.begin(), hexahedra.end(), reinterpret_cast<MHexahedron *>(e));
    if(it != hexahedra.end()) hexahedra.erase(it);
  } break;
  case TYPE_PRI: {
    std::vector<MPrism *>::iterator it =
      std::find(prisms.begin(), prisms.end(), reinterpret_cast<MPrism *>(e));
    if(it != prisms.end()) prisms.erase(it);
  } break;
  case TYPE_PYR: {
    std::vector<MPyramid *>::iterator it = std::find(
      pyramids.begin(), pyramids.end(), reinterpret_cast<MPyramid *>(e));
    if(it != pyramids.end()) pyramids.erase(it);
  } break;
  case TYPE_TRIH: {
    std::vector<MTrihedron *>::iterator it = std::find(
      trihedra.begin(), trihedra.end(), reinterpret_cast<MTrihedron *>(e));
    if(it != trihedra.end()) trihedra.erase(it);
  } break;
  case TYPE_POLYH: {
    std::vector<MPolyhedron *>::iterator it = std::find(
      polyhedra.begin(), polyhedra.end(), reinterpret_cast<MPolyhedron *>(e));
    if(it != polyhedra.end()) polyhedra.erase(it);
  } break;
  default: Msg::Error("Trying to remove unsupported element in region");
  }
}

bool GRegion::reorder(const int elementType, const std::vector<std::size_t> &ordering)
{
  if(tetrahedra.size() != 0) {
    if(tetrahedra.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != tetrahedra.size()) return false;

      for(std::vector<std::size_t>::const_iterator it = ordering.begin();
          it != ordering.end(); ++it) {
        if(*it >= tetrahedra.size()) return false;
      }

      std::vector<MTetrahedron *> newTetrahedraOrder(tetrahedra.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newTetrahedraOrder[i] = tetrahedra[ordering[i]];
      }
#if __cplusplus >= 201103L
      tetrahedra = std::move(newTetrahedraOrder);
#else
      tetrahedra = newTetrahedraOrder;
#endif

      return true;
    }
  }

  if(hexahedra.size() != 0) {
    if(hexahedra.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != hexahedra.size()) return false;

      for(std::vector<std::size_t>::const_iterator it = ordering.begin();
          it != ordering.end(); ++it) {
        if(*it >= hexahedra.size()) return false;
      }

      std::vector<MHexahedron *> newHexahedraOrder(hexahedra.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newHexahedraOrder[i] = hexahedra[ordering[i]];
      }
#if __cplusplus >= 201103L
      hexahedra = std::move(newHexahedraOrder);
#else
      hexahedra = newHexahedraOrder;
#endif

      return true;
    }
  }

  if(prisms.size() != 0) {
    if(prisms.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != prisms.size()) return false;

      for(std::vector<std::size_t>::const_iterator it = ordering.begin();
          it != ordering.end(); ++it) {
        if(*it >= prisms.size()) return false;
      }

      std::vector<MPrism *> newPrismsOrder(prisms.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newPrismsOrder[i] = prisms[ordering[i]];
      }
#if __cplusplus >= 201103L
      prisms = std::move(newPrismsOrder);
#else
      prisms = newPrismsOrder;
#endif

      return true;
    }
  }

  if(pyramids.size() != 0) {
    if(pyramids.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != pyramids.size()) return false;

      for(std::vector<std::size_t>::const_iterator it = ordering.begin();
          it != ordering.end(); ++it) {
        if(*it >= pyramids.size()) return false;
      }

      std::vector<MPyramid *> newPyramidsOrder(pyramids.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newPyramidsOrder[i] = pyramids[ordering[i]];
      }
#if __cplusplus >= 201103L
      pyramids = std::move(newPyramidsOrder);
#else
      pyramids = newPyramidsOrder;
#endif

      return true;
    }
  }

  if(polyhedra.size() != 0) {
    if(polyhedra.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != polyhedra.size()) return false;

      for(std::vector<std::size_t>::const_iterator it = ordering.begin();
          it != ordering.end(); ++it) {
        if(*it >= polyhedra.size()) return false;
      }

      std::vector<MPolyhedron *> newPolyhedraOrder(polyhedra.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newPolyhedraOrder[i] = polyhedra[ordering[i]];
      }
#if __cplusplus >= 201103L
      polyhedra = std::move(newPolyhedraOrder);
#else
      polyhedra = newPolyhedraOrder;
#endif

      return true;
    }
  }

  if(trihedra.size() != 0) {
    if(trihedra.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != trihedra.size()) return false;

      for(std::vector<std::size_t>::const_iterator it = ordering.begin();
          it != ordering.end(); ++it) {
        if(*it >= trihedra.size()) return false;
      }

      std::vector<MTrihedron *> newTrihedraOrder(trihedra.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newTrihedraOrder[i] = trihedra[ordering[i]];
      }
#if __cplusplus >= 201103L
      trihedra = std::move(newTrihedraOrder);
#else
      trihedra = newTrihedraOrder;
#endif

      return true;
    }
  }

  return false;
}

static void setRand(double r[6])
{
  for(int i = 0; i < 6; i++)
    r[i] = 0.0001 * ((double)rand() / (double)RAND_MAX);
}

// X_1 (1-u-v) + X_2 u + X_3 v = P_x + t N_x
// Y_1 (1-u-v) + Y_2 u + Y_3 v = P_y + t N_y
// Z_1 (1-u-v) + Z_2 u + Z_3 v = P_z + t N_z

static int intersectLineTriangle(double X[3], double Y[3], double Z[3],
                                 double P[3], double N[3],
                                 const double eps_prec)
{
  double mat[3][3], det;
  double b[3], res[3];

  mat[0][0] = X[1] - X[0];
  mat[0][1] = X[2] - X[0];
  mat[0][2] = N[0];

  mat[1][0] = Y[1] - Y[0];
  mat[1][1] = Y[2] - Y[0];
  mat[1][2] = N[1];

  mat[2][0] = Z[1] - Z[0];
  mat[2][1] = Z[2] - Z[0];
  mat[2][2] = N[2];

  b[0] = P[0] - X[0];
  b[1] = P[1] - Y[0];
  b[2] = P[2] - Z[0];

  if(!sys3x3_with_tol(mat, b, res, &det)) { return 0; }
  if(res[0] >= eps_prec && res[0] <= 1.0 - eps_prec && res[1] >= eps_prec &&
     res[1] <= 1.0 - eps_prec && 1 - res[0] - res[1] >= eps_prec &&
     1 - res[0] - res[1] <= 1.0 - eps_prec) {
    // the line clearly intersects the triangle
    return (res[2] > 0) ? 1 : 0;
  }
  else if(res[0] < -eps_prec || res[0] > 1.0 + eps_prec || res[1] < -eps_prec ||
          res[1] > 1.0 + eps_prec || 1 - res[0] - res[1] < -eps_prec ||
          1 - res[0] - res[1] > 1.0 + eps_prec) {
    // the line clearly does NOT intersect the triangle
    return 0;
  }
  else {
    // the intersection is not robust, try another triangle
    return -10000;
  }
}

bool GRegion::setOutwardOrientationMeshConstraint()
{
  // perform intersection check in normalized coordinates
  SBoundingBox3d bbox = bounds();
  double scaling = norm(SVector3(bbox.max(), bbox.min()));
  if(!scaling) {
    Msg::Warning("Bad scaling in GRegion::setOutwardOrientationMeshConstraint");
    scaling = 1.;
  }
  double rrr[6];
  setRand(rrr);

  std::vector<GFace *> f = faces();
  std::vector<GFace *>::iterator it = f.begin();
  while(it != f.end()) {
    GFace *gf = (*it);
    gf->buildSTLTriangulation();
    if(gf->stl_triangles.size() < 3) {
      Msg::Error("No valid STL triangulation found for surface %d", gf->tag());
      return false;
    }
    int nb_intersect = 0;
    for(std::size_t i = 0; i < gf->stl_triangles.size(); i += 3) {
      SPoint3 p1 = gf->stl_vertices_xyz[gf->stl_triangles[i]];
      SPoint3 p2 = gf->stl_vertices_xyz[gf->stl_triangles[i + 1]];
      SPoint3 p3 = gf->stl_vertices_xyz[gf->stl_triangles[i + 2]];
      double X[3] = {p1.x(), p2.x(), p3.x()};
      double Y[3] = {p1.y(), p2.y(), p3.y()};
      double Z[3] = {p1.z(), p2.z(), p3.z()};
      for(int j = 0; j < 3; j++) {
        X[j] /= scaling;
        Y[j] /= scaling;
        Z[j] /= scaling;
      }
      double P[3] = {(X[0] + X[1] + X[2]) / 3., (Y[0] + Y[1] + Y[2]) / 3.,
                     (Z[0] + Z[1] + Z[2]) / 3.};
      double v1[3] = {X[0] - X[1], Y[0] - Y[1], Z[0] - Z[1]};
      double v2[3] = {X[2] - X[1], Y[2] - Y[1], Z[2] - Z[1]};
      double N[3];
      prodve(v1, v2, N);
      norme(v1);
      norme(v2);
      norme(N);
      N[0] += rrr[0] * v1[0] + rrr[1] * v2[0];
      N[1] += rrr[2] * v1[1] + rrr[3] * v2[1];
      N[2] += rrr[4] * v1[2] + rrr[5] * v2[2];
      norme(N);
      std::vector<GFace *>::iterator it_b = f.begin();
      while(it_b != f.end()) {
        GFace *gf_b = (*it_b);
        gf_b->buildSTLTriangulation();
        if(gf_b->stl_triangles.size() < 3) {
          Msg::Error("No valid STL triangulation found for surface %d",
                     gf_b->tag());
          return false;
        }
        for(std::size_t i_b = 0; i_b < gf_b->stl_triangles.size(); i_b += 3) {
          SPoint3 p1 = gf_b->stl_vertices_xyz[gf_b->stl_triangles[i_b]];
          SPoint3 p2 = gf_b->stl_vertices_xyz[gf_b->stl_triangles[i_b + 1]];
          SPoint3 p3 = gf_b->stl_vertices_xyz[gf_b->stl_triangles[i_b + 2]];
          double X_b[3] = {p1.x(), p2.x(), p3.x()};
          double Y_b[3] = {p1.y(), p2.y(), p3.y()};
          double Z_b[3] = {p1.z(), p2.z(), p3.z()};
          for(int j = 0; j < 3; j++) {
            X_b[j] /= scaling;
            Y_b[j] /= scaling;
            Z_b[j] /= scaling;
          }
          if(!(std::abs(X[0] - X_b[0]) < 1e-12 &&
               std::abs(X[1] - X_b[1]) < 1e-12 &&
               std::abs(X[2] - X_b[2]) < 1e-12 &&
               std::abs(Y[0] - Y_b[0]) < 1e-12 &&
               std::abs(Y[1] - Y_b[1]) < 1e-12 &&
               std::abs(Y[2] - Y_b[2]) < 1e-12 &&
               std::abs(Z[0] - Z_b[0]) < 1e-12 &&
               std::abs(Z[1] - Z_b[1]) < 1e-12 &&
               std::abs(Z[2] - Z_b[2]) < 1e-12)) {
            int inters = intersectLineTriangle(X_b, Y_b, Z_b, P, N, 1.e-9);
            nb_intersect += inters;
          }
        }
        ++it_b;
      }
      Msg::Info("Region %d Face %d, %d intersect", tag(), gf->tag(),
                nb_intersect);
      if(nb_intersect >= 0)
        break; // negative value means intersection is not "robust"
    }

    if(nb_intersect < 0) { setRand(rrr); }
    else {
      if(nb_intersect % 2 == 1) {
        // odd nb of intersections: the normal points inside the region
        gf->meshAttributes.reverseMesh = true;
        Msg::Info("Setting reverse mesh attribute on surface %d", gf->tag());
      }
      ++it;
    }
  }

  return true;
}
