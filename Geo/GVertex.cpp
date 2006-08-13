#include "GVertex.h"
#include <algorithm>

GVertex::~GVertex()
{
  for(unsigned int i = 0; i < mesh_vertices.size(); i++)
    delete mesh_vertices[i];
  mesh_vertices.clear();
}

void GVertex::addEdge(GEdge *e)
{ 
  l_edges.push_back(e);
}

void GVertex::delEdge(GEdge *e)
{ 
  l_edges.erase(std::find(l_edges.begin(), l_edges.end(), e));
}

std::string GVertex::getAdditionalInfoString()
{
  char str[256];
  sprintf(str, "{%g,%g,%g", x(), y(), z());
  double lc = prescribedMeshSizeAtVertex();
  if(lc > 0.){
    char str2[256];
    sprintf(str2, ",%g", lc);
    strcat(str, str2);
  }
  strcat(str, "}");
  return std::string(str);
}
