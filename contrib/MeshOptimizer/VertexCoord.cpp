// MeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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
// Contributor(s): Thomas Toulorge, Jonathan Lambrechts

#include <iostream>
#include <algorithm>
#include "GmshMessage.h"
#include "GFace.h"
#include "GEdge.h"
#include "MVertex.h"
#include "MLine.h"
#include "VertexCoord.h"

SPoint3 VertexCoordParent::getUvw(MVertex *vert) const
{
  GEntity *ge = vert->onWhat();
  switch(ge->dim()) {
  case 1: {
    SPoint3 p(0., 0., 0.);
    reparamMeshVertexOnEdge(
      vert, static_cast<GEdge *>(ge),
      p[0]); // Overkill if vert. well classified and parametrized
    return p;
    break;
  }
  case 2: {
    SPoint2 p;
    reparamMeshVertexOnFace(
      vert, static_cast<GFace *>(ge),
      p); // Overkill if vert. well classified and parametrized
    return SPoint3(p[0], p[1], 0.);
    break;
  }
  }
  return SPoint3(0., 0., 0.);
}

SPoint3 VertexCoordParent::uvw2Xyz(const SPoint3 &uvw) const
{
  GEntity *ge = _vert->onWhat();
  GPoint gp = (ge->dim() == 1) ?
                static_cast<GEdge *>(ge)->point(uvw[0]) :
                static_cast<GFace *>(ge)->point(uvw[0], uvw[1]);
  return SPoint3(gp.x(), gp.y(), gp.z());
}

void VertexCoordParent::gXyz2gUvw(const SPoint3 &uvw, const SPoint3 &gXyz,
                                  SPoint3 &gUvw) const
{
  GEntity *ge = _vert->onWhat();

  if(ge->dim() == 1) {
    SVector3 der = static_cast<GEdge *>(ge)->firstDer(uvw[0]);
    gUvw[0] = gXyz.x() * der.x() + gXyz.y() * der.y() + gXyz.z() * der.z();
  }
  else {
    Pair<SVector3, SVector3> der =
      static_cast<GFace *>(ge)->firstDer(SPoint2(uvw[0], uvw[1]));
    gUvw[0] = gXyz.x() * der.first().x() + gXyz.y() * der.first().y() +
              gXyz.z() * der.first().z();
    gUvw[1] = gXyz.x() * der.second().x() + gXyz.y() * der.second().y() +
              gXyz.z() * der.second().z();
  }
}

void VertexCoordParent::gXyz2gUvw(const SPoint3 &uvw,
                                  const std::vector<SPoint3> &gXyz,
                                  std::vector<SPoint3> &gUvw) const
{
  GEntity *ge = _vert->onWhat();

  if(ge->dim() == 1) {
    SVector3 der = static_cast<GEdge *>(ge)->firstDer(uvw[0]);
    auto itUvw = gUvw.begin();
    for(auto itXyz = gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
      (*itUvw)[0] =
        itXyz->x() * der.x() + itXyz->y() * der.y() + itXyz->z() * der.z();
      itUvw++;
    }
  }
  else {
    Pair<SVector3, SVector3> der =
      static_cast<GFace *>(ge)->firstDer(SPoint2(uvw[0], uvw[1]));
    auto itUvw = gUvw.begin();
    for(auto itXyz = gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
      (*itUvw)[0] = itXyz->x() * der.first().x() +
                    itXyz->y() * der.first().y() + itXyz->z() * der.first().z();
      (*itUvw)[1] = itXyz->x() * der.second().x() +
                    itXyz->y() * der.second().y() +
                    itXyz->z() * der.second().z();
      itUvw++;
    }
  }
}

namespace {

  SVector3 getLineElTangent(MElement *el, int iNode)
  {
    double gsf[1256][3], u, v, w;
    el->getNode(iNode, u, v, w);
    //  el->getGradShapeFunctions(u,v,w,gsf);
    el->getGradShapeFunctions(u, v, w, gsf, 1);

    SVector3 dxyzdu(0.);
    //  int nSF = el->getNumShapeFunctions()();
    int nSF = el->getNumPrimaryVertices();
    for(int j = 0; j < nSF; j++) {
      const SPoint3 p = el->getVertex(j)->point();
      dxyzdu(0) += gsf[j][0] * p.x();
      dxyzdu(1) += gsf[j][0] * p.y();
      dxyzdu(2) += gsf[j][0] * p.z();
    }
    dxyzdu.normalize();

    return dxyzdu;
  }

  SVector3 getSurfElNormal(MElement *el, int iNode)
  {
    double gsf[1256][3], u, v, w;
    el->getNode(iNode, u, v, w);
    //  el->getGradShapeFunctions(u,v,w,gsf);
    el->getGradShapeFunctions(u, v, w, gsf, 1);

    SVector3 dxyzdu(0.), dxyzdv(0.);
    //  int nSF = el->getNumShapeFunctions()();
    int nSF = el->getNumPrimaryVertices();
    for(int j = 0; j < nSF; j++) {
      const SPoint3 p = el->getVertex(j)->point();
      dxyzdu(0) += gsf[j][0] * p.x();
      dxyzdu(1) += gsf[j][0] * p.y();
      dxyzdu(2) += gsf[j][0] * p.z();
      dxyzdv(0) += gsf[j][1] * p.x();
      dxyzdv(1) += gsf[j][1] * p.y();
      dxyzdv(2) += gsf[j][1] * p.z();
    }

    SVector3 normal = crossprod(dxyzdu, dxyzdv);
    normal.normalize();
    return normal;
  }

} // namespace

VertexCoordLocalLine::VertexCoordLocalLine(MVertex *v)
  : dir(0.), x0(v->x()), y0(v->y()), z0(v->z())
{
  GEntity *ge = v->onWhat();
  const unsigned nEl = ge->getNumMeshElements();

  for(unsigned iEl = 0; iEl < nEl; iEl++) {
    MElement *el = ge->getMeshElement(iEl);
    std::vector<MVertex *> lVerts;
    el->getVertices(lVerts);
    auto itV = std::find(lVerts.begin(), lVerts.end(), v);
    if(itV != lVerts.end()) {
      const int iNode = std::distance(lVerts.begin(), itV);
      dir += getLineElTangent(el, iNode);
    }
  }
  dir.normalize();
}

VertexCoordLocalSurf::VertexCoordLocalSurf(MVertex *v)
  : x0(v->x()), y0(v->y()), z0(v->z())
{
  GEntity *ge = v->onWhat();
  const unsigned nEl = ge->getNumMeshElements();

  SVector3 n(0.);
  for(unsigned iEl = 0; iEl < nEl; iEl++) {
    MElement *el = ge->getMeshElement(iEl);
    std::vector<MVertex *> lVerts;
    el->getVertices(lVerts);
    auto itV = std::find(lVerts.begin(), lVerts.end(), v);
    if(itV != lVerts.end()) {
      const int iNode = std::distance(lVerts.begin(), itV);
      n += getSurfElNormal(el, iNode);
    }
  }
  n.normalize();

  if(fabs(fabs(dot(n, SVector3(1., 0., 0.))) - 1.) <
     1.e-10) { // If normal is x-axis, take y- and z- axis as dir.
    dir0 = SVector3(0., 1., 0.);
    dir1 = SVector3(0., 0., 1.);
  }
  else {
    dir0 =
      SVector3(1. - n.x() * n.x(), -n.x() * n.y(),
               -n.x() * n.z()); // 1st dir. = (normalized) proj. of e_x in plane
    dir0.normalize();
    dir1 = crossprod(dir0, n);
  }
}
