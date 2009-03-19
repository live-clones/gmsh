// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include <algorithm>
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
}

void GVertex::setPosition(GPoint &p)
{
  Msg::Error("Cannot set position of this kind of vertex");
}

void GVertex::addEdge(GEdge *e)
{ 
  l_edges.push_back(e);
}

void GVertex::delEdge(GEdge *e)
{ 
  l_edges.erase(std::find(l_edges.begin(), l_edges.end(), e));
}

SPoint2 GVertex::reparamOnFace(const GFace *gf, int) const
{
  return gf->parFromPoint(SPoint3(x(), y(), z()));
}

std::string GVertex::getAdditionalInfoString()
{
  std::ostringstream sstream;
  sstream << "{" << x() << "," << y() << "," << z() << "}";
  double lc = prescribedMeshSizeAtVertex();
  if(lc < MAX_LC) sstream << " (cl: " << lc << ")";
  return sstream.str();
}

void GVertex::writeGEO(FILE *fp)
{
  fprintf(fp, "Point(%d) = {%.16g, %.16g, %.16g, %.16g};\n",
          tag(), x(), y(), z(), prescribedMeshSizeAtVertex());
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
