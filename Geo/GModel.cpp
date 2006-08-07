#include "GModel.h"

int GModel::numRegion() const
{
  return regions.size();
}
int GModel::numFace  () const
{
  return faces.size();
}
int GModel::numEdge  () const
{
  return edges.size();
}
int GModel::numVertex() const
{
  return vertices.size();
}

// JF: how can we do the following in a cleaner way???

GRegion * GModel::regionByTag(int n) const
{
  dummyEntity tmp((GModel*)this, n);
  riter it = regions.find((GRegion*)&tmp);
  if(it != regions.end())
    return (GRegion *) (*it);
  else
    return 0;
}

GFace * GModel::faceByTag(int n) const
{
  dummyEntity tmp((GModel*)this, n);
  fiter it = faces.find((GFace*)&tmp);
  if(it != faces.end())
    return (GFace *) (*it);
  else
    return 0;
}

GEdge * GModel::edgeByTag(int n) const
{
  dummyEntity tmp((GModel*)this, n);
  eiter it = edges.find((GEdge*)&tmp);
  if(it != edges.end())
    return (GEdge *) (*it);
  else
    return 0;
}

GVertex * GModel::vertexByTag(int n) const
{
  dummyEntity tmp((GModel*)this, n);
  viter it = vertices.find((GVertex*)&tmp);
  if(it != vertices.end())
    return (GVertex *) (*it);
  else
    return 0;
}

int GModel::renumberMeshVertices()
{
  int numVertices = 0;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  for(GModel::eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  for(GModel::fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  for(GModel::riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  return numVertices;
}

bool GModel::noPhysicals()
{
  bool somePhysicals = false;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    if((*it)->physicals.size()){ somePhysicals = true; break; }
  if(!somePhysicals)
    for(eiter it = firstEdge(); it != lastEdge(); ++it)
      if((*it)->physicals.size()){ somePhysicals = true; break; }
  if(!somePhysicals)
    for(fiter it = firstFace(); it != lastFace(); ++it)
      if((*it)->physicals.size()){ somePhysicals = true; break; }
  if(!somePhysicals)
    for(riter it = firstRegion(); it != lastRegion(); ++it)
      if((*it)->physicals.size()){ somePhysicals = true; break; }

  return !somePhysicals;
}

static void addInGroup(GEntity* ge, std::map<int, std::vector<GEntity*> > &group)
{
  for(unsigned int i = 0; i < ge->physicals.size(); i++){
    int p = ge->physicals[i];
    if(std::find(group[p].begin(), group[p].end(), ge) == group[p].end())
      group[p].push_back(ge);
  }
}

void GModel::getPhysicalGroups(std::map<int, std::vector<GEntity*> > groups[4])
{
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    addInGroup(*it, groups[0]);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    addInGroup(*it, groups[1]);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    addInGroup(*it, groups[2]);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    addInGroup(*it, groups[3]);
}

SBoundingBox3d GModel::recomputeBounds()
{
  SBoundingBox3d bb;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    bb += (*it)->bounds();
  /*
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    bb += (*it)->bounds();
  for(fiter it = firstFace(); it != lastFace(); ++it)
    bb += (*it)->bounds();
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    bb += (*it)->bounds();
  */
  boundingBox = bb;
  return bounds();
}
