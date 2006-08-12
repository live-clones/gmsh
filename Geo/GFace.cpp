#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"

GFace::~GFace ()
{ 
  std::list<GEdge*>::iterator it = l_edges.begin();

  while (it != l_edges.end()){
    (*it)->delFace(this);
    ++it;
  }

  for(unsigned int i = 0; i < mesh_vertices.size(); i++) 
    delete mesh_vertices[i];
  mesh_vertices.clear();

  for(unsigned int i = 0; i < triangles.size(); i++) 
    delete triangles[i];
  triangles.clear();

  for(unsigned int i = 0; i < quadrangles.size(); i++) 
    delete quadrangles[i];
  quadrangles.clear();
}

std::list<GVertex*> GFace::vertices() const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  std::list<GVertex*>ret;
  while (it != l_edges.end()){
    GVertex *v1 = (*it)->getBeginVertex();
    GVertex *v2 = (*it)->getEndVertex();
    if(std::find(ret.begin(), ret.end(), v1) == ret.end())
      ret.push_back(v1);
    if(std::find(ret.begin(), ret.end(), v2) == ret.end())
      ret.push_back(v2);
    ++it;
  }
  return ret;
}

void GFace::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive){
    std::list<GEdge*>::iterator it = l_edges.begin();
    while (it != l_edges.end()){
      (*it)->setVisibility(val, recursive);
      ++it;
    }
  }
}

void GFace::recomputeMeshPartitions()
{
  for(unsigned int i = 0; i < triangles.size(); i++) {
    int part = triangles[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
  for(unsigned int i = 0; i < quadrangles.size(); i++) {
    int part = quadrangles[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
}
