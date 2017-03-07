// Copyright (C) 2013 ULg-UCL
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
// Contributor: Thomas Toulorge

#include <iostream>
#include <sstream>
#include "GmshMessage.h"
#include "GEdge.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "BasisFactory.h"
#include "MetaEl.h"


std::map<int, MetaEl::metaInfoType> MetaEl::_metaInfo;


//namespace {
//
//
//void getEdgeIndQuad(int order, std::vector<int> edInd) {
//  edInd.clear();
//  const int nbEdVert = 4*(order-1);
//  edInd.resize(nbEdVert);
//  for (int iV = 0; iV < nbEdVert; iV++) edInd[iV] = iV;
//}
//
//
//
//}


MetaEl::metaInfoType::metaInfoType(int type, int order)
{
  typedef std::vector<int>::iterator VIntIter;

  int iBaseFace = 0, iTopFace = 0, nbEdVert = 0;
  switch (type) {
    case TYPE_QUA:
      iBaseFace = 0; iTopFace = 2; nbEdVert = 4 + 4*(order-1);
      break;
    case TYPE_PRI:
      iBaseFace = 0; iTopFace = 1; nbEdVert = 6 + 9*(order-1);
      break;
    case TYPE_HEX:
      iBaseFace = 0; iTopFace = 5; nbEdVert = 8 + 12*(order-1);
      break;
    default:
      Msg::Error("MetaEl not implemented for element of type %d", type);
      nbVert = 0;
      return;
  }

  // Get HO nodal basis
//  const int tag = ElementType::getTag(type, order, true);                     // Get tag for incomplete element type
  const int tag = ElementType::getTag(type, order);                             // Get tag for complete element type
  if (!tag) return;
  const nodalBasis *basis = BasisFactory::getNodalBasis(tag);
  nbVert = basis->getNumShapeFunctions();
  points = basis->points;
  std::set<int> foundVerts;

  // Vertices on base and top faces
  baseInd = basis->getClosure(basis->getClosureId(iBaseFace, 1, 0));
  topInd = basis->getClosure(basis->getClosureId(iTopFace, 0, 0));
  foundVerts.insert(baseInd.begin(), baseInd.end());
  foundVerts.insert(topInd.begin(), topInd.end());

  // Vertices on edges (excluding base and top faces)
  for (int iV = 0; iV < nbEdVert; iV++)
    if (foundVerts.find(iV) == foundVerts.end()) {
      edgeInd.push_back(iV);
      foundVerts.insert(iV);
    }

  // Remaining face and interior vertices
  for(int iV = 0; iV < nbVert; iV++)
    if (foundVerts.find(iV) == foundVerts.end()) {
      otherInd.push_back(iV);
      foundVerts.insert(iV);
    }
}


MetaEl::MetaEl(int type, int order, const std::vector<MVertex*> &baseVert,
                 const std::vector<MVertex*> &topPrimVert) : _metaEl(0), _metaEl0(0)
{

  // Get useful info on meta-element type if not already there
  std::map<int, MetaEl::metaInfoType>::iterator itSInfo = _metaInfo.find(type);
  if (itSInfo == _metaInfo.end()) {
    const metaInfoType mInfo(type, order);
    itSInfo = _metaInfo.insert(std::pair<int,metaInfoType>(type, mInfo)).first;
  }
  MetaEl::metaInfoType &sInfo = itSInfo->second;

  // Exit if unknown type
  if (sInfo.nbVert == 0) return;

  // References for easier writing
  const int &nbVert = sInfo.nbVert;
  const fullMatrix<double> &points = sInfo.points;
  const std::vector<int> &baseInd = sInfo.baseInd;
  const std::vector<int> &topInd = sInfo.topInd;
  const std::vector<int> &edgeInd = sInfo.edgeInd;
  const std::vector<int> &otherInd = sInfo.otherInd;

  // Add copies of vertices in base & top faces (only first-order vertices for top face)
  _metaVert.resize(nbVert);
  for (int iV = 0; iV < baseInd.size(); iV++)
    _metaVert[baseInd[iV]] = new MVertex(*baseVert[iV]);
  for (int iV = 0; iV < topPrimVert.size(); iV++)
    _metaVert[topInd[iV]] = new MVertex(*topPrimVert[iV]);

  // Create first-order meta-element
  switch (type) {
    case TYPE_QUA:
      _metaEl0 = new MQuadrangle(_metaVert);
      break;
    case TYPE_PRI:
      _metaEl0 = new MPrism(_metaVert);
      break;
    case TYPE_HEX:
      _metaEl0 = new MHexahedron(_metaVert);
      break;
    default:
      Msg::Error("SuperEl not implemented for element of type %d", type);
      return;
  }

  // Add HO vertices in top face
  for (int iV = topPrimVert.size(); iV < topInd.size(); iV++) {
    SPoint3 p;
    const int ind = topInd[iV];
    _metaEl0->pnt(points(ind, 0), points(ind, 1), points(ind, 2), p);
    _metaVert[ind] = new MVertex(p.x(), p.y(), p.z());
  }

  // Add vertices on edges (excluding base and top faces)
  for (int iV = 0; iV < edgeInd.size(); iV++) {
    SPoint3 p;
    const int ind = edgeInd[iV];
    _metaEl0->pnt(points(ind, 0), points(ind, 1), points(ind, 2), p);
    _metaVert[ind] = new MVertex(p.x(), p.y(), p.z());
  }

  // Get incomplete high-order meta-element basis
  const int tag = ElementType::getTag(type, order, true);                       // Get tag for incomplete element type
  if (!tag) return;
  const nodalBasis *incBasis = BasisFactory::getNodalBasis(tag);

  // Add remaining face and interior points
  for (int iV = 0; iV < otherInd.size(); iV++) {
    const int ind = otherInd[iV];
    double shapeFunc[1256];
    incBasis->f(points(ind, 0), points(ind, 1), points(ind, 2), shapeFunc);
    double x = 0., y = 0., z = 0.;
    for (int iSF = 0; iSF < incBasis->getNumShapeFunctions(); iSF++) {
      x += shapeFunc[iSF] * _metaVert[iSF]->x();
      y += shapeFunc[iSF] * _metaVert[iSF]->y();
      z += shapeFunc[iSF] * _metaVert[iSF]->z();
    }
    _metaVert[ind] = new MVertex(x, y, z);
  }

  // Create high-order meta-element
  switch (type) {
    case TYPE_QUA:
      _metaEl = new MQuadrangleN(_metaVert, order);
      break;
    case TYPE_PRI:
      _metaEl = new MPrismN(_metaVert, order);
      break;
    case TYPE_HEX:
      _metaEl = new MHexahedronN(_metaVert, order);
      break;
  }

//  // Scale meta-element if not valid
//  // TODO: Scale depending on target Jmin?
//  // TODO: Could be improved by using complete meta-element and use optimization
//  for (int iter = 0; iter < 10; iter++) {
//    if (_metaEl->distoShapeMeasure() > 0) break;
//    if (iter == 0)
//      Msg::Warning("A meta-element has a negative distortion, trying to scale");
//    for (int i = 0; i < topPrimVert.size(); ++i) {                              // Move top primary vert.
//      MVertex *&vb = _metaVert[baseInd[i]], *&vt = _metaVert[topInd[i]];
//      SPoint3 pb = vb->point(), pt = vt->point();
//      pt += SPoint3(0.25*(pt-pb));
//      vt->setXYZ(pt.x(), pt.y(), pt.z());
//    }
//    for (int i=topPrimVert.size(); i<topInd.size(); ++i) {                      // Recompute HO vert. in top face
//      SPoint3 p;
//      const int ind = topInd[i];
//      _metaEl0->pnt(points(ind,0), points(ind,1), points(ind,2),p);
//      _metaVert[ind]->setXYZ(p.x(), p.y(), p.z());
//    }
//    for (int i=0; i<otherInd.size(); ++i) {                                     // Recompute vert. not in base & top faces
//      SPoint3 p;
//      const int ind = otherInd[i];
//      _metaEl0->pnt(points(ind,0), points(ind,1), points(ind,2),p);
//      _metaVert[ind]->setXYZ(p.x(), p.y(), p.z());
//    }
//  }

}


MetaEl::~MetaEl()
{
  for (int i = 0; i < _metaVert.size(); i++) delete _metaVert[i];
  _metaVert.clear();
  if (_metaEl) delete _metaEl;
  if (_metaEl0) delete _metaEl0;
}


bool MetaEl::isPointIn(const SPoint3 p) const
{
  double xyz[3] = {p.x(), p.y(), p.z()}, uvw[3];
  _metaEl0->xyz2uvw(xyz, uvw);
  return _metaEl0->isInside(uvw[0], uvw[1], uvw[2]);
}


bool MetaEl::straightToCurved(double *xyzS, double *xyzC) const
{
  double uvw[3];
  _metaEl0->xyz2uvw(xyzS, uvw);
  if (!_metaEl0->isInside(uvw[0], uvw[1], uvw[2])) return false;

  SPoint3 pC;
  _metaEl->pnt(uvw[0], uvw[1], uvw[2], pC);
  xyzC[0] = pC[0];
  xyzC[1] = pC[1];
  xyzC[2] = pC[2];

  return true;
}


std::string MetaEl::printPOS()
{
  std::vector<MVertex*> verts;
  _metaEl->getVertices(verts);
  std::string posStr = _metaEl0->getStringForPOS();
  int n = (posStr[posStr.size()-1] == '2' ?
          _metaEl : _metaEl0)->getNumVertices();

  std::ostringstream oss;

  oss << posStr << "(";
  for(int i = 0; i < n; i++){
    if(i) oss << ",";
    oss << _metaVert[i]->x() << "," <<  _metaVert[i]->y() << ","
        <<  _metaVert[i]->z();
  }
  oss << "){0.";
  for(int i = 1; i < n; i++) oss << ",0.";
  oss << "};\n";

  return oss.str();
}
