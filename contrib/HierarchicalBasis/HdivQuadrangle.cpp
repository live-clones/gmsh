// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// References: Solin, P., Segeth, K., & Dolezel, I. (2003). Higher-Order Finite
// Element Methods. Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041
// Zaglmayr, S. (2006). High Order Finite Element Methods for Electromagnetic
// Field Computation. PhD thesis, Johannes Kepler University Linz.

#include "HdivQuadrangle.h"
#include "Blocks.h"

HdivQuadrangle::HdivQuadrangle(int order) : _order(order), _hcurl(order)
{
  _numVertex = _hcurl.getNumVertex();
  _numEdge = _hcurl.getNumEdge();
  _numTriFace = _hcurl.getNumTriFace();
  _numQuadFace = _hcurl.getNumQuadFace();
  _numVertexFunction = 0;
  _numEdgeFunction = _hcurl.getNumEdgeFunction();
  _numQuadFaceFunction = _hcurl.getNumQuadFaceFunction();
  _numTriFaceFunction = _hcurl.getNumTriFaceFunction();
  _numBubbleFunction = 0;
}

void HdivQuadrangle::functions(const Dual *x, std::vector<Vec> &vertex,
                               std::vector<Vec> &edge, std::vector<Vec> &face,
                               std::vector<Vec> &bubble)
{
  _hcurl.functions(x, vertex, edge, face, bubble);
  for(auto &f : edge) f = -1. * rotate(f);
  for(auto &f : face) f = rotate(f);
}

void HdivQuadrangle::faceFunctions(const Dual *x, int flag1, int flag2,
                                   int flag3, int faceNumber,
                                   std::vector<Vec> &face)
{
  // the functions of the only face of the element
  _hcurl.faceFunctions(x, flag1, flag2, flag3, faceNumber, face);
  for(auto &f : face) f = rotate(f);
}

void HdivQuadrangle::functionInfo(std::vector<FunctionInfo> &info)
{ _hcurl.functionInfo(info); }
