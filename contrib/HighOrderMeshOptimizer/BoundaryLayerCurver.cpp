// Copyright (C) 2017 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Amaury Johnen

#include "BoundaryLayerCurver.h"
#include "MElement.h"
#include "GmshDefines.h"

void curve2DTriColumn(MElement *bottomEdge, std::vector<MElement*> &column,
                      SVector3 u, SVector3 v, SVector3 n)
{
  for (int i = 0; i < column.size(); i += 2) {
    MElement *tri0 = column[i];
    MElement *tri1 = column[i+1];
  }
}

void curve2DQuadColumn(MElement *bottomEdge, std::vector<MElement*> &column,
                       SVector3 u, SVector3 v, SVector3 n)
{
  for (int i = 0; i < column.size(); ++i) {
    MElement *quad = column[i];
    
  }
}

void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, SVector3 n)
{
  // Compute reference frame (handle general planar 2D BL)
  int k = 0;
  if (std::abs(n(1)) > std::abs(n(k))) k = 1;
  if (std::abs(n(2)) > std::abs(n(k))) k = 2;
  SVector3 u(0, 0, 0);
  u((k+1) % 3) = 1;
  SVector3 v = crossprod(n, u);
  v.normalize();
  u = crossprod(v, n);

#ifdef _OPENMP
#pragma omp for
#endif
  for (int i = 0; i < bndEl2column.size(); ++i) {
    MElement *bottomEdge = bndEl2column[i].first;
    std::vector<MElement*> &column = bndEl2column[i].second;
    if (column[0]->getType() == TYPE_TRI)
      curve2DTriColumn(bottomEdge, column, u, v, n);
    else
      curve2DQuadColumn(bottomEdge, column, u, v, n);
  }
}

void curve3DBoundaryLayer(VecPairMElemVecMElem &bndEl2column)
{

}
