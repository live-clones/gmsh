// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

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
