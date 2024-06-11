// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <algorithm>
#include "GModel.h"
#include "GVertex.h"
#include "GFace.h"
#include "MPoint.h"
#include "GmshMessage.h"

GVertex::GVertex(GModel *m, int tag, double ms) : GEntity(m, tag), meshSize(ms)
{
}

GVertex::~GVertex() { GVertex::deleteMesh(); }

void GVertex::deleteMesh()
{
  for(auto v : mesh_vertices) delete v;
  mesh_vertices.clear();
  removeElements(true);
  deleteVertexArrays();
  model()->destroyMeshCaches();
}

void GVertex::resetMeshAttributes() { meshSize = MAX_LC; }

void GVertex::setPosition(GPoint &p)
{
  Msg::Error("Cannot set position of this kind of point");
}

void GVertex::addEdge(GEdge *e)
{
  if(std::find(l_edges.begin(), l_edges.end(), e) == l_edges.end())
    l_edges.push_back(e);
}

void GVertex::delEdge(GEdge *const e)
{
  auto it = std::find(l_edges.begin(), l_edges.end(), e);
  if(it != l_edges.end()) l_edges.erase(it);
}

SPoint2 GVertex::reparamOnFace(const GFace *gf, int) const
{
  return gf->parFromPoint(SPoint3(x(), y(), z()));
}

std::string GVertex::getAdditionalInfoString(bool multline)
{
  std::ostringstream sstream;
  sstream.precision(12);
  sstream << "Position (" << x() << ", " << y() << ", " << z() << ")";
  if(multline)
    sstream << "\n";
  else
    sstream << " ";

  if(l_edges.size()) {
    sstream << "On boundary of curves: ";
    for(auto it = l_edges.begin(); it != l_edges.end(); ++it) {
      if(it != l_edges.begin()) sstream << ", ";
      sstream << (*it)->tag();
    }
    if(multline)
      sstream << "\n";
    else
      sstream << " ";
  }

  double lc = prescribedMeshSizeAtVertex();
  if(lc < MAX_LC) { sstream << "Mesh attributes: size " << lc; }

  std::string str = sstream.str();
  if(str.size() && (str[str.size() - 1] == '\n' || str[str.size() - 1] == ' '))
    str.resize(str.size() - 1);

  return str;
}

void GVertex::writeGEO(FILE *fp, const std::string &meshSizeParameter)
{
  if(meshSizeParameter.size())
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g, %s};\n", tag(), x(), y(),
            z(), meshSizeParameter.c_str());
  else if(prescribedMeshSizeAtVertex() != MAX_LC)
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g, %.16g};\n", tag(), x(), y(),
            z(), prescribedMeshSizeAtVertex());
  else
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g};\n", tag(), x(), y(), z());
}

void GVertex::writePY(FILE *fp, const std::string &meshSizeParameter)
{
  const char *factory = getNativeType() == OpenCascadeModel ? "occ" : "geo";
  if(meshSizeParameter.size())
    fprintf(fp, "gmsh.model.%s.addPoint(%.16g, %.16g, %.16g, %s, %d)\n",
            factory, x(), y(), z(), meshSizeParameter.c_str(), tag());
  else if(prescribedMeshSizeAtVertex() != MAX_LC)
    fprintf(fp, "gmsh.model.%s.addPoint(%.16g, %.16g, %.16g, %.16g, %d)\n",
            factory, x(), y(), z(), prescribedMeshSizeAtVertex(), tag());
  else
    fprintf(fp, "gmsh.model.%s.addPoint(%.16g, %.16g, %.16g, tag=%d)\n",
            factory, x(), y(), z(), tag());
}

std::size_t GVertex::getNumMeshElementsByType(const int familyType) const
{
  if(familyType == TYPE_PNT) return points.size();

  return 0;
}

void GVertex::getNumMeshElements(unsigned *const c) const
{
  c[0] += points.size();
}

MElement *GVertex::getMeshElement(std::size_t index) const
{
  if(index < points.size()) return points[index];
  return nullptr;
}

MElement *GVertex::getMeshElementByType(const int familyType,
                                        const std::size_t index) const
{
  if(familyType == TYPE_PNT) return points[index];

  return nullptr;
}

bool GVertex::isOnSeam(const GFace *gf) const
{
  auto const location =
    std::find_if(begin(l_edges), end(l_edges),
                 [&](GEdge *const edge) { return edge->isSeam(gf); });
  return location != end(l_edges);
}

// faces that bound this entity or that this entity bounds.
std::vector<GFace *> GVertex::faces() const
{
  std::vector<GFace *> faces;

  for(auto it = l_edges.begin(); it != l_edges.end(); ++it) {
    std::vector<GFace *> const &temp = (*it)->faces();
    faces.insert(faces.end(), temp.begin(), temp.end());
  }
  std::sort(faces.begin(), faces.end());
  faces.erase(std::unique(faces.begin(), faces.end()), faces.end());

  return faces;
}

// regions that bound this entity or that this entity bounds.
std::list<GRegion *> GVertex::regions() const
{
  std::vector<GFace *> const _faces = faces();
  std::set<GRegion *> _r;
  for(auto it = _faces.begin(); it != _faces.end(); ++it) {
    std::list<GRegion *> temp = (*it)->regions();
    _r.insert(temp.begin(), temp.end());
  }
  std::list<GRegion *> ret;
  ret.insert(ret.begin(), _r.begin(), _r.end());
  return ret;
}

bool GVertex::isOrphan()
{
  if(model()->getNumRegions())
    return regions().empty();
  else if(model()->getNumFaces())
    return faces().empty();
  else if(model()->getNumEdges())
    return edges().empty();
  return false;
}

void GVertex::relocateMeshVertices()
{
  for(std::size_t i = 0; i < mesh_vertices.size(); i++) {
    MVertex *v = mesh_vertices[i];
    v->x() = x();
    v->y() = y();
    v->z() = z();
  }
}

void GVertex::addElement(MElement *e)
{
  switch(e->getType()) {
  case TYPE_PNT: addPoint(reinterpret_cast<MPoint *>(e)); break;
  default:
    Msg::Error("Trying to add unsupported element in point %d", tag());
  }
}

void GVertex::removeElement(MElement *e, bool del)
{
  switch(e->getType()) {
  case TYPE_PNT: {
    auto it =
      std::find(points.begin(), points.end(), reinterpret_cast<MPoint *>(e));
    if(it != points.end()) {
      points.erase(it);
      if(del) delete e;
    }
  } break;
  default:
    Msg::Error("Trying to remove unsupported element in point %d", tag());
  }
}

void GVertex::removeElements(bool del)
{
  if(del) {
    for(auto e : points) delete e;
  }
  points.clear();
}

bool GVertex::reorder(const int elementType,
                      const std::vector<std::size_t> &ordering)
{
  if(points.size() != 0) {
    if(points.front()->getTypeForMSH() == elementType) {
      if(ordering.size() != points.size()) return false;

      for(auto it = ordering.begin(); it != ordering.end(); ++it) {
        if(*it >= points.size()) return false;
      }

      std::vector<MPoint *> newPointsOrder(points.size());
      for(std::size_t i = 0; i < ordering.size(); i++) {
        newPointsOrder[i] = points[ordering[i]];
      }
      points = std::move(newPointsOrder);
      return true;
    }
  }

  return false;
}
