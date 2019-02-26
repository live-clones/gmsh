#include "HierarchicalBasisH1.h"
/*
HierarchicalBasisH1::HierarchicalBasisH1(int nvertex, int nedge, int nface,
                                         int nVertexFunction, int nEdgeFunction,
                                         int nFaceFunction, int nBubbleFunction)
{
  this->nvertex = nvertex;
  this->nedge = nedge;
  this->nface = nface;
  this->nVertexFunction = nVertexFunction;
  this->nEdgeFunction = nEdgeFunction;
  this->nFaceFunction = nFaceFunction;
  this->nBubbleFunction = nBubbleFunction;
}*/

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
