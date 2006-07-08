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

GRegion * GModel::regionByTag(int n) const
{
  std::list<GRegion*>:: const_iterator it = regions.begin();
  std::list<GRegion*>:: const_iterator end = regions.end();
  while (it != end)
    {
      GRegion *rr = (GRegion*) (*it);
      if ( rr->tag() == n)return *it;
      ++it;
    }
  return 0;
}

GFace * GModel::faceByTag(int n) const
{
  std::list<GFace*>:: const_iterator it = faces.begin();
  std::list<GFace*>:: const_iterator end = faces.end();
  while (it != end)
    {
      GFace *ff = (GFace*) (*it);
      if ( ff->tag() == n)return *it;
      ++it;
    }
  return 0;
}

GEdge * GModel::edgeByTag(int n) const
{
  std::list<GEdge*>:: const_iterator it = edges.begin();
  std::list<GEdge*>:: const_iterator end = edges.end();
  while (it != end)
    {
      GEdge *ee = (GEdge*) (*it);
      if ( ee->tag() == n)return *it;
      ++it;
    }
  return 0;
}
GVertex * GModel::vertexByTag(int n) const
{
  std::list<GVertex*>:: const_iterator it = vertices.begin();
  std::list<GVertex*>:: const_iterator end = vertices.end();
  while (it != end)
    {
      GVertex *vv = (GVertex*) (*it);
      if ( vv->tag() == n)return *it;
      ++it;
    }
  return 0;
}

