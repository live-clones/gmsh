// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

#include "HierarchicalBasis.h"

HierarchicalBasis::~HierarchicalBasis() {}

int HierarchicalBasis::getnEdgeFunction() const { return _nEdgeFunction; }

int HierarchicalBasis::getnTriFaceFunction() const { return _nTriFaceFunction; }
int HierarchicalBasis::getnQuadFaceFunction() const
{
  return _nQuadFaceFunction;
}

int HierarchicalBasis::getnBubbleFunction() const { return _nBubbleFunction; }

int HierarchicalBasis::getnVertexFunction() const { return _nVertexFunction; }

int HierarchicalBasis::getNumTriFace() const { return _nfaceTri; }
int HierarchicalBasis::getNumQuadFace() const { return _nfaceQuad; }

int HierarchicalBasis::getNumEdge() const { return _nedge; }
