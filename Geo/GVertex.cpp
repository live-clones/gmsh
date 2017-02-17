// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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

GVertex::~GVertex()
{
  deleteMesh();
}

void GVertex::deleteMesh()
{
  for(unsigned int i = 0; i < mesh_vertices.size(); i++) delete mesh_vertices[i];
  mesh_vertices.clear();
  for(unsigned int i = 0; i < points.size(); i++) delete points[i];
  points.clear();
  deleteVertexArrays();
  model()->destroyMeshCaches();
}

void GVertex::resetMeshAttributes()
{
  meshSize = MAX_LC;
}

void GVertex::setPosition(GPoint &p)
{
  Msg::Error("Cannot set position of this kind of vertex");
}

void GVertex::addEdge(GEdge *e)
{
  if(std::find(l_edges.begin(), l_edges.end(), e) == l_edges.end())
    l_edges.push_back(e);
}

void GVertex::delEdge(GEdge *e)
{
  std::list<GEdge*>::iterator it = std::find(l_edges.begin(), l_edges.end(), e);
  if(it != l_edges.end()) l_edges.erase(it);
}

SPoint2 GVertex::reparamOnFace(const GFace *gf, int) const
{
  return gf->parFromPoint(SPoint3(x(), y(), z()));
}

std::string GVertex::getAdditionalInfoString()
{
  std::ostringstream sstream;
  sstream.precision(12);
  sstream << "{" << x() << "," << y() << "," << z() << "}";
  double lc = prescribedMeshSizeAtVertex();
  if(lc < MAX_LC) sstream << " (mesh size: " << lc << ")";
  return sstream.str();
}

void GVertex::writeGEO(FILE *fp, const std::string &meshSizeParameter)
{
  if(meshSizeParameter.size())
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g, %s};\n",
            tag(), x(), y(), z(), meshSizeParameter.c_str());
  else if(prescribedMeshSizeAtVertex() != MAX_LC)
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g, %.16g};\n",
            tag(), x(), y(), z(), prescribedMeshSizeAtVertex());
  else
    fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g};\n",
            tag(), x(), y(), z());
}

unsigned int GVertex::getNumMeshElements()
{
  return points.size();
}

MElement *GVertex::getMeshElement(unsigned int index)
{
  if(index < points.size())
    return points[index];
  return 0;
}

bool GVertex::isOnSeam(const GFace *gf) const
{
  std::list<GEdge*>::const_iterator eIter = l_edges.begin();
  for (; eIter != l_edges.end(); eIter++) {
    if ( (*eIter)->isSeam(gf) ) return true;
  }
  return false;
}

// faces that bound this entity or that this entity bounds.
std::list<GFace*> GVertex::faces() const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  std::set<GFace*> _f;
  for ( ; it != l_edges.end() ; ++it){
    std::list<GFace*> temp = (*it)->faces();
    _f.insert (temp.begin(), temp.end());
  }
  std::list<GFace*> ret;
  ret.insert (ret.begin(), _f.begin(), _f.end());
  return ret;
}

// regions that bound this entity or that this entity bounds.
std::list<GRegion*> GVertex::regions() const
{
  std::list<GFace*> _faces = faces();
  std::list<GFace*>::const_iterator it = _faces.begin();
  std::set<GRegion*> _r;
  for ( ; it != _faces.end() ; ++it){
    std::list<GRegion*> temp = (*it)->regions();
    _r.insert (temp.begin(), temp.end());
  }
  std::list<GRegion*> ret;
  ret.insert (ret.begin(), _r.begin(), _r.end());
  return ret;
}

void GVertex::relocateMeshVertices()
{
  for(unsigned int i = 0; i < mesh_vertices.size(); i++){
    MVertex *v = mesh_vertices[i];
    v->x() = x();
    v->y() = y();
    v->z() = z();
  }
}
