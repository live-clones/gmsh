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
