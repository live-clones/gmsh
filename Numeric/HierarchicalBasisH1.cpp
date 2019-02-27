#include "HierarchicalBasisH1.h"

HierarchicalBasisH1::~HierarchicalBasisH1() {}

int HierarchicalBasisH1::getnEdgeFunction() const
{
  return this->nEdgeFunction;
}

int HierarchicalBasisH1::getnFaceFunction() const
{
  return this->nFaceFunction;
}

int HierarchicalBasisH1::getnBubbleFunction() const
{
  return this->nBubbleFunction;
}

int HierarchicalBasisH1::getnVertexFunction() const
{
  return this->nVertexFunction;
}
