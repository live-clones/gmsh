#include "HierarchicalBasisH1.h"

HierarchicalBasisH1::~HierarchicalBasisH1() {}

int HierarchicalBasisH1::getnEdgeFunction() const
{
  return _nEdgeFunction;
}

int HierarchicalBasisH1::getnFaceFunction() const
{
  return _nFaceFunction;
}

int HierarchicalBasisH1::getnBubbleFunction() const
{
  return _nBubbleFunction;
}

int HierarchicalBasisH1::getnVertexFunction() const
{
  return _nVertexFunction;
}

int  HierarchicalBasisH1::getNumFace() const
{
  return _nface;
}

int HierarchicalBasisH1::getNumEdge() const
{
  return _nedge;
}
