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
#include "SuperEl.h"

std::map<int,SuperEl::superInfoType> SuperEl::_superInfo;

SuperEl::superInfoType::superInfoType(int type, int order)
{
  int iBaseFace = 0, iTopFace = 0;
  switch (type) {
    case TYPE_QUA:
      iBaseFace = 0; iTopFace = 2;
      break;
    case TYPE_PRI:
      iBaseFace = 0; iTopFace = 1;
      break;
    case TYPE_HEX:
      iBaseFace = 0; iTopFace = 5;
      break;
    default:
      Msg::Error("SuperEl not implemented for element of type %d", type);
      nV = 0;
      return;
  }

  // Get HO nodal basis
  const int tag = ElementType::getTag(type, order, true);                 // Get tag for incomplete element type
//  const int tag = ElementType::getTag(type, order);                     // Get tag for complete element type
  if(tag){
    const nodalBasis *basis = BasisFactory::getNodalBasis(tag);

    nV = basis->getNumShapeFunctions();
    //  _superInfo[type].nV1 = basis->getNumShapeFunctions();
    points = basis->points;

    baseInd = basis->getClosure(basis->getClosureId(iBaseFace,1,0));
    topInd = basis->getClosure(basis->getClosureId(iTopFace,0,0));
    otherInd.reserve(nV-baseInd.size()-topInd.size());
    for(int i=0; i<nV; ++i) {
      const std::vector<int>::iterator inBaseFace = find(baseInd.begin(),baseInd.end(),i);
      const std::vector<int>::iterator inTopFace = find(topInd.begin(),topInd.end(),i);
      if (inBaseFace == baseInd.end() && inTopFace == topInd.end()) otherInd.push_back(i);
    }
  }
}



SuperEl::SuperEl(int type, int order, const std::vector<MVertex*> &baseVert,
                 const std::vector<MVertex*> &topPrimVert) : _superEl(0), _superEl0(0)
{

  // Get useful info on meta-element type if not already there
  std::map<int,SuperEl::superInfoType>::iterator itSInfo = _superInfo.find(type);
  if (itSInfo == _superInfo.end())
    itSInfo = _superInfo.insert(std::pair<int,superInfoType>(type,superInfoType(type, order))).first;
  SuperEl::superInfoType &sInfo = itSInfo->second;

  // Exit if unknown type
  if (sInfo.nV == 0) return;

  // References for easier writing
  const int &nV = sInfo.nV;
  const fullMatrix<double> &points = sInfo.points;
  const std::vector<int> &baseInd = sInfo.baseInd;
  const std::vector<int> &topInd = sInfo.topInd;
  const std::vector<int> &otherInd = sInfo.otherInd;

  // Add copies of vertices in base & top faces (only first-order vertices for top face)
  _superVert.resize(nV);
  for (int i=0; i<baseInd.size(); ++i) _superVert[baseInd[i]] = new MVertex(*baseVert[i]);
  for (int i=0; i<topPrimVert.size(); ++i) _superVert[topInd[i]] = new MVertex(*topPrimVert[i]);

  // Create first-order meta-element
  switch (type) {
    case TYPE_QUA:
      _superEl0 = new MQuadrangle(_superVert);
      break;
    case TYPE_PRI:
      _superEl0 = new MPrism(_superVert);
      break;
    case TYPE_HEX:
      _superEl0 = new MHexahedron(_superVert);
      break;
    default:
      Msg::Error("SuperEl not implemented for element of type %d", type);
      return;
  }

  // Add HO vertices in top face
  for (int i=topPrimVert.size(); i<topInd.size(); ++i) {
    SPoint3 p;
    const int ind = topInd[i];
    _superEl0->pnt(points(ind,0),points(ind,1),points(ind,2),p);
    _superVert[ind] = new MVertex(p.x(),p.y(),p.z());
  }

  // Add vertices not in base & top faces
  for (int i=0; i<otherInd.size(); ++i) {
    SPoint3 p;
    const int ind = otherInd[i];
    _superEl0->pnt(points(ind,0),points(ind,1),points(ind,2),p);
    _superVert[ind] = new MVertex(p.x(),p.y(),p.z());
  }

  // Create high-order meta-element
  switch (type) {
    case TYPE_QUA:
      _superEl = new MQuadrangleN(_superVert, order);
      break;
    case TYPE_PRI:
      _superEl = new MPrismN(_superVert, order);
      break;
    case TYPE_HEX:
      _superEl = new MHexahedronN(_superVert, order);
      break;
  }

  // Scale meta-element if not valid
  // TODO: Scale depending on target Jmin?
  // TODO: Could be improved by using complete meta-element and use optimization
  for (int iter = 0; iter < 10; iter++) {
    if (_superEl->distoShapeMeasure() > 0) break;
    if (iter == 0) Msg::Warning("A meta-element has a negative distortion, trying to scale");
    for (int i=0; i<topPrimVert.size(); ++i) {                                                // Move top primary vert.
      MVertex *&vb = _superVert[baseInd[i]], *&vt = _superVert[topInd[i]];
      SPoint3 pb = vb->point(), pt = vt->point();
      pt += SPoint3(0.25*(pt-pb));
      vt->setXYZ(pt.x(), pt.y(), pt.z());
    }
    for (int i=topPrimVert.size(); i<topInd.size(); ++i) {                                    // Recompute HO vert. in top face
      SPoint3 p;
      const int ind = topInd[i];
      _superEl0->pnt(points(ind,0),points(ind,1),points(ind,2),p);
      _superVert[ind]->setXYZ(p.x(),p.y(),p.z());
    }
    for (int i=0; i<otherInd.size(); ++i) {                                                   // Recompute vert. not in base & top faces
      SPoint3 p;
      const int ind = otherInd[i];
      _superEl0->pnt(points(ind,0),points(ind,1),points(ind,2),p);
      _superVert[ind]->setXYZ(p.x(),p.y(),p.z());
    }
  }

}

SuperEl::~SuperEl()
{
  for (int i = 0; i < _superVert.size(); i++) delete _superVert[i];
  _superVert.clear();
  delete _superEl;
  if(_superEl0) delete _superEl0;
}

bool SuperEl::isPointIn(const SPoint3 p) const
{
  double xyz[3] = {p.x(), p.y(), p.z()}, uvw[3];
  _superEl0->xyz2uvw(xyz,uvw);
  return _superEl0->isInside(uvw[0],uvw[1],uvw[2]);
}

bool SuperEl::straightToCurved(double *xyzS, double *xyzC) const
{
  double uvw[3];
  _superEl0->xyz2uvw(xyzS,uvw);
  if (!_superEl0->isInside(uvw[0],uvw[1],uvw[2])) return false;

  SPoint3 pC;
  _superEl->pnt(uvw[0],uvw[1],uvw[2],pC);
  xyzC[0] = pC[0];
  xyzC[1] = pC[1];
  xyzC[2] = pC[2];

  return true;
}

std::string SuperEl::printPOS()
{
  std::vector<MVertex*> verts;
  _superEl->getVertices(verts);
//  std::string posStr = _superEl->getStringForPOS();
  std::string posStr = _superEl0->getStringForPOS();
  int n = (posStr[posStr.size()-1]=='2' ? _superEl : _superEl0)->getNumVertices();

  std::ostringstream oss;

  oss << posStr << "(";
  for(int i = 0; i < n; i++){
    if(i) oss << ",";
    oss << _superVert[i]->x() << "," <<  _superVert[i]->y() << "," <<  _superVert[i]->z();
  }
  oss << "){0.";
  for(int i = 1; i < n; i++) oss << ",0.";
  oss << "};\n";

  return oss.str();
}
