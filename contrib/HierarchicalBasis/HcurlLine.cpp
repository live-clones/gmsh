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

#include "HcurlLine.h"
#include "Blocks.h"

HcurlLine::HcurlLine(int order) : _order(order), _h1(order + 1)
{
  _numVertex = 2;
  _numEdge = 1;
  _numQuadFace = _numTriFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = order + 1;
  _numQuadFaceFunction = _numTriFaceFunction = _numBubbleFunction = 0;
}

void HcurlLine::functions(const Dual *x, std::vector<Vec> &vertex,
                          std::vector<Vec> &edge, std::vector<Vec> &face,
                          std::vector<Vec> &bubble)
{
  std::vector<Dual> hv, he, hf, hb;
  h1Functions(_h1, x, hv, he, hf, hb);
  hcurlEdge(whitney(hv[0], hv[1]), he.data(), _order, edge.data());
}

void HcurlLine::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                              int faceNumber, std::vector<Vec> &face)
{
}

void HcurlLine::functionInfo(std::vector<FunctionInfo> &info)
{ hcurlEdgeInfo(_order, info); }
