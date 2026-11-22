// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include <sstream>
#include "GmshConfig.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "MPolyhedron.h"
#include "GmshMessage.h"
#include "VertexArray.h"
#include "boundaryLayersData.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "ExtrudeParams.h"
#include "GmshDefines.h"

#if defined(HAVE_MESH)
#include "meshGFace.h"
#endif

GRegion::GRegion(GModel *model, int tag) : GEntity(model, tag)
{
  GRegion::resetMeshAttributes();
}

GRegion::~GRegion()
{
  for(auto gf : l_faces) gf->delRegion(this);
  GRegion::deleteMesh();
}

void GRegion::deleteMesh()
{
  if(getNumMeshVertices() || getNumMeshElements())
    model()->destroyMeshCaches();
  for(std::size_t i = 0; i < mesh_vertices.size(); i++) delete mesh_vertices[i];
  mesh_vertices.clear();
  transfinite_vertices.clear();
  removeElements(true);
  deleteVertexArrays();
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
    if(tetrahedra.empty()) return nullptr; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&tetrahedra[0]);
  case 1:
    if(hexahedra.empty()) return nullptr; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&hexahedra[0]);
  case 2:
    if(prisms.empty()) return nullptr; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&prisms[0]);
  case 3:
    if(pyramids.empty()) return nullptr; // msvc would throw an exception
    return reinterpret_cast<MElement *const *>(&pyramids[0]);
  case 4:
    if(trihedra.empty()) return nullptr;
    return reinterpret_cast<MElement *const *>(&trihedra[0]);
  case 5:
    if(polyhedra.empty()) return nullptr;
    return reinterpret_cast<MElement *const *>(&polyhedra[0]);
  }
  return nullptr;
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

  return nullptr;
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

  return nullptr;
}

void GRegion::resetMeshAttributes()
{
  meshAttributes.recombine3D = 0;
  meshAttributes.method = MESH_UNSTRUCTURED;
  meshAttributes.extrude = nullptr;
  meshAttributes.QuadTri = NO_QUADTRI;
  meshAttributes.meshSize = MAX_LC;
  meshAttributes.outwardOrientation = false;
}

SBoundingBox3d GRegion::bounds(bool fast)
{
  SBoundingBox3d res;
  if(geomType() != DiscreteVolume && geomType() != PartitionVolume) {
    for(auto gf : l_faces)
      res += gf->bounds(fast);
  }
  else {
    for(std::size_t i = 0; i < getNumMeshElements(); i++)
      for(std::size_t j = 0; j < getMeshElement(i)->getNumVertices(); j++)
        res += getMeshElement(i)->getVertex(j)->point();
    // (not meshed yet, e.g. a volume of the discrete CAD modeler: the bounds
    // of its surfaces)
    if(res.empty())
      for(auto gf : l_faces) res += gf->bounds(fast);
  }
  return res;
}

SOrientedBoundingBox GRegion::getOBB()
{
  if(!_obb) {
    std::vector<SPoint3> vertices;
    std::vector<GFace *> b_faces = faces();
    for(auto b_face = b_faces.begin(); b_face != b_faces.end(); b_face++) {
      if((*b_face)->getNumMeshVertices() > 0) {
        int N = (*b_face)->getNumMeshVertices();
        for(int i = 0; i < N; i++) {
          MVertex *mv = (*b_face)->getMeshVertex(i);
          vertices.push_back(mv->point());
        }
        std::vector<GEdge *> eds = (*b_face)->edges();
        for(auto ed = eds.begin(); ed != eds.end(); ed++) {
          int N2 = (*ed)->getNumMeshVertices();
          for(int i = 0; i < N2; i++) {
            MVertex *mv = (*ed)->getMeshVertex(i);
            vertices.push_back(mv->point());
          }
          // Don't forget to add the first and last vertices...
          if((*ed)->getBeginVertex()) {
            SPoint3 pt1((*ed)->getBeginVertex()->x(),
                        (*ed)->getBeginVertex()->y(),
                        (*ed)->getBeginVertex()->z());
            vertices.push_back(pt1);
          }
          if((*ed)->getEndVertex()) {
            SPoint3 pt2((*ed)->getEndVertex()->x(), (*ed)->getEndVertex()->y(),
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
        for(auto b_edge = b_edges.begin(); b_edge != b_edges.end(); b_edge++) {
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
    for(auto f : l_faces) f->setVisibility(val, recursive);
    for(auto f : embedded_faces) f->setVisibility(val, recursive);
    for(auto e : embedded_edges) e->setVisibility(val, recursive);
    for(auto v : embedded_vertices) v->setVisibility(val);
  }
}

void GRegion::setColor(unsigned int val, bool recursive)
{
  GEntity::setColor(val);
  if(recursive) {
    for(auto f : l_faces) f->setColor(val, recursive);
    for(auto f : embedded_faces) f->setColor(val, recursive);
    for(auto e : embedded_edges) e->setColor(val, recursive);
    for(auto v : embedded_vertices) v->setColor(val);
  }
}

int GRegion::delFace(GFace *face)
{
  const auto found = std::find(l_faces.begin(), l_faces.end(), face);
  if(found == l_faces.end()) return 0;

  const std::size_t pos = std::distance(l_faces.begin(), found);
  l_faces.erase(found);
  if(pos >= l_dirs.size()) return 0;

  const int orientation = l_dirs[pos];
  l_dirs.erase(l_dirs.begin() + pos);
  return orientation;
}

std::vector<GEntity *> GRegion::boundaryEntities() const
{
  return std::vector<GEntity *>(l_faces.begin(), l_faces.end());
}

// Whether the surface is already used with this sign: a surface can be used
// twice, with opposite signs
void GRegion::setBoundFaces(const std::set<int> &tagFaces)
{
  for(auto it = tagFaces.begin(); it != tagFaces.end(); ++it) {
    GFace *gf = model()->getFaceByTag(*it);
    if(gf) {
      if(std::find(l_faces.begin(), l_faces.end(), gf) == l_faces.end()) {
        l_faces.push_back(gf);
        gf->addRegion(this);
      }
    }
    else {
      Msg::Error("Unknown surface %d in volume %d", *it, tag());
    }
  }
}

void GRegion::setBoundFaces(const std::vector<int> &tagFaces,
                            const std::vector<int> &signFaces)
{
  if(tagFaces.size() != signFaces.size()) {
    Msg::Error("Wrong number of surface signs in volume %d", tag());
    std::set<int> tags;
    tags.insert(tagFaces.begin(), tagFaces.end());
    setBoundFaces(tags);
    return;
  }
  std::vector<GFace *> faces;
  std::vector<int> signs;
  for(std::size_t i = 0; i < tagFaces.size(); i++) {
    GFace *gf = model()->getFaceByTag(tagFaces[i]);
    if(gf) {
      faces.push_back(gf);
      signs.push_back(signFaces[i]);
    }
    else {
      Msg::Error("Unknown surface %d in volume %d", tagFaces[i], tag());
    }
  }
  setBoundFaces(faces, signs);
}

void GRegion::setBoundFaces(const std::vector<GFace *> &faces,
                            const std::vector<int> &signFaces)
{
  // a volume can be bounded by tens of thousands of surfaces (e.g. in a
  // discrete model): looking for each new surface in the list of the ones
  // already there would take a time quadratic in their number
  std::set<std::pair<GFace *, int> > known;
  for(std::size_t i = 0; i < l_faces.size(); i++)
    known.insert(std::make_pair(l_faces[i], i < l_dirs.size() ? l_dirs[i] : 1));
  for(std::size_t i = 0; i < faces.size(); i++) {
    GFace *gf = faces[i];
    const int sign = i < signFaces.size() ? signFaces[i] : 1;
    if(!known.insert(std::make_pair(gf, sign)).second) continue;
    l_faces.push_back(gf);
    gf->addRegion(this);
    l_dirs.push_back(sign);
  }
}

std::string GRegion::getAdditionalInfoString(bool multline)
{
  std::ostringstream sstream;
  if(l_faces.size()) {
    sstream << "Boundary surfaces: ";
    for(auto it = l_faces.begin(); it != l_faces.end(); ++it) {
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
    for(auto it = embedded_faces.begin(); it != embedded_faces.end(); ++it) {
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
    for(auto it = embedded_edges.begin(); it != embedded_edges.end(); ++it) {
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
    for(auto it = embedded_vertices.begin(); it != embedded_vertices.end();
        ++it) {
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
    for(auto it = l_faces.begin(); it != l_faces.end(); it++) {
      if(it != l_faces.begin())
        fprintf(fp, ", %d", (*it)->tag());
      else
        fprintf(fp, "{%d", (*it)->tag());
    }
    fprintf(fp, "};\n");
    fprintf(fp, "Volume(%d) = {%d};\n", tag(), tag());
  }

  for(auto it = embedded_faces.begin(); it != embedded_faces.end(); it++)
    fprintf(fp, "Surface {%d} In Volume {%d};\n", (*it)->tag(), tag());

  for(auto it = embedded_edges.begin(); it != embedded_edges.end(); it++)
    fprintf(fp, "Line {%d} In Volume {%d};\n", (*it)->tag(), tag());

  for(auto it = embedded_vertices.begin(); it != embedded_vertices.end(); it++)
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

void GRegion::writePY(FILE *fp)
{
  // This is by no means complete - merely a placeholder for a future
  // implementation

  if(geomType() == DiscreteVolume) return;

  const char *factory = getNativeType() == OpenCascadeModel ? "occ" : "geo";

  if(l_faces.size()) {
    fprintf(fp, "gmsh.model.%s.addSurfaceLoop([", factory);
    for(auto it = l_faces.begin(); it != l_faces.end(); it++) {
      if(it != l_faces.begin()) fprintf(fp, ", ");
      fprintf(fp, "%d", (*it)->tag());
    }
    fprintf(fp, "], %d)\n", tag());
    fprintf(fp, "gmsh.model.%s.addVolume(%d, %d)\n", factory, tag(), tag());
  }
}

std::vector<GEdge *> const &GRegion::edges() const
{
  static std::vector<GEdge *> e;
  e.clear();

  for(auto *const face : l_faces) {
    for(auto *const edge : face->edges()) {
      if(std::find(e.begin(), e.end(), edge) == e.end()) { e.push_back(edge); }
    }
  }
  return e;
}

bool GRegion::edgeConnected(GRegion *r) const
{
  std::vector<GEdge *> e = edges(), e2 = r->edges();

  auto it = e.begin();
  while(it != e.end()) {
    if(std::find(e2.begin(), e2.end(), *it) != e2.end()) return true;
    ++it;
  }
  return false;
}

double GRegion::computeSolidProperties(std::vector<double> cg,
                                       std::vector<double> inertia)
{
  auto it = l_faces.begin();
  auto itdir = l_dirs.begin();
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

std::vector<MVertex *> GRegion::getEmbeddedMeshVertices() const
{
  std::set<MVertex *> tmp;
  for(auto it = embedded_faces.begin(); it != embedded_faces.end(); it++) {
    tmp.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
    std::vector<GEdge *> ed = (*it)->edges();
    for(auto it2 = ed.begin(); it2 != ed.end(); it2++) {
      tmp.insert((*it2)->mesh_vertices.begin(), (*it2)->mesh_vertices.end());
      if((*it2)->getBeginVertex())
        tmp.insert((*it2)->getBeginVertex()->mesh_vertices.begin(),
                   (*it2)->getBeginVertex()->mesh_vertices.end());
      if((*it2)->getEndVertex())
        tmp.insert((*it2)->getEndVertex()->mesh_vertices.begin(),
                   (*it2)->getEndVertex()->mesh_vertices.end());
    }
  }
  for(auto it = embedded_edges.begin(); it != embedded_edges.end(); it++) {
    tmp.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
    if((*it)->getBeginVertex())
      tmp.insert((*it)->getBeginVertex()->mesh_vertices.begin(),
                 (*it)->getBeginVertex()->mesh_vertices.end());
    if((*it)->getEndVertex())
      tmp.insert((*it)->getEndVertex()->mesh_vertices.begin(),
                 (*it)->getEndVertex()->mesh_vertices.end());
  }
  for(auto it = embedded_vertices.begin(); it != embedded_vertices.end();
      it++) {
    tmp.insert((*it)->mesh_vertices.begin(), (*it)->mesh_vertices.end());
  }
  return std::vector<MVertex *>(tmp.begin(), tmp.end());
}

std::vector<GVertex *> GRegion::vertices() const
{
  std::set<GVertex *, GEntityPtrLessThan> v;
  for(auto gf : l_faces) {
    std::vector<GVertex *> const &vs = gf->vertices();
    v.insert(vs.begin(), vs.end());
  }
  return std::vector<GVertex *>(v.begin(), v.end());
}

void GRegion::addElement(MElement *e)
{
  switch(e->getType()) {
  case TYPE_TET: addTetrahedron(reinterpret_cast<MTetrahedron *>(e)); break;
  case TYPE_HEX: addHexahedron(reinterpret_cast<MHexahedron *>(e)); break;
  case TYPE_PRI: addPrism(reinterpret_cast<MPrism *>(e)); break;
  case TYPE_PYR: addPyramid(reinterpret_cast<MPyramid *>(e)); break;
  case TYPE_TRIH: addTrihedron(reinterpret_cast<MTrihedron *>(e)); break;
  case TYPE_POLYH: addPolyhedron(reinterpret_cast<MPolyhedron *>(e)); break;
  default:
    Msg::Error("Trying to add unsupported element in volume %d", tag());
  }
}

void GRegion::removeElement(MElement *e, bool del)
{
  switch(e->getType()) {
  case TYPE_TET: {
    auto it = std::find(tetrahedra.begin(), tetrahedra.end(),
                        reinterpret_cast<MTetrahedron *>(e));
    if(it != tetrahedra.end()) {
      tetrahedra.erase(it);
      if(del) delete e;
    }
  } break;
  case TYPE_HEX: {
    auto it = std::find(hexahedra.begin(), hexahedra.end(),
                        reinterpret_cast<MHexahedron *>(e));
    if(it != hexahedra.end()) {
      hexahedra.erase(it);
      if(del) delete e;
    }
  } break;
  case TYPE_PRI: {
    auto it =
      std::find(prisms.begin(), prisms.end(), reinterpret_cast<MPrism *>(e));
    if(it != prisms.end()) {
      prisms.erase(it);
      if(del) delete e;
    }
  } break;
  case TYPE_PYR: {
    auto it = std::find(pyramids.begin(), pyramids.end(),
                        reinterpret_cast<MPyramid *>(e));
    if(it != pyramids.end()) {
      pyramids.erase(it);
      if(del) delete e;
    }
  } break;
  case TYPE_TRIH: {
    auto it = std::find(trihedra.begin(), trihedra.end(),
                        reinterpret_cast<MTrihedron *>(e));
    if(it != trihedra.end()) {
      trihedra.erase(it);
      if(del) delete e;
    }
  } break;
  case TYPE_POLYH: {
    auto it = std::find(polyhedra.begin(), polyhedra.end(),
                        reinterpret_cast<MPolyhedron *>(e));
    if(it != polyhedra.end()) {
      polyhedra.erase(it);
      if(del) delete e;
    }
  } break;
  default:
    Msg::Error("Trying to remove unsupported element in volume %d", tag());
  }
}

void GRegion::removeElements(bool del)
{
  if(del) {
    for(auto e : tetrahedra) delete e;
    for(auto e : hexahedra) delete e;
    for(auto e : prisms) delete e;
    for(auto e : pyramids) delete e;
    for(auto e : trihedra) delete e;
    for(auto e : polyhedra) delete e;
  }
  tetrahedra.clear();
  hexahedra.clear();
  prisms.clear();
  pyramids.clear();
  trihedra.clear();
  polyhedra.clear();
}

bool GRegion::reorder(const int elementType,
                      const std::vector<std::size_t> &ordering)
{
  if(tetrahedra.size() != 0) {
    if(tetrahedra.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != tetrahedra.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= tetrahedra.size()) return false;
      }

      std::vector<MTetrahedron *> newTetrahedraOrder(tetrahedra.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newTetrahedraOrder[i] = tetrahedra[ordering[i]];
      }
      tetrahedra = std::move(newTetrahedraOrder);
      return true;
    }
  }

  if(hexahedra.size() != 0) {
    if(hexahedra.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != hexahedra.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= hexahedra.size()) return false;
      }

      std::vector<MHexahedron *> newHexahedraOrder(hexahedra.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newHexahedraOrder[i] = hexahedra[ordering[i]];
      }
      hexahedra = std::move(newHexahedraOrder);
      return true;
    }
  }

  if(prisms.size() != 0) {
    if(prisms.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != prisms.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= prisms.size()) return false;
      }

      std::vector<MPrism *> newPrismsOrder(prisms.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newPrismsOrder[i] = prisms[ordering[i]];
      }
      prisms = std::move(newPrismsOrder);
      return true;
    }
  }

  if(pyramids.size() != 0) {
    if(pyramids.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != pyramids.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= pyramids.size()) return false;
      }

      std::vector<MPyramid *> newPyramidsOrder(pyramids.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newPyramidsOrder[i] = pyramids[ordering[i]];
      }
      pyramids = std::move(newPyramidsOrder);
      return true;
    }
  }

  if(polyhedra.size() != 0) {
    if(polyhedra.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != polyhedra.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= polyhedra.size()) return false;
      }

      std::vector<MPolyhedron *> newPolyhedraOrder(polyhedra.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newPolyhedraOrder[i] = polyhedra[ordering[i]];
      }
      polyhedra = std::move(newPolyhedraOrder);
      return true;
    }
  }

  if(trihedra.size() != 0) {
    if(trihedra.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != trihedra.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= trihedra.size()) return false;
      }

      std::vector<MTrihedron *> newTrihedraOrder(trihedra.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newTrihedraOrder[i] = trihedra[ordering[i]];
      }
      trihedra = std::move(newTrihedraOrder);
      return true;
    }
  }

  return false;
}

bool GRegion::setOutwardOrientationMeshConstraint()
{
  meshAttributes.outwardOrientation = true;
  // if the surfaces are meshed, reorient their meshes now; otherwise this is
  // done once they are
  return orientSurfaceMeshesOutwards();
}

// Orient the meshes of the surfaces bounding the volume so that their normals
// point out of it, for any CAD kernel (the boundary signs of a volume of the
// built-in kernel are those given by the user). Two surfaces sharing a curve
// are consistently oriented if their mesh edges along the curve are traversed
// in opposite directions; the orientation of each set of surfaces connected in
// this way (a shell) is then given by the sign of the volume it encloses,
// positive for the outer shell (the one enclosing the largest volume) and
// negative for the shells around cavities.
bool GRegion::orientSurfaceMeshesOutwards()
{
  std::vector<GFace *> f;
  std::set<GFace *> seen;
  for(auto gf : faces()) {
    if(!seen.insert(gf).second) continue; // on both sides of the volume
    if(!gf->getNumMeshElements()) return false;
    f.push_back(gf);
  }
  if(f.empty()) return false;

  // the mesh edges on the bounding curves, with the surfaces they are in and
  // their direction there
  std::map<std::pair<std::size_t, std::size_t>,
           std::vector<std::pair<int, int>>>
    edges;
  std::vector<double> flux(f.size(), 0.);
  for(std::size_t i = 0; i < f.size(); i++) {
    for(std::size_t k = 0; k < f[i]->getNumMeshElements(); k++) {
      MElement *e = f[i]->getMeshElement(k);
      for(int l = 0; l < e->getNumEdges(); l++) {
        MEdge me = e->getEdge(l);
        MVertex *v0 = me.getVertex(0), *v1 = me.getVertex(1);
        if(v0->onWhat()->dim() > 1 || v1->onWhat()->dim() > 1) continue;
        std::size_t n0 = v0->getNum(), n1 = v1->getNum();
        edges[std::make_pair(std::min(n0, n1), std::max(n0, n1))].push_back(
          std::make_pair((int)i, n0 < n1 ? 1 : -1));
      }
      // the contribution of the element to the enclosed volume (the flux of
      // x/3 through it), positive if its normal points out
      SPoint3 a = e->getVertex(0)->point();
      for(std::size_t l = 1; l + 1 < e->getNumPrimaryVertices(); l++) {
        SVector3 b(a, e->getVertex(l)->point());
        SVector3 c(a, e->getVertex(l + 1)->point());
        flux[i] += dot(SVector3(a.x(), a.y(), a.z()), crossprod(b, c)) / 6.;
      }
    }
  }

  // the relative orientations of the surfaces sharing a curve that bounds no
  // other surface of the volume
  std::vector<std::map<int, int>> adj(f.size());
  for(auto &kv : edges) {
    if(kv.second.size() != 2) continue;
    int i = kv.second[0].first, j = kv.second[1].first;
    if(i == j) continue;
    int rel = (kv.second[0].second == kv.second[1].second) ? -1 : 1;
    adj[i].insert(std::make_pair(j, rel));
    adj[j].insert(std::make_pair(i, rel));
  }

  // the shells, and the orientation of each surface with respect to the first
  // surface of its shell
  std::vector<int> ori(f.size(), 0), shell(f.size(), -1);
  std::vector<double> volume;
  for(std::size_t i = 0; i < f.size(); i++) {
    if(ori[i]) continue;
    int s = volume.size();
    volume.push_back(0.);
    ori[i] = 1;
    shell[i] = s;
    std::vector<int> stack(1, i);
    while(!stack.empty()) {
      int j = stack.back();
      stack.pop_back();
      volume[s] += ori[j] * flux[j];
      for(auto &n : adj[j]) {
        if(ori[n.first]) continue;
        ori[n.first] = ori[j] * n.second;
        shell[n.first] = s;
        stack.push_back(n.first);
      }
    }
  }
  std::size_t outer = 0;
  for(std::size_t s = 1; s < volume.size(); s++)
    if(std::abs(volume[s]) > std::abs(volume[outer])) outer = s;

  for(std::size_t i = 0; i < f.size(); i++) {
    double v = volume[shell[i]] * (shell[i] == (int)outer ? 1 : -1);
    if(ori[i] * v >= 0) continue;
    for(std::size_t k = 0; k < f[i]->getNumMeshElements(); k++)
      f[i]->getMeshElement(k)->reverse();
    f[i]->meshAttributes.reverseMesh = !f[i]->meshAttributes.reverseMesh;
    Msg::Debug("Reversed the mesh of surface %d to point out of volume %d",
               f[i]->tag(), tag());
  }
  return true;
}

bool GRegion::isFullyDiscrete()
{
  if(geomType() != GEntity::DiscreteVolume) return false;
  if(haveParametrization()) return false;
  std::vector<GFace *> f = faces();
  for(std::size_t i = 0; i < f.size(); i++) {
    if(f[i]->geomType() != GEntity::DiscreteSurface) return false;
    auto *df = dynamic_cast<discreteFace *>(f[i]);
    if(df && df->haveParametrization()) return false;
  }
  std::vector<GEdge *> e = edges();
  for(std::size_t i = 0; i < e.size(); i++) {
    if(e[i]->geomType() != GEntity::DiscreteCurve) return false;
    auto *de = dynamic_cast<discreteEdge *>(e[i]);
    if(de && de->haveParametrization()) return false;
  }
  return true;
}
